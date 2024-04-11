#pragma once
// This file is generated: please don't modify. Go to Unity code generator if you need changes.
#include "../../../../Utility/G_CancellationToken.h"
#include "../../../../../Utility/CancellationToken.h"
#include "../../../../../Generated/RGN/Modules/Matchmaking/MatchmakingModule.h"
#include "../../../../../Generated/RGN/Modules/Matchmaking/GetMatchesResponseData.h"
#include "G_GetMatchesResponseData.h"
#include "../../../../../Generated/RGN/Modules/Matchmaking/MatchmakingData.h"
#include "G_MatchmakingData.h"
#include "../../../../../Generated/RGN/Modules/Matchmaking/GetMatchResponseData.h"
#include "G_GetMatchResponseData.h"
#include "../../../../../Generated/RGN/Modules/Matchmaking/StartMatchResponseData.h"
#include "G_StartMatchResponseData.h"
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

class G_MatchmakingModule : public godot::Object {
    GDCLASS(G_MatchmakingModule, godot::Object);
    static inline G_MatchmakingModule* singleton = nullptr;
protected:
    static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("getJoinOpenMatchesAsync", "limit", "startAfter", "cancellationToken", "onSuccess", "onFail"), &G_MatchmakingModule::getJoinOpenMatchesAsync, DEFVAL(""), DEFVAL(nullptr), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getVoteOpenMatchesAsync", "limit", "startAfter", "cancellationToken", "onSuccess", "onFail"), &G_MatchmakingModule::getVoteOpenMatchesAsync, DEFVAL(""), DEFVAL(nullptr), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getFinishedMatchesAsync", "limit", "startAfter", "cancellationToken", "onSuccess", "onFail"), &G_MatchmakingModule::getFinishedMatchesAsync, DEFVAL(""), DEFVAL(nullptr), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("getFinishedMatchByIdAsync", "matchId", "cancellationToken", "onSuccess", "onFail"), &G_MatchmakingModule::getFinishedMatchByIdAsync, DEFVAL(nullptr), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("createMatchAsync", "matchConfig", "participatePayload", "participateInOnCreate", "cancellationToken", "onSuccess", "onFail"), &G_MatchmakingModule::createMatchAsync, DEFVAL(godot::Dictionary()), DEFVAL(true), DEFVAL(nullptr), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("participateInMatchAsync", "matchId", "participantPayload", "cancellationToken", "onSuccess", "onFail"), &G_MatchmakingModule::participateInMatchAsync, DEFVAL(godot::Dictionary()), DEFVAL(nullptr), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("startMatchAsync", "matchId", "cancellationToken", "onSuccess", "onFail"), &G_MatchmakingModule::startMatchAsync, DEFVAL(nullptr), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("voteForMatchAsync", "matchId", "participantId", "cancellationToken", "onSuccess", "onFail"), &G_MatchmakingModule::voteForMatchAsync, DEFVAL(nullptr), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("submitMatchScoreAsync", "matchId", "score", "cancellationToken", "onSuccess", "onFail"), &G_MatchmakingModule::submitMatchScoreAsync, DEFVAL(nullptr), godot::Callable(), godot::Callable());
        godot::ClassDB::bind_method(godot::D_METHOD("finishMatchAsync", "matchId", "cancellationToken", "onSuccess", "onFail"), &G_MatchmakingModule::finishMatchAsync, DEFVAL(nullptr), godot::Callable(), godot::Callable());
    }
public:
    static G_MatchmakingModule *get_singleton() {
        return singleton;
    }
    G_MatchmakingModule() {
        ERR_FAIL_COND(singleton != nullptr);
        singleton = this;
    }
    ~G_MatchmakingModule() {
        ERR_FAIL_COND(singleton != this);
        singleton = nullptr;
    }
    void getJoinOpenMatchesAsync(
        int32_t limit,
        godot::String startAfter,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            int32_t cpp_limit;
            string cpp_startAfter;
            RGN::CancellationToken cpp_cancellationToken;
            int32_t g_limit = limit;
            cpp_limit = g_limit;
            godot::String g_startAfter = startAfter;
            cpp_startAfter = std::string(g_startAfter.utf8().get_data());
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Matchmaking::MatchmakingModule::GetJoinOpenMatchesAsync(
                [onSuccess](vector<RGN::Modules::Matchmaking::MatchmakingData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_MatchmakingData::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_limit,
                cpp_startAfter,
                cpp_cancellationToken
            );
    }
    void getVoteOpenMatchesAsync(
        int32_t limit,
        godot::String startAfter,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            int32_t cpp_limit;
            string cpp_startAfter;
            RGN::CancellationToken cpp_cancellationToken;
            int32_t g_limit = limit;
            cpp_limit = g_limit;
            godot::String g_startAfter = startAfter;
            cpp_startAfter = std::string(g_startAfter.utf8().get_data());
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Matchmaking::MatchmakingModule::GetVoteOpenMatchesAsync(
                [onSuccess](vector<RGN::Modules::Matchmaking::MatchmakingData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_MatchmakingData::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_limit,
                cpp_startAfter,
                cpp_cancellationToken
            );
    }
    void getFinishedMatchesAsync(
        int32_t limit,
        godot::String startAfter,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            int32_t cpp_limit;
            string cpp_startAfter;
            RGN::CancellationToken cpp_cancellationToken;
            int32_t g_limit = limit;
            cpp_limit = g_limit;
            godot::String g_startAfter = startAfter;
            cpp_startAfter = std::string(g_startAfter.utf8().get_data());
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Matchmaking::MatchmakingModule::GetFinishedMatchesAsync(
                [onSuccess](vector<RGN::Modules::Matchmaking::MatchmakingData> response) {
                    godot::Array gArgs;
                    godot::Array gResponse;
                    godot::Array g_gResponse;
                    for (const auto& response_item : response) {
                        godot::Dictionary g_response_item;
                        godot::Dictionary g_g_response_item = g_response_item;
                        G_MatchmakingData::ConvertToGodotModel(response_item, g_g_response_item);
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
                cpp_limit,
                cpp_startAfter,
                cpp_cancellationToken
            );
    }
    void getFinishedMatchByIdAsync(
        godot::String matchId,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_matchId;
            RGN::CancellationToken cpp_cancellationToken;
            godot::String g_matchId = matchId;
            cpp_matchId = std::string(g_matchId.utf8().get_data());
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Matchmaking::MatchmakingModule::GetFinishedMatchByIdAsync(
                [onSuccess](RGN::Modules::Matchmaking::MatchmakingData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_MatchmakingData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_matchId,
                cpp_cancellationToken
            );
    }
    void createMatchAsync(
        godot::Dictionary matchConfig,
        godot::Dictionary participatePayload,
        bool participateInOnCreate,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            RGN::Modules::Matchmaking::MatchmakingData cpp_matchConfig;
            std::unordered_map<string, string> cpp_participatePayload;
            bool cpp_participateInOnCreate;
            RGN::CancellationToken cpp_cancellationToken;
            G_MatchmakingData::ConvertToCoreModel(matchConfig, cpp_matchConfig);
            godot::Dictionary g_participatePayload = participatePayload;
            godot::Array g_participatePayload_keys = g_participatePayload.keys();
            for (int i = 0; i < g_participatePayload_keys.size(); ++i) {
                godot::String g_participatePayload_key = g_participatePayload_keys[i];
                godot::String g_participatePayload_value = g_participatePayload[g_participatePayload_key];
                string cpp_participatePayload_key;
                godot::String g_g_participatePayload_key = g_participatePayload_key;
                cpp_participatePayload_key = std::string(g_g_participatePayload_key.utf8().get_data());
                string cpp_participatePayload_value;
                godot::String g_g_participatePayload_value = g_participatePayload_value;
                cpp_participatePayload_value = std::string(g_g_participatePayload_value.utf8().get_data());
                cpp_participatePayload.insert({cpp_participatePayload_key, cpp_participatePayload_value});
            }
            bool g_participateInOnCreate = participateInOnCreate;
            cpp_participateInOnCreate = g_participateInOnCreate;
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Matchmaking::MatchmakingModule::CreateMatchAsync(
                [onSuccess](RGN::Modules::Matchmaking::MatchmakingData response) {
                    godot::Array gArgs;
                    godot::Dictionary gResponse;
                    godot::Dictionary g_gResponse = gResponse;
                    G_MatchmakingData::ConvertToGodotModel(response, g_gResponse);
                    gArgs.push_back(gResponse);
                    onSuccess.callv(gArgs);
                },
                [onFail](int code, std::string message) {
                     godot::Array gArgs;
                     gArgs.push_back(code);
                     gArgs.push_back(godot::String(message.c_str()));
                     onFail.callv(gArgs);
                },
                cpp_matchConfig,
                cpp_participatePayload,
                cpp_participateInOnCreate,
                cpp_cancellationToken
            );
    }
    void participateInMatchAsync(
        godot::String matchId,
        godot::Dictionary participantPayload,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_matchId;
            std::unordered_map<string, string> cpp_participantPayload;
            RGN::CancellationToken cpp_cancellationToken;
            godot::String g_matchId = matchId;
            cpp_matchId = std::string(g_matchId.utf8().get_data());
            godot::Dictionary g_participantPayload = participantPayload;
            godot::Array g_participantPayload_keys = g_participantPayload.keys();
            for (int i = 0; i < g_participantPayload_keys.size(); ++i) {
                godot::String g_participantPayload_key = g_participantPayload_keys[i];
                godot::String g_participantPayload_value = g_participantPayload[g_participantPayload_key];
                string cpp_participantPayload_key;
                godot::String g_g_participantPayload_key = g_participantPayload_key;
                cpp_participantPayload_key = std::string(g_g_participantPayload_key.utf8().get_data());
                string cpp_participantPayload_value;
                godot::String g_g_participantPayload_value = g_participantPayload_value;
                cpp_participantPayload_value = std::string(g_g_participantPayload_value.utf8().get_data());
                cpp_participantPayload.insert({cpp_participantPayload_key, cpp_participantPayload_value});
            }
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Matchmaking::MatchmakingModule::ParticipateInMatchAsync(
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
                cpp_matchId,
                cpp_participantPayload,
                cpp_cancellationToken
            );
    }
    void startMatchAsync(
        godot::String matchId,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_matchId;
            RGN::CancellationToken cpp_cancellationToken;
            godot::String g_matchId = matchId;
            cpp_matchId = std::string(g_matchId.utf8().get_data());
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Matchmaking::MatchmakingModule::StartMatchAsync(
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
                cpp_matchId,
                cpp_cancellationToken
            );
    }
    void voteForMatchAsync(
        godot::String matchId,
        godot::String participantId,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_matchId;
            string cpp_participantId;
            RGN::CancellationToken cpp_cancellationToken;
            godot::String g_matchId = matchId;
            cpp_matchId = std::string(g_matchId.utf8().get_data());
            godot::String g_participantId = participantId;
            cpp_participantId = std::string(g_participantId.utf8().get_data());
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Matchmaking::MatchmakingModule::VoteForMatchAsync(
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
                cpp_matchId,
                cpp_participantId,
                cpp_cancellationToken
            );
    }
    void submitMatchScoreAsync(
        godot::String matchId,
        int64_t score,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_matchId;
            int64_t cpp_score;
            RGN::CancellationToken cpp_cancellationToken;
            godot::String g_matchId = matchId;
            cpp_matchId = std::string(g_matchId.utf8().get_data());
            int64_t g_score = score;
            cpp_score = g_score;
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Matchmaking::MatchmakingModule::SubmitMatchScoreAsync(
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
                cpp_matchId,
                cpp_score,
                cpp_cancellationToken
            );
    }
    void finishMatchAsync(
        godot::String matchId,
        godot::Object* cancellationToken,
        godot::Callable onSuccess,
        godot::Callable onFail) {
            string cpp_matchId;
            RGN::CancellationToken cpp_cancellationToken;
            godot::String g_matchId = matchId;
            cpp_matchId = std::string(g_matchId.utf8().get_data());
            G_CancellationToken::ConvertToCoreModel(cancellationToken, cpp_cancellationToken);
            RGN::Modules::Matchmaking::MatchmakingModule::FinishMatchAsync(
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
                cpp_matchId,
                cpp_cancellationToken
            );
    }
};
