/****
 *    BDPSpatialObject.h
 *
 *    Copyright (C) 2015 Bluedot Innovation.  All rights reserved.
 */

@class BDGeometry;

/**
  @brief Objects having an inherent @ref BDGeometry "geometry".
*/
@protocol BDPSpatialObject <NSObject>

/**
  @returns The geometry inherent to this object.
 */
- (BDGeometry *)geometry;

@end

