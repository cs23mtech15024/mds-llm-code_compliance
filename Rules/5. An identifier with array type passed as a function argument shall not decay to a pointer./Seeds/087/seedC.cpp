// Context: Cryptographic nonce generation

// Seed 087 — C: nonce array by reference
#include <iostream>
#include <cstdint>
void generate_nonce(std::uint8_t (&nonce)[16]) { // C
    nonce[0] = 0xAB;
    std::cout << "nonce0=0x" << std::hex << static_cast<int>(nonce[0]) << "\n";
}
int main(){
    std::uint8_t crypto_nonce[16] = {0};
    generate_nonce(crypto_nonce);
    return 0;
}