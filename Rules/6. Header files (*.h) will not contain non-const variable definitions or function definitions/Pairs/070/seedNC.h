// Context: Factory conveyor belt speed configuration

// seed_070_NC.h
#pragma once
float seed070_belt_speed = 1.25F;
bool seed070_within_limit(float s) {
    return s <= seed070_belt_speed;
}
