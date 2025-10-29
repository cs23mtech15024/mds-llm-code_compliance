// Context: Filesystem retention cap counter

// Seed 022 — NC: lowercase hex in cap/mask
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t cap=0x1a;     // NC: 26 files
    std::uint16_t mask=0x3f;    // NC
    std::uint16_t kept = static_cast<std::uint16_t>((cap+7U) & mask);
    std::cout << "kept=0x" << std::hex << kept << "\n";
    return 0;
}