/*
 * ESP32-DiscordBot v0.1
 * Copyright (C) 2023  Neo Ting Wei Terrence
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _DISCORD_ESP32A_EVENTS_H_
#define _DISCORD_ESP32A_EVENTS_H_

namespace Discord {
    enum class EventType {
        Dispatch,
        Heartbeat,
        Identify,
        PresenceUpdate,
        VoiceStateUpdate,
        Resume = 6,
        Reconnect,
        RequestGuildMembers,
        InvalidSession,
        Hello,
        HeartbeatAck,

        // These are subsets of the actual Dispatch event, used for callback event handling optimisation
        Ready,
        Resumed,
        ApplicationCommandPermissionsUpdate,
        // Auto-moderation
        AutoModerationRuleCreate,
        AutoModerationRuleUpdate,
        AutoModerationRuleDelete,
        AutoModerationRuleExecution,
        // Channels
        ChannelCreate,
        ChannelUpdate,
        ChannelDelete,
        ThreadCreate,
        ThreadUpdate,
        ThreadDelete,
        ThreadListSync,
        ThreadMemberUpdate,
        ThreadMembersUpdate,
        ChannelPinsUpdate,
        // Guilds
        GuildCreate,
        GuildUpdate,
        GuildDelete,
        GuildAuditLogEntryCreate,
        GuildBanAdd,
        GuildBanRemove,
        GuildEmojisUpdate,
        GuildStickersUpdate,
        GuildIntegrationsUpdate,
        GuildMemberAdd,
        GuildMemberRemove,
        GuildMemberUpdate,
        GuildMembersChunk,
        GuildRoleCreate,
        GuildRoleUpdate,
        GuildRoleDelete,
        GuildScheduledEventCreate,
        GuildScheduledEventUpdate,
        GuildScheduledEventDelete,
        GuildScheduledEventUserAdd,
        GuildScheduledEventUserRemove,
        //Integrations
        IntegrationCreate,
        IntegrationUpdate,
        IntegrationDelete,
        //Interactions
        InteractionCreate,
        //Invite
        InviteCreate,
        InviteDelete,
        //Messages
        MessageCreate,
        MessageUpdate,
        MessageDelete,
        MessageDeleteBulk,
        //Reactions
        MessageReactionAdd,
        MessageReactionRemove,
        MessageReactionRemoveAll,
        MessageReactionRemoveEmoji,
        //Stage
        StageInstanceCreate,
        StageInstanceUpdate,
        StageInstanceDelete,
        //Misc
        TypingStart,
        UserUpdate,
        VoiceServerUpdate,
        WebhooksUpdate
    };

    union Event {
        EventType type;
    };
}

#endif //_DISCORD_ESP32A_EVENTS_H_
