#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementsModule_Admin.h"
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementData.h"
#include "G_AchievementData.h"
#include "Impl/G_Defs.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_AchievementsModule_Admin : public godot::Object {
    REG_GCLASS(G_AchievementsModule_Admin, godot::Object);
#ifdef GODOT4
    static inline G_AchievementsModule_Admin* singleton = nullptr;
#endif
public:
#ifdef GODOT3
    void _init() {}
#else
    static G_AchievementsModule_Admin *get_singleton() {
        return singleton;
    }
    G_AchievementsModule_Admin() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_AchievementsModule_Admin() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
#endif
    REG_GCLASS_METHODS_HEADER() {
        BIND_GCLASS_METHOD_DEFVAL(G_AchievementsModule_Admin::addAchievementAsync, GCLASS_METHOD_SIGNATURE("addAchievementAsync", "achievementData", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_AchievementsModule_Admin::updateAchievementAsync, GCLASS_METHOD_SIGNATURE("updateAchievementAsync", "achievementData", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_AchievementsModule_Admin::deleteAchievementAsync, GCLASS_METHOD_SIGNATURE("deleteAchievementAsync", "achievementId", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_AchievementsModule_Admin::addLoginDaysInRowAchievementAsync_AchievementId_DaysInRow, GCLASS_METHOD_SIGNATURE("addLoginDaysInRowAchievementAsync_AchievementId_DaysInRow", "achievementId", "daysInRow", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_AchievementsModule_Admin::addLoginDaysInRowAchievementAsync_AchievementData_DaysInRow, GCLASS_METHOD_SIGNATURE("addLoginDaysInRowAchievementAsync_AchievementData_DaysInRow", "achievementData", "daysInRow", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_AchievementsModule_Admin::deleteLoginDaysInRowGameConstRecordAsync, GCLASS_METHOD_SIGNATURE("deleteLoginDaysInRowGameConstRecordAsync", "achievementId", "daysInRow", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_AchievementsModule_Admin::addPlayerProgressAchievementAsync_AchievementId_PlayerProgressFieldName_PlayerProgressFieldValueToReach, GCLASS_METHOD_SIGNATURE("addPlayerProgressAchievementAsync_AchievementId_PlayerProgressFieldName_PlayerProgressFieldValueToReach", "achievementId", "playerProgressFieldName", "playerProgressFieldValueToReach", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_AchievementsModule_Admin::addPlayerProgressAchievementAsync_AchievementData_PlayerProgressFieldName_PlayerProgressFieldValueToReach, GCLASS_METHOD_SIGNATURE("addPlayerProgressAchievementAsync_AchievementData_PlayerProgressFieldName_PlayerProgressFieldValueToReach", "achievementData", "playerProgressFieldName", "playerProgressFieldValueToReach", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_AchievementsModule_Admin::deletePlayerProgressAchievementAsync, GCLASS_METHOD_SIGNATURE("deletePlayerProgressAchievementAsync", "achievementId", "playerProgressFieldName", "playerProgressFieldValueToReach", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_AchievementsModule_Admin::addPurchaseAchievementAsync, GCLASS_METHOD_SIGNATURE("addPurchaseAchievementAsync", "achievementData", "virtualItemTag", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
        BIND_GCLASS_METHOD_DEFVAL(G_AchievementsModule_Admin::deletePurchaseGameConstRecordAsync, GCLASS_METHOD_SIGNATURE("deletePurchaseGameConstRecordAsync", "achievementId", "virtualItemTag", "onSuccess", "onFail"), GCALLBACK_DEFVAL, GCALLBACK_DEFVAL);
    }
    void addAchievementAsync(
        godot::Dictionary achievementData,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            G_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            RGN::Modules::Achievement::AchievementsModule_Admin::AddAchievementAsync(
                [onSuccess](string response) {
                    godot::Array gArgs;
                    godot::String gResponse;
                    gResponse = godot::String(response.c_str());
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_achievementData
            );
    }
    void updateAchievementAsync(
        godot::Dictionary achievementData,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            G_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            RGN::Modules::Achievement::AchievementsModule_Admin::UpdateAchievementAsync(
                [onSuccess](string response) {
                    godot::Array gArgs;
                    godot::String gResponse;
                    gResponse = godot::String(response.c_str());
                    gArgs.push_back(gResponse);
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_achievementData
            );
    }
    void deleteAchievementAsync(
        godot::String achievementId,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_achievementId;
            godot::String g_achievementId = achievementId;
            cpp_achievementId = std::string(g_achievementId.utf8().get_data());
            RGN::Modules::Achievement::AchievementsModule_Admin::DeleteAchievementAsync(
                [onSuccess]() {
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_achievementId
            );
    }
    void addLoginDaysInRowAchievementAsync_AchievementId_DaysInRow(
        godot::String achievementId,
        int32_t daysInRow,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_achievementId;
            int32_t cpp_daysInRow;
            godot::String g_achievementId = achievementId;
            cpp_achievementId = std::string(g_achievementId.utf8().get_data());
            int32_t g_daysInRow = daysInRow;
            cpp_daysInRow = g_daysInRow;
            RGN::Modules::Achievement::AchievementsModule_Admin::AddLoginDaysInRowAchievementAsync(
                [onSuccess]() {
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_achievementId,
                cpp_daysInRow
            );
    }
    void addLoginDaysInRowAchievementAsync_AchievementData_DaysInRow(
        godot::Dictionary achievementData,
        int32_t daysInRow,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            int32_t cpp_daysInRow;
            G_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            int32_t g_daysInRow = daysInRow;
            cpp_daysInRow = g_daysInRow;
            RGN::Modules::Achievement::AchievementsModule_Admin::AddLoginDaysInRowAchievementAsync(
                [onSuccess]() {
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_achievementData,
                cpp_daysInRow
            );
    }
    void deleteLoginDaysInRowGameConstRecordAsync(
        godot::String achievementId,
        int32_t daysInRow,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_achievementId;
            int32_t cpp_daysInRow;
            godot::String g_achievementId = achievementId;
            cpp_achievementId = std::string(g_achievementId.utf8().get_data());
            int32_t g_daysInRow = daysInRow;
            cpp_daysInRow = g_daysInRow;
            RGN::Modules::Achievement::AchievementsModule_Admin::DeleteLoginDaysInRowGameConstRecordAsync(
                [onSuccess]() {
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_achievementId,
                cpp_daysInRow
            );
    }
    void addPlayerProgressAchievementAsync_AchievementId_PlayerProgressFieldName_PlayerProgressFieldValueToReach(
        godot::String achievementId,
        godot::String playerProgressFieldName,
        int64_t playerProgressFieldValueToReach,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_achievementId;
            string cpp_playerProgressFieldName;
            int64_t cpp_playerProgressFieldValueToReach;
            godot::String g_achievementId = achievementId;
            cpp_achievementId = std::string(g_achievementId.utf8().get_data());
            godot::String g_playerProgressFieldName = playerProgressFieldName;
            cpp_playerProgressFieldName = std::string(g_playerProgressFieldName.utf8().get_data());
            int64_t g_playerProgressFieldValueToReach = playerProgressFieldValueToReach;
            cpp_playerProgressFieldValueToReach = g_playerProgressFieldValueToReach;
            RGN::Modules::Achievement::AchievementsModule_Admin::AddPlayerProgressAchievementAsync(
                [onSuccess]() {
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_achievementId,
                cpp_playerProgressFieldName,
                cpp_playerProgressFieldValueToReach
            );
    }
    void addPlayerProgressAchievementAsync_AchievementData_PlayerProgressFieldName_PlayerProgressFieldValueToReach(
        godot::Dictionary achievementData,
        godot::String playerProgressFieldName,
        int64_t playerProgressFieldValueToReach,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            string cpp_playerProgressFieldName;
            int64_t cpp_playerProgressFieldValueToReach;
            G_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            godot::String g_playerProgressFieldName = playerProgressFieldName;
            cpp_playerProgressFieldName = std::string(g_playerProgressFieldName.utf8().get_data());
            int64_t g_playerProgressFieldValueToReach = playerProgressFieldValueToReach;
            cpp_playerProgressFieldValueToReach = g_playerProgressFieldValueToReach;
            RGN::Modules::Achievement::AchievementsModule_Admin::AddPlayerProgressAchievementAsync(
                [onSuccess]() {
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_achievementData,
                cpp_playerProgressFieldName,
                cpp_playerProgressFieldValueToReach
            );
    }
    void deletePlayerProgressAchievementAsync(
        godot::String achievementId,
        godot::String playerProgressFieldName,
        int64_t playerProgressFieldValueToReach,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_achievementId;
            string cpp_playerProgressFieldName;
            int64_t cpp_playerProgressFieldValueToReach;
            godot::String g_achievementId = achievementId;
            cpp_achievementId = std::string(g_achievementId.utf8().get_data());
            godot::String g_playerProgressFieldName = playerProgressFieldName;
            cpp_playerProgressFieldName = std::string(g_playerProgressFieldName.utf8().get_data());
            int64_t g_playerProgressFieldValueToReach = playerProgressFieldValueToReach;
            cpp_playerProgressFieldValueToReach = g_playerProgressFieldValueToReach;
            RGN::Modules::Achievement::AchievementsModule_Admin::DeletePlayerProgressAchievementAsync(
                [onSuccess]() {
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_achievementId,
                cpp_playerProgressFieldName,
                cpp_playerProgressFieldValueToReach
            );
    }
    void addPurchaseAchievementAsync(
        godot::Dictionary achievementData,
        godot::String virtualItemTag,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            string cpp_virtualItemTag;
            G_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            godot::String g_virtualItemTag = virtualItemTag;
            cpp_virtualItemTag = std::string(g_virtualItemTag.utf8().get_data());
            RGN::Modules::Achievement::AchievementsModule_Admin::AddPurchaseAchievementAsync(
                [onSuccess]() {
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_achievementData,
                cpp_virtualItemTag
            );
    }
    void deletePurchaseGameConstRecordAsync(
        godot::String achievementId,
        godot::String virtualItemTag,
        GCALLBACK onSuccess,
        GCALLBACK onFail) {
            string cpp_achievementId;
            string cpp_virtualItemTag;
            godot::String g_achievementId = achievementId;
            cpp_achievementId = std::string(g_achievementId.utf8().get_data());
            godot::String g_virtualItemTag = virtualItemTag;
            cpp_virtualItemTag = std::string(g_virtualItemTag.utf8().get_data());
            RGN::Modules::Achievement::AchievementsModule_Admin::DeletePurchaseGameConstRecordAsync(
                [onSuccess]() {
                    EXECUTE_GCALLBACK_DEFVAL(onSuccess, godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     EXECUTE_GCALLBACK_DEFVAL(onFail, gArgs);
                },
                cpp_achievementId,
                cpp_virtualItemTag
            );
    }
};
