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
@class BtcBrc20Inscription;
@class BtcBrc20InscriptionPage;
@class BtcBrc20Token;
@class BtcBrc20TokenBalance;
@class BtcBrc20TokenBalancePage;
@class BtcBrc20TokenInfo;
@class BtcBrc20TransferableInscription;
@class BtcBrc20TransferableInscriptionPage;
@class BtcChain;
@class BtcFeeRate;
@class BtcNFTPage;
@class BtcStringMap;
@class BtcUtil;

@interface BtcAccount : NSObject <goSeqRefInterface, BaseAccount, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithMnemonic:(NSString* _Nullable)mnemonic chainnet:(NSString* _Nullable)chainnet;
/**
 * Default is `AddressTypeComingTaproot`
 */
@property (nonatomic) long addressType;
/**
 * @return default is the mainnet address
 */
- (NSString* _Nonnull)address;
- (NSString* _Nonnull)addressTypeString;
- (BaseOptionalString* _Nullable)addressWithType:(long)addrType error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)comingTaprootAddress:(NSError* _Nullable* _Nullable)error;
/**
 * @return publicKey that will start with 0x.
 */
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BtcAccount* _Nullable)deriveAccountAt:(NSString* _Nullable)chainnet error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)derivePath;
/**
 * @param publicKey can start with 0x or not.
 */
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BOOL)isValidAddress:(NSString* _Nullable)address;
/**
 * LegacyAddress P2PKH just for m/44'/
 */
- (BaseOptionalString* _Nullable)legacyAddress:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)multiSignaturePubKey;
/**
 * NativeSegwitAddress P2WPKH just for m/84'/
 */
- (BaseOptionalString* _Nullable)nativeSegwitAddress:(NSError* _Nullable* _Nullable)error;
/**
 * NestedSegwitAddress P2SH-P2WPKH just for m/49'/
 */
- (BaseOptionalString* _Nullable)nestedSegwitAddress:(NSError* _Nullable* _Nullable)error;
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
/**
 * TaprootAddress P2TR just for m/86'/
 */
- (BaseOptionalString* _Nullable)taprootAddress:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20Inscription : NSObject <goSeqRefInterface, BaseAniable, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
@property (nonatomic) NSString* _Nonnull inscriptionId;
@property (nonatomic) int64_t inscriptionNumber;
@property (nonatomic) NSString* _Nonnull address;
@property (nonatomic) int64_t outputValue;
@property (nonatomic) NSString* _Nonnull preview;
@property (nonatomic) NSString* _Nonnull content;
@property (nonatomic) int64_t contentLength;
@property (nonatomic) NSString* _Nonnull contentType;
@property (nonatomic) NSString* _Nonnull contentBody;
@property (nonatomic) int64_t timestamp;
@property (nonatomic) NSString* _Nonnull genesisTransaction;
@property (nonatomic) NSString* _Nonnull location;
@property (nonatomic) NSString* _Nonnull output;
/**
 * only has value if the content type starts with 'text/'
 */
@property (nonatomic) NSString* _Nonnull contentText;
- (BaseAny* _Nullable)asAny;
- (BaseNFT* _Nullable)asNFT;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20InscriptionPage : NSObject <goSeqRefInterface, BaseJsonable, BasePageable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
// skipped field Brc20InscriptionPage.SdkPageable with unsupported type: *github.com/coming-chat/wallet-SDK/core/base/inter.SdkPageable[*github.com/coming-chat/wallet-SDK/core/btc.Brc20Inscription]

- (BtcNFTPage* _Nullable)asNFTPage;
- (long)currentCount;
- (NSString* _Nonnull)currentCursor;
- (BOOL)hasNextPage;
- (BaseAnyArray* _Nullable)itemArray;
- (BtcBrc20Inscription* _Nullable)itemAt:(long)index;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
- (long)totalCount;
@end

@interface BtcBrc20Token : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(NSString* _Nullable)ticker;
@property (nonatomic) NSString* _Nonnull ticker;
// skipped method Brc20Token.BalanceOfAccount with unsupported parameter or return types

- (BaseBalance* _Nullable)balanceOfAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BaseBalance* _Nullable)balanceOfPublicKey:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (id<BaseTransaction> _Nullable)buildTransfer:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (id<BaseTransaction> _Nullable)buildTransferAll:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver error:(NSError* _Nullable* _Nullable)error;
/**
 * Before invoking this method, it is best to check `CanTransferAll()`
 */
- (BOOL)canTransferAll;
- (id<BaseChain> _Nullable)chain;
- (BtcBrc20TokenInfo* _Nullable)fullTokenInfo:(NSError* _Nullable* _Nullable)error;
- (BaseTokenInfo* _Nullable)tokenInfo:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20TokenBalance : NSObject <goSeqRefInterface, BaseAniable, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
@property (nonatomic) NSString* _Nonnull ticker;
@property (nonatomic) NSString* _Nonnull overallBalance;
@property (nonatomic) NSString* _Nonnull transferableBalance;
@property (nonatomic) NSString* _Nonnull availableBalance;
- (BaseAny* _Nullable)asAny;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20TokenBalancePage : NSObject <goSeqRefInterface, BaseJsonable, BasePageable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
// skipped field Brc20TokenBalancePage.SdkPageable with unsupported type: *github.com/coming-chat/wallet-SDK/core/base/inter.SdkPageable[*github.com/coming-chat/wallet-SDK/core/btc.Brc20TokenBalance]

- (long)currentCount;
- (NSString* _Nonnull)currentCursor;
- (BOOL)hasNextPage;
- (BaseAnyArray* _Nullable)itemArray;
- (BtcBrc20TokenBalance* _Nullable)itemAt:(long)index;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
- (long)totalCount;
@end

@interface BtcBrc20TokenInfo : NSObject <goSeqRefInterface, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
@property (nonatomic) NSString* _Nonnull ticker;
@property (nonatomic) int64_t holdersCount;
@property (nonatomic) int64_t historyCount;
@property (nonatomic) int64_t inscriptionNumber;
@property (nonatomic) NSString* _Nonnull inscriptionId;
@property (nonatomic) NSString* _Nonnull max;
@property (nonatomic) NSString* _Nonnull limit;
@property (nonatomic) NSString* _Nonnull minted;
@property (nonatomic) NSString* _Nonnull totalMinted;
@property (nonatomic) NSString* _Nonnull confirmedMinted;
@property (nonatomic) NSString* _Nonnull confirmedMinted1h;
@property (nonatomic) NSString* _Nonnull confirmedMinted24h;
@property (nonatomic) int64_t mintTimes;
@property (nonatomic) int16_t decimal;
@property (nonatomic) NSString* _Nonnull creator;
@property (nonatomic) NSString* _Nonnull txid;
@property (nonatomic) int64_t deployHeight;
@property (nonatomic) int64_t deployBlocktime;
@property (nonatomic) int64_t completeHeight;
@property (nonatomic) int64_t completeBlocktime;
@property (nonatomic) int64_t inscriptionNumberStart;
@property (nonatomic) int64_t inscriptionNumberEnd;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20TransferableInscription : NSObject <goSeqRefInterface, BaseAniable, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
@property (nonatomic) NSString* _Nonnull inscriptionId;
@property (nonatomic) int64_t inscriptionNumber;
@property (nonatomic) NSString* _Nonnull amount;
@property (nonatomic) NSString* _Nonnull ticker;
@property (nonatomic) BOOL unconfirmed;
- (BaseAny* _Nullable)asAny;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20TransferableInscriptionPage : NSObject <goSeqRefInterface, BaseJsonable, BasePageable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
// skipped field Brc20TransferableInscriptionPage.SdkPageable with unsupported type: *github.com/coming-chat/wallet-SDK/core/base/inter.SdkPageable[*github.com/coming-chat/wallet-SDK/core/btc.Brc20TransferableInscription]

- (long)currentCount;
- (NSString* _Nonnull)currentCursor;
- (BOOL)hasNextPage;
- (BaseAnyArray* _Nullable)itemArray;
- (BtcBrc20TransferableInscription* _Nullable)itemAt:(long)index;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
- (long)totalCount;
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
- (id<BaseTransaction> _Nullable)buildTransfer:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver amount:(NSString* _Nullable)amount error:(NSError* _Nullable* _Nullable)error;
- (id<BaseTransaction> _Nullable)buildTransferAll:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver error:(NSError* _Nullable* _Nullable)error;
- (BOOL)canTransferAll;
- (id<BaseChain> _Nullable)chain;
- (NSString* _Nonnull)decodeAddressToPublicKey:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)encodePublicDataToAddress:(NSData* _Nullable)public error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)encodePublicKeyToAddress:(NSString* _Nullable)publicKey error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)estimateTransactionFee:(id<BaseTransaction> _Nullable)transaction error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)estimateTransactionFeeUsePublicKey:(id<BaseTransaction> _Nullable)transaction pubkey:(NSString* _Nullable)pubkey error:(NSError* _Nullable* _Nullable)error;
- (BtcBrc20InscriptionPage* _Nullable)fetchBrc20Inscription:(NSString* _Nullable)owner cursor:(NSString* _Nullable)cursor pageSize:(long)pageSize error:(NSError* _Nullable* _Nullable)error;
- (BtcBrc20TokenBalancePage* _Nullable)fetchBrc20TokenBalance:(NSString* _Nullable)owner cursor:(NSString* _Nullable)cursor pageSize:(long)pageSize error:(NSError* _Nullable* _Nullable)error;
- (BtcBrc20TransferableInscriptionPage* _Nullable)fetchBrc20TransferableInscription:(NSString* _Nullable)owner ticker:(NSString* _Nullable)ticker error:(NSError* _Nullable* _Nullable)error;
/**
 * Fetch transaction details through transaction hash
Note: The input parsing of bitcoin is very complex and the network cost is relatively high,
So only the status and timestamp can be queried.
 */
- (BaseTransactionDetail* _Nullable)fetchTransactionDetail:(NSString* _Nullable)hash error:(NSError* _Nullable* _Nullable)error;
- (long)fetchTransactionStatus:(NSString* _Nullable)hash;
- (BOOL)isValidAddress:(NSString* _Nullable)address;
- (id<BaseToken> _Nullable)mainToken;
- (BtcBrc20TokenBalance* _Nullable)queryBrc20Balance:(NSString* _Nullable)owner ticker:(NSString* _Nullable)ticker error:(NSError* _Nullable* _Nullable)error;
/**
 * Send the raw transaction on-chain
@return the hex hash string
 */
- (NSString* _Nonnull)sendRawTransaction:(NSString* _Nullable)signedTx error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)sendSignedTransaction:(id<BaseSignedTransaction> _Nullable)signedTxn error:(NSError* _Nullable* _Nullable)error;
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

@interface BtcNFTPage : NSObject <goSeqRefInterface, BaseJsonable, BasePageable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field NFTPage.SdkPageable with unsupported type: *github.com/coming-chat/wallet-SDK/core/base/inter.SdkPageable[*github.com/coming-chat/wallet-SDK/core/base.NFT]

- (long)currentCount;
- (NSString* _Nonnull)currentCursor;
- (BOOL)hasNextPage;
- (BaseAnyArray* _Nullable)itemArray;
- (BaseNFT* _Nullable)itemAt:(long)index;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
- (long)totalCount;
@end

@interface BtcStringMap : NSObject <goSeqRefInterface, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
// skipped field StringMap.AnyMap with unsupported type: github.com/coming-chat/wallet-SDK/core/base/inter.AnyMap[string]

- (BOOL)hasKey:(NSString* _Nullable)key;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
- (BaseStringArray* _Nullable)keys;
- (NSData* _Nullable)marshalJSON:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)remove:(NSString* _Nullable)key;
- (void)setValue:(NSString* _Nullable)value key:(NSString* _Nullable)key;
- (NSString* _Nonnull)string;
- (BOOL)unmarshalJSON:(NSData* _Nullable)data error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)valueOf:(NSString* _Nullable)key;
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

FOUNDATION_EXPORT const long BtcAddressTypeComingTaproot;
FOUNDATION_EXPORT const long BtcAddressTypeLegacy;
FOUNDATION_EXPORT const long BtcAddressTypeNativeSegwit;
FOUNDATION_EXPORT const long BtcAddressTypeNestedSegwit;
FOUNDATION_EXPORT const long BtcAddressTypeTaproot;
/**
 * ComingChat used, similar mainnet's alias.
 */
FOUNDATION_EXPORT NSString* _Nonnull const BtcChainBitcoin;
FOUNDATION_EXPORT NSString* _Nonnull const BtcChainMainnet;
FOUNDATION_EXPORT NSString* _Nonnull const BtcChainSignet;
FOUNDATION_EXPORT NSString* _Nonnull const BtcChainTestnet;

@interface Btc : NSObject
+ (NSError* _Nullable) errDecodeAddress;
+ (void) setErrDecodeAddress:(NSError* _Nullable)v;

+ (NSError* _Nullable) errHttpResponseParse;
+ (void) setErrHttpResponseParse:(NSError* _Nullable)v;

+ (NSError* _Nullable) errPsbtEncode;
+ (void) setErrPsbtEncode:(NSError* _Nullable)v;

+ (NSError* _Nullable) errPsbtUnsupportedAccountType;
+ (void) setErrPsbtUnsupportedAccountType:(NSError* _Nullable)v;

+ (NSError* _Nullable) errUnsupportedChain;
+ (void) setErrUnsupportedChain:(NSError* _Nullable)v;

@end

FOUNDATION_EXPORT BtcAccount* _Nullable BtcAccountWithPrivateKey(NSString* _Nullable prikey, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcAccount* _Nullable BtcAsBitcoinAccount(id<BaseAccount> _Nullable account);

FOUNDATION_EXPORT BtcBrc20Inscription* _Nullable BtcAsBrc20Inscription(BaseAny* _Nullable a);

FOUNDATION_EXPORT BtcBrc20TokenBalance* _Nullable BtcAsBrc20TokenBalance(BaseAny* _Nullable a);

FOUNDATION_EXPORT BtcBrc20TransferableInscription* _Nullable BtcAsBrc20TransferableInscription(BaseAny* _Nullable a);

/**
 * BatchQueryBalance
@return If any address is successfully queried, it will return normally, and the amount of failed request is 0
@throw error if all address query balance failed
 */
FOUNDATION_EXPORT BtcStringMap* _Nullable BtcBatchQueryBalance(BaseStringArray* _Nullable addresses, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

// skipped function DecodePsbtTxToPacket with unsupported parameter or return types


// skipped function DecodeTx with unsupported parameter or return types


FOUNDATION_EXPORT NSString* _Nonnull BtcEncodePublicDataToAddress(NSData* _Nullable public, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

/**
 * @param publicKey can start with 0x or not.
 */
FOUNDATION_EXPORT NSString* _Nonnull BtcEncodePublicKeyToAddress(NSString* _Nullable publicKey, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

// skipped function ExtractPsbtToMsgTx with unsupported parameter or return types


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

FOUNDATION_EXPORT BOOL BtcIsValidPrivateKey(NSString* _Nullable prikey);

FOUNDATION_EXPORT BtcAccount* _Nullable BtcNewAccountWithMnemonic(NSString* _Nullable mnemonic, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20InscriptionPage* _Nullable BtcNewBrc20InscriptionPageWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20Inscription* _Nullable BtcNewBrc20InscriptionWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20Token* _Nullable BtcNewBrc20Token(NSString* _Nullable ticker);

FOUNDATION_EXPORT BtcBrc20TokenBalancePage* _Nullable BtcNewBrc20TokenBalancePageWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20TokenBalance* _Nullable BtcNewBrc20TokenBalanceWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20TokenInfo* _Nullable BtcNewBrc20TokenInfoWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20TransferableInscriptionPage* _Nullable BtcNewBrc20TransferableInscriptionPageWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20TransferableInscription* _Nullable BtcNewBrc20TransferableInscriptionWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcChain* _Nullable BtcNewChainWithChainnet(NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcStringMap* _Nullable BtcNewStringMap(void);

FOUNDATION_EXPORT BtcUtil* _Nullable BtcNewUtilWithChainnet(NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

// skipped function PsbtPacketToMsgTx with unsupported parameter or return types


/**
 * PublicKeyTransform
@param pubkey the original public key, can be uncompressed, compressed, or hybrid
@param compress the transformed public key should be compressed or not
 */
FOUNDATION_EXPORT NSString* _Nonnull BtcPublicKeyTransform(NSString* _Nullable pubkey, BOOL compress, NSError* _Nullable* _Nullable error);

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

// skipped function SignPSBTTx with unsupported parameter or return types


FOUNDATION_EXPORT BtcFeeRate* _Nullable BtcSuggestFeeRate(NSError* _Nullable* _Nullable error);

#endif
