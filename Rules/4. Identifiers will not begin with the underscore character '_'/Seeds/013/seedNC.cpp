// Context: Checksum verification routine

// Seed 013 — NC: function starts with underscore
#include <cstdint>
#include <iostream>
bool _verify_checksum(std::uint8_t data, std::uint8_t check) { // NC
    return (data ^ 0xFF) == check;
}
int main(){
    std::cout << "valid=" << _verify_checksum(0xAB, 0x54) << "\n";
    return 0;
}