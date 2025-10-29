// Context: IoT greenhouse humidity alarm bitmap

// Seed 011 — NC: lowercase hex in alarm bitmap
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t HI=0xa4, LO=0x12; // NC: 'a' lowercase
    std::uint16_t alarm = static_cast<std::uint16_t>(HI | LO);
    std::cout << "hum_alarm=0x" << std::hex << alarm << "\n";
    return 0;
}