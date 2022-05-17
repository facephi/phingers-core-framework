//
//  OnyxConfiguration.h
//  OnyxCamera
//
//  Created by Matthew Wheatley on 2/3/18.
//  Copyright © 2018 Diamond Fortress. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OnyxEnums.h"
#import "OnyxResult.h"
#import "OnyxError.h"

@class Onyx;

@interface OnyxConfiguration : NSObject {

}

/**
 * This method sets the Onyx license key.
 */
@property NSString *licenseKey;

/**
 * This sets the OnyxSuccess event handler.
 * successCallback (required) the event handler for the SuccessCallback.
 */
@property void (^successCallback)(OnyxResult *onyxResult);

/**
 * This sets the ErrorCallback event handler.
 * errorCallback (required) the event handler for the ErrorCallback.
 */
@property void (^errorCallback)(OnyxError *onyxError);

/**
 * This sets the OnyxCallback event handler.
 * The callback returns the Onyx object used to start Onyx.
 */
@property void (^onyxCallback)(Onyx *onyx);

/**
 * This property sets whether or not to return the raw fingerprint image in the OnyxResult.
 */
@property bool returnRawImage;

/**
 * This property sets whether or not to return the processed fingerprint image in the OnyxResult.
 */
@property bool returnProcessedImage;

/**
 * This property sets whether or not to return the enhanced fingerprint image in the OnyxResult.
 */
@property bool returnEnhancedImage;

/**
 * This method sets whether or not to return a slap image. This contains all fingers captured
 * within a single image as specified in the FBI EBTS
 */
@property bool returnSlapImage;

/**
 * This method sets whether to return a FullFrame image.  This returns
 * an image that is suitable for finger detection in a full frame.
 */
@property bool returnFullFrameImage;

/**
 * This method sets the maximum height for the FullFrame image to be returned, so for example,
 * if you want a 1920 height image returned, pass in 1920.0f for the value.  It will a full frame
 * image resized to 1920 for the maximum height.  To get the original height of the full frame, to
 * get full resolution, pass in a value of 1.0f.
 */
@property float fullFrameMaxImageHeight;

/**
 * This method binarizes the processed image to black and white pixels (necessary for some matchers)
 */
@property bool returnBinarizedProcessedImage;

/**
 * This method sets whether or not the capture task will return the specified FingerprintTemplateType in the OnyxResult
 * The ISO template is the ISO/IEC 19794-4 standard minutiae based template
 * The INNOVATRICS template is a proprietary fingerprint template that is highly scale tolerant and
 * useful for touchless matching
 */
@property enum FingerprintTemplateType returnFingerprintTemplate;

/**
 * This property sets whether or not to return the WSQ image in the OnyxResult.
 */
@property bool returnWsq;

/**
 * This method sets the crop size for the capture image.
 */
@property CGSize cropSize;

/**
 * This method sets the crop factor for the capture image.
 */
@property float cropFactor;

/**
 * This methods sets that the Onyx spinner should be shown.
 */
@property bool showLoadingSpinner;

/**
 * This method sets the method of capture to be a manual capture of the fingerprint
 */
@property bool useManualCapture;

/**
 * Instructions to display for manual capture (localization)
 */
@property NSString *manualCaptureText;

/**
 * This method sets whether to use Onyx Live as part of the configuration
 */
@property bool useOnyxLive;

/**
 * This method sets whether to use the useFlash
 */
@property bool useFlash;

/**
 * This method sets the orientation of the reticle {@link Reticle.Orientation}
 */
@property ReticleOrientation reticleOrientation;

/**
 * Specify to compute NFIQ metrics
 */
@property bool computeNfiqMetrics;

/**
 * Specify target pixels per inch
 */
@property double targetPixelsPerInch;

/**
 * Specify the unique subject id
 */
@property NSString *subjectId;

/**
 * For future use.  Not currently implemented.  Specify whether to upload capture metrics result.
 * This will be used to improve ONYX capture and quality performance in the future.
 */
@property bool uploadMetrics;

/**
 * Specify to return OnyxError on low quality imagery
 */
@property bool returnOnyxErrorOnLowQuality;

/**
 * Specify a value between 0.0 - 1.0 to set the threshold for QualityNet to capture.
 * Higher values mean higher image quality.
 */
@property float captureQualityThreshold;

@end
