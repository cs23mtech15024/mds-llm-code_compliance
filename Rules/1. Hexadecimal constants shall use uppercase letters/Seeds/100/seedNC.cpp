// Context: Docker container resource limit CPU shares

// Seed 100 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t shares=0x400; // NC: 1024 shares
    std::cout << "cpu_shares=" << shares << "\n";
    return 0;
}