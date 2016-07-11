/****
 *    BDPValidatable.h
 *
 *    Copyright (C) 2015 Bluedot Innovation.  All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
  @brief Any object whose state can be validated for correctness.

  Typically this will be implemented only by data-model classes.
  @copyright Bluedot Innovation
*/
@protocol BDPValidatable <NSObject>

/**
 * @returns YES if the state of this object is valid, NO otherwise.
 */
- (BOOL)valid;

@end
