// Context: Filesystem retention cap counter

// Seed 022 — C: uppercase hex in cap/mask
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t cap=0x1A;     // C
    std::uint16_t mask=0x3F;    // C
    std::uint16_t kept = static_cast<std::uint16_t>((cap+7U) & mask);
    std::cout << "kept=0x" << std::hex << kept << "\n";
    return 0;
}