// Objective-C API for talking to github.com/coming-chat/wallet-SDK/core/wallet Go package.
//   gobind -lang=objc github.com/coming-chat/wallet-SDK/core/wallet
//
// File is generated by gobind. Do not edit.

#ifndef __Wallet_H__
#define __Wallet_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

#include "Base.objc.h"
#include "Aptos.objc.h"
#include "Btc.objc.h"
#include "Cosmos.objc.h"
#include "Doge.objc.h"
#include "Eth.objc.h"
#include "Polka.objc.h"
#include "Solana.objc.h"
#include "Starcoin.objc.h"
#include "Sui.objc.h"

@class WalletAccountCache;
@class WalletAccountInfo;
@class WalletWallet;
@class WalletWatchAccount;

/**
 * 旧的钱包对象在内存里面会缓存 **助记词**，还有很多链的账号 **私钥**，这是比较危险的，可能会有用户钱包被盗的风险
因此 SDK 里面不能缓存 **助记词** 、**私钥** 、还有 **keystore 密码**
也建议客户端每次使用完带有私钥的账号后，不要缓存这些账号，而是销毁它们

考虑到每次都导入助记词生成账号，而仅仅是为了获取账号地址或者公钥，可能会影响钱包的性能和体验
因此这里会提供一个可以缓存 *账号地址* 和 *公钥* 这种不敏感信息的工具
 */
@interface WalletAccountCache : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
// skipped field AccountCache.Store with unsupported type: sync.Map

- (void)clean;
- (void)delete:(NSString* _Nullable)key;
- (WalletAccountInfo* _Nullable)get:(NSString* _Nullable)key;
- (WalletAccountInfo* _Nullable)getAccountInfo:(NSString* _Nullable)walletName chainName:(NSString* _Nullable)chainName;
- (void)save:(NSString* _Nullable)key info:(WalletAccountInfo* _Nullable)info;
/**
 * 缓存账号信息，该账号的私钥不会被缓存
 */
- (void)saveAccount:(NSString* _Nullable)walletName chainName:(NSString* _Nullable)chainName account:(id<BaseAccount> _Nullable)account;
- (void)saveAccountInfo:(NSString* _Nullable)walletName chainName:(NSString* _Nullable)chainName info:(WalletAccountInfo* _Nullable)info;
@end

@interface WalletAccountInfo : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSData* _Nullable publicKey;
@property (nonatomic) NSString* _Nonnull address;
@property (nonatomic) NSString* _Nonnull chain;
- (NSString* _Nonnull)publicKeyHex;
@end

/**
 * Deprecated: 这个钱包对象缓存了助记词、密码、私钥等信息，继续使用有泄露资产的风险 ⚠️
 */
@interface WalletWallet : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * Only support Polka keystore.
 */
- (nullable instancetype)initWithKeyStore:(NSString* _Nullable)keyStoreJson password:(NSString* _Nullable)password;
- (nullable instancetype)initWithMnemonic:(NSString* _Nullable)mnemonic;
- (nullable instancetype)initWithWatchAddress:(NSString* _Nullable)address;
@property (nonatomic) NSString* _Nonnull mnemonic;
@property (nonatomic) NSString* _Nonnull keystore;
@property (nonatomic) NSString* _Nonnull address;
/**
 * check keystore password
 */
- (BOOL)checkPassword:(NSString* _Nullable)password ret0_:(BOOL* _Nullable)ret0_ error:(NSError* _Nullable* _Nullable)error;
/**
 * Deprecated: GetAddress is deprecated. Please use wallet.PolkaAccount(network).Address() instead
 */
- (NSString* _Nonnull)getAddress:(long)network error:(NSError* _Nullable* _Nullable)error;
/**
 * Get or create the aptos account.
 */
- (AptosAccount* _Nullable)getOrCreateAptosAccount:(NSError* _Nullable* _Nullable)error;
/**
 * Get or create the bitcoin account with specified chainnet.
 */
- (BtcAccount* _Nullable)getOrCreateBitcoinAccount:(NSString* _Nullable)chainnet error:(NSError* _Nullable* _Nullable)error;
/**
 * Get or create cosmos chain account
 */
- (CosmosAccount* _Nullable)getOrCreateCosmosAccount:(NSError* _Nullable* _Nullable)error;
/**
 * Get or create a wallet account based on cosmos architecture.
 */
- (CosmosAccount* _Nullable)getOrCreateCosmosTypeAccount:(int64_t)cointype addressPrefix:(NSString* _Nullable)addressPrefix error:(NSError* _Nullable* _Nullable)error;
- (DogeAccount* _Nullable)getOrCreateDogeAccount:(NSString* _Nullable)chainnet error:(NSError* _Nullable* _Nullable)error;
/**
 * Get or create the ethereum account.
 */
- (EthAccount* _Nullable)getOrCreateEthereumAccount:(NSError* _Nullable* _Nullable)error;
/**
 * Get or create the polka account with specified network.
 */
- (PolkaAccount* _Nullable)getOrCreatePolkaAccount:(long)network error:(NSError* _Nullable* _Nullable)error;
/**
 * Get or create the solana account.
 */
- (SolanaAccount* _Nullable)getOrCreateSolanaAccount:(NSError* _Nullable* _Nullable)error;
/**
 * Get or create the starcoin account.
 */
- (StarcoinAccount* _Nullable)getOrCreateStarcoinAccount:(NSError* _Nullable* _Nullable)error;
/**
 * Get or create the sui account.
 */
- (SuiAccount* _Nullable)getOrCreateSuiAccount:(NSError* _Nullable* _Nullable)error;
/**
 * Deprecated: GetPrivateKeyHex is deprecated. Please use wallet.PolkaAccount(network).PrivateKey() instead
 */
- (NSString* _Nonnull)getPrivateKeyHex:(NSError* _Nullable* _Nullable)error;
/**
 * Deprecated: GetPublicKey is deprecated. Please use wallet.PolkaAccount(network).PublicKey() instead
 */
- (NSData* _Nullable)getPublicKey:(NSError* _Nullable* _Nullable)error;
/**
 * Deprecated: GetPublicKeyHex is deprecated. Please use wallet.PolkaAccount(network).PublicKey() instead
 */
- (NSString* _Nonnull)getPublicKeyHex:(NSError* _Nullable* _Nullable)error;
- (WalletWatchAccount* _Nullable)getWatchWallet;
- (BOOL)isKeystoreWallet;
- (BOOL)isMnemonicWallet;
- (BOOL)isWatchWallet;
/**
 * Deprecated: Sign is deprecated. Please use wallet.PolkaAccount(network).Sign() instead
 */
- (NSData* _Nullable)sign:(NSData* _Nullable)message password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
/**
 * Deprecated: SignFromHex is deprecated. Please use wallet.PolkaAccount(network).SignHex() instead
 */
- (NSData* _Nullable)signFromHex:(NSString* _Nullable)messageHex password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
@end

@interface WalletWatchAccount : NSObject <goSeqRefInterface, BaseAccount> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
- (NSString* _Nonnull)address;
- (NSData* _Nullable)privateKey:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)privateKeyHex:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)publicKey;
- (NSString* _Nonnull)publicKeyHex;
- (NSData* _Nullable)sign:(NSData* _Nullable)message password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)signHex:(NSString* _Nullable)messageHex password:(NSString* _Nullable)password error:(NSError* _Nullable* _Nullable)error;
@end

FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeBitcoin;
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeCosmos;
/**
 * contains ethereum, bsc, chainx_eth, polygon...
 */
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeEthereum;
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeSolana;

@interface Wallet : NSObject
+ (NSError* _Nullable) errInvalidMnemonic;
+ (void) setErrInvalidMnemonic:(NSError* _Nullable)v;

@end

FOUNDATION_EXPORT NSString* _Nonnull WalletByteToHex(NSData* _Nullable data);

FOUNDATION_EXPORT BaseStringArray* _Nullable WalletChainTypeFrom(NSString* _Nullable address);

FOUNDATION_EXPORT NSString* _Nonnull WalletGenMnemonic(NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSData* _Nullable WalletHexToByte(NSString* _Nullable hex, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BOOL WalletIsValidMnemonic(NSString* _Nullable mnemonic);

FOUNDATION_EXPORT WalletAccountCache* _Nullable WalletNewAccountCache(void);

/**
 * Only support Polka keystore.
 */
FOUNDATION_EXPORT WalletWallet* _Nullable WalletNewWalletWithKeyStore(NSString* _Nullable keyStoreJson, NSString* _Nullable password, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT WalletWallet* _Nullable WalletNewWalletWithMnemonic(NSString* _Nullable mnemonic, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT WalletWallet* _Nullable WalletNewWalletWithWatchAddress(NSString* _Nullable address, NSError* _Nullable* _Nullable error);

#endif
