// Context: Laser distance sensor array

// Seed 046 — NC: laser distances decay to pointer
#include <iostream>
float find_closest_distance(float distances[]) { // NC
    return distances[0];
}
int main(){
    float laser_readings[16] = {2.5F, 3.0F, 2.8F};
    std::cout << "min=" << find_closest_distance(laser_readings) << "\n";
    return 0;
}