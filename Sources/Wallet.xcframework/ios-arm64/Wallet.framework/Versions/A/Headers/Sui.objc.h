// Objective-C API for talking to github.com/coming-chat/wallet-SDK/core/sui Go package.
//   gobind -lang=objc github.com/coming-chat/wallet-SDK/core/sui
//
// File is generated by gobind. Do not edit.

#ifndef __Sui_H__
#define __Sui_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

#include "Base.objc.h"

@class SuiAccount;
@class SuiChain;
@class SuiPickedCoins;
@class SuiToken;
@class SuiTransaction;
@class SuiUtil;

@interface SuiAccount : NSObject <goSeqRefInterface, BaseAccount, BaseAddressUtil> {
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

@interface SuiChain : NSObject <goSeqRefInterface, BaseChain, BaseNFTFetcher> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithRpcUrl:(NSString* _Nullable)rpcUrl;
@property (nonatomic) NSString* _Nonnull rpcUrl;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)batchFetchTransactionStatus:(NSString* _Nullable)hashListString;
// skipped method Chain.FetchNFTs with unsupported parameter or return types

- (BaseOptionalString* _Nullable)fetchNFTsJsonString:(NSString* _Nullable)owner error:(NSError* _Nullable* _Nullable)error;
/**
 * Fetch transaction details through transaction hash
 */
- (BaseTransactionDetail* _Nullable)fetchTransactionDetail:(NSString* _Nullable)hash error:(NSError* _Nullable* _Nullable)error;
- (long)fetchTransactionStatus:(NSString* _Nullable)hash;
- (id<BaseToken> _Nullable)mainToken;
/**
 * @param gasId gas object to be used in this transaction, the gateway will pick one from the signer's possession if not provided
 */
- (SuiTransaction* _Nullable)mintNFT:(NSString* _Nullable)creator name:(NSString* _Nullable)name description:(NSString* _Nullable)description uri:(NSString* _Nullable)uri gasId:(NSString* _Nullable)gasId gasBudget:(int64_t)gasBudget error:(NSError* _Nullable* _Nullable)error;
/**
 * Send the raw transaction on-chain
@return the hex hash string
 */
- (NSString* _Nonnull)sendRawTransaction:(NSString* _Nullable)signedTx error:(NSError* _Nullable* _Nullable)error;
/**
 * Just encapsulation and callbacks to method `TransferObject`.
@param gasId gas object to be used in this transaction, the gateway will pick one from the signer's possession if not provided
 */
- (SuiTransaction* _Nullable)transferNFT:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver nftId:(NSString* _Nullable)nftId gasId:(NSString* _Nullable)gasId gasBudget:(int64_t)gasBudget error:(NSError* _Nullable* _Nullable)error;
/**
 * @param gasId gas object to be used in this transaction, the gateway will pick one from the signer's possession if not provided
 */
- (SuiTransaction* _Nullable)transferObject:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver objectId:(NSString* _Nullable)objectId gasId:(NSString* _Nullable)gasId gasBudget:(int64_t)gasBudget error:(NSError* _Nullable* _Nullable)error;
@end

@interface SuiPickedCoins : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field PickedCoins.Coins with unsupported type: invalid type

// skipped field PickedCoins.Total with unsupported type: *math/big.Int

// skipped field PickedCoins.Amount with unsupported type: *math/big.Int

// skipped method PickedCoins.CoinIds with unsupported parameter or return types

// skipped method PickedCoins.EstimateMergeGas with unsupported parameter or return types

// skipped method PickedCoins.EstimateTotalGas with unsupported parameter or return types

@end

@interface SuiToken : NSObject <goSeqRefInterface, BaseToken> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initMain:(SuiChain* _Nullable)chain;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)buildTransferTx:(NSString* _Nullable)privateKey receiverAddress:(NSString* _Nullable)receiverAddress amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)buildTransferTxWithAccount:(SuiAccount* _Nullable)account receiverAddress:(NSString* _Nullable)receiverAddress amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (id<BaseChain> _Nullable)chain;
- (BaseOptionalString* _Nullable)estimateFees:(SuiAccount* _Nullable)account receiverAddress:(NSString* _Nullable)receiverAddress amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

@interface SuiTransaction : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field Transaction.Txn with unsupported type: invalid type

- (BaseOptionalString* _Nullable)signWithAccount:(SuiAccount* _Nullable)account error:(NSError* _Nullable* _Nullable)error;
@end

@interface SuiUtil : NSObject <goSeqRefInterface, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
/**
 * Warning: Sui cannot support decode address to public key
 */
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
/**
 * @param publicKey can start with 0x or not.
 */
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BOOL)isValidAddress:(NSString* _Nullable)address;
@end

FOUNDATION_EXPORT NSString* _Nonnull const SuiFaucetUrlTestnet;
FOUNDATION_EXPORT const int64_t SuiMaxGasBudget;
FOUNDATION_EXPORT const int64_t SuiMaxGasForMerge;
FOUNDATION_EXPORT const int64_t SuiMaxGasForPay;
FOUNDATION_EXPORT const int64_t SuiMaxGasForTransfer;
FOUNDATION_EXPORT const int64_t SuiSuiDecimal;
FOUNDATION_EXPORT NSString* _Nonnull const SuiSuiName;
FOUNDATION_EXPORT NSString* _Nonnull const SuiSuiSymbol;

/**
 * rename for support android.
Android cannot support both NewAccountWithMnemonic(string) and NewAccountWithPrivateKey(string)
 */
FOUNDATION_EXPORT SuiAccount* _Nullable SuiAccountWithPrivateKey(NSString* _Nullable prikey, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSString* _Nonnull SuiDecodeAddressToPublicKey(NSString* _Nullable address, NSError* _Nullable* _Nullable error);

/**
 * @param publicKey can start with 0x or not.
 */
FOUNDATION_EXPORT NSString* _Nonnull SuiEncodePublicKeyToAddress(NSString* _Nullable publicKey, NSError* _Nullable* _Nullable error);

/**
 * *
 * @param address Hex-encoded 16 bytes Sui account address wich mints tokens
 * @param faucetUrl default https://faucet.testnet.sui.io/gas
 * @return digest of transfer transaction.
 */
FOUNDATION_EXPORT BaseOptionalString* _Nullable SuiFaucetFundAccount(NSString* _Nullable address, NSString* _Nullable faucetUrl, NSError* _Nullable* _Nullable error);

/**
 * @param chainnet chain name
 */
FOUNDATION_EXPORT BOOL SuiIsValidAddress(NSString* _Nullable address);

FOUNDATION_EXPORT SuiAccount* _Nullable SuiNewAccountWithMnemonic(NSString* _Nullable mnemonic, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT SuiChain* _Nullable SuiNewChainWithRpcUrl(NSString* _Nullable rpcUrl);

FOUNDATION_EXPORT SuiToken* _Nullable SuiNewTokenMain(SuiChain* _Nullable chain);

FOUNDATION_EXPORT SuiUtil* _Nullable SuiNewUtil(NSError* _Nullable* _Nullable error);

#endif
