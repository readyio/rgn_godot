#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardModule.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardData.h"
#include "G_LeaderboardData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardsResponse.h"
#include "G_GetLeaderboardsResponse.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardIdsResponseData.h"
#include "G_GetLeaderboardIdsResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/IsLeaderboardAvailableResponseData.h"
#include "G_IsLeaderboardAvailableResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/IsInPromoPeriodResponseData.h"
#include "G_IsInPromoPeriodResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/IsInGracePeriodResponseData.h"
#include "G_IsInGracePeriodResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/SetScoreResponseData.h"
#include "G_SetScoreResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardEntry.h"
#include "G_LeaderboardEntry.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardEntriesResponseData.h"
#include "G_GetLeaderboardEntriesResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardResetsResponseData.h"
#include "G_GetLeaderboardResetsResponseData.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/LeaderboardReset.h"
#include "G_LeaderboardReset.h"
#include "../../../../../Generated/RGN/Modules/Leaderboard/GetLeaderboardResetResponseData.h"
#include "G_GetLeaderboardResetResponseData.h"
#include "Impl/G_Defs.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_LeaderboardModule : public godot::Object {
    REG_GCLASS(G_LeaderboardModule, godot::Object);
#ifdef GODOT4
    static G_LeaderboardModule* singleton;
#endif
public:
#ifdef GODOT3
    void _init() {}
#else
    static G_LeaderboardModule *get_singleton() {
        return singleton;
    }
    G_LeaderboardModule() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_LeaderboardModule() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
#endif
    REG_GCLASS_METHODS_HEADER() {
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::getLeaderboardByIdAsync, GCLASS_METHOD_SIGNATURE("getLeaderboardByIdAsync", "id", "onSuccess", "onFail"), &G_LeaderboardModule::getLeaderboardByIdAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::getLeaderboardByRequestNameAsync, GCLASS_METHOD_SIGNATURE("getLeaderboardByRequestNameAsync", "requestName", "onSuccess", "onFail"), &G_LeaderboardModule::getLeaderboardByRequestNameAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::getLeaderboardByRequestNamesAsync, GCLASS_METHOD_SIGNATURE("getLeaderboardByRequestNamesAsync", "requestNames", "onSuccess", "onFail"), &G_LeaderboardModule::getLeaderboardByRequestNamesAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::getLeaderboardByAppIdsAsync, GCLASS_METHOD_SIGNATURE("getLeaderboardByAppIdsAsync", "appIds", "limit", "startAfter", "ignoreTimestamp", "onSuccess", "onFail"), &G_LeaderboardModule::getLeaderboardByAppIdsAsync, DEFVAL(""), DEFVAL(false), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::getLeaderboardByTagsAsync, GCLASS_METHOD_SIGNATURE("getLeaderboardByTagsAsync", "tags", "limit", "startAfter", "ignoreTimestamp", "onSuccess", "onFail"), &G_LeaderboardModule::getLeaderboardByTagsAsync, DEFVAL(""), DEFVAL(false), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::getLeaderboardForCurrentAppAsync, GCLASS_METHOD_SIGNATURE("getLeaderboardForCurrentAppAsync", "limit", "startAfter", "ignoreTimestamp", "onSuccess", "onFail"), &G_LeaderboardModule::getLeaderboardForCurrentAppAsync, DEFVAL(""), DEFVAL(false), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::getLeaderboardIdsAsync, GCLASS_METHOD_SIGNATURE("getLeaderboardIdsAsync", "ignoreTimestamp", "onSuccess", "onFail"), &G_LeaderboardModule::getLeaderboardIdsAsync, DEFVAL(false), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::isLeaderboardAvailableAsync, GCLASS_METHOD_SIGNATURE("isLeaderboardAvailableAsync", "leaderboardId", "onSuccess", "onFail"), &G_LeaderboardModule::isLeaderboardAvailableAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::isInPromoPeriodAsync, GCLASS_METHOD_SIGNATURE("isInPromoPeriodAsync", "leaderboardId", "onSuccess", "onFail"), &G_LeaderboardModule::isInPromoPeriodAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::isInGracePeriodAsync, GCLASS_METHOD_SIGNATURE("isInGracePeriodAsync", "leaderboardId", "onSuccess", "onFail"), &G_LeaderboardModule::isInGracePeriodAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::setScoreAsync, GCLASS_METHOD_SIGNATURE("setScoreAsync", "leaderboardId", "score", "extraData", "onSuccess", "onFail"), &G_LeaderboardModule::setScoreAsync, DEFVAL(""), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::addScoreAsync, GCLASS_METHOD_SIGNATURE("addScoreAsync", "leaderboardId", "score", "extraData", "onSuccess", "onFail"), &G_LeaderboardModule::addScoreAsync, DEFVAL(""), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::getUserEntryAsync, GCLASS_METHOD_SIGNATURE("getUserEntryAsync", "leaderboardId", "onSuccess", "onFail"), &G_LeaderboardModule::getUserEntryAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::getEntriesAsync, GCLASS_METHOD_SIGNATURE("getEntriesAsync", "leaderboardId", "quantityTop", "includeUser", "quantityAroundUser", "onSuccess", "onFail"), &G_LeaderboardModule::getEntriesAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::getResetsAsync, GCLASS_METHOD_SIGNATURE("getResetsAsync", "leaderboardId", "withEntries", "startAfter", "limit", "orderDirection", "onSuccess", "onFail"), &G_LeaderboardModule::getResetsAsync, DEFVAL(-1), DEFVAL(-1), DEFVAL("asc"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::getResetAsync, GCLASS_METHOD_SIGNATURE("getResetAsync", "leaderboardId", "resetId", "startAfter", "limit", "orderDirection", "onSuccess", "onFail"), &G_LeaderboardModule::getResetAsync, DEFVAL(0), DEFVAL(0), DEFVAL("asc"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_LeaderboardModule::resetLeaderboardAsync, GCLASS_METHOD_SIGNATURE("resetLeaderboardAsync", "leaderboardId", "onSuccess", "onFail"), &G_LeaderboardModule::resetLeaderboardAsync, GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
    }
    void getLeaderboardByIdAsync(
        godot::String id,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_id;
            godot::String g_id = id;
            cpp_id = std::string(g_id.utf8().get_data());
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardByIdAsync(
                [onSuccess](RGN::Modules::Leaderboard::LeaderboardData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_LeaderboardData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_id
            );
    }
    void getLeaderboardByRequestNameAsync(
        godot::String requestName,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_requestName;
            godot::String g_requestName = requestName;
            cpp_requestName = std::string(g_requestName.utf8().get_data());
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardByRequestNameAsync(
                [onSuccess](RGN::Modules::Leaderboard::LeaderboardData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_LeaderboardData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_requestName
            );
    }
    void getLeaderboardByRequestNamesAsync(
        godot::Array requestNames,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            vector<string> cpp_requestNames;
            godot::Array g_cpp_requestNames = requestNames;
            for (int i = 0; i < g_cpp_requestNames.size(); ++i) {
                godot::String g_cpp_requestNames_item = g_cpp_requestNames[i];
                string cpp_requestNames_item;
                godot::String g_g_cpp_requestNames_item = g_cpp_requestNames_item;
                cpp_requestNames_item = std::string(g_g_cpp_requestNames_item.utf8().get_data());
                cpp_requestNames.push_back(cpp_requestNames_item);
            }
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardByRequestNamesAsync(
                [onSuccess](vector<RGN::Modules::Leaderboard::LeaderboardData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_LeaderboardData::ConvertToGodotModel(response_item, g_g_response_item);
                        g_gResponse.push_back(g_response_item);
                    }
                    gResponse = g_gResponse;
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_requestNames
            );
    }
    void getLeaderboardByAppIdsAsync(
        godot::Array appIds,
        int32_t limit,
        godot::String startAfter,
        bool ignoreTimestamp,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            vector<string> cpp_appIds;
            int32_t cpp_limit;
            string cpp_startAfter;
            bool cpp_ignoreTimestamp;
            godot::Array g_cpp_appIds = appIds;
            for (int i = 0; i < g_cpp_appIds.size(); ++i) {
                godot::String g_cpp_appIds_item = g_cpp_appIds[i];
                string cpp_appIds_item;
                godot::String g_g_cpp_appIds_item = g_cpp_appIds_item;
                cpp_appIds_item = std::string(g_g_cpp_appIds_item.utf8().get_data());
                cpp_appIds.push_back(cpp_appIds_item);
            }
            int32_t g_limit = limit;
            cpp_limit = g_limit;
            godot::String g_startAfter = startAfter;
            cpp_startAfter = std::string(g_startAfter.utf8().get_data());
            bool g_ignoreTimestamp = ignoreTimestamp;
            cpp_ignoreTimestamp = g_ignoreTimestamp;
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardByAppIdsAsync(
                [onSuccess](vector<RGN::Modules::Leaderboard::LeaderboardData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_LeaderboardData::ConvertToGodotModel(response_item, g_g_response_item);
                        g_gResponse.push_back(g_response_item);
                    }
                    gResponse = g_gResponse;
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_appIds,
                cpp_limit,
                cpp_startAfter,
                cpp_ignoreTimestamp
            );
    }
    void getLeaderboardByTagsAsync(
        godot::Array tags,
        int32_t limit,
        godot::String startAfter,
        bool ignoreTimestamp,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            vector<string> cpp_tags;
            int32_t cpp_limit;
            string cpp_startAfter;
            bool cpp_ignoreTimestamp;
            godot::Array g_cpp_tags = tags;
            for (int i = 0; i < g_cpp_tags.size(); ++i) {
                godot::String g_cpp_tags_item = g_cpp_tags[i];
                string cpp_tags_item;
                godot::String g_g_cpp_tags_item = g_cpp_tags_item;
                cpp_tags_item = std::string(g_g_cpp_tags_item.utf8().get_data());
                cpp_tags.push_back(cpp_tags_item);
            }
            int32_t g_limit = limit;
            cpp_limit = g_limit;
            godot::String g_startAfter = startAfter;
            cpp_startAfter = std::string(g_startAfter.utf8().get_data());
            bool g_ignoreTimestamp = ignoreTimestamp;
            cpp_ignoreTimestamp = g_ignoreTimestamp;
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardByTagsAsync(
                [onSuccess](vector<RGN::Modules::Leaderboard::LeaderboardData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_LeaderboardData::ConvertToGodotModel(response_item, g_g_response_item);
                        g_gResponse.push_back(g_response_item);
                    }
                    gResponse = g_gResponse;
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_tags,
                cpp_limit,
                cpp_startAfter,
                cpp_ignoreTimestamp
            );
    }
    void getLeaderboardForCurrentAppAsync(
        int32_t limit,
        godot::String startAfter,
        bool ignoreTimestamp,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            int32_t cpp_limit;
            string cpp_startAfter;
            bool cpp_ignoreTimestamp;
            int32_t g_limit = limit;
            cpp_limit = g_limit;
            godot::String g_startAfter = startAfter;
            cpp_startAfter = std::string(g_startAfter.utf8().get_data());
            bool g_ignoreTimestamp = ignoreTimestamp;
            cpp_ignoreTimestamp = g_ignoreTimestamp;
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardForCurrentAppAsync(
                [onSuccess](vector<RGN::Modules::Leaderboard::LeaderboardData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_LeaderboardData::ConvertToGodotModel(response_item, g_g_response_item);
                        g_gResponse.push_back(g_response_item);
                    }
                    gResponse = g_gResponse;
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_limit,
                cpp_startAfter,
                cpp_ignoreTimestamp
            );
    }
    void getLeaderboardIdsAsync(
        bool ignoreTimestamp,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            bool cpp_ignoreTimestamp;
            bool g_ignoreTimestamp = ignoreTimestamp;
            cpp_ignoreTimestamp = g_ignoreTimestamp;
            RGN::Modules::Leaderboard::LeaderboardModule::GetLeaderboardIdsAsync(
                [onSuccess](vector<string> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::String g_response_item;
                        g_response_item = godot::String(response_item.c_str());
                        g_gResponse.push_back(g_response_item);
                    }
                    gResponse = g_gResponse;
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_ignoreTimestamp
            );
    }
    void isLeaderboardAvailableAsync(
        godot::String leaderboardId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_leaderboardId;
            godot::String g_leaderboardId = leaderboardId;
            cpp_leaderboardId = std::string(g_leaderboardId.utf8().get_data());
            RGN::Modules::Leaderboard::LeaderboardModule::IsLeaderboardAvailableAsync(
                [onSuccess](RGN::Modules::Leaderboard::IsLeaderboardAvailableResponseData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_IsLeaderboardAvailableResponseData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_leaderboardId
            );
    }
    void isInPromoPeriodAsync(
        godot::String leaderboardId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_leaderboardId;
            godot::String g_leaderboardId = leaderboardId;
            cpp_leaderboardId = std::string(g_leaderboardId.utf8().get_data());
            RGN::Modules::Leaderboard::LeaderboardModule::IsInPromoPeriodAsync(
                [onSuccess](RGN::Modules::Leaderboard::IsInPromoPeriodResponseData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_IsInPromoPeriodResponseData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_leaderboardId
            );
    }
    void isInGracePeriodAsync(
        godot::String leaderboardId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_leaderboardId;
            godot::String g_leaderboardId = leaderboardId;
            cpp_leaderboardId = std::string(g_leaderboardId.utf8().get_data());
            RGN::Modules::Leaderboard::LeaderboardModule::IsInGracePeriodAsync(
                [onSuccess](RGN::Modules::Leaderboard::IsInGracePeriodResponseData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_IsInGracePeriodResponseData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_leaderboardId
            );
    }
    void setScoreAsync(
        godot::String leaderboardId,
        int32_t score,
        godot::String extraData,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_leaderboardId;
            int32_t cpp_score;
            string cpp_extraData;
            godot::String g_leaderboardId = leaderboardId;
            cpp_leaderboardId = std::string(g_leaderboardId.utf8().get_data());
            int32_t g_score = score;
            cpp_score = g_score;
            godot::String g_extraData = extraData;
            cpp_extraData = std::string(g_extraData.utf8().get_data());
            RGN::Modules::Leaderboard::LeaderboardModule::SetScoreAsync(
                [onSuccess](int32_t response) {
                    godot::Array gArgs;
                    int32_t gResponse;
                    gResponse = response;
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_leaderboardId,
                cpp_score,
                cpp_extraData
            );
    }
    void addScoreAsync(
        godot::String leaderboardId,
        int32_t score,
        godot::String extraData,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_leaderboardId;
            int32_t cpp_score;
            string cpp_extraData;
            godot::String g_leaderboardId = leaderboardId;
            cpp_leaderboardId = std::string(g_leaderboardId.utf8().get_data());
            int32_t g_score = score;
            cpp_score = g_score;
            godot::String g_extraData = extraData;
            cpp_extraData = std::string(g_extraData.utf8().get_data());
            RGN::Modules::Leaderboard::LeaderboardModule::AddScoreAsync(
                [onSuccess](int32_t response) {
                    godot::Array gArgs;
                    int32_t gResponse;
                    gResponse = response;
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_leaderboardId,
                cpp_score,
                cpp_extraData
            );
    }
    void getUserEntryAsync(
        godot::String leaderboardId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_leaderboardId;
            godot::String g_leaderboardId = leaderboardId;
            cpp_leaderboardId = std::string(g_leaderboardId.utf8().get_data());
            RGN::Modules::Leaderboard::LeaderboardModule::GetUserEntryAsync(
                [onSuccess](RGN::Modules::Leaderboard::LeaderboardEntry response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_LeaderboardEntry::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_leaderboardId
            );
    }
    void getEntriesAsync(
        godot::String leaderboardId,
        int32_t quantityTop,
        bool includeUser,
        int32_t quantityAroundUser,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_leaderboardId;
            int32_t cpp_quantityTop;
            bool cpp_includeUser;
            int32_t cpp_quantityAroundUser;
            godot::String g_leaderboardId = leaderboardId;
            cpp_leaderboardId = std::string(g_leaderboardId.utf8().get_data());
            int32_t g_quantityTop = quantityTop;
            cpp_quantityTop = g_quantityTop;
            bool g_includeUser = includeUser;
            cpp_includeUser = g_includeUser;
            int32_t g_quantityAroundUser = quantityAroundUser;
            cpp_quantityAroundUser = g_quantityAroundUser;
            RGN::Modules::Leaderboard::LeaderboardModule::GetEntriesAsync(
                [onSuccess](vector<RGN::Modules::Leaderboard::LeaderboardEntry> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_LeaderboardEntry::ConvertToGodotModel(response_item, g_g_response_item);
                        g_gResponse.push_back(g_response_item);
                    }
                    gResponse = g_gResponse;
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_leaderboardId,
                cpp_quantityTop,
                cpp_includeUser,
                cpp_quantityAroundUser
            );
    }
    void getResetsAsync(
        godot::String leaderboardId,
        bool withEntries,
        int64_t startAfter,
        int32_t limit,
        godot::String orderDirection,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_leaderboardId;
            bool cpp_withEntries;
            int64_t cpp_startAfter;
            int32_t cpp_limit;
            string cpp_orderDirection;
            godot::String g_leaderboardId = leaderboardId;
            cpp_leaderboardId = std::string(g_leaderboardId.utf8().get_data());
            bool g_withEntries = withEntries;
            cpp_withEntries = g_withEntries;
            int64_t g_startAfter = startAfter;
            cpp_startAfter = g_startAfter;
            int32_t g_limit = limit;
            cpp_limit = g_limit;
            godot::String g_orderDirection = orderDirection;
            cpp_orderDirection = std::string(g_orderDirection.utf8().get_data());
            RGN::Modules::Leaderboard::LeaderboardModule::GetResetsAsync(
                [onSuccess](vector<RGN::Modules::Leaderboard::LeaderboardReset> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_LeaderboardReset::ConvertToGodotModel(response_item, g_g_response_item);
                        g_gResponse.push_back(g_response_item);
                    }
                    gResponse = g_gResponse;
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_leaderboardId,
                cpp_withEntries,
                cpp_startAfter,
                cpp_limit,
                cpp_orderDirection
            );
    }
    void getResetAsync(
        godot::String leaderboardId,
        godot::String resetId,
        int64_t startAfter,
        int32_t limit,
        godot::String orderDirection,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_leaderboardId;
            string cpp_resetId;
            int64_t cpp_startAfter;
            int32_t cpp_limit;
            string cpp_orderDirection;
            godot::String g_leaderboardId = leaderboardId;
            cpp_leaderboardId = std::string(g_leaderboardId.utf8().get_data());
            godot::String g_resetId = resetId;
            cpp_resetId = std::string(g_resetId.utf8().get_data());
            int64_t g_startAfter = startAfter;
            cpp_startAfter = g_startAfter;
            int32_t g_limit = limit;
            cpp_limit = g_limit;
            godot::String g_orderDirection = orderDirection;
            cpp_orderDirection = std::string(g_orderDirection.utf8().get_data());
            RGN::Modules::Leaderboard::LeaderboardModule::GetResetAsync(
                [onSuccess](RGN::Modules::Leaderboard::LeaderboardReset response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_LeaderboardReset::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_leaderboardId,
                cpp_resetId,
                cpp_startAfter,
                cpp_limit,
                cpp_orderDirection
            );
    }
    void resetLeaderboardAsync(
        godot::String leaderboardId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_leaderboardId;
            godot::String g_leaderboardId = leaderboardId;
            cpp_leaderboardId = std::string(g_leaderboardId.utf8().get_data());
            RGN::Modules::Leaderboard::LeaderboardModule::ResetLeaderboardAsync(
                [onSuccess]() {
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_leaderboardId
            );
    }
};
