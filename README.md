# Graphical Installer (Recommended for Bazzite/Fedora Immutable)

1. Copy the project folder to your Steam Deck.
2. In Desktop Mode, right-click `install_decksend.sh`, go to Properties → Permissions, and check "Is executable".
3. Double-click `install_decksend.sh` to run the installer.
4. Follow the prompts. The app will build and install itself, and a launcher will appear in your app menu.

**The installer will automatically use toolbox (if available), rpm-ostree, or dnf as needed.**

---

## Manual Installation (Advanced)

If you prefer, you can still build and install manually using toolbox, rpm-ostree, or dnf as described earlier in this README.

# Example: Main Entry Point (`main.c`)

Below is the main entry point for the sender app. It initializes input and Bluetooth, reads controller events, builds HID reports, and sends them over Bluetooth:

```c
#include "input.h"
#include "bluetooth.h"
#include "hid.h"
#include <stdio.h>

int main() {
   printf("Steam Deck Sender App Starting...\n");
   if (init_input() != 0) {
      fprintf(stderr, "Failed to initialize input\n");
      return 1;
   }
   if (init_bluetooth() != 0) {
      fprintf(stderr, "Failed to initialize Bluetooth\n");
      return 1;
   }
   while (1) {
      struct ControllerEvent event;
      if (read_input_event(&event) == 0) {
         unsigned char report[64];
         build_hid_report(&event, report);
         send_hid_report(report, sizeof(report));
      }
   }
   cleanup_input();
   cleanup_bluetooth();
   return 0;
}
```

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
