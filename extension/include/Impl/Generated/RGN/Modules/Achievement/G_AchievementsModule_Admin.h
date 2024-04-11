#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementsModule_Admin.h"
#include "../../../../../Generated/RGN/Modules/Achievement/AchievementData.h"
#include "G_AchievementData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_AchievementsModule_Admin : public godot::Object {
    GDCLASS(G_AchievementsModule_Admin, godot::Object);
    static inline G_AchievementsModule_Admin* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("addAchievementAsync", "achievementData", "onSuccess", "onFail"), &G_AchievementsModule_Admin::addAchievementAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("updateAchievementAsync", "achievementData", "onSuccess", "onFail"), &G_AchievementsModule_Admin::updateAchievementAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("deleteAchievementAsync", "achievementId", "onSuccess", "onFail"), &G_AchievementsModule_Admin::deleteAchievementAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("addLoginDaysInRowAchievementAsync_AchievementId_DaysInRow", "achievementId", "daysInRow", "onSuccess", "onFail"), &G_AchievementsModule_Admin::addLoginDaysInRowAchievementAsync_AchievementId_DaysInRow, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("addLoginDaysInRowAchievementAsync_AchievementData_DaysInRow", "achievementData", "daysInRow", "onSuccess", "onFail"), &G_AchievementsModule_Admin::addLoginDaysInRowAchievementAsync_AchievementData_DaysInRow, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("deleteLoginDaysInRowGameConstRecordAsync", "achievementId", "daysInRow", "onSuccess", "onFail"), &G_AchievementsModule_Admin::deleteLoginDaysInRowGameConstRecordAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("addPlayerProgressAchievementAsync_AchievementId_PlayerProgressFieldName_PlayerProgressFieldValueToReach", "achievementId", "playerProgressFieldName", "playerProgressFieldValueToReach", "onSuccess", "onFail"), &G_AchievementsModule_Admin::addPlayerProgressAchievementAsync_AchievementId_PlayerProgressFieldName_PlayerProgressFieldValueToReach, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("addPlayerProgressAchievementAsync_AchievementData_PlayerProgressFieldName_PlayerProgressFieldValueToReach", "achievementData", "playerProgressFieldName", "playerProgressFieldValueToReach", "onSuccess", "onFail"), &G_AchievementsModule_Admin::addPlayerProgressAchievementAsync_AchievementData_PlayerProgressFieldName_PlayerProgressFieldValueToReach, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("deletePlayerProgressAchievementAsync", "achievementId", "playerProgressFieldName", "playerProgressFieldValueToReach", "onSuccess", "onFail"), &G_AchievementsModule_Admin::deletePlayerProgressAchievementAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("addPurchaseAchievementAsync", "achievementData", "virtualItemTag", "onSuccess", "onFail"), &G_AchievementsModule_Admin::addPurchaseAchievementAsync, godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("deletePurchaseGameConstRecordAsync", "achievementId", "virtualItemTag", "onSuccess", "onFail"), &G_AchievementsModule_Admin::deletePurchaseGameConstRecordAsync, godot::Callable(), godot::Callable());
    }
public:
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
    void addAchievementAsync(
        godot::Dictionary achievementData,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            G_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            RGN::Modules::Achievement::AchievementsModule_Admin::AddAchievementAsync(
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
                cpp_achievementData
            );
    }
    void updateAchievementAsync(
        godot::Dictionary achievementData,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            G_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            RGN::Modules::Achievement::AchievementsModule_Admin::UpdateAchievementAsync(
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
                cpp_achievementData
            );
    }
    void deleteAchievementAsync(
        godot::String achievementId,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_achievementId;
            godot::String g_achievementId = achievementId;
            cpp_achievementId = std::string(g_achievementId.utf8().get_data());
            RGN::Modules::Achievement::AchievementsModule_Admin::DeleteAchievementAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_achievementId
            );
    }
    void addLoginDaysInRowAchievementAsync_AchievementId_DaysInRow(
        godot::String achievementId,
        int32_t daysInRow,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_achievementId;
            int32_t cpp_daysInRow;
            godot::String g_achievementId = achievementId;
            cpp_achievementId = std::string(g_achievementId.utf8().get_data());
            int32_t g_daysInRow = daysInRow;
            cpp_daysInRow = g_daysInRow;
            RGN::Modules::Achievement::AchievementsModule_Admin::AddLoginDaysInRowAchievementAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_achievementId,
                cpp_daysInRow
            );
    }
    void addLoginDaysInRowAchievementAsync_AchievementData_DaysInRow(
        godot::Dictionary achievementData,
        int32_t daysInRow,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            int32_t cpp_daysInRow;
            G_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            int32_t g_daysInRow = daysInRow;
            cpp_daysInRow = g_daysInRow;
            RGN::Modules::Achievement::AchievementsModule_Admin::AddLoginDaysInRowAchievementAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_achievementData,
                cpp_daysInRow
            );
    }
    void deleteLoginDaysInRowGameConstRecordAsync(
        godot::String achievementId,
        int32_t daysInRow,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_achievementId;
            int32_t cpp_daysInRow;
            godot::String g_achievementId = achievementId;
            cpp_achievementId = std::string(g_achievementId.utf8().get_data());
            int32_t g_daysInRow = daysInRow;
            cpp_daysInRow = g_daysInRow;
            RGN::Modules::Achievement::AchievementsModule_Admin::DeleteLoginDaysInRowGameConstRecordAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_achievementId,
                cpp_daysInRow
            );
    }
    void addPlayerProgressAchievementAsync_AchievementId_PlayerProgressFieldName_PlayerProgressFieldValueToReach(
        godot::String achievementId,
        godot::String playerProgressFieldName,
        int64_t playerProgressFieldValueToReach,
        godot::Callable onSuccess,
        godot::Callable onFail) {
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
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
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
        godot::Callable onSuccess,
        godot::Callable onFail) {
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
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
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
        godot::Callable onSuccess,
        godot::Callable onFail) {
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
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_achievementId,
                cpp_playerProgressFieldName,
                cpp_playerProgressFieldValueToReach
            );
    }
    void addPurchaseAchievementAsync(
        godot::Dictionary achievementData,
        godot::String virtualItemTag,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::Achievement::AchievementData cpp_achievementData;
            string cpp_virtualItemTag;
            G_AchievementData::ConvertToCoreModel(achievementData, cpp_achievementData);
            godot::String g_virtualItemTag = virtualItemTag;
            cpp_virtualItemTag = std::string(g_virtualItemTag.utf8().get_data());
            RGN::Modules::Achievement::AchievementsModule_Admin::AddPurchaseAchievementAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_achievementData,
                cpp_virtualItemTag
            );
    }
    void deletePurchaseGameConstRecordAsync(
        godot::String achievementId,
        godot::String virtualItemTag,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_achievementId;
            string cpp_virtualItemTag;
            godot::String g_achievementId = achievementId;
            cpp_achievementId = std::string(g_achievementId.utf8().get_data());
            godot::String g_virtualItemTag = virtualItemTag;
            cpp_virtualItemTag = std::string(g_virtualItemTag.utf8().get_data());
            RGN::Modules::Achievement::AchievementsModule_Admin::DeletePurchaseGameConstRecordAsync(
                [onSuccess]() {
                    onSuccess.callv(godot::Array());
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_achievementId,
                cpp_virtualItemTag
            );
    }
};
