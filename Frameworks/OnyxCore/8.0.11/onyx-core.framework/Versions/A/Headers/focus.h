#ifndef FOCUS_H_
#define FOCUS_H_

#include <vector>
#include <opencv2/core/core.hpp>

#include "dft/Finger.h"

namespace dft {

double focusMeasureImpl(const cv::Mat& src, const std::vector<dft::Finger>& fingers);

double focusDepthFactorImpl(
  const std::vector<double>& focusMeasures,
  const std::vector<dft::Finger>& fingers,
  const cv::Size& imageSize,
  double calibratedFocusDist
);

double findScaleFactorImpl(const cv::Mat& from, const cv::Mat& to);

void polyfit(const cv::Mat& x, const cv::Mat& y, cv::Mat& dst, int order);
double evalfit(const cv::Mat_<double>& weights, const double& x);
std::pair<double, double> stdScaler(const cv::Mat_<double>& src);

std::pair<double, double> order3Roots(const cv::Mat_<double>& fit);

}

#endif
