// Context: Blockchain transaction validation nonce

// Seed 078 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint64_t nonce=0x1a2b3c4d5e6f7a8bULL; // NC
    std::cout << "nonce=0x" << std::hex << nonce << "\n";
    return 0;
}