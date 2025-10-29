// Context: IoT greenhouse humidity alarm bitmap

// Seed 011 — C: uppercase hex in alarm bitmap
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t HI=0xA4, LO=0x12; // C
    std::uint16_t alarm = static_cast<std::uint16_t>(HI | LO);
    std::cout << "hum_alarm=0x" << std::hex << alarm << "\n";
    return 0;
}