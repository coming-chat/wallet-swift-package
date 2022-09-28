// Objective-C API for talking to github.com/coming-chat/wallet-SDK/core/aptos Go package.
//   gobind -lang=objc github.com/coming-chat/wallet-SDK/core/aptos
//
// File is generated by gobind. Do not edit.

#ifndef __Aptos_H__
#define __Aptos_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

#include "Base.objc.h"
#include "Aptosclient.objc.h"

@class AptosAccount;
@class AptosChain;
@class AptosRestReachability;
@class AptosToken;
@class AptosUtil;
@protocol AptosIChain;
@class AptosIChain;

@protocol AptosIChain <NSObject>
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)batchFetchTransactionStatus:(NSString* _Nullable)hashListString;
- (BaseOptionalString* _Nullable)estimatePayloadGasFeeBCS:(id<BaseAccount> _Nullable)account data:(NSData* _Nullable)data error:(NSError* _Nullable* _Nullable)error;
- (BaseTransactionDetail* _Nullable)fetchTransactionDetail:(NSString* _Nullable)hash error:(NSError* _Nullable* _Nullable)error;
- (long)fetchTransactionStatus:(NSString* _Nullable)hash;
- (AptosclientRestClient* _Nullable)getClient:(NSError* _Nullable* _Nullable)error;
- (id<BaseToken> _Nullable)mainToken;
- (NSString* _Nonnull)sendRawTransaction:(NSString* _Nullable)signedTx error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)submitTransactionPayloadBCS:(id<BaseAccount> _Nullable)account data:(NSData* _Nullable)data error:(NSError* _Nullable* _Nullable)error;
@end

@interface AptosAccount : NSObject <goSeqRefInterface, BaseAccount, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithMnemonic:(NSString* _Nullable)mnemonic;
- (NSString* _Nonnull)address;
/**
 * @return publicKey that will start with 0x.
 */
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
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
- (NSData* _Nullable)sign:(NSData* _Nullable)message password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)signHex:(NSString* _Nullable)messageHex password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
@end

@interface AptosChain : NSObject <goSeqRefInterface, BaseChain, AptosIChain> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithRestUrl:(NSString* _Nullable)restUrl;
@property (nonatomic) NSString* _Nonnull restUrl;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)batchFetchTransactionStatus:(NSString* _Nullable)hashListString;
// skipped method Chain.EstimateMaxGasAmount with unsupported parameter or return types

// skipped method Chain.EstimateMaxGasAmountBCS with unsupported parameter or return types

- (BaseOptionalString* _Nullable)estimatePayloadGasFeeBCS:(id<BaseAccount> _Nullable)account data:(NSData* _Nullable)data error:(NSError* _Nullable* _Nullable)error;
/**
 * Fetch transaction details through transaction hash
 */
- (BaseTransactionDetail* _Nullable)fetchTransactionDetail:(NSString* _Nullable)hash error:(NSError* _Nullable* _Nullable)error;
- (long)fetchTransactionStatus:(NSString* _Nullable)hash;
- (AptosclientRestClient* _Nullable)getClient:(NSError* _Nullable* _Nullable)error;
- (id<BaseToken> _Nullable)mainToken;
/**
 * Send the raw transaction on-chain
@return the hex hash string
 */
- (NSString* _Nonnull)sendRawTransaction:(NSString* _Nullable)signedTx error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)signAndSendTransaction:(id<BaseAccount> _Nullable)account hexData:(NSString* _Nullable)hexData error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)submitTransactionPayloadBCS:(id<BaseAccount> _Nullable)account data:(NSData* _Nullable)data error:(NSError* _Nullable* _Nullable)error;
@end

@interface AptosRestReachability : NSObject <goSeqRefInterface, BaseRpcReachability> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
/**
 * @return latency (ms) of rpc query blockNumber. -1 means the connection failed.
 */
- (BaseRpcLatency* _Nullable)latencyOf:(NSString* _Nullable)rpc timeout:(int64_t)timeout error:(NSError* _Nullable* _Nullable)error;
@end

@interface AptosToken : NSObject <goSeqRefInterface, BaseToken> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * @param tag format `address::module_name::name`, e.g. "0x1::aptos_coin::AptosCoin"
 */
- (nullable instancetype)init:(AptosChain* _Nullable)chain tag:(NSString* _Nullable)tag;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)buildTransferTx:(NSString* _Nullable)privateKey receiverAddress:(NSString* _Nullable)receiverAddress amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)buildTransferTxWithAccount:(AptosAccount* _Nullable)account receiverAddress:(NSString* _Nullable)receiverAddress amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (id<BaseChain> _Nullable)chain;
- (BaseOptionalString* _Nullable)ensureOwnerRegistedToken:(AptosAccount* _Nullable)owner error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)estimateFees:(AptosAccount* _Nullable)account receiverAddress:(NSString* _Nullable)receiverAddress amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalBool* _Nullable)hasRegisted:(NSString* _Nullable)ownerAddress error:(NSError* _Nullable* _Nullable)error;
/**
 * @return transaction hash if register token succeed.
 */
- (BaseOptionalString* _Nullable)registerTokenForOwner:(AptosAccount* _Nullable)owner error:(NSError* _Nullable* _Nullable)error;
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

@interface AptosUtil : NSObject <goSeqRefInterface, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
/**
 * Warning: Aptos cannot support decode address to public key
 */
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
/**
 * @param publicKey can start with 0x or not.
 */
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BOOL)isValidAddress:(NSString* _Nullable)address;
@end

FOUNDATION_EXPORT const int64_t AptosAptosDecimal;
FOUNDATION_EXPORT NSString* _Nonnull const AptosAptosName;
FOUNDATION_EXPORT NSString* _Nonnull const AptosAptosSymbol;
FOUNDATION_EXPORT NSString* _Nonnull const AptosFaucetUrlDevnet;
FOUNDATION_EXPORT NSString* _Nonnull const AptosFaucetUrlTestnet;
FOUNDATION_EXPORT const int64_t AptosGasPrice;
FOUNDATION_EXPORT const int64_t AptosMaxGasAmount;
FOUNDATION_EXPORT const int64_t AptosTxExpireSec;

/**
 * rename for support android.
Android cant support both NewAccountWithMnemonic(string) and NewAccountWithPrivateKey(string)
 */
FOUNDATION_EXPORT AptosAccount* _Nullable AptosAccountWithPrivateKey(NSString* _Nullable prikey, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSString* _Nonnull AptosDecodeAddressToPublicKey(NSString* _Nullable address, NSError* _Nullable* _Nullable error);

/**
 * @param publicKey can start with 0x or not.
 */
FOUNDATION_EXPORT NSString* _Nonnull AptosEncodePublicKeyToAddress(NSString* _Nullable publicKey, NSError* _Nullable* _Nullable error);

/**
 * *
 * This creates an account if it does not exist and mints the specified amount of
 * coins into that account
 * @param address Hex-encoded 16 bytes Aptos account address wich mints tokens
 * @param amount Amount of tokens to mint
 * @param faucetUrl default https://faucet.devnet.aptoslabs.com
 * @returns Hashes of submitted transactions, e.g. "hash1,has2,hash3,..."
 */
FOUNDATION_EXPORT BaseOptionalString* _Nullable AptosFaucetFundAccount(NSString* _Nullable address, int64_t amount, NSString* _Nullable faucetUrl, NSError* _Nullable* _Nullable error);

/**
 * @param chainnet chain name
 */
FOUNDATION_EXPORT BOOL AptosIsValidAddress(NSString* _Nullable address);

FOUNDATION_EXPORT AptosAccount* _Nullable AptosNewAccountWithMnemonic(NSString* _Nullable mnemonic, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT AptosChain* _Nullable AptosNewChainWithRestUrl(NSString* _Nullable restUrl);

FOUNDATION_EXPORT AptosToken* _Nullable AptosNewMainToken(AptosChain* _Nullable chain);

FOUNDATION_EXPORT AptosRestReachability* _Nullable AptosNewRestReachability(void);

/**
 * @param tag format `address::module_name::name`, e.g. "0x1::aptos_coin::AptosCoin"
 */
FOUNDATION_EXPORT AptosToken* _Nullable AptosNewToken(AptosChain* _Nullable chain, NSString* _Nullable tag, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT AptosUtil* _Nullable AptosNewUtil(NSError* _Nullable* _Nullable error);

@class AptosIChain;

@interface AptosIChain : NSObject <goSeqRefInterface, AptosIChain> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)batchFetchTransactionStatus:(NSString* _Nullable)hashListString;
- (BaseOptionalString* _Nullable)estimatePayloadGasFeeBCS:(id<BaseAccount> _Nullable)account data:(NSData* _Nullable)data error:(NSError* _Nullable* _Nullable)error;
- (BaseTransactionDetail* _Nullable)fetchTransactionDetail:(NSString* _Nullable)hash error:(NSError* _Nullable* _Nullable)error;
- (long)fetchTransactionStatus:(NSString* _Nullable)hash;
- (AptosclientRestClient* _Nullable)getClient:(NSError* _Nullable* _Nullable)error;
- (id<BaseToken> _Nullable)mainToken;
- (NSString* _Nonnull)sendRawTransaction:(NSString* _Nullable)signedTx error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)submitTransactionPayloadBCS:(id<BaseAccount> _Nullable)account data:(NSData* _Nullable)data error:(NSError* _Nullable* _Nullable)error;
@end

#endif
