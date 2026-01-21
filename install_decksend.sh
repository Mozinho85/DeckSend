#!/bin/bash
set -e

# Helper: show a graphical message if zenity is available, else echo
show_msg() {
    if command -v zenity &> /dev/null; then
        zenity --info --text="$1"
    else
        echo "$1"
    fi
}

# Check for toolbox (recommended for immutable Fedora/Bazzite)
if command -v toolbox &> /dev/null; then
    show_msg "Detected immutable Fedora/Bazzite. Using toolbox for build."
    toolbox run bash -c '
        set -e
        sudo dnf install -y gcc cmake libevdev-devel bluez bluez-libs-devel || true
        cd "$(dirname "$0")"
        mkdir -p build
        cd build
        cmake ..
        make
    '
    BIN_PATH="$(pwd)/build/steamdeck_sender"
else
    # Try rpm-ostree for system-wide install
    if command -v rpm-ostree &> /dev/null; then
        show_msg "Installing build dependencies system-wide with rpm-ostree. This may require a reboot."
        pkexec rpm-ostree install gcc cmake libevdev-devel bluez bluez-libs-devel || true
        show_msg "If new packages were installed, please reboot and re-run this installer."
    fi
    # Try dnf as fallback (for non-immutable systems)
    if command -v dnf &> /dev/null; then
        sudo dnf install -y gcc cmake libevdev-devel bluez bluez-libs-devel || true
    fi
    # Build the app
    cd "$(dirname "$0")"
    mkdir -p build
    cd build
    cmake ..
    make
    BIN_PATH="$(pwd)/steamdeck_sender"
fi

# Create .desktop shortcut
cat > ~/.local/share/applications/io.github.Mozinho85.DeckSend.desktop <<EOF
[Desktop Entry]
Name=DeckSend
Comment=Use your Steam Deck as a controller
Exec=$BIN_PATH
Icon=application-x-executable
Terminal=false
Type=Application
Categories=Utility;Game;
EOF

show_msg "DeckSend is installed! You can now launch it from your application menu."
