// Context: Sensor calibration scale/offset registry

// Seed 008 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t SCALE=0x1a, OFFSET=0x2b; // NC
    std::uint16_t y = static_cast<std::uint16_t>(10U*SCALE + OFFSET);
    std::cout << "cal=0x" << std::hex << y << "\n";
    return 0;
}