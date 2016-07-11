/****
 *    NSString+BDURLEncoding.h
 *
 *    Implements a wrapper around URL encoding.
 *
 *    Copyright (C) 2015 Bluedot Innovation.  All rights reserved.
 */

#import <Foundation/Foundation.h>


@interface NSString (BDURLEncoding)

//  Methods for encoding and decoding a URL
- (NSString *)urlEncodeUsingEncoding: (NSStringEncoding)encoding;
- (NSString *)urlDecode;

@end