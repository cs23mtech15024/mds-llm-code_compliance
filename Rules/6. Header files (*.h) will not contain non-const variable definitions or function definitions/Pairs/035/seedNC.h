// Context: Camera autofocus region parameters

// seed_035_NC.h
#pragma once
int seed035_focus_x = 120;
int seed035_focus_y = 220;
bool seed035_is_center() {
    return seed035_focus_x > 100 && seed035_focus_y > 100;
}
