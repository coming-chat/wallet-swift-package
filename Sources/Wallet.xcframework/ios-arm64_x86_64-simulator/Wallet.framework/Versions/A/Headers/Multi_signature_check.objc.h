// Objective-C API for talking to github.com/coming-chat/wallet-SDK/core/multi-signature-check Go package.
//   gobind -lang=objc github.com/coming-chat/wallet-SDK/core/multi-signature-check
//
// File is generated by gobind. Do not edit.

#ifndef __Multi_signature_check_H__
#define __Multi_signature_check_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"


@class Multi_signature_checkJsonRpcReq;

@interface Multi_signature_checkJsonRpcReq : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) int64_t id_;
@property (nonatomic) NSString* _Nonnull jsonrpc;
@property (nonatomic) NSString* _Nonnull method;
// skipped field JsonRpcReq.Params with unsupported type: []interface{}

@end

FOUNDATION_EXPORT NSString* _Nonnull Multi_signature_checkAddressAmountKey(NSString* _Nullable address, NSString* _Nullable amount);

// skipped function RequestJsonRpc with unsupported parameter or return types


FOUNDATION_EXPORT BOOL Multi_signature_checkXGatewayBitcoinVerifyTxValid(NSString* _Nullable url, NSString* _Nullable rawTx, NSString* _Nullable withdrawalIds, BOOL isFullAmount, BOOL* _Nullable ret0_, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT NSString* _Nonnull Multi_signature_checkXGatewayCommonWithdrawalListWithFeeInfo(NSString* _Nullable url, long assertId, NSError* _Nullable* _Nullable error);

#endif
