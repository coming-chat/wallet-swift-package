// Objective-C API for talking to github.com/coming-chat/wallet-SDK/core/base Go package.
//   gobind -lang=objc github.com/coming-chat/wallet-SDK/core/base
//
// File is generated by gobind. Do not edit.

#ifndef __Base_H__
#define __Base_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"


@class BaseBalance;
@class BaseOptionalBool;
@class BaseOptionalString;
@class BaseReachMonitor;
@class BaseRpcLatency;
@class BaseTokenInfo;
@class BaseTransaction;
@class BaseTransactionDetail;
@protocol BaseAccount;
@class BaseAccount;
@protocol BaseAddressUtil;
@class BaseAddressUtil;
@protocol BaseChain;
@class BaseChain;
@protocol BaseReachMonitorDelegate;
@class BaseReachMonitorDelegate;
@protocol BaseRpcReachability;
@class BaseRpcReachability;
@protocol BaseToken;
@class BaseToken;

@protocol BaseAccount <NSObject>
/**
 * @return address string
 */
- (NSString* _Nonnull)address;
/**
 * @return privateKey data
 */
- (NSData* _Nullable)privateKey:(NSError* _Nullable* _Nullable)error;
/**
 * @return privateKey string that will start with 0x.
 */
- (NSString* _Nonnull)privateKeyHex:(NSError* _Nullable* _Nullable)error;
/**
 * @return publicKey data
 */
- (NSData* _Nullable)publicKey;
/**
 * @return publicKey string that will start with 0x.
 */
- (NSString* _Nonnull)publicKeyHex;
- (NSData* _Nullable)sign:(NSData* _Nullable)message password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)signHex:(NSString* _Nullable)messageHex password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
@end

@protocol BaseAddressUtil <NSObject>
/**
 * @return publicKey that will start with 0x.
 */
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
/**
 * @param publicKey can start with 0x or not.
 */
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BOOL)isValidAddress:(NSString* _Nullable)address;
@end

@protocol BaseChain <NSObject>
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
/**
 * Batch fetch the transaction status, the hash list and the return value,
which can only be passed as strings separated by ","
@param hashListString The hash of the transactions to be queried in batches, a string concatenated with ",": "hash1,hash2,hash3"
@return Batch transaction status, its order is consistent with hashListString: "status1,status2,status3"
 */
- (NSString* _Nonnull)batchFetchTransactionStatus:(NSString* _Nullable)hashListString;
/**
 * Fetch transaction details through transaction hash
 */
- (BaseTransactionDetail* _Nullable)fetchTransactionDetail:(NSString* _Nullable)hash error:(NSError* _Nullable* _Nullable)error;
/**
 * Fetch transaction status through transaction hash
 */
- (long)fetchTransactionStatus:(NSString* _Nullable)hash;
- (id<BaseToken> _Nullable)mainToken;
/**
 * Send the raw transaction on-chain
@return the hex hash string
 */
- (NSString* _Nonnull)sendRawTransaction:(NSString* _Nullable)signedTx error:(NSError* _Nullable* _Nullable)error;
@end

@protocol BaseReachMonitorDelegate <NSObject>
/**
 * A node request failed
 */
- (void)reachabilityDidFailNode:(BaseReachMonitor* _Nullable)tester latency:(BaseRpcLatency* _Nullable)latency;
/**
 * The entire network connection test task is over
@param overview Overview of the results of all connection tests
 */
- (void)reachabilityDidFinish:(BaseReachMonitor* _Nullable)tester overview:(NSString* _Nullable)overview;
/**
 * A node has received a response
 */
- (void)reachabilityDidReceiveNode:(BaseReachMonitor* _Nullable)tester latency:(BaseRpcLatency* _Nullable)latency;
@end

@protocol BaseRpcReachability <NSObject>
- (BaseRpcLatency* _Nullable)latencyOf:(NSString* _Nullable)rpc timeout:(int64_t)timeout error:(NSError* _Nullable* _Nullable)error;
@end

@protocol BaseToken <NSObject>
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (id<BaseChain> _Nullable)chain;
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

@interface BaseBalance : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull total;
@property (nonatomic) NSString* _Nonnull usable;
@end

/**
 * Optional bool for easy of writing iOS code
 */
@interface BaseOptionalBool : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) BOOL value;
@end

/**
 * Optional string for easy of writing iOS code
 */
@interface BaseOptionalString : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull value;
@end

@interface BaseReachMonitor : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithReachability:(id<BaseRpcReachability> _Nullable)reachability;
/**
 * The number of network connectivity tests to be performed per rpc. 0 means infinite, default is 1
 */
@property (nonatomic) long reachCount;
/**
 * Timeout for each connectivity test (ms). default 20000ms
 */
@property (nonatomic) int64_t timeout;
/**
 * Time interval between two network connectivity tests (ms). default 1500ms
 */
@property (nonatomic) int64_t delay;
/**
 * @param rpcList string of rpcs like "rpc1,rpc2,rpc3,..."
 */
- (void)startConnectivityDelegate:(NSString* _Nullable)rpcList delegate:(id<BaseReachMonitorDelegate> _Nullable)delegate;
/**
 * @param rpcList string of rpcs like "rpc1,rpc2,rpc3,..."
@return jsonString sorted array base of tatency like "[{rpcUrl:rpc1,latency:100}, {rpcUrl:rpc2, latency:111}, ...]" latency unit is ms. -1 means the connection failed
 */
- (NSString* _Nonnull)startConnectivitySync:(NSString* _Nullable)rpcList;
- (void)stopConnectivity;
@end

@interface BaseRpcLatency : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull rpcUrl;
@property (nonatomic) int64_t latency;
@property (nonatomic) int64_t height;
@end

@interface BaseTokenInfo : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull name;
@property (nonatomic) NSString* _Nonnull symbol;
@property (nonatomic) int16_t decimal;
@end

@interface BaseTransaction : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@end

/**
 * Transaction details that can be fetched from the chain
 */
@interface BaseTransactionDetail : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * hash string on chain
 */
@property (nonatomic) NSString* _Nonnull hashString;
/**
 * transaction amount
 */
@property (nonatomic) NSString* _Nonnull amount;
@property (nonatomic) NSString* _Nonnull estimateFees;
/**
 * sender's address
 */
@property (nonatomic) NSString* _Nonnull fromAddress;
/**
 * receiver's address
 */
@property (nonatomic) NSString* _Nonnull toAddress;
@property (nonatomic) long status;
/**
 * transaction completion timestamp (s), 0 if Status is in Pending
 */
@property (nonatomic) int64_t finishTimestamp;
/**
 * failure message
 */
@property (nonatomic) NSString* _Nonnull failureMessage;
@end

FOUNDATION_EXPORT const long BaseTransactionStatusFailure;
FOUNDATION_EXPORT const long BaseTransactionStatusNone;
FOUNDATION_EXPORT const long BaseTransactionStatusPending;
FOUNDATION_EXPORT const long BaseTransactionStatusSuccess;

@interface Base : NSObject
+ (NSError* _Nullable) errUnsupportedFunction;
+ (void) setErrUnsupportedFunction:(NSError* _Nullable)v;

@end

// skipped function CatchPanicAndMapToBasicError with unsupported parameter or return types


FOUNDATION_EXPORT BaseBalance* _Nullable BaseEmptyBalance(void);

// skipped function MapAnyToBasicError with unsupported parameter or return types


// skipped function MapListConcurrent with unsupported parameter or return types


// skipped function MapListConcurrentStringToString with unsupported parameter or return types


// skipped function Max with unsupported parameter or return types


// skipped function MaxBigInt with unsupported parameter or return types


// skipped function Min with unsupported parameter or return types


FOUNDATION_EXPORT BaseReachMonitor* _Nullable BaseNewReachMonitorWithReachability(id<BaseRpcReachability> _Nullable reachability);

@class BaseAccount;

@class BaseAddressUtil;

@class BaseChain;

@class BaseReachMonitorDelegate;

@class BaseRpcReachability;

@class BaseToken;

@interface BaseAccount : NSObject <goSeqRefInterface, BaseAccount> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * @return address string
 */
- (NSString* _Nonnull)address;
/**
 * @return privateKey data
 */
- (NSData* _Nullable)privateKey:(NSError* _Nullable* _Nullable)error;
/**
 * @return privateKey string that will start with 0x.
 */
- (NSString* _Nonnull)privateKeyHex:(NSError* _Nullable* _Nullable)error;
/**
 * @return publicKey data
 */
- (NSData* _Nullable)publicKey;
/**
 * @return publicKey string that will start with 0x.
 */
- (NSString* _Nonnull)publicKeyHex;
- (NSData* _Nullable)sign:(NSData* _Nullable)message password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)signHex:(NSString* _Nullable)messageHex password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
@end

@interface BaseAddressUtil : NSObject <goSeqRefInterface, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * @return publicKey that will start with 0x.
 */
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
/**
 * @param publicKey can start with 0x or not.
 */
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BOOL)isValidAddress:(NSString* _Nullable)address;
@end

@interface BaseChain : NSObject <goSeqRefInterface, BaseChain> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
/**
 * Batch fetch the transaction status, the hash list and the return value,
which can only be passed as strings separated by ","
@param hashListString The hash of the transactions to be queried in batches, a string concatenated with ",": "hash1,hash2,hash3"
@return Batch transaction status, its order is consistent with hashListString: "status1,status2,status3"
 */
- (NSString* _Nonnull)batchFetchTransactionStatus:(NSString* _Nullable)hashListString;
/**
 * Fetch transaction details through transaction hash
 */
- (BaseTransactionDetail* _Nullable)fetchTransactionDetail:(NSString* _Nullable)hash error:(NSError* _Nullable* _Nullable)error;
/**
 * Fetch transaction status through transaction hash
 */
- (long)fetchTransactionStatus:(NSString* _Nullable)hash;
- (id<BaseToken> _Nullable)mainToken;
/**
 * Send the raw transaction on-chain
@return the hex hash string
 */
- (NSString* _Nonnull)sendRawTransaction:(NSString* _Nullable)signedTx error:(NSError* _Nullable* _Nullable)error;
@end

@interface BaseReachMonitorDelegate : NSObject <goSeqRefInterface, BaseReachMonitorDelegate> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * A node request failed
 */
- (void)reachabilityDidFailNode:(BaseReachMonitor* _Nullable)tester latency:(BaseRpcLatency* _Nullable)latency;
/**
 * The entire network connection test task is over
@param overview Overview of the results of all connection tests
 */
- (void)reachabilityDidFinish:(BaseReachMonitor* _Nullable)tester overview:(NSString* _Nullable)overview;
/**
 * A node has received a response
 */
- (void)reachabilityDidReceiveNode:(BaseReachMonitor* _Nullable)tester latency:(BaseRpcLatency* _Nullable)latency;
@end

@interface BaseRpcReachability : NSObject <goSeqRefInterface, BaseRpcReachability> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (BaseRpcLatency* _Nullable)latencyOf:(NSString* _Nullable)rpc timeout:(int64_t)timeout error:(NSError* _Nullable* _Nullable)error;
@end

@interface BaseToken : NSObject <goSeqRefInterface, BaseToken> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (id<BaseChain> _Nullable)chain;
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

#endif
