// Context: Display brightness profile header

// seed_025_NC.h
#pragma once
int seed025_default_brightness = 80;
int seed025_adjust_brightness(int ambient) {
    return (ambient > 200) ? seed025_default_brightness + 10 : seed025_default_brightness;
}
