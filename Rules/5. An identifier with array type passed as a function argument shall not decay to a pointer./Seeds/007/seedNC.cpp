// Context: Encryption key rotation buffer

// Seed 007 — NC: key buffer decays to pointer
#include <iostream>
#include <cstdint>
void rotate_keys(std::uint8_t keys[]) { // NC
    keys[0] ^= 0xFF;
    std::cout << "key0=0x" << std::hex << static_cast<int>(keys[0]) << "\n";
}
int main(){
    std::uint8_t key_buffer[32] = {0xAB};
    rotate_keys(key_buffer);
    return 0;
}