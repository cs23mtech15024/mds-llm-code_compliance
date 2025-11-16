// Context: Data center thermal zone alarm header

// seed_087_NC.h
#pragma once
int seed087_alarm_temp = 42;
bool seed087_trigger(int t) {
    return t >= seed087_alarm_temp;
}
