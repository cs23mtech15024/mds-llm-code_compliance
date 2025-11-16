// Context: Robotic vacuum mapping resolution header

// seed_046_NC.h
#pragma once
int seed046_map_resolution = 50;
int seed046_cells(int meters) {
    return meters * seed046_map_resolution;
}
