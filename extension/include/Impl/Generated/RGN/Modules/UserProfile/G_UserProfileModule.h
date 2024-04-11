#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../Utility/G_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/UserProfileModule.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/UserData.h"
#include "G_UserData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/GetUserProfileRequestData.h"
#include "G_GetUserProfileRequestData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/SearchUsersRequestData.h"
#include "G_SearchUsersRequestData.h"
#include "../../../../../Generated/RGN/Modules/Currency/Currency.h"
#include "../Currency/G_Currency.h"
#include "../../../../../Generated/RGN/Model/Request/BaseRequestData.h"
#include "../../Model/Request/G_BaseRequestData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/GetUserIdByShortUIDRequestData.h"
#include "G_GetUserIdByShortUIDRequestData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/UpdateUserProfileRequestData.h"
#include "G_UpdateUserProfileRequestData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/UserCustomClaims.h"
#include "G_UserCustomClaims.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/SetInvisibleStatusRequestData.h"
#include "G_SetInvisibleStatusRequestData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/GetUserStatusResponseData.h"
#include "G_GetUserStatusResponseData.h"
#include "../../../../../Generated/RGN/Modules/UserProfile/GetUserStatusRequestData.h"
#include "G_GetUserStatusRequestData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_UserProfileModule : public godot::Object {
    GDCLASS(G_UserProfileModule, godot::Object);
    static inline G_UserProfileModule* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("getProfileAsync", "onSuccess", "onFail"), &G_UserProfileModule::getProfileAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getProfileAsync_UserId", "userId", "onSuccess", "onFail"), &G_UserProfileModule::getProfileAsync_UserId, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getFullUserProfileAsync", "onSuccess", "onFail"), &G_UserProfileModule::getFullUserProfileAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getFullUserProfileAsync_UserId", "userId", "onSuccess", "onFail"), &G_UserProfileModule::getFullUserProfileAsync_UserId, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("searchUsersAsync", "nicknameQuery", "onSuccess", "onFail"), &G_UserProfileModule::searchUsersAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getUserCurrenciesAsync", "onSuccess", "onFail"), &G_UserProfileModule::getUserCurrenciesAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getUserIdByShortUIDAsync", "shortUID", "onSuccess", "onFail"), &G_UserProfileModule::getUserIdByShortUIDAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("setDisplayNameAsync", "displayName", "onSuccess", "onFail"), &G_UserProfileModule::setDisplayNameAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("setBioAsync", "bio", "onSuccess", "onFail"), &G_UserProfileModule::setBioAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("setDisplayNameAndBioAsync", "displayName", "bio", "onSuccess", "onFail"), &G_UserProfileModule::setDisplayNameAndBioAsync, DEFVAL(""), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("uploadAvatarImageAsync", "bytes", "cancellationToken", "onSuccess", "onFail"), &G_UserProfileModule::uploadAvatarImageAsync, DEFVAL(nullptr), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("downloadAvatarImageAsync", "userId", "size", "cancellationToken", "onSuccess", "onFail"), &G_UserProfileModule::downloadAvatarImageAsync, DEFVAL(nullptr), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("changeAdminStatusByEmailAsync", "email", "isAdmin", "accessLevel", "onSuccess", "onFail"), &G_UserProfileModule::changeAdminStatusByEmailAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("changeAdminStatusByUserIdAsync", "userId", "isAdmin", "accessLevel", "onSuccess", "onFail"), &G_UserProfileModule::changeAdminStatusByUserIdAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getUserCustomClaimsByUserIdAsync", "userId", "onSuccess", "onFail"), &G_UserProfileModule::getUserCustomClaimsByUserIdAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getUserCustomClaimsByEmailAsync", "email", "onSuccess", "onFail"), &G_UserProfileModule::getUserCustomClaimsByEmailAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("setInvisibleStatusAsync", "invisibleStatus", "onSuccess", "onFail"), &G_UserProfileModule::setInvisibleStatusAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("pingAsync", "onSuccess", "onFail"), &G_UserProfileModule::pingAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("suspendAsync", "onSuccess", "onFail"), &G_UserProfileModule::suspendAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getUserStateAsync", "userId", "onSuccess", "onFail"), &G_UserProfileModule::getUserStateAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("deleteUser", "onSuccess", "onFail"), &G_UserProfileModule::deleteUser, godot::Callable(), godot::Callable());
    }
public:
    static G_UserProfileModule *get_singleton() {
        return singleton;
    }
    G_UserProfileModule() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_UserProfileModule() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
    void getProfileAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::UserProfile::UserProfileModule::GetProfileAsync(
                [onSuccess](RGN::Modules::UserProfile::UserData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_UserData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                }            );
    }
    void getProfileAsync_UserId(
        godot::String userId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_userId;
            godot::String g_userId = userId;
            cpp_userId = std::string(g_userId.utf8().get_data());
            RGN::Modules::UserProfile::UserProfileModule::GetProfileAsync(
                [onSuccess](RGN::Modules::UserProfile::UserData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_UserData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_userId
            );
    }
    void getFullUserProfileAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::UserProfile::UserProfileModule::GetFullUserProfileAsync(
                [onSuccess](string response) {
                    godot::Array gArgs;
                    godot::String gResponse;
                    gResponse = godot::String(response.c_str());
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                }            );
    }
    void getFullUserProfileAsync_UserId(
        godot::String userId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_userId;
            godot::String g_userId = userId;
            cpp_userId = std::string(g_userId.utf8().get_data());
            RGN::Modules::UserProfile::UserProfileModule::GetFullUserProfileAsync(
                [onSuccess](string response) {
                    godot::Array gArgs;
                    godot::String gResponse;
                    gResponse = godot::String(response.c_str());
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_userId
            );
    }
    void searchUsersAsync(
        godot::String nicknameQuery,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_nicknameQuery;
            godot::String g_nicknameQuery = nicknameQuery;
            cpp_nicknameQuery = std::string(g_nicknameQuery.utf8().get_data());
            RGN::Modules::UserProfile::UserProfileModule::SearchUsersAsync(
                [onSuccess](vector<RGN::Modules::UserProfile::UserData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_UserData::ConvertToGodotModel(response_item, g_g_response_item);
                        g_gResponse.push_back(g_response_item);
                    }
                    gResponse = g_gResponse;
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_nicknameQuery
            );
    }
    void getUserCurrenciesAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::UserProfile::UserProfileModule::GetUserCurrenciesAsync(
                [onSuccess](vector<RGN::Modules::Currency::Currency> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_Currency::ConvertToGodotModel(response_item, g_g_response_item);
                        g_gResponse.push_back(g_response_item);
                    }
                    gResponse = g_gResponse;
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                }            );
    }
    void getUserIdByShortUIDAsync(
        godot::String shortUID,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_shortUID;
            godot::String g_shortUID = shortUID;
            cpp_shortUID = std::string(g_shortUID.utf8().get_data());
            RGN::Modules::UserProfile::UserProfileModule::GetUserIdByShortUIDAsync(
                [onSuccess](string response) {
                    godot::Array gArgs;
                    godot::String gResponse;
                    gResponse = godot::String(response.c_str());
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_shortUID
            );
    }
    void setDisplayNameAsync(
        godot::String displayName,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_displayName;
            godot::String g_displayName = displayName;
            cpp_displayName = std::string(g_displayName.utf8().get_data());
            RGN::Modules::UserProfile::UserProfileModule::SetDisplayNameAsync(
                [onSuccess](string response) {
                    godot::Array gArgs;
                    godot::String gResponse;
                    gResponse = godot::String(response.c_str());
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_displayName
            );
    }
    void setBioAsync(
        godot::String bio,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_bio;
            godot::String g_bio = bio;
            cpp_bio = std::string(g_bio.utf8().get_data());
            RGN::Modules::UserProfile::UserProfileModule::SetBioAsync(
                [onSuccess](string response) {
                    godot::Array gArgs;
                    godot::String gResponse;
                    gResponse = godot::String(response.c_str());
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_bio
            );
    }
    void setDisplayNameAndBioAsync(
        godot::String displayName,
        godot::String bio,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_displayName;
            string cpp_bio;
            godot::String g_displayName = displayName;
            cpp_displayName = std::string(g_displayName.utf8().get_data());
            godot::String g_bio = bio;
            cpp_bio = std::string(g_bio.utf8().get_data());
            RGN::Modules::UserProfile::UserProfileModule::SetDisplayNameAndBioAsync(
                [onSuccess](string response) {
                    godot::Array gArgs;
                    godot::String gResponse;
                    gResponse = godot::String(response.c_str());
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_displayName,
                cpp_bio
            );
    }
    void uploadAvatarImageAsync(
        godot::Array bytes,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            vector<uint8_t> cpp_bytes;
            RGN::CancellationToken cpp_cancellationToken;
            godot::Array g_cpp_bytes = bytes;
            for (int i = 0; i < g_cpp_bytes.size(); ++i) {
                uint8_t g_cpp_bytes_item = static_cast<uint8_t>((uint32_t)g_cpp_bytes[i]);
                uint8_t cpp_bytes_item;
                uint8_t g_g_cpp_bytes_item = g_cpp_bytes_item;
                cpp_bytes_item = static_cast<uint8_t>(g_g_cpp_bytes_item);
                cpp_bytes.push_back(cpp_bytes_item);
            }
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::UserProfile::UserProfileModule::UploadAvatarImageAsync(
                [onSuccess](bool response) {
                    godot::Array gArgs;
                    bool gResponse;
                    gResponse = response;
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_bytes,
                cpp_cancellationToken
            );
    }
    void downloadAvatarImageAsync(
        godot::String userId,
        int32_t size,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_userId;
            RGN::Model::ImageSize cpp_size;
            RGN::CancellationToken cpp_cancellationToken;
            godot::String g_userId = userId;
            cpp_userId = std::string(g_userId.utf8().get_data());
            int32_t g_size = size;
            cpp_size = static_cast<RGN::Model::ImageSize>(g_size);
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::UserProfile::UserProfileModule::DownloadAvatarImageAsync(
                [onSuccess](vector<uint8_t> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        uint8_t g_response_item;
                        g_response_item = static_cast<uint32_t>(response_item);
                        g_gResponse.push_back(g_response_item);
                    }
                    gResponse = g_gResponse;
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_userId,
                cpp_size,
                cpp_cancellationToken
            );
    }
    void changeAdminStatusByEmailAsync(
        godot::String email,
        bool isAdmin,
        int32_t accessLevel,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_email;
            bool cpp_isAdmin;
            int32_t cpp_accessLevel;
            godot::String g_email = email;
            cpp_email = std::string(g_email.utf8().get_data());
            bool g_isAdmin = isAdmin;
            cpp_isAdmin = g_isAdmin;
            int32_t g_accessLevel = accessLevel;
            cpp_accessLevel = g_accessLevel;
            RGN::Modules::UserProfile::UserProfileModule::ChangeAdminStatusByEmailAsync(
                [onSuccess](RGN::Modules::UserProfile::UserCustomClaims response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_UserCustomClaims::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_email,
                cpp_isAdmin,
                cpp_accessLevel
            );
    }
    void changeAdminStatusByUserIdAsync(
        godot::String userId,
        bool isAdmin,
        int32_t accessLevel,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_userId;
            bool cpp_isAdmin;
            int32_t cpp_accessLevel;
            godot::String g_userId = userId;
            cpp_userId = std::string(g_userId.utf8().get_data());
            bool g_isAdmin = isAdmin;
            cpp_isAdmin = g_isAdmin;
            int32_t g_accessLevel = accessLevel;
            cpp_accessLevel = g_accessLevel;
            RGN::Modules::UserProfile::UserProfileModule::ChangeAdminStatusByUserIdAsync(
                [onSuccess](RGN::Modules::UserProfile::UserCustomClaims response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_UserCustomClaims::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_userId,
                cpp_isAdmin,
                cpp_accessLevel
            );
    }
    void getUserCustomClaimsByUserIdAsync(
        godot::String userId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_userId;
            godot::String g_userId = userId;
            cpp_userId = std::string(g_userId.utf8().get_data());
            RGN::Modules::UserProfile::UserProfileModule::GetUserCustomClaimsByUserIdAsync(
                [onSuccess](RGN::Modules::UserProfile::UserCustomClaims response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_UserCustomClaims::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_userId
            );
    }
    void getUserCustomClaimsByEmailAsync(
        godot::String email,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_email;
            godot::String g_email = email;
            cpp_email = std::string(g_email.utf8().get_data());
            RGN::Modules::UserProfile::UserProfileModule::GetUserCustomClaimsByEmailAsync(
                [onSuccess](RGN::Modules::UserProfile::UserCustomClaims response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_UserCustomClaims::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_email
            );
    }
    void setInvisibleStatusAsync(
        bool invisibleStatus,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            bool cpp_invisibleStatus;
            bool g_invisibleStatus = invisibleStatus;
            cpp_invisibleStatus = g_invisibleStatus;
            RGN::Modules::UserProfile::UserProfileModule::SetInvisibleStatusAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_invisibleStatus
            );
    }
    void pingAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::UserProfile::UserProfileModule::PingAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                }            );
    }
    void suspendAsync(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::UserProfile::UserProfileModule::SuspendAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                }            );
    }
    void getUserStateAsync(
        godot::String userId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_userId;
            godot::String g_userId = userId;
            cpp_userId = std::string(g_userId.utf8().get_data());
            RGN::Modules::UserProfile::UserProfileModule::GetUserStateAsync(
                [onSuccess](RGN::Modules::UserProfile::GetUserStatusResponseData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_GetUserStatusResponseData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_userId
            );
    }
    void deleteUser(
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::UserProfile::UserProfileModule::DeleteUser(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                }            );
    }
};
