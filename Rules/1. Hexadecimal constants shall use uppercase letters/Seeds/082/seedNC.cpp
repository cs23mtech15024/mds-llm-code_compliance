// Context: USB device descriptor vendor ID

// Seed 093 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t vid=0x1a2b; // NC
    std::cout << "usb_vid=0x" << std::hex << vid << "\n";
    return 0;
}