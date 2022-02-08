//
//  CaptureMetrics.h
//  OnyxCamera
//
//  Created by Matthew Wheatley on 5/6/18.
//  Copyright © 2018 Diamond Fortress. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NfiqMetrics.h"

@interface CaptureMetrics : NSObject
@property float livenessConfidence;
@property NSMutableArray* nfiqMetrics;
@property float qualityMetric;
@property double actualScale;
@property int outputPixelsPerInch;

- (float) getLivenessConfidence;
- (float) getQualityMetric;
- (NSMutableArray *) getNfiqMetrics;

@end
