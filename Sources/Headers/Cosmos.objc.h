// Objective-C API for talking to github.com/coming-chat/wallet-SDK/core/cosmos Go package.
//   gobind -lang=objc github.com/coming-chat/wallet-SDK/core/cosmos
//
// File is generated by gobind. Do not edit.

#ifndef __Cosmos_H__
#define __Cosmos_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

#include "Base.objc.h"

@class CosmosAccount;
@class CosmosAccountInfo;
@class CosmosChain;
@class CosmosGradedGasPrice;
@class CosmosKnownTokenInfo;
@class CosmosRpcReachability;
@class CosmosToken;
@class CosmosUtil;

@interface CosmosAccount : NSObject <goSeqRefInterface, BaseAccount> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithMnemonic:(NSString* _Nullable)mnemonic cointype:(int64_t)cointype addressPrefix:(NSString* _Nullable)addressPrefix;
@property (nonatomic) int64_t cointype;
@property (nonatomic) NSString* _Nonnull addressPrefix;
/**
 * The ethereum address is same as public key in coming
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
 * Is deocde from address
@return publicKey data
 */
- (NSData* _Nullable)publicKey;
/**
 * The ethereum public key is same as address in coming
@return publicKey string that will start with 0x.
 */
- (NSString* _Nonnull)publicKeyHex;
/**
 * TODO: Need Test.
 */
- (NSData* _Nullable)sign:(NSData* _Nullable)message password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
/**
 * TODO: Need Test.
 */
- (BaseOptionalString* _Nullable)signHex:(NSString* _Nullable)messageHex password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
@end

@interface CosmosAccountInfo : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull accountNumber;
@property (nonatomic) NSString* _Nonnull sequence;
/**
 * Is aslias of Sequence
 */
- (NSString* _Nonnull)nonce;
@end

@interface CosmosChain : NSObject <goSeqRefInterface, BaseChain> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithRpc:(NSString* _Nullable)rpcUrl restUrl:(NSString* _Nullable)restUrl;
@property (nonatomic) NSString* _Nonnull rpcUrl;
@property (nonatomic) NSString* _Nonnull restUrl;
- (CosmosAccountInfo* _Nullable)accountOf:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddressAndDenom:(NSString* _Nullable)address denom:(NSString* _Nullable)denom error:(NSError* _Nullable* _Nullable)error;
/**
 * Warning: Unable to use public key to query balance
 */
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
/**
 * Batch fetch the transaction status, the hash list and the return value,
which can only be passed as strings separated by ","
@param hashListString The hash of the transactions to be queried in batches, a string concatenated with ",": "hash1,hash2,hash3"
@return Batch transaction status, its order is consistent with hashListString: "status1,status2,status3"
 */
- (NSString* _Nonnull)batchFetchTransactionStatus:(NSString* _Nullable)hashListString;
- (CosmosToken* _Nullable)denomToken:(NSString* _Nullable)prefix denom:(NSString* _Nullable)denom;
/**
 * Fetch transaction details through transaction hash
 */
- (BaseTransactionDetail* _Nullable)fetchTransactionDetail:(NSString* _Nullable)hash error:(NSError* _Nullable* _Nullable)error;
/**
 * Fetch transaction status through transaction hash
 */
- (long)fetchTransactionStatus:(NSString* _Nullable)hash;
// skipped method Chain.GetClient with unsupported parameter or return types

/**
 * Warning Cosmos not supported main token
 */
- (id<BaseToken> _Nullable)mainToken;
/**
 * Send the raw transaction on-chain
@return the hex hash string
 */
- (NSString* _Nonnull)sendRawTransaction:(NSString* _Nullable)signedTx error:(NSError* _Nullable* _Nullable)error;
@end

@interface CosmosGradedGasPrice : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull low;
@property (nonatomic) NSString* _Nonnull average;
@property (nonatomic) NSString* _Nonnull high;
@end

@interface CosmosKnownTokenInfo : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) int64_t cointype;
@property (nonatomic) NSString* _Nonnull prefix;
@property (nonatomic) NSString* _Nonnull denom;
@property (nonatomic) CosmosGradedGasPrice* _Nullable gasPrice;
@property (nonatomic) NSString* _Nonnull gasLimit;
@end

@interface CosmosRpcReachability : NSObject <goSeqRefInterface, BaseRpcReachability> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
/**
 * @return latency (ms) of rpc query blockNumber. -1 means the connection failed.
 */
- (BaseRpcLatency* _Nullable)latencyOf:(NSString* _Nullable)rpc timeout:(int64_t)timeout error:(NSError* _Nullable* _Nullable)error;
@end

@interface CosmosToken : NSObject <goSeqRefInterface, BaseToken> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(CosmosChain* _Nullable)chain prefix:(NSString* _Nullable)prefix denom:(NSString* _Nullable)denom;
@property (nonatomic) NSString* _Nonnull prefix;
@property (nonatomic) NSString* _Nonnull denom;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
/**
 * Warning: Unable to use public key to query balance
 */
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)buildTransferTx:(NSString* _Nullable)privateKey receiverAddress:(NSString* _Nullable)receiverAddress gasPrice:(NSString* _Nullable)gasPrice gasLimit:(NSString* _Nullable)gasLimit amount:(NSString* _Nullable)amount memo:(NSString* _Nullable)memo error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)buildTransferTxWithAccount:(CosmosAccount* _Nullable)account receiverAddress:(NSString* _Nullable)receiverAddress gasPrice:(NSString* _Nullable)gasPrice gasLimit:(NSString* _Nullable)gasLimit amount:(NSString* _Nullable)amount memo:(NSString* _Nullable)memo error:(NSError* _Nullable* _Nullable)error;
- (id<BaseChain> _Nullable)chain;
/**
 * Warning: Main token does not support
 */
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

@interface CosmosUtil : NSObject <goSeqRefInterface, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithPrefix:(NSString* _Nullable)addressPrefix;
@property (nonatomic) NSString* _Nonnull addressPrefix;
/**
 * @throw decode address to public key is not supported
 */
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
/**
 * @param publicKey can start with 0x or not.
 */
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BOOL)isValidAddress:(NSString* _Nullable)address;
@end

/**
 * uatom
 */
FOUNDATION_EXPORT NSString* _Nonnull const CosmosCosmosAtomDenom;
/**
 * 118
 */
FOUNDATION_EXPORT const int64_t CosmosCosmosCointype;
/**
 * cosmos
 */
FOUNDATION_EXPORT NSString* _Nonnull const CosmosCosmosPrefix;
/**
 * 100000
 */
FOUNDATION_EXPORT NSString* _Nonnull const CosmosGasLimitDefault;
/**
 * 0.025
 */
FOUNDATION_EXPORT NSString* _Nonnull const CosmosGasPriceAverage;
/**
 * 0.04
 */
FOUNDATION_EXPORT NSString* _Nonnull const CosmosGasPriceHigh;
/**
 * 0.01
 */
FOUNDATION_EXPORT NSString* _Nonnull const CosmosGasPriceLow;
/**
 * 330
 */
FOUNDATION_EXPORT const int64_t CosmosTerraCointype;
/**
 * 80000
 */
FOUNDATION_EXPORT NSString* _Nonnull const CosmosTerraGasLimitDefault;
/**
 * 10
 */
FOUNDATION_EXPORT NSString* _Nonnull const CosmosTerraGasPrice;
/**
 * 0.25
 */
FOUNDATION_EXPORT NSString* _Nonnull const CosmosTerraGasPriceUST;
/**
 * uluna
 */
FOUNDATION_EXPORT NSString* _Nonnull const CosmosTerraLunaDenom;
/**
 * terra
 */
FOUNDATION_EXPORT NSString* _Nonnull const CosmosTerraPrefix;
/**
 * uusd
 */
FOUNDATION_EXPORT NSString* _Nonnull const CosmosTerraUSTDenom;

@interface Cosmos : NSObject
+ (CosmosKnownTokenInfo* _Nullable) cosmosAtom;
+ (void) setCosmosAtom:(CosmosKnownTokenInfo* _Nullable)v;

+ (CosmosKnownTokenInfo* _Nullable) terraLunc;
+ (void) setTerraLunc:(CosmosKnownTokenInfo* _Nullable)v;

+ (CosmosKnownTokenInfo* _Nullable) terraUst;
+ (void) setTerraUst:(CosmosKnownTokenInfo* _Nullable)v;

@end

// skipped function AccAddressFromBech32 with unsupported parameter or return types


FOUNDATION_EXPORT CosmosAccount* _Nullable CosmosAccountWithPrivateKey(NSString* _Nullable privatekey, int64_t cointype, NSString* _Nullable addressPrefix, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT CosmosAccount* _Nullable CosmosAsCosmosAccount(id<BaseAccount> _Nullable account);

FOUNDATION_EXPORT NSString* _Nonnull CosmosBech32FromAccAddress(NSData* _Nullable address, NSString* _Nullable addressPrefix, NSError* _Nullable* _Nullable error);

/**
 * @param publicKey can start with 0x or not.
 */
FOUNDATION_EXPORT NSString* _Nonnull CosmosEncodePublicKeyToAddress(NSString* _Nullable publicKey, NSString* _Nullable addressPrefix, NSError* _Nullable* _Nullable error);

/**
 * @param chainnet chain name
 */
FOUNDATION_EXPORT BOOL CosmosIsValidAddress(NSString* _Nullable address, NSString* _Nullable addressPrefix);

FOUNDATION_EXPORT CosmosAccount* _Nullable CosmosNewAccountWithMnemonic(NSString* _Nullable mnemonic, int64_t cointype, NSString* _Nullable addressPrefix, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT CosmosChain* _Nullable CosmosNewChainWithRpc(NSString* _Nullable rpcUrl, NSString* _Nullable restUrl);

/**
 * return NewAccountWithMnemonic(mnemonic, 118, "cosmos")
 */
FOUNDATION_EXPORT CosmosAccount* _Nullable CosmosNewCosmosAccountWithMnemonic(NSString* _Nullable mnemonic, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT CosmosRpcReachability* _Nullable CosmosNewRpcReachability(void);

/**
 * return NewAccountWithMnemonic(mnemonic, 330, "terra")
 */
FOUNDATION_EXPORT CosmosAccount* _Nullable CosmosNewTerraAccountWithMnemonic(NSString* _Nullable mnemonic, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT CosmosToken* _Nullable CosmosNewToken(CosmosChain* _Nullable chain, NSString* _Nullable prefix, NSString* _Nullable denom);

FOUNDATION_EXPORT CosmosUtil* _Nullable CosmosNewUtilWithPrefix(NSString* _Nullable addressPrefix);

#endif
