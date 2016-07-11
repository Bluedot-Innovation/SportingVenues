//
// Created by Christopher Hatton on 08/01/15.
// Copyright (c) 2015 BlueDot. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDAuthenticationState.h"

/**
@brief Describes an object which can provide an authentication state.  Currently @ref BDLocationManager(BDPointSDK).
*/
@protocol BDPAuthenticationStateProvider <NSObject>

/**
* This property must have a KVO-compliant implementation.
*/
@property (readonly) BDAuthenticationState authenticationState;

@end
