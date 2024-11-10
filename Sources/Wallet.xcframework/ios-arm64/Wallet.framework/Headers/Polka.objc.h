// Objective-C API for talking to github.com/coming-chat/wallet-SDK/core/polka Go package.
//   gobind -lang=objc github.com/coming-chat/wallet-SDK/core/polka
//
// File is generated by gobind. Do not edit.

#ifndef __Polka_H__
#define __Polka_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

#include "Base.objc.h"

@class PolkaAccount;
@class PolkaChain;
@class PolkaMiniXScriptHash;
@class PolkaRpcReachability;
@class PolkaToken;
@class PolkaTransaction;
@class PolkaTx;
@class PolkaUtil;
@class PolkaXBTCToken;

@interface PolkaAccount : NSObject <goSeqRefInterface, BaseAccount, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithKeystore:(NSString* _Nullable)keystoreString password:(NSString* _Nullable)password network:(long)network;
- (nullable instancetype)initWithMnemonic:(NSString* _Nullable)mnemonic network:(long)network;
@property (nonatomic) long network;
/**
 * @return address string
 */
- (NSString* _Nonnull)address;
- (BOOL)checkPassword:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
/**
 * @return publicKey that will start with 0x.
 */
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (PolkaAccount* _Nullable)deriveAccountAt:(long)network error:(NSError* _Nullable* _Nullable)error;
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

@interface PolkaChain : NSObject <goSeqRefInterface, BaseChain> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * @param rpcUrl will be used to get metadata, query balance, estimate fee, send signed tx.
@param scanUrl will be used to query transaction details
 */
- (nullable instancetype)initWithRpc:(NSString* _Nullable)rpcUrl scanUrl:(NSString* _Nullable)scanUrl;
@property (nonatomic) NSString* _Nonnull rpcUrl;
@property (nonatomic) NSString* _Nonnull scanUrl;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)batchFetchTransactionStatus:(NSString* _Nullable)hashListString;
- (BaseOptionalString* _Nullable)estimateTransactionFee:(id<BaseTransaction> _Nullable)transaction error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)estimateTransactionFeeUsePublicKey:(id<BaseTransaction> _Nullable)transaction pubkey:(NSString* _Nullable)pubkey error:(NSError* _Nullable* _Nullable)error;
/**
 * 获取 mini 多签转账时需要的 scriptHash
@param transferTo 转账目标地址
@param amount 要转出的金额
 */
- (PolkaMiniXScriptHash* _Nullable)fetchScriptHashForMiniX:(NSString* _Nullable)transferTo amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (BaseTransactionDetail* _Nullable)fetchTransactionDetail:(NSString* _Nullable)hashString error:(NSError* _Nullable* _Nullable)error;
- (long)fetchTransactionStatus:(NSString* _Nullable)hashString;
/**
 * Get the metadata string of the chain (if not, it will be downloaded automatically)
 */
- (NSString* _Nonnull)getMetadataString:(NSError* _Nullable* _Nullable)error;
/**
 * 功能和 GetSignData 相同，不需要提供 nonce, version 等参数，但需要提供 chain 对象和地址
 */
- (NSData* _Nullable)getSignData:(PolkaTransaction* _Nullable)t walletAddress:(NSString* _Nullable)walletAddress error:(NSError* _Nullable* _Nullable)error;
- (PolkaTx* _Nullable)getTx:(NSError* _Nullable* _Nullable)error;
/**
 * Load cached metadata string.
This will save a lot of network traffic to download metadata from rpcUrl.
 */
- (BOOL)loadCachedMetadataString:(NSString* _Nullable)metadataString error:(NSError* _Nullable* _Nullable)error;
- (id<BaseToken> _Nullable)mainToken;
/**
 * Reload the latest metadata of this chain.
@return the latest metadata string
 */
- (NSString* _Nonnull)reloadMetadata:(NSError* _Nullable* _Nullable)error;
// skipped method Chain.RpcCall with unsupported parameter or return types

- (NSString* _Nonnull)sendRawTransaction:(NSString* _Nullable)signedTx error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)sendSignedTransaction:(id<BaseSignedTransaction> _Nullable)signedTxn error:(NSError* _Nullable* _Nullable)error;
/**
 * Note: Only chainx have XBTC token.
 */
- (PolkaXBTCToken* _Nullable)xbtcToken;
@end

@interface PolkaMiniXScriptHash : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull scriptHash;
@property (nonatomic) int32_t blockNumber;
@end

@interface PolkaRpcReachability : NSObject <goSeqRefInterface, BaseRpcReachability> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
/**
 * @return latency (ms) of rpc query blockNumber. -1 means the connection failed.
 */
- (BaseRpcLatency* _Nullable)latencyOf:(NSString* _Nullable)rpc timeout:(int64_t)timeout error:(NSError* _Nullable* _Nullable)error;
@end

@interface PolkaToken : NSObject <goSeqRefInterface, BaseToken> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(PolkaChain* _Nullable)chain;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (id<BaseTransaction> _Nullable)buildTransfer:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (id<BaseTransaction> _Nullable)buildTransferAll:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver error:(NSError* _Nullable* _Nullable)error;
- (BOOL)canTransferAll;
- (id<BaseChain> _Nullable)chain;
/**
 * Warning: polka chain is not currently supported
 */
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

@interface PolkaTransaction : NSObject <goSeqRefInterface, BaseTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
- (NSData* _Nullable)getSignData:(NSString* _Nullable)genesisHashString nonce:(int64_t)nonce specVersion:(int32_t)specVersion transVersion:(int32_t)transVersion error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)getTx:(NSData* _Nullable)signerPublicKey signatureData:(NSData* _Nullable)signatureData error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)getTxFromHex:(NSString* _Nullable)signerPublicKeyHex signatureDataHex:(NSString* _Nullable)signatureDataHex error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)getUnSignTx:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)signWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (id<BaseSignedTransaction> _Nullable)signedTransactionWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
@end

@interface PolkaTx : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(NSString* _Nullable)metadataString;
- (PolkaTransaction* _Nullable)newBalanceTransferTx:(NSString* _Nullable)dest amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (PolkaTransaction* _Nullable)newComingNftTransferTx:(NSString* _Nullable)dest cid:(int64_t)cid error:(NSError* _Nullable* _Nullable)error;
// skipped method Tx.NewExtrinsics with unsupported parameter or return types

- (PolkaTransaction* _Nullable)newThreshold:(NSString* _Nullable)thresholdPublicKey destAddress:(NSString* _Nullable)destAddress aggSignature:(NSString* _Nullable)aggSignature aggPublicKey:(NSString* _Nullable)aggPublicKey controlBlock:(NSString* _Nullable)controlBlock message:(NSString* _Nullable)message scriptHash:(NSString* _Nullable)scriptHash transferAmount:(NSString* _Nullable)transferAmount blockNumber:(int32_t)blockNumber error:(NSError* _Nullable* _Nullable)error;
- (PolkaTransaction* _Nullable)newTransactionFromHex:(NSString* _Nullable)txHex error:(NSError* _Nullable* _Nullable)error;
- (PolkaTransaction* _Nullable)newXAssetsTransferTx:(NSString* _Nullable)dest amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (PolkaTransaction* _Nullable)newXGatewayBitcoinCreateTaprootWithdrawTx:(NSString* _Nullable)ids transactionHex:(NSString* _Nullable)transactionHex error:(NSError* _Nullable* _Nullable)error;
@end

@interface PolkaUtil : NSObject <goSeqRefInterface, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithNetwork:(long)network;
@property (nonatomic) long network;
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

@interface PolkaXBTCToken : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
- (BaseBalance* _Nullable)balanceOfAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

@interface Polka : NSObject
+ (NSError* _Nullable) errAddress;
+ (void) setErrAddress:(NSError* _Nullable)v;

+ (NSError* _Nullable) errEncoded;
+ (void) setErrEncoded:(NSError* _Nullable)v;

+ (NSError* _Nullable) errEncryptedLength;
+ (void) setErrEncryptedLength:(NSError* _Nullable)v;

+ (NSError* _Nullable) errInvalidMnemonic;
+ (void) setErrInvalidMnemonic:(NSError* _Nullable)v;

+ (NSError* _Nullable) errInvalidParams;
+ (void) setErrInvalidParams:(NSError* _Nullable)v;

+ (NSError* _Nullable) errKeystore;
+ (void) setErrKeystore:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNilExtrinsic;
+ (void) setErrNilExtrinsic:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNilKey;
+ (void) setErrNilKey:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNilKeystore;
+ (void) setErrNilKeystore:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNilMetadata;
+ (void) setErrNilMetadata:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNilPassword;
+ (void) setErrNilPassword:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNilWallet;
+ (void) setErrNilWallet:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNoEncrypted;
+ (void) setErrNoEncrypted:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNoEncryptedData;
+ (void) setErrNoEncryptedData:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNoPublicKey;
+ (void) setErrNoPublicKey:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNonPkcs8;
+ (void) setErrNonPkcs8:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNotSigned;
+ (void) setErrNotSigned:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNumber;
+ (void) setErrNumber:(NSError* _Nullable)v;

+ (NSError* _Nullable) errPassword;
+ (void) setErrPassword:(NSError* _Nullable)v;

+ (NSError* _Nullable) errPkcs8Divider;
+ (void) setErrPkcs8Divider:(NSError* _Nullable)v;

+ (NSError* _Nullable) errPkcs8Header;
+ (void) setErrPkcs8Header:(NSError* _Nullable)v;

+ (NSError* _Nullable) errPublicKey;
+ (void) setErrPublicKey:(NSError* _Nullable)v;

+ (NSError* _Nullable) errSecretLength;
+ (void) setErrSecretLength:(NSError* _Nullable)v;

+ (NSError* _Nullable) errSeedOrPhrase;
+ (void) setErrSeedOrPhrase:(NSError* _Nullable)v;

+ (NSError* _Nullable) errSign;
+ (void) setErrSign:(NSError* _Nullable)v;

+ (NSError* _Nullable) errWrongMetadata;
+ (void) setErrWrongMetadata:(NSError* _Nullable)v;

@end

FOUNDATION_EXPORT PolkaAccount* _Nullable PolkaAccountWithPrivateKey(NSString* _Nullable prikey, long network, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT PolkaAccount* _Nullable PolkaAsPolkaAccount(id<BaseAccount> _Nullable account);

FOUNDATION_EXPORT NSString* _Nonnull PolkaByteToHex(NSData* _Nullable data);

FOUNDATION_EXPORT BOOL PolkaCheckKeystorePassword(NSString* _Nullable keystoreJson, NSString* _Nullable password, NSError* _Nullable* _Nullable error);

/**
 * @return publicKey that will start with 0x.
 */
FOUNDATION_EXPORT NSString* _Nonnull PolkaDecodeAddressToPublicKey(NSString* _Nullable address, NSError* _Nullable* _Nullable error);

/**
 * @param publicKey can start with 0x or not.
 */
FOUNDATION_EXPORT NSString* _Nonnull PolkaEncodePublicKeyToAddress(NSString* _Nullable publicKey, long network, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSData* _Nullable PolkaHexToByte(NSString* _Nullable hex, NSError* _Nullable* _Nullable error);

/**
 * @param chainnet chain name
 */
FOUNDATION_EXPORT BOOL PolkaIsValidAddress(NSString* _Nullable address);

FOUNDATION_EXPORT PolkaAccount* _Nullable PolkaNewAccountWithKeystore(NSString* _Nullable keystoreString, NSString* _Nullable password, long network, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT PolkaAccount* _Nullable PolkaNewAccountWithMnemonic(NSString* _Nullable mnemonic, long network, NSError* _Nullable* _Nullable error);

/**
 * @param rpcUrl will be used to get metadata, query balance, estimate fee, send signed tx.
@param scanUrl will be used to query transaction details
 */
FOUNDATION_EXPORT PolkaChain* _Nullable PolkaNewChainWithRpc(NSString* _Nullable rpcUrl, NSString* _Nullable scanUrl, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT PolkaRpcReachability* _Nullable PolkaNewRpcReachability(void);

FOUNDATION_EXPORT PolkaToken* _Nullable PolkaNewToken(PolkaChain* _Nullable chain);

FOUNDATION_EXPORT PolkaTx* _Nullable PolkaNewTx(NSString* _Nullable metadataString, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT PolkaUtil* _Nullable PolkaNewUtilWithNetwork(long network);

/**
 * Warning: initial unavailable, You must create based on Chain.XBTCToken()
 */
FOUNDATION_EXPORT PolkaToken* _Nullable PolkaNewXBTCToken(NSError* _Nullable* _Nullable error);

#endif