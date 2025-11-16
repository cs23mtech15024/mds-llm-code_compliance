// Context: Encryption key rotation buffer

// Seed 007 — C: key buffer by reference
#include <iostream>
#include <cstdint>
void rotate_keys(std::uint8_t (&keys)[32]) { // C
    keys[0] ^= 0xFF;
    std::cout << "key0=0x" << std::hex << static_cast<int>(keys[0]) << "\n";
}
int main(){
    std::uint8_t key_buffer[32] = {0xAB};
    rotate_keys(key_buffer);
    return 0;
}