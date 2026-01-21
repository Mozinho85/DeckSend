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



## Installation on Steam Deck (Bazzite/Silverblue/Fedora Immutable)

### Option 1: System-wide install with rpm-ostree

1. Open a terminal in Desktop Mode.
2. Run:
   ```sh
   sudo rpm-ostree install git cmake gcc libevdev-devel bluez bluez-libs-devel
   ```
3. **Reboot** your Steam Deck after installation.

### Option 2: Use a Toolbox (Recommended for Development)

1. Create and enter a toolbox:
   ```sh
   toolbox create
   toolbox enter
   ```
2. Install dependencies inside the toolbox:
   ```sh
   sudo dnf install -y git cmake gcc libevdev-devel bluez bluez-libs-devel
   ```

---

## Clone and Build

```sh
git clone https://github.com/Mozinho85/DeckSend.git
cd DeckSend/steamdeck_sender
mkdir build
cd build
cmake ..
make
```

---

## Run the App

```sh
sudo ./steamdeck_sender
```
- You may need to adjust input device paths in the code if you get errors about input devices.

---

## Bluetooth Setup

Make sure Bluetooth is enabled:
```sh
sudo systemctl start bluetooth
```
Pair your Steam Deck with your PC using Bluetooth settings.

---

## Notes

- For immutable systems, toolbox is recommended for development.
- If you encounter issues, ensure you are in Desktop Mode and have a working network connection.

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
