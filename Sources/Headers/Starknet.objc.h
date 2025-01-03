// Objective-C API for talking to github.com/coming-chat/wallet-SDK/core/starknet Go package.
//   gobind -lang=objc github.com/coming-chat/wallet-SDK/core/starknet
//
// File is generated by gobind. Do not edit.

#ifndef __Starknet_H__
#define __Starknet_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

#include "Base.objc.h"

@class StarknetAccount;
@class StarknetChain;
@class StarknetDeployAccountTransaction;
@class StarknetSignedTransaction;
@class StarknetToken;
@class StarknetTransaction;
@class StarknetUtil;

@interface StarknetAccount : NSObject <goSeqRefInterface, BaseAccount> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithMnemonic:(NSString* _Nullable)mnemonic;
/**
 * default false
 */
@property (nonatomic) BOOL cairo0;
/**
 * The ethereum address is same as public key in coming
 */
- (NSString* _Nonnull)address;
- (NSString* _Nonnull)addressCairo0;
- (NSString* _Nonnull)addressCairo1;
/**
 * @return privateKey data
 */
- (NSData* _Nullable)privateKey:(NSError* _Nullable* _Nullable)error;
/**
 * @return privateKey string that will start with 0x.
 */
- (NSString* _Nonnull)privateKeyHex:(NSError* _Nullable* _Nullable)error;
/**
 * Is decode from address
@return publicKey data
 */
- (NSData* _Nullable)publicKey;
/**
 * The ethereum public key is same as address in coming
@return publicKey string that will start with 0x.
 */
- (NSString* _Nonnull)publicKeyHex;
- (NSData* _Nullable)sign:(NSData* _Nullable)message password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
// skipped method Account.SignHash with unsupported parameter or return types

- (BaseOptionalString* _Nullable)signHex:(NSString* _Nullable)messageHex password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
@end

@interface StarknetChain : NSObject <goSeqRefInterface, BaseChain> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithRpc:(NSString* _Nullable)baseRpc;
- (BaseBalance* _Nullable)balanceOf:(NSString* _Nullable)ownerAddress erc20Address:(NSString* _Nullable)erc20Address error:(NSError* _Nullable* _Nullable)error;
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
 * BuildDeployAccountTransaction
@param maxFee default is 0.0002
 */
- (StarknetDeployAccountTransaction* _Nullable)buildDeployAccountTransaction:(NSString* _Nullable)publicKey maxFee:(NSString* _Nullable)maxFee error:(NSError* _Nullable* _Nullable)error;
/**
 * BuildDeployAccountTransaction
@param maxFee default is 0.0002
 */
- (StarknetDeployAccountTransaction* _Nullable)buildDeployAccountTransactionCairo0:(NSString* _Nullable)publicKey maxFee:(NSString* _Nullable)maxFee error:(NSError* _Nullable* _Nullable)error;
/**
 * unsupported
 */
- (BaseOptionalString* _Nullable)estimateTransactionFee:(id<BaseTransaction> _Nullable)transaction error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)estimateTransactionFeeUseAccount:(id<BaseTransaction> _Nullable)transaction acc:(StarknetAccount* _Nullable)acc error:(NSError* _Nullable* _Nullable)error;
/**
 * unsupported
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
- (BaseOptionalBool* _Nullable)isContractAddressDeployed:(NSString* _Nullable)contractAddress error:(NSError* _Nullable* _Nullable)error;
- (id<BaseToken> _Nullable)mainToken;
- (StarknetToken* _Nullable)newToken:(NSString* _Nullable)tokenAddress error:(NSError* _Nullable* _Nullable)error;
/**
 * Send the raw transaction on-chain
@return the hex hash string
 */
- (NSString* _Nonnull)sendRawTransaction:(NSString* _Nullable)signedTx error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)sendSignedTransaction:(id<BaseSignedTransaction> _Nullable)signedTxn error:(NSError* _Nullable* _Nullable)error;
@end

@interface StarknetDeployAccountTransaction : NSObject <goSeqRefInterface, BaseTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
// skipped constructor DeployAccountTransaction.NewDeployAccountTransaction with unsupported parameter or return types

// skipped field DeployAccountTransaction.DeployAccountTxn with unsupported type: invalid type

// skipped field DeployAccountTransaction.TransactionHash with unsupported type: *invalid type

- (BaseOptionalString* _Nullable)signWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (id<BaseSignedTransaction> _Nullable)signedTransactionWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
@end

@interface StarknetSignedTransaction : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * Do you need to automatically deploy the contract address first when you send the transaction for the first time? default NO
 */
@property (nonatomic) BOOL needAutoDeploy;
@property (nonatomic) StarknetAccount* _Nullable account;
- (BaseOptionalString* _Nullable)hexString:(NSError* _Nullable* _Nullable)error;
- (BOOL)resignInvokeTransaction:(StarknetChain* _Nullable)chain acc:(StarknetAccount* _Nullable)acc error:(NSError* _Nullable* _Nullable)error;
@end

@interface StarknetToken : NSObject <goSeqRefInterface, BaseToken> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(StarknetChain* _Nullable)chain tokenAddress:(NSString* _Nullable)tokenAddress;
@property (nonatomic) NSString* _Nonnull tokenAddress;
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
/**
 * Warning: Main token does not support
 */
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

@interface StarknetTransaction : NSObject <goSeqRefInterface, BaseTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
- (BaseOptionalString* _Nullable)signWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (id<BaseSignedTransaction> _Nullable)signedTransactionWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
@end

@interface StarknetUtil : NSObject <goSeqRefInterface, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
/**
 * Warning: starknet cannot support decode address to public key
 */
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
/**
 * Check if address is 40 hexadecimal characters
 */
- (BOOL)isValidAddress:(NSString* _Nullable)address;
@end

FOUNDATION_EXPORT NSString* _Nonnull const StarknetBaseRpcUrlMainnet;
FOUNDATION_EXPORT NSString* _Nonnull const StarknetETHTokenAddress;
FOUNDATION_EXPORT const double StarknetInvokeMaxFee;

FOUNDATION_EXPORT StarknetAccount* _Nullable StarknetAccountWithPrivateKey(NSString* _Nullable privatekey, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT StarknetSignedTransaction* _Nullable StarknetAsSignedTransaction(id<BaseSignedTransaction> _Nullable txn);

FOUNDATION_EXPORT StarknetAccount* _Nullable StarknetAsStarknetAccount(id<BaseAccount> _Nullable account);

/**
 * CheckCairoVersion
- return address version, 0 for cairo0, 1 for cairo1.0
 */
FOUNDATION_EXPORT BaseOptionalInt* _Nullable StarknetCheckCairoVersion(NSString* _Nullable address, NSString* _Nullable pubkey, NSError* _Nullable* _Nullable error);

// skipped function CheckCairoVersionFelt with unsupported parameter or return types


/**
 * Warning: starknet cannot support decode address to public key
 */
FOUNDATION_EXPORT NSString* _Nonnull StarknetDecodeAddressToPublicKey(NSString* _Nullable address, NSError* _Nullable* _Nullable error);

/**
 * EncodePublicKeyToAddress
- return: encode cairo version 1.0 address
 */
FOUNDATION_EXPORT NSString* _Nonnull StarknetEncodePublicKeyToAddress(NSString* _Nullable publicKey, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSString* _Nonnull StarknetEncodePublicKeyToAddressCairo0(NSString* _Nullable publicKey, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BOOL StarknetIsNotDeployedError(NSError* _Nullable err);

FOUNDATION_EXPORT BOOL StarknetIsValidAddress(NSString* _Nullable address);

FOUNDATION_EXPORT BOOL StarknetIsValidPrivateKey(NSString* _Nullable key);

FOUNDATION_EXPORT StarknetAccount* _Nullable StarknetNewAccountWithMnemonic(NSString* _Nullable mnemonic, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT StarknetChain* _Nullable StarknetNewChainWithRpc(NSString* _Nullable baseRpc, NSError* _Nullable* _Nullable error);

// skipped function NewDeployAccountTransaction with unsupported parameter or return types


FOUNDATION_EXPORT StarknetToken* _Nullable StarknetNewToken(StarknetChain* _Nullable chain, NSString* _Nullable tokenAddress, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT StarknetUtil* _Nullable StarknetNewUtil(void);

#endif
