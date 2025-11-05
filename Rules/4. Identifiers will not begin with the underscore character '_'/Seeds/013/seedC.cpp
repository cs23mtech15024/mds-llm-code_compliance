// Context: Checksum verification routine

// Seed 013 — C: function without underscore prefix
#include <cstdint>
#include <iostream>
bool verify_checksum(std::uint8_t data, std::uint8_t check) { // C
    return (data ^ 0xFF) == check;
}
int main(){
    std::cout << "valid=" << verify_checksum(0xAB, 0x54) << "\n";
    return 0;
}