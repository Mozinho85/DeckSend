// HID report builder implementation
#include "hid.h"
#include <string.h>

void build_hid_report(const struct ControllerEvent *event, unsigned char *report) {
    memset(report, 0, 64);
    report[0] = 0x01; // Report ID (example)
    report[1] = event->button & 0xFF;
    report[2] = (event->trackpad_x >> 8) & 0xFF;
    report[3] = event->trackpad_x & 0xFF;
    report[4] = (event->trackpad_y >> 8) & 0xFF;
    report[5] = event->trackpad_y & 0xFF;
    // Add more fields as needed for full Steam Controller report
}
