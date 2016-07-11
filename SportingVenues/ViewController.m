//
//  Created by Bluedot Innovation
//  Copyright (c) 2016 Bluedot Innovation. All rights reserved.
//
//  Implementation of the Root ViewController to Authenticate & Logout Bluedot Point SDK
//

#import "ViewController.h"
#import <BDPointSDK.h>

@interface ViewController ()<BDPSessionDelegate, BDPLocationDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)btnAuthenticate:(id)sender {
    NSLog(@"Authenticating with Bluedot Point SDK");
    BDLocationManager  *locationManager = [ BDLocationManager instance ];
    
    // For demo purpase only, recommend to set the `locationDelegate` and `sessionDelegate` in your AppDelegate
    locationManager.locationDelegate = self;
    locationManager.sessionDelegate  = self;
    [self authenticateWithBluedotSDK];
}

- (IBAction)btnLogout:(id)sender {
    BDLocationManager  *locationManager = [ BDLocationManager instance ];
    [locationManager logOut];
}



-(void)authenticateWithBluedotSDK
{
    NSString  *apiKey      = @"PUT YOUR API KEY HERE";          // Api key which can be retrieved from Point Access Web Interface
    NSString  *packageName = @"PUT YOUR PACKAGE NAME HERE";     // Package name which can be retrieved from Point Access Web Interface
    NSString  *username    = @"PUT YOUR USERNAME HERE";         // Username which you used to login Point Access Web Interface
    
    BDLocationManager  *locationManager = BDLocationManager.instance;
    
    [ locationManager authenticateWithApiKey: apiKey packageName: packageName username: username ];
}

#pragma mark - BDPSessionDelegate

- (void)didUpdateZoneInfo: (NSSet *)zoneInfos
{
    
    NSLog(@"Bluedot SDK downloaded %lu rules", (unsigned long) zoneInfos.count);

}

- (void)didEndSession
{
    NSLog( @"Logged out" );
}

- (void)didEndSessionWithError:(NSError *)error
{
    NSLog( @"Logged out failed with error: %@", error.localizedDescription );
}

- (void)authenticationWasSuccessful
{
       NSLog(@"Authenticated successfully ");
}


- (void)authenticationFailedWithError: (NSError *)error
{
    NSLog( @"Authentication failed, with error: %@", error.localizedDescription );
}

- (void)willAuthenticateWithUsername: (NSString *)username
                              apiKey: (NSString *)apiKey
                         packageName: (NSString *)packageName
{
     NSLog(@"Authenticating with Bluedot SDK");
    
}

- (void)authenticationWasDeniedWithReason: (NSString *)reason
{
    NSLog( @"Authentication denied with reason: %@", reason );
}

@end
