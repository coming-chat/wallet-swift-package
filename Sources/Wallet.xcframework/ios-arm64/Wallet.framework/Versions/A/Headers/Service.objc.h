// Objective-C API for talking to github.com/coming-chat/go-defi-sdk/core/crossswap/service Go package.
//   gobind -lang=objc github.com/coming-chat/go-defi-sdk/core/crossswap/service
//
// File is generated by gobind. Do not edit.

#ifndef __Service_H__
#define __Service_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

#include "Types.objc.h"
#include "Util.objc.h"

@class ServiceApiService;
@class ServiceChainService;
@class ServiceConfigService;

@interface ServiceApiService : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * EstimateGas get evm account pendingNonce
 */
- (TypesEstimateGasRes* _Nullable)estimateGas:(TypesEstimateGasReq* _Nullable)input error:(NSError* _Nullable* _Nullable)error;
/**
 * GetAccountNonce get evm account pendingNonce
 */
- (TypesAccountNonceRes* _Nullable)getAccountNonce:(NSString* _Nullable)chain address:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
/**
 * GetChains get all avaliable chains from api server
 */
- (TypesChainListRes* _Nullable)getChains:(TypesGetChainTokensReq* _Nullable)input error:(NSError* _Nullable* _Nullable)error;
/**
 * GetConnections get tokens that req token can swap to
 */
- (TypesChainListRes* _Nullable)getConnections:(NSString* _Nullable)fromChain fromToken:(NSString* _Nullable)fromToken fromTokenAddress:(NSString* _Nullable)fromTokenAddress toChain:(NSString* _Nullable)toChain error:(NSError* _Nullable* _Nullable)error;
/**
 * GetQuote get swap staps & estimate result
 */
- (TypesQuoteRes* _Nullable)getQuote:(TypesQuoteReq* _Nullable)quoteReq error:(NSError* _Nullable* _Nullable)error;
/**
 * GetStatus query cross swap status by fromChain & txHash
Deprecated: use GetStatusBySwapId
 */
- (TypesStatusRes* _Nullable)getStatus:(NSString* _Nullable)fromChain txHash:(NSString* _Nullable)txHash error:(NSError* _Nullable* _Nullable)error;
/**
 * GetStatusBySwapId get cross swap status by QuoteRes.Id
swap id is [32]byte, generated by server, and encode to hex string
because one crossswap may have many steps, and hava many tx hash,
so we use generated swapId to represent the swap
 */
- (TypesStatusRes* _Nullable)getStatusBySwapId:(NSString* _Nullable)fromChain swapId:(NSString* _Nullable)swapId error:(NSError* _Nullable* _Nullable)error;
/**
 * GetToken get one token info
 */
- (TypesTokenInfoRes* _Nullable)getToken:(NSString* _Nullable)chain token:(NSString* _Nullable)token error:(NSError* _Nullable* _Nullable)error;
/**
 * GetTokens get all avaliable tokens from one chain
 */
- (TypesTokenListRes* _Nullable)getTokens:(NSString* _Nullable)chain page:(long)page pageSize:(long)pageSize error:(NSError* _Nullable* _Nullable)error;
/**
 * GetTxStatus query evm tx status, isPending/status
 */
- (TypesTxStatusRes* _Nullable)getTxStatus:(NSString* _Nullable)chain txHash:(NSString* _Nullable)txHash error:(NSError* _Nullable* _Nullable)error;
- (BOOL)reportSwap:(TypesReportSwapReq* _Nullable)swap error:(NSError* _Nullable* _Nullable)error;
/**
 * SearchConnectionToken search connection tokens
 */
- (TypesChainListRes* _Nullable)searchConnectionToken:(TypesSearchConnectTokenReq* _Nullable)input error:(NSError* _Nullable* _Nullable)error;
/**
 * SearchToken search one token
 */
- (TypesChainListRes* _Nullable)searchToken:(TypesSearchTokenReq* _Nullable)input error:(NSError* _Nullable* _Nullable)error;
@end

@interface ServiceChainService : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
- (TypesChainInfo* _Nullable)getChainByName:(NSString* _Nullable)name error:(NSError* _Nullable* _Nullable)error;
- (TypesChainListRes* _Nullable)getChains;
- (TypesChainListRes* _Nullable)refreshChains:(NSError* _Nullable* _Nullable)error;
@end

@interface ServiceConfigService : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * UpdateConfig assign not empty field from input config
 */
- (TypesConfig* _Nullable)updateConfig:(TypesConfig* _Nullable)config;
- (void)useDefaultApi;
- (void)useLocalApi;
- (void)useTestApi;
@end

FOUNDATION_EXPORT ServiceApiService* _Nullable ServiceGetApiService(void);

FOUNDATION_EXPORT ServiceApiService* _Nullable ServiceGetApiServiceInstance(void);

FOUNDATION_EXPORT ServiceChainService* _Nullable ServiceGetChainInstance(void);

FOUNDATION_EXPORT ServiceConfigService* _Nullable ServiceGetConfigServiceInstance(void);

#endif
