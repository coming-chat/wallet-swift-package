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
@class BtcBrc20CommitCustom;
@class BtcBrc20Inscription;
@class BtcBrc20InscriptionPage;
@class BtcBrc20MintTransaction;
@class BtcBrc20Token;
@class BtcBrc20TokenBalance;
@class BtcBrc20TokenBalancePage;
@class BtcBrc20TokenInfo;
@class BtcBrc20TransferTransaction;
@class BtcBrc20TransferableInscription;
@class BtcBrc20TransferableInscriptionPage;
@class BtcBrc20UTXO;
@class BtcBrc20UTXOArray;
@class BtcChain;
@class BtcFeeRate;
@class BtcNFTPage;
@class BtcPsbtTransaction;
@class BtcSignedPsbtTransaction;
@class BtcSignedTransaction;
@class BtcTransaction;
@class BtcTransactionDetail;
@class BtcTxOut;
@class BtcTxOutArray;
@class BtcUtil;

@interface BtcAccount : NSObject <goSeqRefInterface, BaseAccount, BaseAddressUtil> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithMnemonic:(NSString* _Nullable)mnemonic chainnet:(NSString* _Nullable)chainnet addressType:(long)addressType;
/**
 * @return default is the mainnet address
 */
- (NSString* _Nonnull)address;
- (long)addressType;
- (NSString* _Nonnull)addressTypeString;
- (BaseOptionalString* _Nullable)addressWithType:(long)addrType error:(NSError* _Nullable* _Nullable)error;
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
- (NSString* _Nonnull)multiSignaturePubKey;
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
 * SignMessage
https://developer.bitcoin.org/reference/rpc/signmessage.html
@param msg The message to create a signature of.
@return The signature of the message encoded in base64.
 */
- (BaseOptionalString* _Nullable)signMessage:(NSString* _Nullable)msg error:(NSError* _Nullable* _Nullable)error;
- (BtcSignedPsbtTransaction* _Nullable)signPsbt:(NSString* _Nullable)psbtHex error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)wifPrivateKeyString:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20CommitCustom : NSObject <goSeqRefInterface, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initJson:(NSString* _Nullable)json;
@property (nonatomic) NSString* _Nonnull baseTx;
@property (nonatomic) BtcBrc20UTXOArray* _Nullable utxos;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
- (BOOL)unmarshalJSON:(NSData* _Nullable)data error:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20Inscription : NSObject <goSeqRefInterface, BaseJsonable> {
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
- (BaseNFT* _Nullable)asNFT;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20InscriptionPage : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
// skipped field Brc20InscriptionPage.SdkPageable with unsupported type: *github.com/coming-chat/wallet-SDK/core/base/inter.SdkPageable[*github.com/coming-chat/wallet-SDK/core/btc.Brc20Inscription]

- (BtcNFTPage* _Nullable)asNFTPage;
- (long)currentCount;
- (NSString* _Nonnull)currentCursor;
- (BOOL)hasNextPage;
- (BtcBrc20Inscription* _Nullable)itemAt:(long)index;
- (NSString* _Nonnull)jsonString;
- (long)totalCount;
@end

@interface BtcBrc20MintTransaction : NSObject <goSeqRefInterface, BaseSignedTransaction, BaseTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)jsonStr;
@property (nonatomic) NSString* _Nonnull commit;
@property (nonatomic) BaseStringArray* _Nullable reveal;
@property (nonatomic) BaseStringArray* _Nullable inscription;
@property (nonatomic) BtcBrc20CommitCustom* _Nullable commitCustom;
@property (nonatomic) int64_t networkFee;
@property (nonatomic) int64_t satpointFee;
@property (nonatomic) int64_t serviceFee;
@property (nonatomic) int64_t commitFee;
@property (nonatomic) int64_t commitVsize;
- (BaseOptionalString* _Nullable)hexString:(NSError* _Nullable* _Nullable)error;
- (BOOL)isSigned;
- (BaseOptionalString* _Nullable)psbtHexString:(NSError* _Nullable* _Nullable)error;
/**
 * PublishWithChain
@return hash string
 */
- (BaseOptionalString* _Nullable)publishWithChain:(BtcChain* _Nullable)c error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)signWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (id<BaseSignedTransaction> _Nullable)signedTransactionWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20Token : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(NSString* _Nullable)ticker chainnet:(NSString* _Nullable)chainnet;
@property (nonatomic) NSString* _Nonnull ticker;
@property (nonatomic) NSString* _Nonnull chainnet;
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

@interface BtcBrc20TokenBalance : NSObject <goSeqRefInterface, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
@property (nonatomic) NSString* _Nonnull ticker;
@property (nonatomic) NSString* _Nonnull overallBalance;
@property (nonatomic) NSString* _Nonnull transferableBalance;
@property (nonatomic) NSString* _Nonnull availableBalance;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20TokenBalancePage : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
// skipped field Brc20TokenBalancePage.SdkPageable with unsupported type: *github.com/coming-chat/wallet-SDK/core/base/inter.SdkPageable[*github.com/coming-chat/wallet-SDK/core/btc.Brc20TokenBalance]

- (long)currentCount;
- (NSString* _Nonnull)currentCursor;
- (BOOL)hasNextPage;
- (BtcBrc20TokenBalance* _Nullable)itemAt:(long)index;
- (NSString* _Nonnull)jsonString;
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
@property (nonatomic) double price;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20TransferTransaction : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)jsonStr;
@property (nonatomic) NSString* _Nonnull transaction;
@property (nonatomic) int64_t networkFee;
@property (nonatomic) BtcBrc20CommitCustom* _Nullable commitCustom;
- (BtcPsbtTransaction* _Nullable)toPsbtTransaction:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20TransferableInscription : NSObject <goSeqRefInterface, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
@property (nonatomic) NSString* _Nonnull inscriptionId;
@property (nonatomic) int64_t inscriptionNumber;
@property (nonatomic) NSString* _Nonnull amount;
@property (nonatomic) NSString* _Nonnull ticker;
@property (nonatomic) BOOL unconfirmed;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcBrc20TransferableInscriptionPage : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
// skipped field Brc20TransferableInscriptionPage.SdkPageable with unsupported type: *github.com/coming-chat/wallet-SDK/core/base/inter.SdkPageable[*github.com/coming-chat/wallet-SDK/core/btc.Brc20TransferableInscription]

- (long)currentCount;
- (NSString* _Nonnull)currentCursor;
- (BOOL)hasNextPage;
- (BtcBrc20TransferableInscription* _Nullable)itemAt:(long)index;
- (NSString* _Nonnull)jsonString;
- (long)totalCount;
@end

@interface BtcBrc20UTXO : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(NSString* _Nullable)txid index:(int64_t)index;
@property (nonatomic) NSString* _Nonnull txid;
@property (nonatomic) int64_t index;
@end

@interface BtcBrc20UTXOArray : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
// skipped field Brc20UTXOArray.AnyArray with unsupported type: github.com/coming-chat/wallet-SDK/core/base/inter.AnyArray[*github.com/coming-chat/wallet-SDK/core/btc.Brc20UTXO]

- (void)append:(BtcBrc20UTXO* _Nullable)value;
- (long)count;
- (NSString* _Nonnull)jsonString;
- (NSData* _Nullable)marshalJSON:(NSError* _Nullable* _Nullable)error;
- (BtcBrc20UTXO* _Nullable)remove:(long)index;
- (void)setValue:(BtcBrc20UTXO* _Nullable)value index:(long)index;
- (BOOL)unmarshalJSON:(NSData* _Nullable)data error:(NSError* _Nullable* _Nullable)error;
- (BtcBrc20UTXO* _Nullable)valueAt:(long)index;
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
- (BtcBrc20MintTransaction* _Nullable)buildBrc20MintTransaction:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver op:(NSString* _Nullable)op ticker:(NSString* _Nullable)ticker amount:(NSString* _Nullable)amount feeRate:(int64_t)feeRate error:(NSError* _Nullable* _Nullable)error;
- (BtcBrc20MintTransaction* _Nullable)buildBrc20MintWithPostage:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver op:(NSString* _Nullable)op ticker:(NSString* _Nullable)ticker amount:(NSString* _Nullable)amount feeRate:(int64_t)feeRate postage:(int64_t)postage error:(NSError* _Nullable* _Nullable)error;
- (BtcBrc20TransferTransaction* _Nullable)buildBrc20TransferTransaction:(NSString* _Nullable)sender receiver:(NSString* _Nullable)receiver inscriptionIds:(BaseStringArray* _Nullable)inscriptionIds feeRate:(int64_t)feeRate opReturn:(NSString* _Nullable)opReturn error:(NSError* _Nullable* _Nullable)error;
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
- (BaseOptionalString* _Nullable)pushPsbt:(NSString* _Nullable)psbtHex error:(NSError* _Nullable* _Nullable)error;
- (BtcBrc20TokenBalance* _Nullable)queryBrc20Balance:(NSString* _Nullable)owner ticker:(NSString* _Nullable)ticker error:(NSError* _Nullable* _Nullable)error;
/**
 * Send the raw transaction on-chain
@return the hex hash string
 */
- (NSString* _Nonnull)sendRawTransaction:(NSString* _Nullable)signedTx error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)sendSignedTransaction:(id<BaseSignedTransaction> _Nullable)signedTxn error:(NSError* _Nullable* _Nullable)error;
- (BtcFeeRate* _Nullable)suggestFeeRate:(NSError* _Nullable* _Nullable)error;
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

@interface BtcNFTPage : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field NFTPage.SdkPageable with unsupported type: *github.com/coming-chat/wallet-SDK/core/base/inter.SdkPageable[*github.com/coming-chat/wallet-SDK/core/base.NFT]

- (long)currentCount;
- (NSString* _Nonnull)currentCursor;
- (BOOL)hasNextPage;
- (BaseNFT* _Nullable)itemAt:(long)index;
- (NSString* _Nonnull)jsonString;
- (long)totalCount;
@end

@interface BtcPsbtTransaction : NSObject <goSeqRefInterface, BaseTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(NSString* _Nullable)psbtString;
// skipped field PsbtTransaction.Packet with unsupported type: github.com/btcsuite/btcd/btcutil/psbt.Packet

- (BaseOptionalString* _Nullable)signWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (id<BaseSignedTransaction> _Nullable)signedTransactionWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcSignedPsbtTransaction : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field SignedPsbtTransaction.Packet with unsupported type: github.com/btcsuite/btcd/btcutil/psbt.Packet

- (BaseOptionalString* _Nullable)hexString:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)psbtHexString:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)publishWithChain:(BtcChain* _Nullable)c error:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcSignedTransaction : NSObject <goSeqRefInterface, BaseSignedTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
- (BaseOptionalString* _Nullable)hexString:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcTransaction : NSObject <goSeqRefInterface, BaseTransaction> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(NSString* _Nullable)chainnet;
- (BOOL)addInput:(NSString* _Nullable)txId index:(int64_t)index address:(NSString* _Nullable)address value:(int64_t)value error:(NSError* _Nullable* _Nullable)error;
- (BOOL)addInput2:(NSString* _Nullable)txId index:(int64_t)index prevTx:(NSString* _Nullable)prevTx error:(NSError* _Nullable* _Nullable)error;
- (BOOL)addOpReturn:(NSString* _Nullable)opReturn error:(NSError* _Nullable* _Nullable)error;
/**
 * If the value is 0, `AddOpReturn` will be called.
 */
- (BOOL)addOutput:(NSString* _Nullable)address value:(int64_t)value error:(NSError* _Nullable* _Nullable)error;
- (int64_t)estimateTransactionSize;
- (BaseOptionalString* _Nullable)signWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (id<BaseSignedTransaction> _Nullable)signedTransactionWithAccount:(id<BaseAccount> _Nullable)account error:(NSError* _Nullable* _Nullable)error;
- (int64_t)totalInputValue;
- (int64_t)totalOutputValue;
@end

@interface BtcTransactionDetail : NSObject <goSeqRefInterface, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) int64_t totalCost;
@property (nonatomic) int64_t networkFee;
@property (nonatomic) double feeRate;
@property (nonatomic) BtcTxOutArray* _Nullable inputs;
@property (nonatomic) BtcTxOutArray* _Nullable outputs;
- (NSString* _Nonnull)desc;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface BtcTxOut : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull hash;
@property (nonatomic) int64_t index;
@property (nonatomic) int64_t value;
@property (nonatomic) NSString* _Nonnull address;
@end

@interface BtcTxOutArray : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field TxOutArray.AnyArray with unsupported type: github.com/coming-chat/wallet-SDK/core/base/inter.AnyArray[*github.com/coming-chat/wallet-SDK/core/btc.TxOut]

- (void)append:(BtcTxOut* _Nullable)value;
- (long)count;
- (NSString* _Nonnull)jsonString;
- (NSData* _Nullable)marshalJSON:(NSError* _Nullable* _Nullable)error;
- (BtcTxOut* _Nullable)remove:(long)index;
- (void)setValue:(BtcTxOut* _Nullable)value index:(long)index;
- (BOOL)unmarshalJSON:(NSData* _Nullable)data error:(NSError* _Nullable* _Nullable)error;
- (BtcTxOut* _Nullable)valueAt:(long)index;
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
FOUNDATION_EXPORT const int64_t BtcMaxOpReturnLength;

@interface Btc : NSObject
+ (NSError* _Nullable) errDecodeAddress;
+ (void) setErrDecodeAddress:(NSError* _Nullable)v;

+ (NSError* _Nullable) errHttpResponseParse;
+ (void) setErrHttpResponseParse:(NSError* _Nullable)v;

+ (NSError* _Nullable) errPsbtEncode;
+ (void) setErrPsbtEncode:(NSError* _Nullable)v;

+ (NSError* _Nullable) errPsbtUnsupportedAccountType;
+ (void) setErrPsbtUnsupportedAccountType:(NSError* _Nullable)v;

+ (NSError* _Nullable) errTransactionNotSigned;
+ (void) setErrTransactionNotSigned:(NSError* _Nullable)v;

+ (NSError* _Nullable) errUnsupportedChain;
+ (void) setErrUnsupportedChain:(NSError* _Nullable)v;

@end

FOUNDATION_EXPORT BtcAccount* _Nullable BtcAccountWithPrivateKey(NSString* _Nullable prikey, NSString* _Nullable chainnet, long addressType, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSString* _Nonnull BtcAddressTypeDerivePath(long t);

FOUNDATION_EXPORT NSString* _Nonnull BtcAddressTypeDescription(long t);

FOUNDATION_EXPORT BtcAccount* _Nullable BtcAsBitcoinAccount(id<BaseAccount> _Nullable account);

/**
 * BatchQueryBalance
@return If any address is successfully queried, it will return normally, and the amount of failed request is 0
@throw error if all address query balance failed
 */
FOUNDATION_EXPORT BaseStringMap* _Nullable BtcBatchQueryBalance(BaseStringArray* _Nullable addresses, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

// skipped function ComingPrivateKey with unsupported parameter or return types


FOUNDATION_EXPORT BtcTransactionDetail* _Nullable BtcDecodePsbtTransactionDetail(NSString* _Nullable psbtHex, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

// skipped function DecodePsbtTxToPacket with unsupported parameter or return types


// skipped function DecodeTx with unsupported parameter or return types


FOUNDATION_EXPORT BtcTransactionDetail* _Nullable BtcDecodeTxHexTransactionDetail(NSString* _Nullable txHex, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

// skipped function Derivation with unsupported parameter or return types


// skipped function EncodeAddressComingTaproot with unsupported parameter or return types


// skipped function EncodeAddressLegacy with unsupported parameter or return types


// skipped function EncodeAddressNativeSegwit with unsupported parameter or return types


// skipped function EncodeAddressNestedSegwit with unsupported parameter or return types


// skipped function EncodeAddressTaproot with unsupported parameter or return types


// skipped function EncodePubKeyToAddress with unsupported parameter or return types


FOUNDATION_EXPORT NSString* _Nonnull BtcEncodePublicDataToAddress(NSData* _Nullable pubKey, NSString* _Nullable chainnet, long addressType, NSError* _Nullable* _Nullable error);

/**
 * @param publicKey can start with 0x or not.
 */
FOUNDATION_EXPORT NSString* _Nonnull BtcEncodePublicKeyToAddress(NSString* _Nullable publicKey, NSString* _Nullable chainnet, long addressType, NSError* _Nullable* _Nullable error);

// skipped function EnsurePsbtFinalize with unsupported parameter or return types


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

FOUNDATION_EXPORT BtcAccount* _Nullable BtcNewAccountWithMnemonic(NSString* _Nullable mnemonic, NSString* _Nullable chainnet, long addressType, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20CommitCustom* _Nullable BtcNewBrc20CommitCustomJson(NSString* _Nullable json);

FOUNDATION_EXPORT BtcBrc20InscriptionPage* _Nullable BtcNewBrc20InscriptionPageWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20Inscription* _Nullable BtcNewBrc20InscriptionWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20MintTransaction* _Nullable BtcNewBrc20MintTransactionWithJsonString(NSString* _Nullable jsonStr, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20Token* _Nullable BtcNewBrc20Token(NSString* _Nullable ticker, NSString* _Nullable chainnet);

FOUNDATION_EXPORT BtcBrc20TokenBalancePage* _Nullable BtcNewBrc20TokenBalancePageWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20TokenBalance* _Nullable BtcNewBrc20TokenBalanceWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20TokenInfo* _Nullable BtcNewBrc20TokenInfoWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20TransferTransaction* _Nullable BtcNewBrc20TransferTransaction(void);

FOUNDATION_EXPORT BtcBrc20TransferTransaction* _Nullable BtcNewBrc20TransferTransactionWithJsonString(NSString* _Nullable jsonStr, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20TransferableInscriptionPage* _Nullable BtcNewBrc20TransferableInscriptionPageWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20TransferableInscription* _Nullable BtcNewBrc20TransferableInscriptionWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcBrc20UTXO* _Nullable BtcNewBrc20UTXO(NSString* _Nullable txid, int64_t index);

FOUNDATION_EXPORT BtcBrc20UTXOArray* _Nullable BtcNewBrc20UTXOArray(void);

FOUNDATION_EXPORT BtcChain* _Nullable BtcNewChainWithChainnet(NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcPsbtTransaction* _Nullable BtcNewPsbtTransaction(NSString* _Nullable psbtString, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcTransaction* _Nullable BtcNewTransaction(NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BtcUtil* _Nullable BtcNewUtilWithChainnet(NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSData* _Nullable BtcPayToPubKeyHashScript(NSData* _Nullable pubKeyHash, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSData* _Nullable BtcPayToWitnessPubKeyHashScript(NSData* _Nullable pubKeyHash, NSError* _Nullable* _Nullable error);

// skipped function PrivateKeyToWIF with unsupported parameter or return types


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

// skipped function Sign with unsupported parameter or return types


// skipped function SignPSBTTx with unsupported parameter or return types


FOUNDATION_EXPORT BOOL BtcVerifySignature(NSString* _Nullable pubkey, NSString* _Nullable message, NSString* _Nullable signature);

#endif
