// Context: RFID transponder frequency band code

// Seed 093 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t band=0x0d; // NC: 13.56MHz
    std::cout << "rfid_band=0x" << std::hex << static_cast<unsigned>(band) << "\n";
    return 0;
}