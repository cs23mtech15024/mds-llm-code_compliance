// Context: NFC tag memory block address pointer

// Seed 098 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t addr=0x2f; // NC: block 47
    std::cout << "nfc_addr=0x" << std::hex << static_cast<unsigned>(addr) << "\n";
    return 0;
}