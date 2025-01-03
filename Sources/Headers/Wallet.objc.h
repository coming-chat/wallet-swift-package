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
#include "Starknet.objc.h"
#include "Sui.objc.h"

@class WalletAccountInfo;
@class WalletCacheWallet;
@class WalletWallet;
@class WalletWatchAccount;
@protocol WalletSDKWalletSecretInfo;
@class WalletSDKWalletSecretInfo;

@protocol WalletSDKWalletSecretInfo <NSObject>
/**
 * 需要提供一个 key, 可以缓存钱包地址公钥信息
 */
- (NSString* _Nonnull)sdkCacheKey;
/**
 * 如果是一个 keystore 钱包，返回 keystore
 */
- (NSString* _Nonnull)sdkKeystore;
/**
 * 如果是一个助记词钱包，返回助记词
 */
- (NSString* _Nonnull)sdkMnemonic;
/**
 * 如果是一个 keystore 钱包，返回密码
 */
- (NSString* _Nonnull)sdkPassword;
/**
 * 如果是一个私钥钱包，返回私钥
 */
- (NSString* _Nonnull)sdkPrivateKey;
/**
 * 如果是一个观察者钱包，返回观察地址
 */
- (NSString* _Nonnull)sdkWatchAddress;
@end

@interface WalletAccountInfo : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) WalletCacheWallet* _Nullable wallet;
/**
 * 获取账号对象，该对象可以用来签名. 账号不会缓存，每次都会重新生成
 */
- (id<BaseAccount> _Nullable)account:(NSError* _Nullable* _Nullable)error;
/**
 * 获取地址，该方法会优先读取缓存
 */
- (BaseOptionalString* _Nullable)address:(NSError* _Nullable* _Nullable)error;
/**
 * 获取账号私钥，私钥不会缓存，每次都会重新生成
 */
- (BaseOptionalString* _Nullable)privateKeyHex:(NSError* _Nullable* _Nullable)error;
/**
 * 获取公钥，该方法会优先读取缓存
 */
- (BaseOptionalString* _Nullable)publicKeyHex:(NSError* _Nullable* _Nullable)error;
@end

/**
 * 旧的钱包对象在内存里面会缓存 **助记词**，还有很多链的账号 **私钥**，可能会有用户钱包被盗的风险
因此 SDK 里面不能缓存 **助记词** 、**私钥** 、还有 **keystore 密码**

考虑到每次都导入助记词生成账号，而仅仅是为了获取账号地址或者公钥，可能会影响钱包的性能和体验
因此新提供了这个可以缓存 *账号地址* 和 *公钥* 这种不敏感信息的钱包
 */
@interface WalletCacheWallet : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(id<WalletSDKWalletSecretInfo> _Nullable)info;
@property (nonatomic) id<WalletSDKWalletSecretInfo> _Nullable walletInfo;
- (WalletAccountInfo* _Nullable)aptosAccountInfo;
- (WalletAccountInfo* _Nullable)bitcoinAccountInfo:(NSString* _Nullable)chainnet addressType:(long)addressType;
- (WalletAccountInfo* _Nullable)cosmosAccountInfo:(int64_t)cointype prefix:(NSString* _Nullable)prefix;
- (WalletAccountInfo* _Nullable)dogecoinAccountInfo:(NSString* _Nullable)chainnet;
- (WalletAccountInfo* _Nullable)ethereumAccountInfo;
- (WalletAccountInfo* _Nullable)polkaAccountInfo:(long)network;
- (WalletAccountInfo* _Nullable)solanaAccountInfo;
- (WalletAccountInfo* _Nullable)starcoinAccountInfo;
- (WalletAccountInfo* _Nullable)starknetAccountInfo:(BOOL)isCairo0;
- (WalletAccountInfo* _Nullable)suiAccountInfo;
/**
 * 获取钱包类型
枚举值见 `WalletType` (Mnemonic / Keystore / PrivateKey / Watch / Error)
 */
- (long)walletType;
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
@property (nonatomic) NSString* _Nonnull mnemonic;
@property (nonatomic) NSString* _Nonnull keystore;
@property (nonatomic) NSString* _Nonnull watchAddress;
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
- (BtcAccount* _Nullable)getOrCreateBitcoinAccount:(NSString* _Nullable)chainnet addressType:(long)addressType error:(NSError* _Nullable* _Nullable)error;
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
 * Get or create the starknet account.
 */
- (StarknetAccount* _Nullable)getOrCreateStarknetAccount:(BOOL)isCairo0 error:(NSError* _Nullable* _Nullable)error;
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

FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeAptos;
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeBitcoin;
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeCosmos;
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeDoge;
/**
 * contains ethereum, bsc, chainx_eth, polygon...
 */
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeEthereum;
/**
 * contains chainx, minix, sherpax, polkadot...
 */
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypePolka;
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeSignet;
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeSolana;
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeStarcoin;
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeStarknet;
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeSui;
FOUNDATION_EXPORT NSString* _Nonnull const WalletChainTypeTerra;
FOUNDATION_EXPORT const long WalletWalletTypeError;
FOUNDATION_EXPORT const long WalletWalletTypeKeystore;
FOUNDATION_EXPORT const long WalletWalletTypeMnemonic;
FOUNDATION_EXPORT const long WalletWalletTypePrivateKey;
FOUNDATION_EXPORT const long WalletWalletTypeWatch;

@interface Wallet : NSObject
+ (NSError* _Nullable) errInvalidMnemonic;
+ (void) setErrInvalidMnemonic:(NSError* _Nullable)v;

+ (NSError* _Nullable) errUnsupportKeystore;
+ (void) setErrUnsupportKeystore:(NSError* _Nullable)v;

+ (NSError* _Nullable) errWalletInfoNotExist;
+ (void) setErrWalletInfoNotExist:(NSError* _Nullable)v;

+ (NSError* _Nullable) errWalletInfoUnspecified;
+ (void) setErrWalletInfoUnspecified:(NSError* _Nullable)v;

@end

FOUNDATION_EXPORT NSString* _Nonnull WalletByteToHex(NSData* _Nullable data);

/**
 * Deprecated: renamed to `ChainTypeOfWatchAddress()`.
 */
FOUNDATION_EXPORT BaseStringArray* _Nullable WalletChainTypeFrom(NSString* _Nullable address);

FOUNDATION_EXPORT BaseStringArray* _Nullable WalletChainTypeOfPrivateKey(NSString* _Nullable prikey);

/**
 * Only support evm, btc, cosmos, solana now.
 */
FOUNDATION_EXPORT BaseStringArray* _Nullable WalletChainTypeOfWatchAddress(NSString* _Nullable address);

FOUNDATION_EXPORT void WalletCleanCachedAccountInfo(void);

/**
 * ExtendMasterKey derives a master key from the given mnemonic and chain network identifier.

Parameters:
  - mnemonic: A string representing the mnemonic phrase used to generate the seed.
  - chainnet: The blockchain network, which must be either
    "mainnet", "testnet", "signet", "simnet" or "regtest".
 */
FOUNDATION_EXPORT NSString* _Nonnull WalletExtendMasterKey(NSString* _Nullable mnemonic, NSString* _Nullable chainnet, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSString* _Nonnull WalletGenMnemonic(NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSData* _Nullable WalletHexToByte(NSString* _Nullable hex, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT BOOL WalletIsValidMnemonic(NSString* _Nullable mnemonic);

FOUNDATION_EXPORT WalletCacheWallet* _Nullable WalletNewCacheWallet(id<WalletSDKWalletSecretInfo> _Nullable info);

/**
 * Only support Polka keystore.
 */
FOUNDATION_EXPORT WalletWallet* _Nullable WalletNewWalletWithKeyStore(NSString* _Nullable keyStoreJson, NSString* _Nullable password, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT WalletWallet* _Nullable WalletNewWalletWithMnemonic(NSString* _Nullable mnemonic, NSError* _Nullable* _Nullable error);

/**
 * Create a watch wallet
 */
FOUNDATION_EXPORT WalletCacheWallet* _Nullable WalletNewWatchWallet(NSString* _Nullable address, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT WalletWallet* _Nullable WalletWatchWallet(NSString* _Nullable address, NSError* _Nullable* _Nullable error);

@class WalletSDKWalletSecretInfo;

/**
 * 任意一个类可以遵循这个协议, 通过创建一个 `CacheWallet` 来计算钱包公钥、地址
SDK 会在需要的时候从该对象读取 **助记词/keystore/私钥** 等信息
 */
@interface WalletSDKWalletSecretInfo : NSObject <goSeqRefInterface, WalletSDKWalletSecretInfo> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * 需要提供一个 key, 可以缓存钱包地址公钥信息
 */
- (NSString* _Nonnull)sdkCacheKey;
/**
 * 如果是一个 keystore 钱包，返回 keystore
 */
- (NSString* _Nonnull)sdkKeystore;
/**
 * 如果是一个助记词钱包，返回助记词
 */
- (NSString* _Nonnull)sdkMnemonic;
/**
 * 如果是一个 keystore 钱包，返回密码
 */
- (NSString* _Nonnull)sdkPassword;
/**
 * 如果是一个私钥钱包，返回私钥
 */
- (NSString* _Nonnull)sdkPrivateKey;
/**
 * 如果是一个观察者钱包，返回观察地址
 */
- (NSString* _Nonnull)sdkWatchAddress;
@end

#endif
