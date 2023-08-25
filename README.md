# ESP32 Discord Bot Library

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

A simple Arduino-based Discord Bot framework for the ESP32 MCU. Currently only supports basic slash commands, and additional features are still a work in progress.

Documentation is also a work-in-progress.

## Dependencies

- [ArduinoJson](https://github.com/bblanchon/ArduinoJson) 6.21.2
- [arduinoWebSockets](https://github.com/Links2004/arduinoWebSockets) 2.4.1

## Features

- Basic Discord WebSocket Gateway support with automatic Gateway URL retrieval
    - Heartbeat, Identify and Resume event handling
- Slash command registration, deletion, receiving and responding
    - Creation and deletion functions in optional `interactions.h` header
    - Respond with message or custom JSON payload
- Event reporting for most common Discord events

## Installation and Usage

Documentation WIP. For now, install the listed dependencies and see the example on how to setup the bot.

### Basic Setup

```cpp
Discord::Bot discord;

void setup() {
    /*
        Setup serial, Wi-Fi and others...
    */

    // Login with the provided bot token and no intent requirements.
    // If needed, specify intents in the second parameter as a number.
    // I recommend an intent calculator.
    discord.login(BOT_TOKEN);
    // Optional: Set the interaction handling callback.
    discord.onInteraction(on_discord_interaction);
    // Optional: Set the event handling callback.
    discord.onEvent(on_discord_event);
}

void loop() {
    // This needs to run even when the bot isn't connected.
    discord.update();
}

```

## Limitations

While the framework should be sufficient for simple bots, it does consume a significant amount of stack memory, and paired with large tasks, can cause an ESP32 to exceed its default loop task stack size of 8kB.

While I have taken steps to reduce stack depth, do avoid doing heavy stack operations within the interaction callback itself, or increase the task stack size.

Support for editing the response after responding with the `DEFERRED_CHANNEL_MESSAGE_WITH_SOURCE` type is still in the works.

### Loop Task Stack Size

To increase the stack size of the default loop task in ESP32, you can use the following snippet:
```cpp
SET_LOOP_TASK_STACK_SIZE(16 * 1024); // 16kB
```

## Support, Bug Reporting, Contributing

If you do find an issue with the library, or need help using it, do create a GitHub issue. I can't guarentee extensive support at this stage of development.

If you want to help, great! Feel free to fork this and file a pull request.