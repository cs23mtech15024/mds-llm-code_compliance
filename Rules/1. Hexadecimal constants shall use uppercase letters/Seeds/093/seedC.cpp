// Context: RFID transponder frequency band code

// Seed 093 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t band=0x0D; // C
    std::cout << "rfid_band=0x" << std::hex << static_cast<unsigned>(band) << "\n";
    return 0;
}