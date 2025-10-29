// Context: NFC tag memory block address pointer

// Seed 098 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t addr=0x2F; // C
    std::cout << "nfc_addr=0x" << std::hex << static_cast<unsigned>(addr) << "\n";
    return 0;
}