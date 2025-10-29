// Context: Autonomous vehicle lane detection threshold

// Seed 094 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t thresh=0xd9; // NC: 217/255 = 85%
    float t = static_cast<float>(thresh) / 255.0F;
    std::cout << "lane_thresh=" << t << "\n";
    return 0;
}