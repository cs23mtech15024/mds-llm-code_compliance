// Context: Thermostat setpoint header with mutable setpoint

// seed_021_NC.h
#pragma once
float seed021_thermostat_setpoint = 22.5F;
float seed021_get_setpoint() {
    return seed021_thermostat_setpoint;
}
