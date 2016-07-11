/****
 *    BDPLocationDelegate.h
 *
 *    Copyright (C) 2015 Bluedot.  All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "BDGeospatialUnits.h"

@class BDZoneInfo;
@class BDFenceInfo;
@class BDBeaconInfo;

/**
  @brief Defines the call-backs which <b>Point SDK</b> makes to inform the Application of location-related events.

  <p>Assign your own implementation of this protocol to the @ref BDLocationManager#locationDelegate "locationDelegate" property of the
  shared @ref BDLocationManager instance, to handle location related callbacks.</p>

  <p>Callbacks inform the application when:
<ul>
<li>...new Zones have been received from <b>Point Access</b></li>
<li>...the user has triggered a <b>Custom Notification</b> action</li>
</ul>
</p>
*/
@protocol BDPLocationDelegate <NSObject>

@optional

/**
 * <p>Called whenever new @ref BDZoneInfo "zone info" is received from <b>Point Access</b>.</p>
 * <p>This occurs immediately after the <b>Point SDK</b> successfully authenticates, and repeats when the rule download
 * time interval is reached or significant distance has been travelled.</p>
 * <p>This is a value that you set when creating the Application in the Point Access web-interface, and determines how often the Zone data
 * will be refreshed on the device.<p>
 *
 * @param zoneInfos A collection of @ref BDZoneInfo objects, corresponding to the Zones you created for this application, in the
 * <b>Point Access</b> web-interface.
 */
- (void)didUpdateZoneInfo: (NSSet *)zoneInfos;

/**
 * <p>Implement this method to provide your own <b>Custom Action</b> when a Zone is triggered by entering a Fence.</p>
 *
 * <p>This method and @ref didCheckIntoBeacon:inZone:withProximity:onDate:willCheckOut: are both optional.<br/>
 * Implement them according to whether you have Custom Actions in your geo-location scenario, and whether those actions
 * may be triggered by entering Fences, Beacon proximities, or both.</p>
 *
 * <p><b>For clarity</b>: When a user's device checks into a @ref BDZoneInfo "Zone", this method is called only if
 * <b>Custom Action</b> is chosen as one of the @ref BDZoneInfo "Zone"'s Actions in the <b>Point Access</b> web-interface.</p>
 *
 * @param fence The fence that the user entered in order to trigger this custom action.
 * @param createZoneInfo The zone containing the entered fence.
 * @param coordinate The location of the device when the custom action was triggered.
 * @param date The date and time when the custom action was triggered.
 * @param willCheckOut Whether a subsequent Check Out callback is expected when the device moves a significant distance away from the Fence.
 */
- (void)didCheckIntoFence: (BDFenceInfo *)fence
                   inZone: (BDZoneInfo *)zoneInfo
             atCoordinate: (BDLocationCoordinate2D)coordinate
                   onDate: (NSDate *)date
             willCheckOut: (BOOL)willCheckOut;

/**
 * <p>This method has been deprecated as of version 1.6; it will be removed in a future version.</p>
 * @deprecated Use @ref didCheckIntoFence:inZone:atCoordinate:onDate:willCheckOut:
 */
- (void)didCheckIntoFence: (BDFenceInfo *)fence
                   inZone: (BDZoneInfo *)zoneInfo
             atCoordinate: (BDLocationCoordinate2D)coordinate
                   onDate: (NSDate *)date;

/**
 * <p>Implement this method to provide your own <b>Custom Action</b> when checking out of fence.</p>
 *
 * <p>This method and @ref didCheckOutFromBeacon:inZone:withProximity:onDate:withDuration: are both optional.<br/>
 * Implement them according to whether you have a fence that has been configured with Check Out set.
 *
 * @param fence The fence that the user checked out of in order to trigger this custom action.
 * @param createZoneInfo The zone containing the entered fence.
 * @param date The date and time when the custom action was triggered.
 * @param withDuration The dwell time minutes of the device within a fence.
 */
- (void)didCheckOutFromFence: (BDFenceInfo *)fence
                      inZone: (BDZoneInfo *)zoneInfo
                      onDate: (NSDate *)date
                withDuration: (NSUInteger)checkedInDuration;

/**
 * <p>This method has been deprecated as of version 1.6; it will be removed in a future version.</p>
 * @deprecated Use @ref didCheckIntoBeacon:inZone:withProximity:onDate:willCheckOut:
 */
- (void)didCheckIntoBeacon: (BDBeaconInfo *)beacon
                    inZone: (BDZoneInfo *)zoneInfo
             withProximity: (CLProximity)proximity
                    onDate: (NSDate *)date;

/**
 * <p>Implement this method to provide your own <b>Custom Action</b> when a Zone is triggered by entering the configured proximity of a Beacon.</p>
 * <p>This configuration can be made in the Management section of each Zone in the <b>Point Access</b> web-interface.</p>
 *
 * <p>This method and @ref didCheckIntoFence:inZone:atCoordinate:onDate:willCheckOut: are both optional.<br/>
 * Implement them according to whether you have Custom Actions in your geo-location scenario, and whether those actions
 * may be triggered by entering Fences, Beacon proximities or both.</p>
 *
 * <p><b>For clarity</b>: When a user's device checks into a @ref BDZoneInfo "Zone", this method is called only if
 * <b>Custom Action</b> is chosen as one of the @ref BDZoneInfo "Zone"'s Actions in the <b>Point Access</b> web-interface.</p>
 *
 * @param beacon The beacon that the user entered the required proximity of, in order to trigger this custom action.
 * @param createZoneInfo The zone containing the beacon in proximity.
 * @param proximity The proximity of the beacon when the custom action was triggered.
 * @param date The date and time when the custom action was triggered.
 * @param willCheckOut Whether a subsequent Check Out callback is expected when the device moves outside of the Beacon's range.
 */
- (void)didCheckIntoBeacon: (BDBeaconInfo *)beacon
                    inZone: (BDZoneInfo *)zoneInfo
             withProximity: (CLProximity)proximity
                    onDate: (NSDate *)date
              willCheckOut: (BOOL)willCheckOut;

/**
 * <p>Implement this method to provide your own <b>Custom Action</b> when checking out of beacon.</p>
 *
 * <p>This method and @ref didCheckOutFromFence:inZone:onDate:withDuration: are both optional.<br/>
 * Implement them according to whether you have a beacon that has been configured with Check Out set.
 *
 * @param beacon The beacon that the user checked out of in order to trigger this custom action.
 * @param createZoneInfo The zone containing the entered fence.
 * @param proximity The proximity of the beacon when the check-in was triggered.
 * @param date The date and time when the custom action was triggered.
 * @param withDuration The dwell time minutes of the device within the range of a beacon.
 */
- (void)didCheckOutFromBeacon: (BDBeaconInfo *)beacon
                       inZone: (BDZoneInfo *)zoneInfo
                withProximity: (CLProximity)proximity
                       onDate: (NSDate *)date
                 withDuration: (NSUInteger)checkedInDuration;

/**
 * <p>These methods can be implemented to monitor whether the Bluetooth
 * capabilities of the device are in a valid state when utilising the SDK's beacon functionality.</p>
 *
 * <p>If the configured location of a beacon is near the device and Bluetooth has not been enabled, then didStartRequiringUserInterventionForBluetooth will be called.</p>
 * <p>Thereafter, if the device leaves proximity of the beacon, then didStopRequiringUserInterventionForBluetooth is called.</p>
 * <p>If Bluetooth is both required and enabled, then these callbacks will not be invoked.</p>
 */
- (void)didStartRequiringUserInterventionForBluetooth;

/**
 * <p>Please refer to @ref didStartRequiringUserInterventionForBluetooth.</p>
 */
- (void)didStopRequiringUserInterventionForBluetooth;

/**
 * <p>These methods can be implemented to monitor whether iOS Location Services are in a valid state while the SDK is authenticated with Point Access.</p>
 *
 * <p>If Point SDK is authenticated with Point Access and Location Services have not been enabled, then didStartRequiringUserInterventionForLocationServices will be called.</p>
 * <p>Thereafter, if the Point SDK logs out from the authenticated state, then didStopRequiringUserInterventionForLocationServices is called.</p>
 * <p>If Location Services are both required and enabled, then these callbacks will not be invoked.</p>
 */
- (void)didStartRequiringUserInterventionForLocationServices;

/**
 * <p>Please refer to @ref didStartRequiringUserInterventionForLocationServices.</p>
 */
- (void)didStopRequiringUserInterventionForLocationServices;

/**
 * <p>These methods can be implemented to monitor whether the iOS 'Low Power Mode' has been enabled while the SDK is authenticated with Point Access.</p>
 * <p>The callback is required because Low Power mode negatively impacts the timeliness and precision of Point SDK, which your Application may need to communicate to the user.</p>
 *
 * <p>If Point SDK is authenticated with Point Access and iOS has been switched to 'Low Power mode', then didStartRequiringUserInterventionForPowerMode will be called.</p>
 * <p>Thereafter, if the user switches off 'Low Power mode', then didStopRequiringUserInterventionForPowerMode is called.</p>
 */
- (void)didStartRequiringUserInterventionForPowerMode;

/**
 * <p>Please refer to @ref didStartRequiringUserInterventionForPowerMode.</p>
 */
- (void)didStopRequiringUserInterventionForPowerMode;

@end
