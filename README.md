# Steam Deck Sender App

This app lets you use your Steam Deck as a Steam Controller on a Linux PC (Fedora/Bazzite).

## Features
- Captures button and trackpad events
- Emulates Steam Controller over Bluetooth HID (work in progress)
- Sends controller input to paired PC for native Steam support

## Requirements
- Bazzite (Fedora) on Steam Deck
- Bluetooth enabled
- Dependencies:
  - cmake
  - gcc
  - libevdev-devel
  - bluez
  - bluez-libs-devel


## Installation

### Option 1: Use Pre-built Binary
1. **Install runtime dependencies:**
   ```sh
   sudo dnf install -y libevdev bluez bluez-libs
   ```
2. **Run the app:**
   ```sh
   sudo ./steamdeck_sender
   ```
   - You may need to adjust the input device path in `input.c` (e.g., `/dev/input/event0`).

### Option 2: Build from Source
1. **Install build dependencies:**
   ```sh
   sudo dnf install -y cmake gcc libevdev-devel bluez bluez-libs-devel
   ```
2. **Build the app:**
   ```sh
   cd steamdeck_sender
   mkdir build && cd build
   cmake ..
   make
   ```
3. **Run the app:**
   ```sh
   sudo ./steamdeck_sender
   ```

## Bluetooth Setup
- Make sure Bluetooth is enabled:
  ```sh
  systemctl start bluetooth
  ```
- Pair the Steam Deck with your Fedora PC using Bluetooth settings.

## Notes
- Bluetooth HID emulation is a work in progress. Steam Controller detection may require further protocol implementation.
- For advanced configuration, edit the source files as needed.

## Support
If you need help, open an issue or ask for guidance.
