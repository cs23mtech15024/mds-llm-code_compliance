// Context: JPEG XL encoding effort parameter

// Seed 096 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t effort=0x07; // NC: effort level 7
    std::cout << "jxl_effort=" << static_cast<unsigned>(effort) << "\n";
    return 0;
}