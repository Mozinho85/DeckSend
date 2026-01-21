// Main entry point for Steam Deck sender app
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
