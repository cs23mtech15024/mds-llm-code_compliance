// Context: SSH key exchange algorithm preference

// Seed 097 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t kex=0x1f; // NC: algorithm 31
    std::cout << "ssh_kex=0x" << std::hex << static_cast<unsigned>(kex) << "\n";
    return 0;
}