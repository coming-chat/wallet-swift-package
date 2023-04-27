// Objective-C API for talking to github.com/coming-chat/go-dmens-sdk/dmens Go package.
//   gobind -lang=objc github.com/coming-chat/go-dmens-sdk/dmens
//
// File is generated by gobind. Do not edit.

#ifndef __Dmens_H__
#define __Dmens_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

#include "Base.objc.h"
#include "Sui.objc.h"

@class DmensConfiguration;
@class DmensNFTAvatar;
@class DmensNote;
@class DmensNotePage;
@class DmensNoteStatus;
@class DmensPoster;
@class DmensPosterConfig;
@class DmensProfile;
@class DmensQuery;
@class DmensRepostNote;
@class DmensRepostNotePage;
@class DmensUserFollowCount;
@class DmensUserInfo;
@class DmensUserPage;
@class DmensValidProfile;
@protocol DmensPageable;
@class DmensPageable;

@protocol DmensPageable <NSObject>
/**
 * The count of data in the current page.
 */
- (long)currentCount;
/**
 * The cursor of the current page.
 */
- (NSString* _Nonnull)currentCursor;
/**
 * Is there has next page.
 */
- (BOOL)hasNextPage;
- (BaseAnyArray* _Nullable)itemArray;
- (NSString* _Nonnull)jsonString:(NSError* _Nullable* _Nullable)error;
/**
 * The total count of all data in the remote server.
 */
- (long)totalCount;
@end

@interface DmensConfiguration : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull name;
@property (nonatomic) NSString* _Nonnull fullNodeUrl;
@property (nonatomic) NSString* _Nonnull graphqlUrl;
@property (nonatomic) NSString* _Nonnull contractAddress;
@property (nonatomic) NSString* _Nonnull globalProfileId;
@property (nonatomic) NSString* _Nonnull globalProfileTableId;
@property (nonatomic) NSString* _Nonnull profileCheckUrl;
@property (nonatomic) BOOL isMainNet;
@end

@interface DmensNFTAvatar : NSObject <goSeqRefInterface, BaseAniable, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
- (nullable instancetype)initWithId:(NSString* _Nullable)nftId image:(NSString* _Nullable)image typ:(NSString* _Nullable)typ;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
@property (nonatomic) NSString* _Nonnull id_;
@property (nonatomic) NSString* _Nonnull image;
@property (nonatomic) NSString* _Nonnull type;
@property (nonatomic) NSString* _Nonnull name;
- (BaseAny* _Nullable)asAny;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface DmensNote : NSObject <goSeqRefInterface, BaseAniable, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
@property (nonatomic) int64_t createTime;
@property (nonatomic) NSString* _Nonnull noteId;
@property (nonatomic) long action;
@property (nonatomic) NSString* _Nonnull text;
@property (nonatomic) NSString* _Nonnull poster;
@property (nonatomic) NSString* _Nonnull refId;
@property (nonatomic) DmensNoteStatus* _Nullable status;
- (BaseAny* _Nullable)asAny;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface DmensNotePage : NSObject <goSeqRefInterface, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
- (long)currentCount;
- (NSString* _Nonnull)currentCursor;
- (DmensNote* _Nullable)firstObject;
- (BOOL)hasNextPage;
- (BaseAnyArray* _Nullable)itemArray;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
- (long)totalCount;
@end

@interface DmensNoteStatus : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull noteId;
@property (nonatomic) NSString* _Nonnull viewer;
@property (nonatomic) int64_t replyCount;
@property (nonatomic) int64_t repostCount;
@property (nonatomic) int64_t likeCount;
/**
 * Whether the viewer reposted it
 */
@property (nonatomic) BOOL isReposted;
/**
 * Whether the viewer liked it
 */
@property (nonatomic) BOOL isLiked;
@end

@interface DmensPoster : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(DmensPosterConfig* _Nullable)posterConfig configuration:(DmensConfiguration* _Nullable)configuration;
@property (nonatomic) DmensConfiguration* _Nullable configuration;
@property (nonatomic) DmensPosterConfig* _Nullable posterConfig;
/**
 * BatchQueryIsFollowingStatus
Batch query the following status of all users in a specified list.
The query results will be modified directly in the pointer object.
 */
- (BOOL)batchQueryIsFollowingStatus:(DmensUserPage* _Nullable)users error:(NSError* _Nullable* _Nullable)error;
// skipped method Poster.BatchQueryNFTAvatarByIds with unsupported parameter or return types

- (BOOL)batchQueryNFTAvatarForUserPage:(DmensUserPage* _Nullable)page error:(NSError* _Nullable* _Nullable)error;
// skipped method Poster.BatchQueryNoteByIds with unsupported parameter or return types

/**
 * BatchQueryNoteStatus
批量查询 page 中所有 note 的状态，数据会直接同步到 page 中每一个 note 对象中
@param viewer the note's viewer, if the viewer is empty, the poster's address will be queried.
 */
- (BOOL)batchQueryNoteStatus:(DmensNotePage* _Nullable)page viewer:(NSString* _Nullable)viewer error:(NSError* _Nullable* _Nullable)error;
// skipped method Poster.BatchQueryNoteStatusByIds with unsupported parameter or return types

- (DmensUserPage* _Nullable)batchQueryUserByAddressArray:(BaseStringArray* _Nullable)array error:(NSError* _Nullable* _Nullable)error;
/**
 * BatchQueryUserByAddressJson
@param jsonString address array's json string. e.g. `["0x1","0x2",   "0x3"]`
 */
- (DmensUserPage* _Nullable)batchQueryUserByAddressJson:(NSString* _Nullable)jsonString error:(NSError* _Nullable* _Nullable)error;
- (DmensValidProfile* _Nullable)checkProfile:(DmensProfile* _Nullable)profile error:(NSError* _Nullable* _Nullable)error;
- (SuiTransaction* _Nullable)dmensFollow:(BaseStringArray* _Nullable)addresses error:(NSError* _Nullable* _Nullable)error;
- (SuiTransaction* _Nullable)dmensPost:(NSString* _Nullable)text error:(NSError* _Nullable* _Nullable)error;
- (SuiTransaction* _Nullable)dmensPostWithRef:(long)action text:(NSString* _Nullable)text refIdentifier:(NSString* _Nullable)refIdentifier error:(NSError* _Nullable* _Nullable)error;
- (SuiTransaction* _Nullable)dmensUnfollow:(BaseStringArray* _Nullable)addresses error:(NSError* _Nullable* _Nullable)error;
- (BOOL)fetchDmensGlobalConfig:(NSError* _Nullable* _Nullable)error;
/**
 * FetchDmensObjecId After ios or android call profileRegister and send that transaction,
this func should be recalled again to fetch the registered dmens object id
 */
- (BOOL)fetchDmensObjecId:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalBool* _Nullable)isMyFollowing:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (BOOL)isRegister;
- (NSString* _Nonnull)makeQuery:(DmensQuery* _Nullable)q error:(NSError* _Nullable* _Nullable)error;
/**
 * QueryAllNoteList
@param pageSize The number of notes per page.
@param afterCursor Each page has a cursor, and you need to specify the cursor to get the next page of content, If you want to get the first page of content, pass in empty.
 */
- (DmensNotePage* _Nullable)queryAllNoteList:(long)pageSize afterCursor:(NSString* _Nullable)afterCursor error:(NSError* _Nullable* _Nullable)error;
- (DmensQuery* _Nullable)queryDmensGlobalConfig;
- (DmensQuery* _Nullable)queryDmensObjectId;
- (DmensNFTAvatar* _Nullable)queryNFTAvatar:(NSString* _Nullable)nftId error:(NSError* _Nullable* _Nullable)error;
- (DmensNote* _Nullable)queryNoteById:(NSString* _Nullable)noteId error:(NSError* _Nullable* _Nullable)error;
/**
 * QueryNoteStatusById
@param noteId the note's id
@param viewer the note's viewer, if the viewer is empty, the poster's address will be queried.
 */
- (DmensNoteStatus* _Nullable)queryNoteStatusById:(NSString* _Nullable)noteId viewer:(NSString* _Nullable)viewer error:(NSError* _Nullable* _Nullable)error;
- (DmensNotePage* _Nullable)queryNotesMyFollowed:(long)pageSize afterCursor:(NSString* _Nullable)afterCursor error:(NSError* _Nullable* _Nullable)error;
- (DmensNotePage* _Nullable)queryReplyNoteList:(NSString* _Nullable)noteId pageSize:(long)pageSize afterCursor:(NSString* _Nullable)afterCursor error:(NSError* _Nullable* _Nullable)error;
- (BaseOptionalString* _Nullable)querySuiNameByAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
- (DmensNotePage* _Nullable)queryTrendNoteList:(long)pageSize afterCursor:(NSString* _Nullable)afterCursor error:(NSError* _Nullable* _Nullable)error;
- (DmensUserPage* _Nullable)queryTrendUserList:(long)pageSize error:(NSError* _Nullable* _Nullable)error;
/**
 * QueryUserFollowCount
@param user If the user is empty, the poster's address will be queried.
 */
- (DmensUserFollowCount* _Nullable)queryUserFollowCount:(NSString* _Nullable)user error:(NSError* _Nullable* _Nullable)error;
/**
 * QueryUserFollowers
@param user If the user is empty, the poster's address will be queried.
 */
- (DmensUserPage* _Nullable)queryUserFollowers:(NSString* _Nullable)user pageSize:(long)pageSize afterCursor:(NSString* _Nullable)afterCursor error:(NSError* _Nullable* _Nullable)error;
/**
 * QueryUserFollowing
@param user If the user is empty, the poster's address will be queried.
 */
- (DmensUserPage* _Nullable)queryUserFollowing:(NSString* _Nullable)user pageSize:(long)pageSize afterCursor:(NSString* _Nullable)afterCursor error:(NSError* _Nullable* _Nullable)error;
/**
 * QueryUserInfoByAddress
@param address If the address is empty, the poster's address will be queried.
 */
- (DmensUserInfo* _Nullable)queryUserInfoByAddress:(NSString* _Nullable)address error:(NSError* _Nullable* _Nullable)error;
/**
 * QueryUserNoteList
@param user If the user is empty, the poster's address will be queried.
 */
- (DmensNotePage* _Nullable)queryUserNoteList:(NSString* _Nullable)user pageSize:(long)pageSize afterCursor:(NSString* _Nullable)afterCursor error:(NSError* _Nullable* _Nullable)error;
/**
 * QueryUserRepostList
@param user If the user is empty, the poster's address will be queried.
 */
- (DmensRepostNotePage* _Nullable)queryUserRepostList:(NSString* _Nullable)user pageSize:(long)pageSize afterCursor:(NSString* _Nullable)afterCursor error:(NSError* _Nullable* _Nullable)error;
/**
 * QueryUserRepostListAsNotePage
@param user If the user is empty, the poster's address will be queried.
 */
- (DmensNotePage* _Nullable)queryUserRepostListAsNotePage:(NSString* _Nullable)user pageSize:(long)pageSize afterCursor:(NSString* _Nullable)afterCursor error:(NSError* _Nullable* _Nullable)error;
- (DmensUserPage* _Nullable)queryUsersByName:(NSString* _Nullable)name pageSize:(long)pageSize afterCursor:(NSString* _Nullable)afterCursor error:(NSError* _Nullable* _Nullable)error;
- (SuiTransaction* _Nullable)register:(DmensValidProfile* _Nullable)validProfile error:(NSError* _Nullable* _Nullable)error;
- (SuiTransaction* _Nullable)removeNftAvatar:(DmensNFTAvatar* _Nullable)avatar error:(NSError* _Nullable* _Nullable)error;
- (SuiTransaction* _Nullable)setNftAvatar:(NSString* _Nullable)nftId error:(NSError* _Nullable* _Nullable)error;
- (void)switchRpcUrl:(NSString* _Nullable)rpc;
@end

@interface DmensPosterConfig : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init:(NSString* _Nullable)address reviewing:(BOOL)reviewing;
@property (nonatomic) NSString* _Nonnull address;
@property (nonatomic) NSString* _Nonnull dmensNftId;
/**
 * Default false
 */
@property (nonatomic) BOOL reviewing;
@end

@interface DmensProfile : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull name;
@property (nonatomic) NSString* _Nonnull bio;
@property (nonatomic) NSString* _Nonnull avatar;
@property (nonatomic) NSString* _Nonnull background;
@property (nonatomic) NSString* _Nonnull website;
@property (nonatomic) NSString* _Nonnull identification;
@end

@interface DmensQuery : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull query;
@property (nonatomic) NSString* _Nonnull operationName;
// skipped field Query.Variables with unsupported type: map[string]interface{}

/**
 * 因为在 Variables 中使用 cursor 无法实现 `null cursor`, 因此将 cursor 单独取出来
cursor 为空时，表示 null
 */
@property (nonatomic) NSString* _Nonnull cursor;
- (NSString* _Nonnull)actualQueryString;
@end

@interface DmensRepostNote : NSObject <goSeqRefInterface, BaseAniable, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
@property (nonatomic) DmensNote* _Nullable note;
@property (nonatomic) DmensNote* _Nullable repost;
- (BaseAny* _Nullable)asAny;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface DmensRepostNotePage : NSObject <goSeqRefInterface, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
- (long)currentCount;
- (NSString* _Nonnull)currentCursor;
- (DmensRepostNote* _Nullable)firstObject;
- (BOOL)hasNextPage;
- (BaseAnyArray* _Nullable)itemArray;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
- (long)totalCount;
@end

@interface DmensUserFollowCount : NSObject <goSeqRefInterface, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
@property (nonatomic) NSString* _Nonnull user;
@property (nonatomic) long followerCount;
@property (nonatomic) long followingCount;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface DmensUserInfo : NSObject <goSeqRefInterface, BaseAniable, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
@property (nonatomic) NSString* _Nonnull address;
@property (nonatomic) NSString* _Nonnull avatar;
@property (nonatomic) NSString* _Nonnull bio;
@property (nonatomic) NSString* _Nonnull name;
@property (nonatomic) NSString* _Nonnull nodeId;
@property (nonatomic) NSString* _Nonnull background;
@property (nonatomic) NSString* _Nonnull website;
@property (nonatomic) NSString* _Nonnull identification;
/**
 * Only queried when call QueryUserInfoByAddress
 */
@property (nonatomic) NSString* _Nonnull suiName;
// skipped field UserInfo.Item with unsupported type: []string

@property (nonatomic) DmensNFTAvatar* _Nullable nftAvatar;
@property (nonatomic) BOOL isFollowing;
- (BaseAny* _Nullable)asAny;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
@end

@interface DmensUserPage : NSObject <goSeqRefInterface, BaseJsonable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nullable instancetype)init;
- (nullable instancetype)initWithJsonString:(NSString* _Nullable)str;
- (long)currentCount;
- (NSString* _Nonnull)currentCursor;
- (DmensUserInfo* _Nullable)firstObject;
- (BOOL)hasNextPage;
- (BaseAnyArray* _Nullable)itemArray;
- (BaseOptionalString* _Nullable)jsonString:(NSError* _Nullable* _Nullable)error;
- (long)totalCount;
@end

@interface DmensValidProfile : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull profile;
@property (nonatomic) NSString* _Nonnull signature;
@end

FOUNDATION_EXPORT const long DmensACTION_LIKE;
FOUNDATION_EXPORT const long DmensACTION_POST;
FOUNDATION_EXPORT const long DmensACTION_QUOTE_POST;
FOUNDATION_EXPORT const long DmensACTION_REPLY;
FOUNDATION_EXPORT const long DmensACTION_REPOST;
FOUNDATION_EXPORT const int64_t DmensActionLike;
FOUNDATION_EXPORT const int64_t DmensActionQuotePost;
FOUNDATION_EXPORT const int64_t DmensActionRePost;
FOUNDATION_EXPORT const int64_t DmensActionReply;
FOUNDATION_EXPORT NSString* _Nonnull const DmensFunctionAddItem;
FOUNDATION_EXPORT NSString* _Nonnull const DmensFunctionRegister;
FOUNDATION_EXPORT NSString* _Nonnull const DmensFunctionRemoveItem;

@interface Dmens : NSObject
+ (DmensConfiguration* _Nullable) devnetConfig;
+ (void) setDevnetConfig:(DmensConfiguration* _Nullable)v;

+ (NSError* _Nullable) errGetNullConfiguration;
+ (void) setErrGetNullConfiguration:(NSError* _Nullable)v;

+ (NSError* _Nullable) errNotValidPorfile;
+ (void) setErrNotValidPorfile:(NSError* _Nullable)v;

+ (NSError* _Nullable) errUserNotRegistered;
+ (void) setErrUserNotRegistered:(NSError* _Nullable)v;

+ (DmensConfiguration* _Nullable) mainnetConfig;
+ (void) setMainnetConfig:(DmensConfiguration* _Nullable)v;

+ (DmensConfiguration* _Nullable) testnetConfig;
+ (void) setTestnetConfig:(DmensConfiguration* _Nullable)v;

@end

FOUNDATION_EXPORT DmensNFTAvatar* _Nullable DmensAsNFTAvatar(BaseAny* _Nullable any);

FOUNDATION_EXPORT DmensNote* _Nullable DmensAsNote(BaseAny* _Nullable any);

FOUNDATION_EXPORT DmensRepostNote* _Nullable DmensAsRepostNote(BaseAny* _Nullable any);

FOUNDATION_EXPORT DmensUserInfo* _Nullable DmensAsUserInfo(BaseAny* _Nullable a);

FOUNDATION_EXPORT DmensNFTAvatar* _Nullable DmensNewNFTAvatar(void);

FOUNDATION_EXPORT DmensNFTAvatar* _Nullable DmensNewNFTAvatarWithId(NSString* _Nullable nftId, NSString* _Nullable image, NSString* _Nullable typ);

FOUNDATION_EXPORT DmensNFTAvatar* _Nullable DmensNewNFTAvatarWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT DmensNote* _Nullable DmensNewNote(void);

FOUNDATION_EXPORT DmensNotePage* _Nullable DmensNewNotePage(void);

FOUNDATION_EXPORT DmensNotePage* _Nullable DmensNewNotePageWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT DmensNote* _Nullable DmensNewNoteWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT DmensPoster* _Nullable DmensNewPoster(DmensPosterConfig* _Nullable posterConfig, DmensConfiguration* _Nullable configuration, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT DmensPosterConfig* _Nullable DmensNewPosterConfig(NSString* _Nullable address, BOOL reviewing);

FOUNDATION_EXPORT DmensRepostNote* _Nullable DmensNewRepostNote(void);

FOUNDATION_EXPORT DmensRepostNotePage* _Nullable DmensNewRepostNotePage(void);

FOUNDATION_EXPORT DmensRepostNotePage* _Nullable DmensNewRepostNotePageWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT DmensRepostNote* _Nullable DmensNewRepostNoteWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT DmensUserFollowCount* _Nullable DmensNewUserFollowCount(void);

FOUNDATION_EXPORT DmensUserFollowCount* _Nullable DmensNewUserFollowCountWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT DmensUserInfo* _Nullable DmensNewUserInfo(void);

FOUNDATION_EXPORT DmensUserInfo* _Nullable DmensNewUserInfoWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

FOUNDATION_EXPORT DmensUserPage* _Nullable DmensNewUserPage(void);

FOUNDATION_EXPORT DmensUserPage* _Nullable DmensNewUserPageWithJsonString(NSString* _Nullable str, NSError* _Nullable* _Nullable error);

@class DmensPageable;

@interface DmensPageable : NSObject <goSeqRefInterface, DmensPageable> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * The count of data in the current page.
 */
- (long)currentCount;
/**
 * The cursor of the current page.
 */
- (NSString* _Nonnull)currentCursor;
/**
 * Is there has next page.
 */
- (BOOL)hasNextPage;
- (BaseAnyArray* _Nullable)itemArray;
- (NSString* _Nonnull)jsonString:(NSError* _Nullable* _Nullable)error;
/**
 * The total count of all data in the remote server.
 */
- (long)totalCount;
@end

#endif
