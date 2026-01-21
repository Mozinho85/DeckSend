// Input event capture implementation
#include "input.h"
#include <libevdev/libevdev.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static struct libevdev *dev = NULL;
static int fd = -1;

int init_input() {
    fd = open("/dev/input/event0", O_RDONLY|O_NONBLOCK);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    if (libevdev_new_from_fd(fd, &dev) < 0) {
        perror("libevdev_new_from_fd");
        return 1;
    }
    printf("Input device: %s\n", libevdev_get_name(dev));
    return 0;
}

int read_input_event(struct ControllerEvent *event) {
    struct input_event ev;
    int rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
    if (rc == 0) {
        if (ev.type == EV_KEY) {
            event->button = ev.value;
        } else if (ev.type == EV_ABS) {
            if (ev.code == ABS_X) event->trackpad_x = ev.value;
            if (ev.code == ABS_Y) event->trackpad_y = ev.value;
        }
        return 0;
    }
    return 1;
}

void cleanup_input() {
    if (dev) libevdev_free(dev);
    if (fd >= 0) close(fd);
}
