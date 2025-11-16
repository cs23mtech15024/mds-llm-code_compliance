// Context: Smart thermostat humidity correction parameters

// seed_062_NC.h
#pragma once
float seed062_humidity_offset = 3.5F;
float seed062_correct(float h) {
    return h + seed062_humidity_offset;
}
