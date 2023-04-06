// Objective-C API for talking to github.com/coming-chat/go-aptos/aptosclient Go package.
//   gobind -lang=objc github.com/coming-chat/go-aptos/aptosclient
//
// File is generated by gobind. Do not edit.

#ifndef __Aptosclient_H__
#define __Aptosclient_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"


@class AptosclientRestClient;
@class AptosclientTableItemRequest;

@interface AptosclientRestClient : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped method RestClient.AptosBalanceOf with unsupported parameter or return types

// skipped method RestClient.BalanceOf with unsupported parameter or return types

- (long)chainId;
// skipped method RestClient.CreateTransactionSigningMessage with unsupported parameter or return types

// skipped method RestClient.EstimateGasPrice with unsupported parameter or return types

// skipped method RestClient.GetAccount with unsupported parameter or return types

// skipped method RestClient.GetAccountModule with unsupported parameter or return types

// skipped method RestClient.GetAccountModules with unsupported parameter or return types

// skipped method RestClient.GetAccountResource with unsupported parameter or return types

// skipped method RestClient.GetAccountResourceHandle404 with unsupported parameter or return types

// skipped method RestClient.GetAccountResources with unsupported parameter or return types

// skipped method RestClient.GetAccountTransactions with unsupported parameter or return types

// skipped method RestClient.GetBlockByHeight with unsupported parameter or return types

// skipped method RestClient.GetBlockByVersion with unsupported parameter or return types

// skipped method RestClient.GetCoinInfo with unsupported parameter or return types

// skipped method RestClient.GetEventsByCreationNumber with unsupported parameter or return types

// skipped method RestClient.GetEventsByEventHandle with unsupported parameter or return types

// skipped method RestClient.GetTableItem with unsupported parameter or return types

// skipped method RestClient.GetTransactionByHash with unsupported parameter or return types

// skipped method RestClient.GetTransactionByVersion with unsupported parameter or return types

// skipped method RestClient.GetTransactions with unsupported parameter or return types

- (NSString* _Nonnull)getVersion;
- (NSString* _Nonnull)getVersionedRpcUrl;
// skipped method RestClient.IsAccountHasResource with unsupported parameter or return types

// skipped method RestClient.LedgerInfo with unsupported parameter or return types

// skipped method RestClient.RawQuery with unsupported parameter or return types

- (void)setVersion:(NSString* _Nullable)version;
// skipped method RestClient.SimulateSignedBCSTransaction with unsupported parameter or return types

// skipped method RestClient.SimulateTransaction with unsupported parameter or return types

// skipped method RestClient.SubmitSignedBCSTransaction with unsupported parameter or return types

// skipped method RestClient.SubmitTransaction with unsupported parameter or return types

@end

@interface AptosclientTableItemRequest : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull keyType;
@property (nonatomic) NSString* _Nonnull valueType;
// skipped field TableItemRequest.Key with unsupported type: any

@end

FOUNDATION_EXPORT NSString* _Nonnull const AptosclientVERSION1;
FOUNDATION_EXPORT NSString* _Nonnull const AptosclientVERSIONNONE;

// skipped function Dial with unsupported parameter or return types


// skipped function DialWithClient with unsupported parameter or return types


// skipped function FaucetFundAccount with unsupported parameter or return types


#endif
