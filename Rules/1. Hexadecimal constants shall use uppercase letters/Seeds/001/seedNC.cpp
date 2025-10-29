// Context: Financial risk-bucket encoder (hex flags)

// Seed 001 — NC: lowercase hex A–F
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t credit=0xa5, liquid=0x1f, market=0xbe; // NC
    std::uint8_t code = static_cast<std::uint8_t>(credit ^ market ^ liquid);
    std::cout << "risk=0x" << std::hex << static_cast<unsigned>(code) << "\n";
    return 0;
}