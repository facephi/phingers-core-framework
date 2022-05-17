//
//  OnyxConfigurationBuilder.h
//  OnyxCamera
//
//  Created by Matthew Wheatley on 2/3/18.
//  Copyright © 2018 Diamond Fortress. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OnyxConfiguration.h"
#import "Onyx.h"

@interface OnyxConfigurationBuilder : NSObject {

}

@property OnyxConfiguration *onyxConfig;

/**
 * This sets the Onyx license key (required)
 */
- (OnyxConfigurationBuilder *(^)(NSString *))licenseKey;

/**
 * This sets the OnyxSuccess event handler.
 */
- (OnyxConfigurationBuilder *(^)(void(^)(OnyxResult *)))successCallback;

/**
 * This sets the ErrorCallback event handler.
 */
- (OnyxConfigurationBuilder *(^)(void(^)(OnyxError *)))errorCallback;

/**
 * This sets the OnyxCallback event handler.
 * The callback returns the Onyx object used to start Onyx.
 */
- (OnyxConfigurationBuilder *(^)(void(^)(Onyx *)))onyxCallback;

/**
 * Specify whether or not to return imagery for the raw fingerprint image.
 * Returned  in the OnyxResult.
 */
- (OnyxConfigurationBuilder *(^)(bool))returnRawImage;

/**
 * Specify whether or not to return imagery for the processed fingerprint image.
 * Returned in the OnyxResult.
 */
- (OnyxConfigurationBuilder *(^)(bool))returnProcessedImage;

/**
 * Specify whether or not to return imagery for the enhanced fingerprint image.
 * Returned  in the OnyxResult.
 */
- (OnyxConfigurationBuilder *(^)(bool))returnEnhancedImage;

/**
 * Specify whether or not to return a slap image. This contains all fingers captured
 * within a single image as specified in the FBI EBTS format.
 * Returned in the OnyxResult.
 */
- (OnyxConfigurationBuilder *(^)(bool))returnSlapImage;

/**
 * Specify whether or not to return the binarized processed fingerprint image in the OnyxResult
 */
- (OnyxConfigurationBuilder *(^)(bool))shouldBinarizeProcessedImage;

/**
 * Specify whether to return a FullFrame image.  This returns
 * an image that is suitable for finger detection in a full frame.
 */
- (OnyxConfigurationBuilder *(^)(bool))returnFullFrameImage;

/**
 * Specify the maximum height for the FullFrame image to be returned, so for example,
 * if you want a 1920 height image returned, pass in 1080.0f for the value.  It will a full frame
 * image resized to 1920 for the maximum height.  To get the original height of the full frame, to
 * get full resolution, pass in a value of 1.0f.
 */
- (OnyxConfigurationBuilder *(^)(float))fullFrameMaxImageHeight;

/**
 * Specify whether or not the capture task will return the specified FingerprintTemplateType in the OnyxResult
 * The ISO template is the ISO/IEC 19794-4 standard minutiae based template
 * The INNOVATRICS template is a proprietary fingerprint template that is highly scale tolerant and
 * useful for touchless matching
 */
- (OnyxConfigurationBuilder *(^)(FingerprintTemplateType))returnFingerprintTemplate;

/**
 * Specify whether or not to return the WSQ image in the OnyxResult.
 */
- (OnyxConfigurationBuilder *(^)(bool))returnWSQ;

/**
 * Specify the crop size for the capture image.  This will determine the image dimensions
 * in length and width for the resulting images.  This should be set to whatever is required
 * for the matching algorithm that is going to be used.
 */
- (OnyxConfigurationBuilder *(^)(CGSize))cropSize;

/**
 * Specify the crop factor for the capture image.  This has a built in scaling factor and
 * this crop factor should be adjusted until you get an image that looks close to images that are
 * known to match against whatever biometric system you are attempting to match against.
 */
- (OnyxConfigurationBuilder *(^)(float))cropFactor;

/**
 * Specify that the spinner should be shown during OnyxConfiguration and during
 * image processing.
 */
- (OnyxConfigurationBuilder *(^)(bool))showLoadingSpinner;

/**
 * Specify whether or not to use the manual capture instead of the auto-capture.
 * Manual capture is where the operator will tap the screen in order to capture.
 */
- (OnyxConfigurationBuilder *(^)(bool))useManualCapture;

/**
 * Specify the text to display for manual capture (localization)
 */
- (OnyxConfigurationBuilder *(^)(NSString *))manualCaptureText;

/**
 * Specify whether or not to use Onyx LIVE liveness detection
 */
- (OnyxConfigurationBuilder *(^)(bool))useOnyxLive;

/**
 * Specify to use the flash
 */
- (OnyxConfigurationBuilder *(^)(bool))useFlash;

/**
 * Specify the {@link com.dft.onyxcamera.ui.reticles.Reticle.Orientation}
 */
- (OnyxConfigurationBuilder *(^)(ReticleOrientation))reticleOrientation;

/**
 * Specify Onyx to compute NFIQ metrics
 */
- (OnyxConfigurationBuilder *(^)(bool))computeNfiqMetrics;

/**
 * Specify target pixels per inch
 */
- (OnyxConfigurationBuilder *(^)(double))targetPixelsPerInch;

/**
 * Specify the subject id
 */
- (OnyxConfigurationBuilder *(^)(NSString *))subjectId;

/**
 * For future use.  Not currently implemented.  Specify whether to upload capture metrics result.
 * This will be used to improve ONYX capture and quality performance in the future.
 */
- (OnyxConfigurationBuilder *(^)(bool))uploadMetrics;

/**
 * Specify to return OnyxError on low quality imagery
 */
- (OnyxConfigurationBuilder *(^)(bool))returnOnyxErrorOnLowQuality;

/**
 * Specify the captureQualityThreshold.
 * Specify a double value between 0.0 - 1.0 to set the threshold for QualityNet to capture.
 * Higher values mean higher image quality.
 */
- (OnyxConfigurationBuilder *(^)(float))captureQualityThreshold;

/**
 * This method builds the OnyxConfiguration object with the specified parameters, and
 * checks that all configuration setup is complete before returning the Onyx object
 */
- (void)buildOnyxConfiguration;

@end
