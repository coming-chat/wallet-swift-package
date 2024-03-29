// Objective-C API for talking to github.com/coming-chat/wallet-SDK/core/starcoin Go package.
//   gobind -lang=objc github.com/coming-chat/wallet-SDK/core/starcoin
//
// File is generated by gobind. Do not edit.

#ifndef __Starcoin_H__
#define __Starcoin_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

#include "Base.objc.h"
#include "Eth.objc.h"

@class StarcoinAccount;
@class StarcoinChain;
@class StarcoinSignedTransaction;
@class StarcoinToken;
@class StarcoinTransaction;
@class StarcoinUtil;

@interface StarcoinAccount : NSObject <goSeqRefInterface, BaseAccount, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithMnemonic:(NSString* _Nullable)mnemonic;
@property (nonatomic) NSData* _Nullable authKey;
// skipped method Account.AccountAddress with unsupported parameter or return types

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
// skipped method Account.StarcoinPrivateKey with unsupported parameter or return types

// skipped method Account.StarcoinPublicKey with unsupported parameter or return types

@end

@interface StarcoinChain : NSObject <goSeqRefInterface, BaseChain> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithRpc:(NSString* _Nullable)rpcUrl;
@property (nonatomic) NSString* _Nonnull rpcUrl;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)batchFetchTransactionStatus:(NSString* _Nullable)hashListString;
- (BaseOptionalString* _Nullable)estimateTransactionFee:(id<BaseTransaction> _Nullable)transaction error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)estimateTransactionFeeUsePublicKey:(id<BaseTransaction> _Nullable)transaction pubkey:(NSString* _Nullable)pubkey error:(NSError* _Nullable* _Nullable)error;
/**
 * Fetch transaction details through transaction hash
 */
- (BaseTransactionDetail* _Nullable)fetchTransactionDetail:(NSString* _Nullable)hash error:(NSError* _Nullable* _Nullable)error;
- (long)fetchTransactionStatus:(NSString* _Nullable)hash;
- (BaseOptionalString* _Nullable)gasPrice:(NSError* _Nullable* _Nullable)error;
// skipped method Chain.GetState with unsupported parameter or return types

- (id<BaseToken> _Nullable)mainToken;
/**
 * Send the raw transaction on-chain
@return the hex hash string
 */
- (NSString* _Nonnull)sendRawTransaction:(NSString* _Nullable)signedTx error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)sendSignedTransaction:(id<BaseSignedTransaction> _Nullable)signedTxn error:(NSError* _Nullable* _Nullable)error;
@end

@interface StarcoinSignedTransaction : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field SignedTransaction.Txn with unsupported type: *invalid type

- (BaseOptionalString* _Nullable)hexString:(NSError* _Nullable* _Nullable)error;
@end

@interface StarcoinToken : NSObject <goSeqRefInterface, BaseToken> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (id<BaseTransaction> _Nullable)buildTransfer:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (id<BaseTransaction> _Nullable)buildTransferAll:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver error:(NSError* _Nullable* _Nullable)error;
// skipped method Token.BuildTransferPayload with unsupported parameter or return types

- (BaseOptionalString* _Nullable)buildTransferTx:(NSString* _Nullable)privateKey receiverAddress:(NSString* _Nullable)receiverAddress amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)buildTransferTxWithAccount:(StarcoinAccount* _Nullable)account receiverAddress:(NSString* _Nullable)receiverAddress amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (BOOL)canTransferAll;
- (id<BaseChain> _Nullable)chain;
- (BaseOptionalString* _Nullable)estimateFees:(StarcoinAccount* _Nullable)account receiverAddress:(NSString* _Nullable)receiverAddress amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

@interface StarcoinTransaction : NSObject <goSeqRefInterface, BaseTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field Transaction.Txn with unsupported type: *invalid type

- (BaseOptionalString* _Nullable)signWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (id<BaseSignedTransaction> _Nullable)signedTransactionWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
@end

@interface StarcoinUtil : NSObject <goSeqRefInterface, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
/**
 * Warning: Starcoin cannot support decode address to public key
 */
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
/**
 * @param publicKey can start with 0x or not.
 */
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BOOL)isValidAddress:(NSString* _Nullable)address;
@end

// skipped const MaxGasAmount with unsupported type: invalid type


FOUNDATION_EXPORT StarcoinAccount* _Nullable StarcoinAccountWithPrivateKey(NSString* _Nullable privateKey, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT StarcoinSignedTransaction* _Nullable StarcoinAsSignedTransaction(id<BaseSignedTransaction> _Nullable txn);

FOUNDATION_EXPORT StarcoinAccount* _Nullable StarcoinAsStarcoinAccount(id<BaseAccount> _Nullable account);

FOUNDATION_EXPORT NSString* _Nonnull StarcoinDecodeAddressToPublicKey(NSString* _Nullable address, NSError* _Nullable* _Nullable error);

/**
 * @param publicKey can start with 0x or not.
 */
FOUNDATION_EXPORT NSString* _Nonnull StarcoinEncodePublicKeyToAddress(NSString* _Nullable publicKey, NSError* _Nullable* _Nullable error);

/**
 * @param chainnet chain name
 */
FOUNDATION_EXPORT BOOL StarcoinIsValidAddress(NSString* _Nullable address);

// skipped function NewAccountAddressFromHex with unsupported parameter or return types


FOUNDATION_EXPORT StarcoinAccount* _Nullable StarcoinNewAccountWithMnemonic(NSString* _Nullable mnemonic, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT StarcoinChain* _Nullable StarcoinNewChainWithRpc(NSString* _Nullable rpcUrl);

FOUNDATION_EXPORT StarcoinToken* _Nullable StarcoinNewMainToken(StarcoinChain* _Nullable chain);

// skipped function NewStructTag with unsupported parameter or return types


// skipped function NewU128FromString with unsupported parameter or return types


FOUNDATION_EXPORT StarcoinUtil* _Nullable StarcoinNewUtil(NSError* _Nullable* _Nullable error);

// skipped function StructTagToString with unsupported parameter or return types


#endif
