//
//  FileUploader.h
//
//  Copyright (C) 2014 IRCCloud, Ltd.
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#import <Foundation/Foundation.h>

@protocol FileUploaderDelegate<NSObject>
-(void)fileUploadProgress:(float)progress;
-(void)fileUploadDidFail;
-(void)fileUploadDidFinish;
-(void)fileUploadWasCancelled;
@end

@protocol FileUploaderMetadataDelegate<NSObject>
-(void)fileUploadWillUpload:(NSUInteger)bytes mimeType:(NSString *)mimeType;
@end

@interface FileUploader : NSObject<NSURLConnectionDelegate,NSURLConnectionDataDelegate,NSURLSessionDataDelegate,NSURLSessionDownloadDelegate> {
    NSURLConnection *_connection;
    NSMutableData *_response;
    NSObject<FileUploaderDelegate> *_delegate;
    NSObject<FileUploaderMetadataDelegate> *_metadatadelegate;
    int _bid;
    int _reqid;
    BOOL _filenameSet;
    BOOL _finished;
    NSString *_id;
    NSString *_msg;
    NSMutableData *_body;
    NSString *_originalFilename;
    NSString *_filename;
    NSString *_mimeType;
    NSString *_backgroundID;
}
@property NSObject<FileUploaderDelegate> *delegate;
@property NSObject<FileUploaderMetadataDelegate> *metadatadelegate;
@property int bid;
@property (readonly) NSString *originalFilename;
-(void)uploadFile:(NSURL *)file;
-(void)uploadImage:(UIImage *)image;
-(void)setFilename:(NSString *)filename message:(NSString *)message;
-(void)cancel;
@end
