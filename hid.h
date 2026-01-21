// HID report builder header
#ifndef HID_H
#define HID_H

#include "input.h"

void build_hid_report(const struct ControllerEvent *event, unsigned char *report);

#endif // HID_H
