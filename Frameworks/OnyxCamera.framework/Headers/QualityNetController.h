//
//  QualityNetController.h
//  OnyxCamera
//
//  Created by Christopher Wheatley on 5/30/21.
//  Copyright © 2021 Diamond Fortress. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TFLTensorFlowLite.h"

NS_ASSUME_NONNULL_BEGIN

@interface QualityNetController : NSObject

/*!
 * @brief Holds the batchSize used for QualityNet TensorLite model
 */
@property NSNumber* batchSize;

/*!
 * @brief Holds the imageWidth of images used for QualityNet TensorLite model
 */
@property NSNumber* imageWidth;

/*!
 * @brief Holds the imageHeight of images used for QualityNet TensorLite model
 */
@property NSNumber* imageHeight;

/*!
 * @brief Holds the imageDepth of images used for QualityNet TensorLite model
 */
@property NSNumber* imageDepth;

- (instancetype)init;

- (NSDictionary<NSString *, id> *)runInference:(NSData *)imageData error:(NSError**) error;

- (double)convertNSDataToDouble:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
