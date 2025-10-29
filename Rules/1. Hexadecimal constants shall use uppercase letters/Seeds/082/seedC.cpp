// Context: USB device descriptor vendor ID

// Seed 093 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t vid=0x1A2B; // C
    std::cout << "usb_vid=0x" << std::hex << vid << "\n";
    return 0;
}