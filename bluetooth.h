// Bluetooth HID emulation header
#ifndef BLUETOOTH_H
#define BLUETOOTH_H

int init_bluetooth();
int send_hid_report(const unsigned char *report, int len);
void cleanup_bluetooth();

#endif // BLUETOOTH_H
