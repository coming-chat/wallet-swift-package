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
@class SuiDelegatedStake;
@class SuiPickedCoins;
@class SuiSignedTransaction;
@class SuiToken;
@class SuiTransaction;
@class SuiUtil;
@class SuiValidator;
@class SuiValidatorState;

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
- (SuiTransaction* _Nullable)addDelegation:(NSString* _Nullable)owner amount:(NSString* _Nullable)amount validatorAddress:(NSString* _Nullable)validatorAddress error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
// skipped method Chain.BaseMoveCall with unsupported parameter or return types

- (NSString* _Nonnull)batchFetchTransactionStatus:(NSString* _Nullable)hashListString;
// skipped method Chain.Client with unsupported parameter or return types

- (BaseOptionalString* _Nullable)estimateGasFee:(SuiTransaction* _Nullable)transaction error:(NSError* _Nullable* _Nullable)error;
// skipped method Chain.FetchNFTs with unsupported parameter or return types

- (BaseOptionalString* _Nullable)fetchNFTsJsonString:(NSString* _Nullable)owner error:(NSError* _Nullable* _Nullable)error;
/**
 * Fetch transaction details through transaction hash
 */
- (BaseTransactionDetail* _Nullable)fetchTransactionDetail:(NSString* _Nullable)hash error:(NSError* _Nullable* _Nullable)error;
- (long)fetchTransactionStatus:(NSString* _Nullable)hash;
- (BaseOptionalString* _Nullable)gasPrice:(NSError* _Nullable* _Nullable)error;
/**
 * @return Array of `DelegatedStake` elements
 */
- (BaseAnyArray* _Nullable)getDelegatedStakes:(NSString* _Nullable)owner error:(NSError* _Nullable* _Nullable)error;
- (SuiValidator* _Nullable)getValidator:(NSString* _Nullable)address useCache:(BOOL)useCache error:(NSError* _Nullable* _Nullable)error;
- (SuiValidatorState* _Nullable)getValidatorState:(NSError* _Nullable* _Nullable)error;
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
 * @useCache If true, when there is cached data, the result will be returned directly without requesting data on the chain.
 */
- (BaseOptionalString* _Nullable)totalStakedSuiAtValidator:(NSString* _Nullable)validator owner:(NSString* _Nullable)owner useCache:(BOOL)useCache error:(NSError* _Nullable* _Nullable)error;
/**
 * Just encapsulation and callbacks to method `TransferObject`.
@param gasId gas object to be used in this transaction, the gateway will pick one from the signer's possession if not provided
 */
- (SuiTransaction* _Nullable)transferNFT:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver nftId:(NSString* _Nullable)nftId gasId:(NSString* _Nullable)gasId gasBudget:(int64_t)gasBudget error:(NSError* _Nullable* _Nullable)error;
/**
 * @param gasId gas object to be used in this transaction, the gateway will pick one from the signer's possession if not provided
 */
- (SuiTransaction* _Nullable)transferObject:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver objectId:(NSString* _Nullable)objectId gasId:(NSString* _Nullable)gasId gasBudget:(int64_t)gasBudget error:(NSError* _Nullable* _Nullable)error;
- (SuiTransaction* _Nullable)withdrawDelegation:(NSString* _Nullable)owner stakeId:(NSString* _Nullable)stakeId error:(NSError* _Nullable* _Nullable)error;
@end

@interface SuiDelegatedStake : NSObject <goSeqRefInterface, BaseAniable, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
@property (nonatomic) NSString* _Nonnull stakeId;
@property (nonatomic) NSString* _Nonnull validatorAddress;
@property (nonatomic) NSString* _Nonnull principal;
@property (nonatomic) int64_t requestEpoch;
@property (nonatomic) long status;
@property (nonatomic) NSString* _Nonnull delegationId;
@property (nonatomic) NSString* _Nonnull earnedAmount;
@property (nonatomic) SuiValidator* _Nullable validator;
- (BaseAny* _Nullable)asAny;
/**
 * @return if time > 0 indicates how long it will take to get the reward;
if time < 0 indicates how much time has passed since the reward was earned;
 */
- (int64_t)earningAmountTimeAfterNowMs:(SuiValidatorState* _Nullable)stateInfo;
// skipped method DelegatedStake.EarningAmountTimeAfterTimestampMs with unsupported parameter or return types

- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface SuiPickedCoins : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field PickedCoins.Coins with unsupported type: github.com/coming-chat/go-sui/types.Coins

// skipped field PickedCoins.Total with unsupported type: *math/big.Int

// skipped field PickedCoins.Amount with unsupported type: *math/big.Int

// skipped method PickedCoins.CoinIds with unsupported parameter or return types

// skipped method PickedCoins.EstimateMergeGas with unsupported parameter or return types

// skipped method PickedCoins.EstimateTotalGas with unsupported parameter or return types

@end

@interface SuiSignedTransaction : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field SignedTransaction.TxBytes with unsupported type: *github.com/coming-chat/go-sui/types.Base64Data

// skipped field SignedTransaction.Signature with unsupported type: *github.com/coming-chat/go-sui/sui_types.Signature

@end

@interface SuiToken : NSObject <goSeqRefInterface, BaseToken> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * @param tag format `address::module_name::name`, e.g. "0x2::sui::SUI"
 */
- (nullable instancetype)init:(SuiChain* _Nullable)chain tag:(NSString* _Nullable)tag;
- (nullable instancetype)initMain:(SuiChain* _Nullable)chain;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (SuiTransaction* _Nullable)buildTransferTransaction:(SuiAccount* _Nullable)account receiverAddress:(NSString* _Nullable)receiverAddress amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
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
// skipped field Transaction.Txn with unsupported type: github.com/coming-chat/go-sui/types.TransactionBytes

@property (nonatomic) int64_t maxGasBudget;
@property (nonatomic) int64_t estimateGasFee;
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

@interface SuiValidator : NSObject <goSeqRefInterface, BaseAniable, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
@property (nonatomic) NSString* _Nonnull address;
@property (nonatomic) NSString* _Nonnull name;
@property (nonatomic) NSString* _Nonnull desc;
@property (nonatomic) NSString* _Nonnull imageUrl;
@property (nonatomic) NSString* _Nonnull projectUrl;
@property (nonatomic) double apy;
@property (nonatomic) int64_t commission;
@property (nonatomic) NSString* _Nonnull totalStaked;
@property (nonatomic) NSString* _Nonnull delegatedStaked;
@property (nonatomic) NSString* _Nonnull selfStaked;
@property (nonatomic) NSString* _Nonnull totalRewards;
@property (nonatomic) int64_t gasPrice;
- (BaseAny* _Nullable)asAny;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface SuiValidatorState : NSObject <goSeqRefInterface, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
/**
 * The current epoch in Sui. An epoch takes approximately 24 hours and runs in checkpoints.
 */
@property (nonatomic) int64_t epoch;
/**
 * Array of `Validator` elements
 */
@property (nonatomic) BaseAnyArray* _Nullable validators;
/**
 * The amount of all tokens staked in the Sui Network.
 */
@property (nonatomic) NSString* _Nonnull totalStaked;
/**
 * The amount of rewards won by all Sui validators in the last epoch.
 */
@property (nonatomic) NSString* _Nonnull totalRewards;
@property (nonatomic) int64_t epochStartTimestampMs;
@property (nonatomic) int64_t epochDurationMs;
/**
 * @return if time > 0 indicates how long it will take to get the reward;
if time < 0 indicates how much time has passed since the reward was earned;
 */
- (int64_t)earningAmountTimeAfterNowMs;
- (int64_t)earningAmountTimeAfterTimestampMs:(int64_t)timestamp;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

FOUNDATION_EXPORT const long SuiDelegationStatusActived;
FOUNDATION_EXPORT const long SuiDelegationStatusPending;
FOUNDATION_EXPORT NSString* _Nonnull const SuiDevNetFaucetUrl;
FOUNDATION_EXPORT const int64_t SuiMaxGasBudget;
FOUNDATION_EXPORT const int64_t SuiMaxGasForMerge;
FOUNDATION_EXPORT const int64_t SuiMaxGasForPay;
FOUNDATION_EXPORT const int64_t SuiMaxGasForTransfer;
FOUNDATION_EXPORT const int64_t SuiSuiDecimal;
FOUNDATION_EXPORT NSString* _Nonnull const SuiSuiName;
FOUNDATION_EXPORT NSString* _Nonnull const SuiSuiSymbol;
FOUNDATION_EXPORT NSString* _Nonnull const SuiTestNetFaucetUrl;

/**
 * rename for support android.
Android cannot support both NewAccountWithMnemonic(string) and NewAccountWithPrivateKey(string)
 */
FOUNDATION_EXPORT SuiAccount* _Nullable SuiAccountWithPrivateKey(NSString* _Nullable prikey, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT SuiDelegatedStake* _Nullable SuiAsDelegatedStake(BaseAny* _Nullable a);

FOUNDATION_EXPORT SuiAccount* _Nullable SuiAsSuiAccount(id<BaseAccount> _Nullable account);

FOUNDATION_EXPORT SuiValidator* _Nullable SuiAsValidator(BaseAny* _Nullable a);

FOUNDATION_EXPORT double SuiAverageApyOfDelegatedStakes(BaseAnyArray* _Nullable stakes);

FOUNDATION_EXPORT NSString* _Nonnull SuiDecodeAddressToPublicKey(NSString* _Nullable address, NSError* _Nullable* _Nullable error);

/**
 * @param publicKey can start with 0x or not.
 */
FOUNDATION_EXPORT NSString* _Nonnull SuiEncodePublicKeyToAddress(NSString* _Nullable publicKey, NSError* _Nullable* _Nullable error);

/**
 * *
 * @param address Hex-encoded 16 bytes Sui account address wich mints tokens
 * @param faucetUrl default https://faucet.testnet.sui.io/gas
 * @return digest of the faucet transfer transaction.
 */
FOUNDATION_EXPORT BaseOptionalString* _Nullable SuiFaucetFundAccount(NSString* _Nullable address, NSString* _Nullable faucetUrl, NSError* _Nullable* _Nullable error);

/**
 * @param chainnet chain name
 */
FOUNDATION_EXPORT BOOL SuiIsValidAddress(NSString* _Nullable address);

FOUNDATION_EXPORT SuiAccount* _Nullable SuiNewAccountWithMnemonic(NSString* _Nullable mnemonic, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT SuiChain* _Nullable SuiNewChainWithRpcUrl(NSString* _Nullable rpcUrl);

FOUNDATION_EXPORT SuiDelegatedStake* _Nullable SuiNewDelegatedStake(void);

FOUNDATION_EXPORT BaseAnyArray* _Nullable SuiNewDelegatedStakeArrayWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT SuiDelegatedStake* _Nullable SuiNewDelegatedStakeWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

/**
 * @param tag format `address::module_name::name`, e.g. "0x2::sui::SUI"
 */
FOUNDATION_EXPORT SuiToken* _Nullable SuiNewToken(SuiChain* _Nullable chain, NSString* _Nullable tag, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT SuiToken* _Nullable SuiNewTokenMain(SuiChain* _Nullable chain);

FOUNDATION_EXPORT SuiUtil* _Nullable SuiNewUtil(NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT SuiValidator* _Nullable SuiNewValidator(void);

FOUNDATION_EXPORT SuiValidatorState* _Nullable SuiNewValidatorState(void);

FOUNDATION_EXPORT SuiValidatorState* _Nullable SuiNewValidatorStateWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT SuiValidator* _Nullable SuiNewValidatorWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

#endif
