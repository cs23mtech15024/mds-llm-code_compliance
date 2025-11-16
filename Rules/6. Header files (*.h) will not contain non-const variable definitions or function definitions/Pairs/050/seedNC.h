// Context: Display color temperature adjustment header

// seed_050_NC.h
#pragma once
int seed050_color_temp = 6500;
int seed050_adjust(int ambient) {
    return seed050_color_temp + ambient;
}
