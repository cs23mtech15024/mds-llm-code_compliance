// Context: Medical CT scan Hounsfield unit offset

// Seed 086 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t offset=0x3E8; // C
    std::cout << "HU_offset=" << offset << "\n";
    return 0;
}