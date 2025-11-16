// Context: Industrial sensor hysteresis header

// seed_053_NC.h
#pragma once
float seed053_hysteresis = 0.5F;
bool seed053_should_switch(float oldv, float newv) {
    return (newv - oldv) > seed053_hysteresis;
}
