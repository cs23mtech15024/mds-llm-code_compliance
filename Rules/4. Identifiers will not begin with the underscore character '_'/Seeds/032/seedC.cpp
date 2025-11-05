// Context: Bit mask generator

// Seed 032 — C: function and parameter without underscore prefix
#include <cstdint>
#include <iostream>
std::uint32_t create_mask(int bits) { // C
    return (1U << bits) - 1U;
}
int main(){
    std::cout << "mask=0x" << std::hex << create_mask(8) << "\n";
    return 0;
}