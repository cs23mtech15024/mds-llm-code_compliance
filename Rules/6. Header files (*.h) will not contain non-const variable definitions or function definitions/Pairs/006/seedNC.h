// Context: IoT device boot configuration flags

// seed_006_NC.h
#pragma once
// NC: mutable settings + implementation
int seed006_boot_mode = 2; // NC
bool seed006_debug_enabled = false; // NC

bool seed006_is_debug() { // NC
    return seed006_debug_enabled;
}
