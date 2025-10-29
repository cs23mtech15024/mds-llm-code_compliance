// Context: JPEG XL encoding effort parameter

// Seed 096 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t effort=0x07; // C (digits only)
    std::cout << "jxl_effort=" << static_cast<unsigned>(effort) << "\n";
    return 0;
}