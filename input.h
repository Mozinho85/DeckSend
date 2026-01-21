// Input event capture header
#ifndef INPUT_H
#define INPUT_H

struct ControllerEvent {
    int button;
    int trackpad_x;
    int trackpad_y;
    // Add more fields as needed
};

int init_input();
int read_input_event(struct ControllerEvent *event);
void cleanup_input();

#endif // INPUT_H
