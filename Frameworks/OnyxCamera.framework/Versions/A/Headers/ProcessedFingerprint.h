//
//  ProcessedFingerprint.h
//  OnyxDemo
//
//  Created by Devan Buggay on 6/12/14.
//  Copyright (c) 2014 Devan Buggay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/*!
 @class ProcessedFingerprint
 @abstract Object returned from OnyxViewController that holds all data on fingerprint.
 */
@interface ProcessedFingerprint : NSObject
/*!
 * @brief The source image.
 */
@property UIImage *sourceImage;
/*!
 * @brief The cropped raw image.
 */
@property UIImage *rawImage;
/*!
 * @brief The processed image.
 */
@property UIImage *processedImage;
/*!
 * @brief The enhanced image.
 */
@property UIImage *enhancedImage;
/*!
 * @brief The slap image
 */
 @property UIImage *slapImage;
/*!
 * @brief The fingerprint template, to be used with Onyx matchers.
 */
@property NSData *fingerprintTemplate;
/*!
 * @brief The WSQ data for processed fingerprint.
 */
@property NSData *WSQ;
/*!
 * @brief The nfiqscore of the fingerprint.
 */
@property int nfiqscore;
/*!
 * @brief The finger number.
 */
@property NSInteger finger;
/*!
 * @brief image size for all returned images.
 */
@property CGSize size;

@end
