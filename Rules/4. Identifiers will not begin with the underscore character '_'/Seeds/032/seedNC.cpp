// Context: Bit mask generator

// Seed 032 — NC: function and parameter start with underscore
#include <cstdint>
#include <iostream>
std::uint32_t _create_mask(int _bits) { // NC
    return (1U << _bits) - 1U;
}
int main(){
    std::cout << "mask=0x" << std::hex << _create_mask(8) << "\n";
    return 0;
}