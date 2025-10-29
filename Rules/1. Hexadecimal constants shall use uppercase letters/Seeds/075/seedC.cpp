// Context: SLAM map occupancy grid probability

// Seed 089 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t prob=0xB3; // C
    float p = static_cast<float>(prob) / 255.0F;
    std::cout << "occupancy=" << p << "\n";
    return 0;
}