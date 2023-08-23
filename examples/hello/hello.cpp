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

#include <Arduino.h>
#include <Wifi.h>

#include <discord.h>
#include <interactions.h>

 // Wifi network credentials
#define WIFI_SSID ""
#define WIFI_PASSWORD ""
 // Discord Bot Token
#define BOT_TOKEN ""

Discord::Bot discord;

void on_discord_event(Discord::EventType type, const Discord::Event& data) {
    if (type != Discord::EventType::Ready) return;
    Serial.println("Registering commands...");
    /**
     * For this example, commands are registered via the Ready event. However, the registration persists
     * via Discord's servers, so avoid re-registering in your application unless you are making changes
    */
    Discord::Interactions::ApplicationCommand cmd;
    cmd.name = "hello";
    cmd.type = Discord::Interactions::CommandType::CHAT_INPUT;
    cmd.description = "Ping the bot for a greeting.";
    cmd.default_member_permissions = 2147483648; //Use Application Commands

    //[STACK CHANGE] Loop() - Free Stack Space: 6604 (-4672)
    uint64_t id = Discord::Interactions::registerGlobalCommand(discord, cmd, BOT_TOKEN);
    if (id == 0) {
        Serial.println("Command registration failed!");
    }
    else {
        Serial.print("Registered hello command to id ");
        Serial.println(id);
    }
}

void on_discord_interaction(const char* name, const JsonObject& interaction) {
    if (strcmp(name, "hello") == 0) {
        Discord::Bot::MessageResponse response;
        response.content = "Hello world!";
        //response.flags = Discord::Bot::MessageResponse::Flags::EPHEMERAL;
        discord.sendCommandResponse(Discord::Bot::InteractionResponse::CHANNEL_MESSAGE_WITH_SOURCE, response);
    }
}

// PROGRAM BEGIN

// put your setup code here, to run once:
void setup() {
    // Clear the serial port buffer and set the serial port baud rate to 115200.
    Serial.begin(115200);
    Serial.println();

    Serial.print("Establishing Wi-Fi connection to ");
    Serial.println(WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println("\nWiFi connected. Connecting to Discord...");

    discord.login(BOT_TOKEN);
    discord.onInteraction(on_discord_interaction);
    discord.onEvent(on_discord_event);
}

// put your main code here, to run repeatedly:
void loop() {
    discord.update(millis());
}
