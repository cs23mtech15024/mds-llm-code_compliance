// Context: Genomics base-call quality mask

// Seed 002 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t PHRED_PASS=0xAF, N_MASK=0x3B; // C
    std::uint16_t code = static_cast<std::uint16_t>(PHRED_PASS | N_MASK);
    std::cout << "geno=0x" << std::hex << code << "\n";
    return 0;
}