// Objective-C API for talking to github.com/coming-chat/wallet-SDK/core/btc Go package.
//   gobind -lang=objc github.com/coming-chat/wallet-SDK/core/btc
//
// File is generated by gobind. Do not edit.

#ifndef __Btc_H__
#define __Btc_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

#include "Base.objc.h"

@class BtcAccount;
@class BtcChain;
@class BtcFeeRate;
@class BtcUtil;

@interface BtcAccount : NSObject <goSeqRefInterface, BaseAccount, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithMnemonic:(NSString* _Nullable)mnemonic chainnet:(NSString* _Nullable)chainnet;
@property (nonatomic) NSString* _Nonnull chainnet;
/**
 * @return default is the mainnet address
 */
- (NSString* _Nonnull)address;
/**
 * @return publicKey that will start with 0x.
 */
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BtcAccount* _Nullable)deriveAccountAt:(NSString* _Nullable)chainnet error:(NSError* _Nullable* _Nullable)error;
/**
 * @param publicKey can start with 0x or not.
 */
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BOOL)isValidAddress:(NSString* _Nullable)address;
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
/**
 * TODO: function not implement yet.
 */
- (NSData* _Nullable)sign:(NSData* _Nullable)message password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
/**
 * TODO: function not implement yet.
 */
- (BaseOptionalString* _Nullable)signHex:(NSString* _Nullable)messageHex password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcChain : NSObject <goSeqRefInterface, BaseAddressUtil, BaseChain, BaseToken> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithChainnet:(NSString* _Nullable)chainnet;
@property (nonatomic) BtcUtil* _Nullable util;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)batchFetchTransactionStatus:(NSString* _Nullable)hashListString;
- (id<BaseChain> _Nullable)chain;
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)encodePublicDataToAddress:(NSData* _Nullable)public error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
/**
 * Fetch transaction details through transaction hash
Note: The input parsing of bitcoin is very complex and the network cost is relatively high,
So only the status and timestamp can be queried.
 */
- (BaseTransactionDetail* _Nullable)fetchTransactionDetail:(NSString* _Nullable)hash error:(NSError* _Nullable* _Nullable)error;
- (long)fetchTransactionStatus:(NSString* _Nullable)hash;
- (BOOL)isValidAddress:(NSString* _Nullable)address;
- (id<BaseToken> _Nullable)mainToken;
/**
 * Send the raw transaction on-chain
@return the hex hash string
 */
- (NSString* _Nonnull)sendRawTransaction:(NSString* _Nullable)signedTx error:(NSError* _Nullable* _Nullable)error;
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcFeeRate : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) int64_t low;
@property (nonatomic) int64_t average;
@property (nonatomic) int64_t high;
@end

@interface BtcUtil : NSObject <goSeqRefInterface, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithChainnet:(NSString* _Nullable)chainnet;
@property (nonatomic) NSString* _Nonnull chainnet;
/**
 * Warning: Btc cannot support decode address to public key
 */
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)encodePublicDataToAddress:(NSData* _Nullable)public error:(NSError* _Nullable* _Nullable)error;
/**
 * @param publicKey can start with 0x or not.
 */
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BOOL)isValidAddress:(NSString* _Nullable)address;
@end

/**
 * ComingChat used, similar mainnet's alias.
 */
FOUNDATION_EXPORT NSString* _Nonnull const BtcChainBitcoin;
FOUNDATION_EXPORT NSString* _Nonnull const BtcChainMainnet;
FOUNDATION_EXPORT NSString* _Nonnull const BtcChainSignet;

@interface Btc : NSObject
+ (NSError* _Nullable) errDecodeAddress;
+ (void) setErrDecodeAddress:(NSError* _Nullable)v;

+ (NSError* _Nullable) errHttpResponseParse;
+ (void) setErrHttpResponseParse:(NSError* _Nullable)v;

+ (NSError* _Nullable) errUnsupportedChain;
+ (void) setErrUnsupportedChain:(NSError* _Nullable)v;

@end

FOUNDATION_EXPORT BtcAccount* _Nullable BtcAccountWithPrivateKey(NSString* _Nullable prikey, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSString* _Nonnull BtcEncodePublicDataToAddress(NSData* _Nullable public, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

/**
 * @param publicKey can start with 0x or not.
 */
FOUNDATION_EXPORT NSString* _Nonnull BtcEncodePublicKeyToAddress(NSString* _Nullable publicKey, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

/**
 * Deprecated: FetchTransactionDetail is deprecated. Please Use Chain.FetchTransactionDetail() instead.
 */
FOUNDATION_EXPORT BaseTransactionDetail* _Nullable BtcFetchTransactionDetail(NSString* _Nullable hashString, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

/**
 * Deprecated: FetchTransactionStatus is deprecated. Please Use Chain.FetchTransactionStatus() instead.
 */
FOUNDATION_EXPORT long BtcFetchTransactionStatus(NSString* _Nullable hashString, NSString* _Nullable chainnet);

/**
 * @param chainnet chain name
 */
FOUNDATION_EXPORT BOOL BtcIsValidAddress(NSString* _Nullable address, NSString* _Nullable chainnet);

FOUNDATION_EXPORT BtcAccount* _Nullable BtcNewAccountWithMnemonic(NSString* _Nullable mnemonic, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcChain* _Nullable BtcNewChainWithChainnet(NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcUtil* _Nullable BtcNewUtilWithChainnet(NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

/**
 * Deprecated: QueryBalance is deprecated. Please Use Chain.QueryBalanceWithAddress() instead.
 */
FOUNDATION_EXPORT NSString* _Nonnull BtcQueryBalance(NSString* _Nullable address, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

/**
 * Deprecated: QueryBalancePubkey is deprecated. Please Use Chain.QueryBalanceWithPublicKey() instead.
 */
FOUNDATION_EXPORT NSString* _Nonnull BtcQueryBalancePubkey(NSString* _Nullable pubkey, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

/**
 * Deprecated: SdkBatchTransactionStatus is deprecated. Please Use Chain.BatchFetchTransactionStatus() instead.
 */
FOUNDATION_EXPORT NSString* _Nonnull BtcSdkBatchTransactionStatus(NSString* _Nullable hashListString, NSString* _Nullable chainnet);

/**
 * Deprecated: SendRawTransaction is deprecated. Please Use Chain.SendRawTransaction() instead.
 */
FOUNDATION_EXPORT NSString* _Nonnull BtcSendRawTransaction(NSString* _Nullable signedTx, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcFeeRate* _Nullable BtcSuggestFeeRate(NSError* _Nullable* _Nullable error);

#endif
