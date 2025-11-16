// Context: LED controller color table header

// seed_028_NC.h
#pragma once
unsigned long seed028_color_map[4] = {0xFF0000};
unsigned long seed028_get_color(int i) {
    return seed028_color_map[i];
}
