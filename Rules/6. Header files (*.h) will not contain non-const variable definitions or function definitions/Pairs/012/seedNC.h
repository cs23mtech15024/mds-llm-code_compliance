// Context: Power management regulator default settings

// seed_012_NC.h
#pragma once
// NC: regulator defaults and function defined in header
int seed012_vout_default = 3300; // NC (mV)

int seed012_get_safe_margin() { // NC
    return seed012_vout_default - 100;
}
