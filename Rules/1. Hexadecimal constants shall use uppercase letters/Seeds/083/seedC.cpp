// Context: Autonomous vehicle lane detection threshold

// Seed 094 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t thresh=0xD9; // C
    float t = static_cast<float>(thresh) / 255.0F;
    std::cout << "lane_thresh=" << t << "\n";
    return 0;
}