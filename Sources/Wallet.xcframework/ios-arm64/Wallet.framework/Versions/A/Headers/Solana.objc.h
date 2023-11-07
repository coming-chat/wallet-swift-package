// Objective-C API for talking to github.com/coming-chat/wallet-SDK/core/solana Go package.
//   gobind -lang=objc github.com/coming-chat/wallet-SDK/core/solana
//
// File is generated by gobind. Do not edit.

#ifndef __Solana_H__
#define __Solana_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

#include "Base.objc.h"

@class SolanaAccount;
@class SolanaChain;
@class SolanaRpcReachability;
@class SolanaSPLToken;
@class SolanaSignedTransaction;
@class SolanaToken;
@class SolanaTokenAccount;
@class SolanaTransaction;
@class SolanaUtil;

@interface SolanaAccount : NSObject <goSeqRefInterface, BaseAccount, BaseAddressUtil> {
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

@interface SolanaChain : NSObject <goSeqRefInterface, BaseAddressUtil, BaseChain> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithRpc:(NSString* _Nullable)rpcUrl;
@property (nonatomic) SolanaUtil* _Nullable util;
@property (nonatomic) NSString* _Nonnull rpcUrl;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)batchFetchTransactionStatus:(NSString* _Nullable)hashListString;
// skipped method Chain.Client with unsupported parameter or return types

- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)estimateTransactionFee:(id<BaseTransaction> _Nullable)transaction error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)estimateTransactionFeeUsePublicKey:(id<BaseTransaction> _Nullable)transaction pubkey:(NSString* _Nullable)pubkey error:(NSError* _Nullable* _Nullable)error;
/**
 * Fetch transaction details through transaction hash
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
- (BaseOptionalString* _Nullable)sendSignedTransaction:(id<BaseSignedTransaction> _Nullable)signedTxn error:(NSError* _Nullable* _Nullable)error;
@end

@interface SolanaRpcReachability : NSObject <goSeqRefInterface, BaseRpcReachability> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
/**
 * @return latency (ms) of rpc query blockNumber. -1 means the connection failed.
 */
- (BaseRpcLatency* _Nullable)latencyOf:(NSString* _Nullable)rpc timeout:(int64_t)timeout error:(NSError* _Nullable* _Nullable)error;
@end

@interface SolanaSPLToken : NSObject <goSeqRefInterface, BaseToken> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(SolanaChain* _Nullable)chain mintAddress:(NSString* _Nullable)mintAddress;
@property (nonatomic) NSString* _Nonnull mintAddress;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
/**
 * BuildTransfer
This method will automatically create an token account for the receiver if receiver does not own it.
 */
- (id<BaseTransaction> _Nullable)buildTransfer:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
/**
 * BuildTransferAll
This method will automatically create an token account for the receiver if receiver does not own it.
 */
- (id<BaseTransaction> _Nullable)buildTransferAll:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver error:(NSError* _Nullable* _Nullable)error;
/**
 * BuildTransferAuto
@param transferAll if true will transfer all balance, else transfer the amount
@param autoCreateAccount if true will auto create token account for receiver, else throw error if receiver no has token account
 */
- (id<BaseTransaction> _Nullable)buildTransferAuto:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver amount:(NSString* _Nullable)amount transferAll:(BOOL)transferAll autoCreateAccount:(BOOL)autoCreateAccount error:(NSError* _Nullable* _Nullable)error;
/**
 * CanTransferAll
Available
 */
- (BOOL)canTransferAll;
- (id<BaseChain> _Nullable)chain;
- (SolanaTransaction* _Nullable)createTokenAccount:(NSString* _Nullable)ownerAddress signerAddress:(NSString* _Nullable)signerAddress error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalBool* _Nullable)hasCreated:(NSString* _Nullable)ownerAddress error:(NSError* _Nullable* _Nullable)error;
// skipped method SPLToken.TokenAccountOfAddress with unsupported parameter or return types

- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
/**
 * TokenInfoChainid
@param chainId mainnet 101, testnet 102, devnet 103
 */
- (BaseTokenInfo* _Nullable)tokenInfoChainid:(long)chainId error:(NSError* _Nullable* _Nullable)error;
@end

@interface SolanaSignedTransaction : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field SignedTransaction.Transaction with unsupported type: invalid type

- (BaseOptionalString* _Nullable)hexString:(NSError* _Nullable* _Nullable)error;
@end

@interface SolanaToken : NSObject <goSeqRefInterface, BaseToken> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(SolanaChain* _Nullable)chain;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (id<BaseTransaction> _Nullable)buildTransfer:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (id<BaseTransaction> _Nullable)buildTransferAll:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)buildTransferTx:(NSString* _Nullable)privateKey receiverAddress:(NSString* _Nullable)receiverAddress amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)buildTransferTxWithAccount:(SolanaAccount* _Nullable)account receiverAddress:(NSString* _Nullable)receiverAddress amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (BOOL)canTransferAll;
- (id<BaseChain> _Nullable)chain;
- (BaseOptionalString* _Nullable)estimateFees:(NSString* _Nullable)receiverAddress amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

@interface SolanaTokenAccount : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull address;
@property (nonatomic) NSString* _Nonnull owner;
// skipped field TokenAccount.Amount with unsupported type: uint64

@property (nonatomic) NSString* _Nonnull accountType;
@end

@interface SolanaTransaction : NSObject <goSeqRefInterface, BaseTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(NSString* _Nullable)rawBase58String;
// skipped field Transaction.Message with unsupported type: invalid type

- (BaseOptionalString* _Nullable)signWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (id<BaseSignedTransaction> _Nullable)signedTransactionWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
@end

@interface SolanaUtil : NSObject <goSeqRefInterface, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
/**
 * Warning: eth cannot support decode address to public key
 */
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
/**
 * Check if address is 40 hexadecimal characters
 */
- (BOOL)isValidAddress:(NSString* _Nullable)address;
@end

// skipped const DevnetRPCEndpoint with unsupported type: invalid type

// skipped const MainnetRPCEndpoint with unsupported type: invalid type

FOUNDATION_EXPORT NSString* _Nonnull const SolanaSPLAccountTypeAssociated;
FOUNDATION_EXPORT NSString* _Nonnull const SolanaSPLAccountTypeRandom;
// skipped const TestnetRPCEndpoint with unsupported type: invalid type


@interface Solana : NSObject
+ (NSError* _Nullable) errNoTokenAccount;
+ (void) setErrNoTokenAccount:(NSError* _Nullable)v;

@end

/**
 * rename for support android.
Android cant support both NewAccountWithMnemonic(string) and NewAccountWithPrivateKey(string)
 */
FOUNDATION_EXPORT SolanaAccount* _Nullable SolanaAccountWithPrivateKey(NSString* _Nullable prikey, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT SolanaSignedTransaction* _Nullable SolanaAsSignedTransaction(id<BaseSignedTransaction> _Nullable txn);

FOUNDATION_EXPORT SolanaAccount* _Nullable SolanaAsSolanaAccount(id<BaseAccount> _Nullable account);

FOUNDATION_EXPORT NSString* _Nonnull SolanaDecodeAddressToPublicKey(NSString* _Nullable address, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSString* _Nonnull SolanaEncodePublicKeyToAddress(NSString* _Nullable publicKey, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BOOL SolanaIsNoTokenAccountError(NSError* _Nullable err);

FOUNDATION_EXPORT BOOL SolanaIsValidAddress(NSString* _Nullable address);

FOUNDATION_EXPORT SolanaAccount* _Nullable SolanaNewAccountWithMnemonic(NSString* _Nullable mnemonic, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT SolanaChain* _Nullable SolanaNewChainWithRpc(NSString* _Nullable rpcUrl);

FOUNDATION_EXPORT SolanaRpcReachability* _Nullable SolanaNewRpcReachability(void);

FOUNDATION_EXPORT SolanaSPLToken* _Nullable SolanaNewSPLToken(SolanaChain* _Nullable chain, NSString* _Nullable mintAddress, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT SolanaToken* _Nullable SolanaNewToken(SolanaChain* _Nullable chain);

FOUNDATION_EXPORT SolanaTransaction* _Nullable SolanaNewTransaction(NSString* _Nullable rawBase58String, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT SolanaUtil* _Nullable SolanaNewUtil(void);

// skipped function TransformTokenAccount with unsupported parameter or return types


#endif
