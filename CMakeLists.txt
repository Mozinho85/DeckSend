# Steam Deck Sender App
# CMake project for building the Steam Deck controller emulator
cmake_minimum_required(VERSION 3.10)
project(steamdeck_sender)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBEVDEV REQUIRED libevdev)
pkg_check_modules(BLUEZ REQUIRED bluez)

include_directories(${LIBEVDEV_INCLUDE_DIRS} ${BLUEZ_INCLUDE_DIRS})
link_directories(${LIBEVDEV_LIBRARY_DIRS} ${BLUEZ_LIBRARY_DIRS})

add_executable(steamdeck_sender main.c input.c bluetooth.c hid.c)

target_link_libraries(steamdeck_sender ${LIBEVDEV_LIBRARIES} ${BLUEZ_LIBRARIES})
