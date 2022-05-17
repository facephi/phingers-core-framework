//
// Created by wlucas on 3/8/22.
//

#ifndef GAUSSIAN_RANSAC_H_
#define GAUSSIAN_RANSAC_H_

#include <iostream>
#include <vector>
#include <random>
#include <opencv2/core/core.hpp>

#include "dft/Finger.h"
#include "dft/DftException.h"

namespace dft {
class GaussianRANSAC {
 private:
  int maxIters; // Number of iterations before termination
  double epsilon; // The threshold for computing model consensus

  std::size_t numParams;

 public:
  GaussianRANSAC(double epsilon, int numParams = 3) : epsilon(epsilon), numParams(numParams) {
    // being very pessimistic on the noise here...
    maxIters = estimateRANSACIters(0.999, 0.8, numParams);
  };

  virtual ~GaussianRANSAC() = default;;

  std::pair<std::vector<int>, cv::Vec3d> estimate(const std::vector<double>& xs, const std::vector<double>& ys) {
    assert(xs.size() == ys.size());

    std::size_t maxPosition = std::max_element(ys.begin(), ys.end()) - ys.begin();
    std::size_t leftPosition = std::max(std::size_t(0), maxPosition - 6);
    std::size_t rightPosition = std::min(ys.size(), maxPosition + 7); // upper-bound non-inclusive

    std::vector<double> peakXs, peakYs;
    for(std::size_t i = leftPosition; i < rightPosition; ++i) {
      peakXs.emplace_back(xs[i]);
      peakYs.emplace_back(ys[i]);
    }

    cv::Mat matx(peakXs);
    cv::Mat maty(peakYs);

    cv::Mat data;
    cv::hconcat(matx, maty, data);

    if(data.rows <= numParams) {
      throw DftException("RANSAC needs at least 3 samples to estimate a gaussian curve fit.");
    }

    int lowerBound = static_cast<int>((numParams - 1) / 2);
    int upperBound = static_cast<int>(peakXs.size() - 1 - (numParams - 1) / 2);
    std::mt19937 randEngine(std::time(nullptr));
    std::uniform_int_distribution<int> midDist(lowerBound, upperBound);

    std::pair<std::vector<int>, cv::Vec3d> bestInliers(std::vector<int>(), cv::Vec3d(0., 0., 0.));
    for(int i = 0; i < maxIters; ++i) {
      std::vector<int> sampleIndices(numParams);

      // TODO: make this work for 5 or 7 samples
      // pick the center
      sampleIndices[1] = midDist(randEngine);

      // pick the left
      std::uniform_int_distribution<int> leftDist(0, sampleIndices[1] - 1);
      sampleIndices[0] = leftDist(randEngine);

      // pick the right
      std::uniform_int_distribution<int> rightDist(sampleIndices[1] + 1, static_cast<int>(peakXs.size() - 1));
      sampleIndices[2] = rightDist(randEngine);

      // Check if the sampled model is the best so far
      std::pair<std::vector<int>, cv::Vec3d> inliers = countInliers(data, sampleIndices);

      if(inliers.first.size() > bestInliers.first.size()) {
        bestInliers = inliers;
      }
    }

    // offset indices into original samples
    for(int& i: bestInliers.first) {
      i += static_cast<int>(leftPosition);
    }

    return bestInliers;
  };

 private:
  static cv::Vec3d estimateParams(const cv::Mat& samples, const std::vector<int>& subsetIndices) {
    std::vector<cv::Mat> subset;
    for(int i: subsetIndices) {
      subset.emplace_back(samples.row(i));
    }

    cv::Mat matSubset;
    cv::vconcat(subset, matSubset);

    cv::Scalar mu, sigma;
    cv::meanStdDev(matSubset.col(0), mu, sigma);

    double maxVal;
    cv::minMaxLoc(matSubset.col(1), nullptr, &maxVal, nullptr, nullptr);

    return {mu.val[0], sigma.val[0], maxVal};
  }

  static double gaussian(const cv::Vec3d& p, double x) {
    return p[2] * std::exp(-0.5 * std::pow((x - p[0]) / (p[1] * p[1]), 2));
  }

  std::pair<std::vector<int>, cv::Vec3d> countInliers(
    const cv::Mat& samples,
    const std::vector<int>& sampleIndices
  ) const {
    cv::Vec3d m = estimateParams(samples, sampleIndices);

    std::vector<int> inliers;
    for(int i = 0; i < samples.rows; ++i) {
      double y = gaussian(m, samples.at<double>(i, 0));

      if(std::abs(samples.at<double>(i, 1) - y) < epsilon * m[2]) {
        inliers.emplace_back(i);
      }
    }

    return {inliers, m};
  }

  static int estimateRANSACIters(double probability, double outlierRatio, int numParams) {
    probability = clamp(probability, 0.0, 1.0);
    outlierRatio = clamp(outlierRatio, 0.0, 1.0);

    return static_cast<int>(std::log(1.0 - probability) / std::log(1.0 - std::pow(1.0 - outlierRatio, numParams)));
  }

};
}

#endif //GAUSSIAN_RANSAC_H_
