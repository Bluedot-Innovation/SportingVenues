/****
*    BDPointSessionException.h
*
*    Copyright (C) 2015 Bluedot.  All rights reserved.
*/

#import <Foundation/Foundation.h>

/**
  @brief Thrown when the <b>Point SDK</b> session life-cycle or authentication state has been violated.
  @copyright Bluedot Innovation
*/
@interface BDPointSessionException : NSException

+ (NSException *)exceptionWithReason:(NSString*)reason;

@end
