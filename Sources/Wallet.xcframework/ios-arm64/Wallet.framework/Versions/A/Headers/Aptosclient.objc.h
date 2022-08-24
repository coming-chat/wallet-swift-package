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

@interface AptosclientRestClient : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped method RestClient.BalanceOf with unsupported parameter or return types

// skipped method RestClient.CreateTransactionSigningMessage with unsupported parameter or return types

// skipped method RestClient.GetAccount with unsupported parameter or return types

// skipped method RestClient.GetAccountModule with unsupported parameter or return types

// skipped method RestClient.GetAccountModules with unsupported parameter or return types

// skipped method RestClient.GetAccountResource with unsupported parameter or return types

// skipped method RestClient.GetAccountResources with unsupported parameter or return types

// skipped method RestClient.GetAccountTransactions with unsupported parameter or return types

// skipped method RestClient.GetEventsByEventHandle with unsupported parameter or return types

// skipped method RestClient.GetEventsByKey with unsupported parameter or return types

// skipped method RestClient.GetTransactionByHash with unsupported parameter or return types

// skipped method RestClient.GetTransactionByVersion with unsupported parameter or return types

// skipped method RestClient.GetTransactions with unsupported parameter or return types

- (NSString* _Nonnull)getVersion;
- (NSString* _Nonnull)getVersionedRpcUrl;
// skipped method RestClient.LedgerInfo with unsupported parameter or return types

- (void)setVersion:(NSString* _Nullable)version;
// skipped method RestClient.SimulateTransaction with unsupported parameter or return types

// skipped method RestClient.SubmitTransaction with unsupported parameter or return types

@end

FOUNDATION_EXPORT NSString* _Nonnull const AptosclientVERSION1;
FOUNDATION_EXPORT NSString* _Nonnull const AptosclientVERSIONNONE;

// skipped function Dial with unsupported parameter or return types


// skipped function DialWithClient with unsupported parameter or return types


// skipped function FaucetFundAccount with unsupported parameter or return types


#endif