// Context: DICOM tag filter (metadata masking)

// Seed 023 — C: uppercase hex tag/mask
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t group=0x7FE0, elem=0x0010; // C
    std::uint32_t tag = (static_cast<std::uint32_t>(group)<<16) | elem;
    std::uint32_t mask=0x00FF00FFU;          // C
    std::cout << "tag=0x" << std::hex << (tag & mask) << "\n";
    return 0;
}