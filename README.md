<div align="center" markdown="1">
<img src=".github/meshtastic_logo.png" alt="Meshtastic Logo" width="80"/>
</div>

# MODIFIED Meshtastic Firmware

## List of modifications
 - Added Ping module
   Module that automatically sends `Ping` with delay of `MODULE_PING_DELAY` define.
   To enable this module you should use
   ```
   export PLATFORMIO_BUILD_FLAGS="-D MESHTASTIC_EXCLUDE_PING=0 -DMODULE_PING_DELAY=<Delay in ms, default 30000 (30 sec)>"
   ```
 - Added Pong module
   Module that automatically send `Pong ...` reply to `Ping` message 

## Overview

This repository contains the modified device firmware for Meshtastic, an open-source LoRa mesh networking project designed for long-range, low-power communication without relying on internet or cellular infrastructure. The firmware supports various hardware platforms, including ESP32, nRF52, RP2040/RP2350, and Linux-based devices.

Meshtastic enables text messaging, location sharing, and telemetry over a decentralized mesh network, making it ideal for outdoor adventures, emergency preparedness, and remote operations.

### Get Started

- 🔧 **[Building Instructions](https://meshtastic.org/docs/development/firmware/build)** – Learn how to compile the firmware from source.
- ⚡ **[Flashing Instructions](https://meshtastic.org/docs/getting-started/flashing-firmware/)** – Install or update the firmware on your device.

Join our community and help improve Meshtastic! 🚀

## Stats

![Alt](https://repobeats.axiom.co/api/embed/8025e56c482ec63541593cc5bd322c19d5c0bdcf.svg "Repobeats analytics image")

