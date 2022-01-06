//-------------------------------------------------------------------------------------------------
// File    : bmx_error.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx error define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef __bmx_error_h__
#define __bmx_error_h__

#include <string>
#include "bmx_defines.h"

namespace floo {

/**
 * @brief 错误码
 **/
enum class BMXErrorCode {
  NoError,

  GeneralError,
  InvalidParam,
  NotFound,

  UserNotLogin,
  UserAlreadyLogin,
  UserAuthFailed,
  UserPermissionDenied,
  UserNotExist,
  UserAlreadyExist,
  UserFrozen,
  UserBanned,
  UserRemoved,
  UserTooManyDevice,
  UserPasswordChanged,
  UserKickedBySameDevice,
  UserKickedByOtherDevices,
  UserAbnormal,
  UserCancel,
  UserOldPasswordNotMatch,

  PushTokenInvalid,
  PushAliasBindByOtherUser,
  PushAliasTokenNotMatch,

  InvalidVerificationCode,
  InvalidRequestParameter,
  InvalidUserNameParameter,
  MissingAccessToken,
  CurrentUserIsInRoster,
  CurrentUserIsInBlocklist,
  AnswerFailed,
  InvalidToken,
  InvalidFileSign,
  InvalidFileObjectType,
  InvalidFileUploadToType,
  InvalidFileDownloadUrl,

  RosterNotFriend,
  RosterBlockListExist,
  RosterRejectApplication,

  GroupServerDbError,
  GroupNotExist,
  GroupNotMemberFound,
  GroupMsgNotifyTypeUnknown,
  GroupOwnerCannotLeave,
  GroupTransferNotAllowed,
  GroupRecoveryMode,
  GroupExceedLimitGlobal,
  GroupExceedLimitUserCreate,
  GroupExceedLimitUserJoin,
  GroupCapacityExceedLimit,
  GroupMemberPermissionRequired,
  GroupAdminPermissionRequired,
  GroupOwnerPermissionRequired,
  GroupApplicationExpiredOrHandled,
  GroupInvitationExpiredOrHandled,
  GroupKickTooManyTimes,
  GroupMemberExist,
  GroupBlockListExist,
  GroupAnnouncementNotFound,
  GroupAnnouncementForbidden,
  GroupSharedFileNotFound,
  GroupSharedFileOperateNotAllowed,
  GroupMemberBanned,

  SignInCancelled,
  SignInTimeout,
  SignInFailed,

  DbOperationFailed,

  MessageInvalid,
  MessageOutRecallTime,
  MessageRecallDisabled,
  MessageCensored,
  MessageInvalidType,

  ServerNotReachable,
  ServerUnknownError,
  ServerInvalid,
  ServerDecryptionFailed,
  ServerEncryptMethodUnsupported,
  ServerBusy,
  ServerNeedRetry,
  ServerTimeOut,
  ServerConnectFailed,
  ServerDNSFailed,
  ServerNeedReconnected,
  ServerFileUploadUnknownError,
  ServerFileDownloadUnknownError,
  ServerInvalidLicense,
  ServerLicenseLimit,
  ServerAppFrozen,
  ServerTooManyRequest,
  ServerNotAllowOpenRegister,
  ServerFireplaceUnknownError,
  ServerResponseInvalid,
  ServerInvalidUploadUrl,
  ServerAppLicenseInvalid,
  ServerAppLicenseExpired,
  ServerAppLicenseExceedLimit,
  ServerAppIdMissing,
  ServerAppIdInvalid,
  ServerAppSignInvalid,
  ServerAppNotifierNotExist,
  ServerNoClusterInfoForClusterId,
  ServerFileDownloadFailure,
  ServerAppStatusNotNormal,
};

/**
 * @brief 通过错误码获取错误详细描述信息
 * @param errorCode 错误码
 * @return std::string
 **/
EXPORT_API std::string getErrorMessage(BMXErrorCode errorCode);

class BMXError {
public:
  BMXError(BMXErrorCode errorCode);
  virtual ~BMXError();
  BMXError& operator=(BMXErrorCode errorCode);
  bool operator==(BMXErrorCode errorCode);
  bool operator==(const BMXError& error);

  BMXErrorCode errorCode();
  std::string description();

private:
  BMXErrorCode mErrorCode;
};

}

#endif /* __bmx_error_h__ */
