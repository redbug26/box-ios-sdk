//
//  BOXFileDownloadRequest.h
//  BoxContentSDK
//

#import "BOXRequestWithSharedLinkHeader.h"
#import "BOXAPIOperation.h"

@interface BOXFileDownloadRequest : BOXRequestWithSharedLinkHeader

// This is not the etag of a particular version of the file, nor the sequential version number,
// it is the ID of the version representation gotten from /files/<fileID>/versions
@property (nonatomic, readwrite, strong) NSString *versionID;

/**
 * request will download file into destinationPath, and the file download can continue
 * running in the background even if app is not running
 */
- (instancetype)initWithLocalDestination:(NSString *)destinationPath
                                  fileID:(NSString *)fileID;

/**
 * Similar to the above init method, request will download file into destinationPath,
 * and the file download can continue running in the background even if app is not running
 * If downloadTask is provided, it will be used to execute/reconnect with the existing download task
 * downloadTaskReplacedBlock is to notify when the downloadTask used by the request has been changed,
 * useful to reconnecting to ongoing download task upon app restart
 */
- (instancetype)initWithLocalDestination:(NSString *)destinationPath
                                  fileID:(NSString *)fileID
                             associateId:(NSString *)associateId;

/**
 * request will download file into outputStream, and the file download cannot continue
 * if the app is not running
 */
- (instancetype)initWithOutputStream:(NSOutputStream *)outputStream
                              fileID:(NSString *)fileID;

- (void)performRequestWithProgress:(BOXProgressBlock)progressBlock completion:(BOXErrorBlock)completionBlock;

/**
 * Call this to cancel background download with intention to resume from where it left off in a later request
 */
- (void)cancelWithIntentionToResume;

@end
