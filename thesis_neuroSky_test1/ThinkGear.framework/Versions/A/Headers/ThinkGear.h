//
//  ThinkGearObjC.h
//  MindView
//
//  Created by Masamine Someha on 2/27/12.
//  Copyright (c) 2012 NeuroSky Inc. All rights reserved.
//

#import "ThinkGearDelegate.h"
//#import "TGHrv.h"

#import <Foundation/Foundation.h>

typedef enum {
    TGRawData = 0x01,
    TGAnalyzedData = 0x02
} RecordFlag;

@interface ThinkGearObjC : NSObject <NSStreamDelegate>{
    BOOL connected;
    BOOL rawEnabled;
    BOOL isRecording;
    BOOL readyToSend;
    
    id<ThinkGearDelegate> delegate;
    NSTimeInterval dispatchInterval;
    
    NSMutableDictionary * data;
    
    NSThread * notificationThread;
    uint8_t buffer[1024];
    NSInputStream * inputStream;
    NSOutputStream * outputStream;
    
    uint8_t * payloadBuffer;
    int payloadBytesRemaining;
    
    int rawPackets;
    NSMutableArray *rawBuffer;
    
    NSString *portName;
    
    uint8_t recordFlag;
    NSString * logFilePath;
    NSString * logRow;
    NSFileHandle * logFileHandle;
}

#pragma mark Properties
@property (nonatomic, readonly) BOOL connected;
@property (nonatomic, readonly) BOOL isRecording;
@property (nonatomic, readonly) BOOL readyToSend;
@property (nonatomic, assign) id<ThinkGearDelegate> delegate;
@property (nonatomic, assign) NSTimeInterval dispatchInterval;
@property BOOL rawEnabled;

- (int)getVersion;
- (void)ConnectTo:(NSString *)portNameString;
- (void)Disconnect;
- (void)startRecording:(NSString *)applicationSupportFolder withFlag:(uint8_t)flag;
- (void)stopRecording:(NSString *)savePath;
- (void)sendBytes:(uint8_t *)bytes length:(int)length;

@end
