// Context: Motor driver header with speed variable

// seed_024_NC.h
#pragma once
int seed024_motor_speed = 1500;
void seed024_set_speed(int s) {
    seed024_motor_speed = s;
}
