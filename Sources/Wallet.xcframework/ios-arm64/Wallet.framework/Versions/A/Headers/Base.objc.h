// Objective-C API for talking to github.com/coming-chat/wallet-SDK/core/base Go package.
//   gobind -lang=objc github.com/coming-chat/wallet-SDK/core/base
//
// File is generated by gobind. Do not edit.

#ifndef __Base_H__
#define __Base_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"


@class BaseAny;
@class BaseAnyArray;
@class BaseAnyMap;
@class BaseBalance;
@class BaseBigInt;
@class BaseBigInts;
@class BaseNFT;
@class BaseOptionalBool;
@class BaseOptionalString;
@class BaseReachMonitor;
@class BaseRpcLatency;
@class BaseStringArray;
@class BaseTokenInfo;
@class BaseTransactionDetail;
@protocol BaseAccount;
@class BaseAccount;
@protocol BaseAddressUtil;
@class BaseAddressUtil;
@protocol BaseAniable;
@class BaseAniable;
@protocol BaseChain;
@class BaseChain;
@protocol BaseJsonable;
@class BaseJsonable;
@protocol BaseNFTFetcher;
@class BaseNFTFetcher;
@protocol BasePageable;
@class BasePageable;
@protocol BaseReachMonitorDelegate;
@class BaseReachMonitorDelegate;
@protocol BaseRpcReachability;
@class BaseRpcReachability;
@protocol BaseSignedTransaction;
@class BaseSignedTransaction;
@protocol BaseToken;
@class BaseToken;
@protocol BaseTransaction;
@class BaseTransaction;

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

@protocol BaseAniable <NSObject>
- (BaseAny* _Nullable)asAny;
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
 * Most chains can estimate the fee directly to the transaction object
**But two chains don't work: `aptos`, `starcoin`**
 */
- (BaseOptionalString* _Nullable)estimateTransactionFee:(id<BaseTransaction> _Nullable)transaction error:(NSError* _Nullable* _Nullable)error;
/**
 * All chains can call this method to estimate the gas fee.
**Chain  `aptos`, `starcoin` must pass in publickey**
 */
- (BaseOptionalString* _Nullable)estimateTransactionFeeUsePublicKey:(id<BaseTransaction> _Nullable)transaction pubkey:(NSString* _Nullable)pubkey error:(NSError* _Nullable* _Nullable)error;
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
/**
 * Send the signed transaction on-chain
@return the hex hash string
 */
- (BaseOptionalString* _Nullable)sendSignedTransaction:(id<BaseSignedTransaction> _Nullable)signedTxn error:(NSError* _Nullable* _Nullable)error;
@end

@protocol BaseJsonable <NSObject>
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@protocol BaseNFTFetcher <NSObject>
// skipped method NFTFetcher.FetchNFTs with unsupported parameter or return types

/**
 * * Gets all NFT JSON Strings for the specified account
	 * @owner The specified account address
	 * @return This method directly calls `FetchNFTs()` and jsonifies the result and returns
 */
- (BaseOptionalString* _Nullable)fetchNFTsJsonString:(NSString* _Nullable)owner error:(NSError* _Nullable* _Nullable)error;
@end

@protocol BasePageable <NSObject>
/**
 * The count of data in the current page.
 */
- (long)currentCount;
/**
 * The cursor of the current page.
 */
- (NSString* _Nonnull)currentCursor;
/**
 * Is there has next page.
 */
- (BOOL)hasNextPage;
- (BaseAnyArray* _Nullable)itemArray;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
/**
 * The total count of all data in the remote server. Returns 0 if statistics are not available
 */
- (long)totalCount;
@end

@protocol BaseReachMonitorDelegate <NSObject>
/**
 * A node request failed
 */
- (void)reachabilityDidFailNode:(BaseReachMonitor* _Nullable)monitor latency:(BaseRpcLatency* _Nullable)latency;
/**
 * The entire network connection test task is over
@param overview Overview of the results of all connection tests
 */
- (void)reachabilityDidFinish:(BaseReachMonitor* _Nullable)monitor overview:(NSString* _Nullable)overview;
/**
 * A node has received a response
 */
- (void)reachabilityDidReceiveNode:(BaseReachMonitor* _Nullable)monitor latency:(BaseRpcLatency* _Nullable)latency;
@end

@protocol BaseRpcReachability <NSObject>
- (BaseRpcLatency* _Nullable)latencyOf:(NSString* _Nullable)rpc timeout:(int64_t)timeout error:(NSError* _Nullable* _Nullable)error;
@end

@protocol BaseSignedTransaction <NSObject>
@end

@protocol BaseToken <NSObject>
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (id<BaseTransaction> _Nullable)buildTransfer:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (id<BaseTransaction> _Nullable)buildTransferAll:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver error:(NSError* _Nullable* _Nullable)error;
/**
 * Before invoking this method, it is best to check `CanTransferAll()`
 */
- (BOOL)canTransferAll;
- (id<BaseChain> _Nullable)chain;
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

@protocol BaseTransaction <NSObject>
- (BaseOptionalString* _Nullable)signWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (id<BaseSignedTransaction> _Nullable)signedTransactionWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
@end

/**
 * 如果需要自定义类型支持 Any, 需要遵循协议 Aniable
 */
@interface BaseAny : NSObject <goSeqRefInterface, BaseJsonable, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
// skipped field Any.Value with unsupported type: any

- (BaseBigInt* _Nullable)getBigInt;
- (BOOL)getBool;
- (long)getInt;
- (int16_t)getInt16;
- (int32_t)getInt32;
- (int64_t)getInt64;
- (int8_t)getInt8;
- (NSString* _Nonnull)getString;
- (BaseBigInt* _Nullable)getUInt16;
- (BaseBigInt* _Nullable)getUInt32;
- (BaseBigInt* _Nullable)getUInt64;
- (BaseBigInt* _Nullable)getUInt8;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
/**
 * `Any` only support Marshal
 */
- (NSData* _Nullable)marshalJSON:(NSError* _Nullable* _Nullable)error;
- (void)setBigInt:(BaseBigInt* _Nullable)v;
- (void)setBool:(BOOL)v;
- (void)setInt:(long)v;
- (void)setInt16:(int16_t)v;
- (void)setInt32:(int32_t)v;
- (void)setInt64:(int64_t)v;
- (void)setInt8:(int8_t)v;
- (void)setString:(NSString* _Nullable)v;
- (void)setUInt16:(BaseBigInt* _Nullable)v;
- (void)setUInt32:(BaseBigInt* _Nullable)v;
- (void)setUInt64:(BaseBigInt* _Nullable)v;
- (void)setUInt8:(BaseBigInt* _Nullable)v;
@end

@interface BaseAnyArray : NSObject <goSeqRefInterface, BaseAniable, BaseJsonable, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
// skipped field AnyArray.Values with unsupported type: []any

- (void)append:(BaseAny* _Nullable)any;
- (BaseAny* _Nullable)asAny;
- (BOOL)contains:(BaseAny* _Nullable)any;
- (long)count;
/**
 * return -1 if not found
 */
- (long)indexOf:(BaseAny* _Nullable)any;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
/**
 * `AnyArray` only support Marshal
 */
- (NSData* _Nullable)marshalJSON:(NSError* _Nullable* _Nullable)error;
- (void)remove:(long)index;
- (void)setValue:(BaseAny* _Nullable)value index:(long)index;
- (NSString* _Nonnull)string;
- (BaseAny* _Nullable)valueOf:(long)index;
@end

@interface BaseAnyMap : NSObject <goSeqRefInterface, BaseAniable, BaseJsonable, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
// skipped field AnyMap.Values with unsupported type: map[string]any

- (BaseAny* _Nullable)asAny;
- (BOOL)hasKey:(NSString* _Nullable)key;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
- (BaseStringArray* _Nullable)keys;
/**
 * `AnyMap` only support Marshal
 */
- (NSData* _Nullable)marshalJSON:(NSError* _Nullable* _Nullable)error;
- (BaseAny* _Nullable)remove:(NSString* _Nullable)key;
- (void)setValue:(BaseAny* _Nullable)value key:(NSString* _Nullable)key;
- (NSString* _Nonnull)string;
- (BaseAny* _Nullable)valueOf:(NSString* _Nullable)key;
@end

@interface BaseBalance : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull total;
@property (nonatomic) NSString* _Nonnull usable;
@end

/**
 * A BigInt represents a signed multi-precision integer.
 */
@interface BaseBigInt : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * NewBigInt allocates and returns a new BigInt set to x.
 */
- (nullable instancetype)init:(int64_t)x;
/**
 * NewBigIntFromString allocates and returns a new BigInt set to x
interpreted in the provided base.
 */
- (nullable instancetype)initFromString:(NSString* _Nullable)x base:(long)base;
/**
 * GetBytes returns the absolute value of x as a big-endian byte slice.
 */
- (NSData* _Nullable)getBytes;
/**
 * GetInt64 returns the int64 representation of x. If x cannot be represented in
an int64, the result is undefined.
 */
- (int64_t)getInt64;
/**
 * GetString returns the value of x as a formatted string in some number base.
 */
- (NSString* _Nonnull)getString:(long)base;
/**
 * SetBytes interprets buf as the bytes of a big-endian unsigned integer and sets
the big int to that value.
 */
- (void)setBytes:(NSData* _Nullable)buf;
/**
 * SetInt64 sets the big int to x.
 */
- (void)setInt64:(int64_t)x;
/**
 * SetString sets the big int to x.

The string prefix determines the actual conversion base. A prefix of "0x" or
"0X" selects base 16; the "0" prefix selects base 8, and a "0b" or "0B" prefix
selects base 2. Otherwise the selected base is 10.
 */
- (void)setString:(NSString* _Nullable)x base:(long)base;
/**
 * Sign returns:

	-1 if x <  0
	 0 if x == 0
	+1 if x >  0
 */
- (long)sign;
/**
 * String returns the value of x as a formatted decimal string.
 */
- (NSString* _Nonnull)string;
@end

/**
 * BigInts represents a slice of big ints.
 */
@interface BaseBigInts : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * NewBigInts creates a slice of uninitialized big numbers.
 */
- (nullable instancetype)init:(long)size;
/**
 * Get returns the bigint at the given index from the slice.
 */
- (BaseBigInt* _Nullable)get:(long)index error:(NSError* _Nullable* _Nullable)error;
/**
 * Set sets the big int at the given index in the slice.
 */
- (BOOL)set:(long)index bigint:(BaseBigInt* _Nullable)bigint error:(NSError* _Nullable* _Nullable)error;
/**
 * Size returns the number of big ints in the slice.
 */
- (long)size;
@end

@interface BaseNFT : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) int64_t timestamp;
@property (nonatomic) NSString* _Nonnull hashString;
@property (nonatomic) NSString* _Nonnull id_;
@property (nonatomic) NSString* _Nonnull name;
@property (nonatomic) NSString* _Nonnull image;
@property (nonatomic) NSString* _Nonnull standard;
@property (nonatomic) NSString* _Nonnull collection;
@property (nonatomic) NSString* _Nonnull descr;
@property (nonatomic) NSString* _Nonnull contractAddress;
@property (nonatomic) NSString* _Nonnull relatedUrl;
/**
 * Aptos token's largest_property_version
 */
@property (nonatomic) int64_t aptTokenVersion;
/**
 * Aptos token's amount
 */
@property (nonatomic) int64_t aptAmount;
- (NSString* _Nonnull)extractedImageUrl;
- (NSString* _Nonnull)groupName;
@end

/**
 * Optional bool for easy of writing iOS code
 */
@interface BaseOptionalBool : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) BOOL value;
@end

/**
 * Optional string for easy of writing iOS code
 */
@interface BaseOptionalString : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull value;
@end

@interface BaseReachMonitor : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * You need to pass in different objects to get the latency and block height of different chains.
let reachability = eth.RpcReachability()
let reachability = polka.RpcReachability()
let reachability = sui.RestReachability()
...
let monitor = NewReachMonitorWithReachability(reachability)
 */
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

@interface BaseRpcLatency : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull rpcUrl;
@property (nonatomic) int64_t latency;
@property (nonatomic) int64_t height;
@end

@interface BaseStringArray : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field StringArray.Values with unsupported type: []string

- (void)append:(NSString* _Nullable)value;
- (BOOL)contains:(NSString* _Nullable)value;
- (long)count;
/**
 * return -1 if not found
 */
- (long)indexOf:(NSString* _Nullable)value;
- (void)remove:(long)index;
- (void)setValue:(NSString* _Nullable)value index:(long)index;
- (NSString* _Nonnull)string;
- (NSString* _Nonnull)valueOf:(long)index;
@end

@interface BaseTokenInfo : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull name;
@property (nonatomic) NSString* _Nonnull symbol;
@property (nonatomic) int16_t decimal;
@end

/**
 * Transaction details that can be fetched from the chain
 */
@interface BaseTransactionDetail : NSObject <goSeqRefInterface, BaseSignedTransaction> {
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
/**
 * If this transaction is a CID transfer, its value will be the CID, otherwise it is empty
 */
@property (nonatomic) NSString* _Nonnull cidNumber;
/**
 * If this transaction is a NFT transfer, its value will be the Token name, otherwise it is empty
 */
@property (nonatomic) NSString* _Nonnull tokenName;
/**
 * Check the `CIDNumber` is not empty.
 */
- (BOOL)isCIDTransfer;
/**
 * Check the `TokenName` is not empty.
 */
- (BOOL)isNFTTransfer;
- (NSString* _Nonnull)jsonString;
@end

FOUNDATION_EXPORT const long BaseTransactionStatusFailure;
FOUNDATION_EXPORT const long BaseTransactionStatusNone;
FOUNDATION_EXPORT const long BaseTransactionStatusPending;
FOUNDATION_EXPORT const long BaseTransactionStatusSuccess;

@interface Base : NSObject
+ (NSError* _Nullable) errEstimateGasNeedPublicKey;
+ (void) setErrEstimateGasNeedPublicKey:(NSError* _Nullable)v;

+ (NSError* _Nullable) errInvalidAccountAddress;
+ (void) setErrInvalidAccountAddress:(NSError* _Nullable)v;

+ (NSError* _Nullable) errInvalidAccountType;
+ (void) setErrInvalidAccountType:(NSError* _Nullable)v;

+ (NSError* _Nullable) errInvalidAddress;
+ (void) setErrInvalidAddress:(NSError* _Nullable)v;

+ (NSError* _Nullable) errInvalidAmount;
+ (void) setErrInvalidAmount:(NSError* _Nullable)v;

+ (NSError* _Nullable) errInvalidChainType;
+ (void) setErrInvalidChainType:(NSError* _Nullable)v;

+ (NSError* _Nullable) errInvalidPrivateKey;
+ (void) setErrInvalidPrivateKey:(NSError* _Nullable)v;

+ (NSError* _Nullable) errInvalidPublicKey;
+ (void) setErrInvalidPublicKey:(NSError* _Nullable)v;

+ (NSError* _Nullable) errInvalidTransactionType;
+ (void) setErrInvalidTransactionType:(NSError* _Nullable)v;

+ (NSError* _Nullable) errMissingTransaction;
+ (void) setErrMissingTransaction:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNotCoinTransferTxn;
+ (void) setErrNotCoinTransferTxn:(NSError* _Nullable)v;

+ (NSError* _Nullable) errUnsupportedFunction;
+ (void) setErrUnsupportedFunction:(NSError* _Nullable)v;

@end

FOUNDATION_EXPORT BaseAnyArray* _Nullable BaseAsAnyArray(BaseAny* _Nullable a);

FOUNDATION_EXPORT BaseAnyMap* _Nullable BaseAsAnyMap(BaseAny* _Nullable a);

// skipped function CatchPanicAndMapToBasicError with unsupported parameter or return types


FOUNDATION_EXPORT BaseBalance* _Nullable BaseEmptyBalance(void);

/**
 * ExtractNFTImageUrl
Extract the nft's real image url.
If the content type of the given url is JSON, it's will return the `image` field specified url.
 */
FOUNDATION_EXPORT BaseOptionalString* _Nullable BaseExtractNFTImageUrl(NSString* _Nullable url, NSError* _Nullable* _Nullable error);

// skipped function FromJsonString with unsupported parameter or return types


// skipped function JsonString with unsupported parameter or return types


// skipped function MapAnyToBasicError with unsupported parameter or return types


// skipped function MapListConcurrent with unsupported parameter or return types


// skipped function MapListConcurrentStringToString with unsupported parameter or return types


// skipped function Max with unsupported parameter or return types


// skipped function MaxBigInt with unsupported parameter or return types


// skipped function Min with unsupported parameter or return types


FOUNDATION_EXPORT BaseAny* _Nullable BaseNewAny(void);

FOUNDATION_EXPORT BaseAnyArray* _Nullable BaseNewAnyArray(void);

FOUNDATION_EXPORT BaseAnyMap* _Nullable BaseNewAnyMap(void);

/**
 * NewBigInt allocates and returns a new BigInt set to x.
 */
FOUNDATION_EXPORT BaseBigInt* _Nullable BaseNewBigInt(int64_t x);

/**
 * NewBigIntFromString allocates and returns a new BigInt set to x
interpreted in the provided base.
 */
FOUNDATION_EXPORT BaseBigInt* _Nullable BaseNewBigIntFromString(NSString* _Nullable x, long base);

/**
 * NewBigInts creates a slice of uninitialized big numbers.
 */
FOUNDATION_EXPORT BaseBigInts* _Nullable BaseNewBigInts(long size);

/**
 * You need to pass in different objects to get the latency and block height of different chains.
let reachability = eth.RpcReachability()
let reachability = polka.RpcReachability()
let reachability = sui.RestReachability()
...
let monitor = NewReachMonitorWithReachability(reachability)
 */
FOUNDATION_EXPORT BaseReachMonitor* _Nullable BaseNewReachMonitorWithReachability(id<BaseRpcReachability> _Nullable reachability);

// skipped function ParseNumber with unsupported parameter or return types


/**
 * ParseNumberToDecimal
@param num any format number, such as decimal "1237890123", hex "0x123ef0", "123ef0"
@return decimal number, characters include 0-9
 */
FOUNDATION_EXPORT NSString* _Nonnull BaseParseNumberToDecimal(NSString* _Nullable num);

/**
 * ParseNumberToHex
@param num any format number, such as decimal "1237890123", hex "0x123ef0", "123ef0"
@return hex number start with 0x, characters include 0-9 a-f
 */
FOUNDATION_EXPORT NSString* _Nonnull BaseParseNumberToHex(NSString* _Nullable num);

@class BaseAccount;

@class BaseAddressUtil;

@class BaseAniable;

@class BaseChain;

@class BaseJsonable;

@class BaseNFTFetcher;

@class BasePageable;

@class BaseReachMonitorDelegate;

@class BaseRpcReachability;

@class BaseSignedTransaction;

@class BaseToken;

@class BaseTransaction;

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

/**
 * exchange `Aniable Object` & `Any`
 */
@interface BaseAniable : NSObject <goSeqRefInterface, BaseAniable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (BaseAny* _Nullable)asAny;
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
 * Most chains can estimate the fee directly to the transaction object
**But two chains don't work: `aptos`, `starcoin`**
 */
- (BaseOptionalString* _Nullable)estimateTransactionFee:(id<BaseTransaction> _Nullable)transaction error:(NSError* _Nullable* _Nullable)error;
/**
 * All chains can call this method to estimate the gas fee.
**Chain  `aptos`, `starcoin` must pass in publickey**
 */
- (BaseOptionalString* _Nullable)estimateTransactionFeeUsePublicKey:(id<BaseTransaction> _Nullable)transaction pubkey:(NSString* _Nullable)pubkey error:(NSError* _Nullable* _Nullable)error;
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
/**
 * Send the signed transaction on-chain
@return the hex hash string
 */
- (BaseOptionalString* _Nullable)sendSignedTransaction:(id<BaseSignedTransaction> _Nullable)signedTxn error:(NSError* _Nullable* _Nullable)error;
@end

@interface BaseJsonable : NSObject <goSeqRefInterface, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface BaseNFTFetcher : NSObject <goSeqRefInterface, BaseNFTFetcher> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
// skipped method NFTFetcher.FetchNFTs with unsupported parameter or return types

/**
 * * Gets all NFT JSON Strings for the specified account
	 * @owner The specified account address
	 * @return This method directly calls `FetchNFTs()` and jsonifies the result and returns
 */
- (BaseOptionalString* _Nullable)fetchNFTsJsonString:(NSString* _Nullable)owner error:(NSError* _Nullable* _Nullable)error;
@end

@interface BasePageable : NSObject <goSeqRefInterface, BasePageable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * The count of data in the current page.
 */
- (long)currentCount;
/**
 * The cursor of the current page.
 */
- (NSString* _Nonnull)currentCursor;
/**
 * Is there has next page.
 */
- (BOOL)hasNextPage;
- (BaseAnyArray* _Nullable)itemArray;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
/**
 * The total count of all data in the remote server. Returns 0 if statistics are not available
 */
- (long)totalCount;
@end

@interface BaseReachMonitorDelegate : NSObject <goSeqRefInterface, BaseReachMonitorDelegate> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * A node request failed
 */
- (void)reachabilityDidFailNode:(BaseReachMonitor* _Nullable)monitor latency:(BaseRpcLatency* _Nullable)latency;
/**
 * The entire network connection test task is over
@param overview Overview of the results of all connection tests
 */
- (void)reachabilityDidFinish:(BaseReachMonitor* _Nullable)monitor overview:(NSString* _Nullable)overview;
/**
 * A node has received a response
 */
- (void)reachabilityDidReceiveNode:(BaseReachMonitor* _Nullable)monitor latency:(BaseRpcLatency* _Nullable)latency;
@end

/**
 * You can customize the test latency method of rpc
 */
@interface BaseRpcReachability : NSObject <goSeqRefInterface, BaseRpcReachability> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (BaseRpcLatency* _Nullable)latencyOf:(NSString* _Nullable)rpc timeout:(int64_t)timeout error:(NSError* _Nullable* _Nullable)error;
@end

@interface BaseSignedTransaction : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
@end

@interface BaseToken : NSObject <goSeqRefInterface, BaseToken> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (id<BaseTransaction> _Nullable)buildTransfer:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (id<BaseTransaction> _Nullable)buildTransferAll:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver error:(NSError* _Nullable* _Nullable)error;
/**
 * Before invoking this method, it is best to check `CanTransferAll()`
 */
- (BOOL)canTransferAll;
- (id<BaseChain> _Nullable)chain;
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

@interface BaseTransaction : NSObject <goSeqRefInterface, BaseTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (BaseOptionalString* _Nullable)signWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (id<BaseSignedTransaction> _Nullable)signedTransactionWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
@end

#endif
