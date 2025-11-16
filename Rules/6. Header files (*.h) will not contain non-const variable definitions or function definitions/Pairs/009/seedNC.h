// Context: Home automation lighting profile

// seed_009_NC.h
#pragma once
// NC: default brightness + function
enum seed009_mode { SEED009_DAY, SEED009_NIGHT };
int seed009_default_level = 75; // NC

int seed009_get_level(seed009_mode m) { // NC
    return (m == SEED009_DAY) ? 100 : seed009_default_level;
}
