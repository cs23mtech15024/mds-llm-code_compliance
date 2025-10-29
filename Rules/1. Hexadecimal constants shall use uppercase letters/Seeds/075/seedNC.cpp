// Context: SLAM map occupancy grid probability

// Seed 089 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t prob=0xb3; // NC: 179/255 = 70%
    float p = static_cast<float>(prob) / 255.0F;
    std::cout << "occupancy=" << p << "\n";
    return 0;
}