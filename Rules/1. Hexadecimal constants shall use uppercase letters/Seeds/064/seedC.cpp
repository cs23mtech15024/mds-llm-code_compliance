// Context: Blockchain transaction validation nonce

// Seed 078 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint64_t nonce=0x1A2B3C4D5E6F7A8BULL; // C
    std::cout << "nonce=0x" << std::hex << nonce << "\n";
    return 0;
}