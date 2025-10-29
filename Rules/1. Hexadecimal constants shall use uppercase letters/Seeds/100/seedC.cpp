// Context: Docker container resource limit CPU shares

// Seed 100 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t shares=0x400; // C (digits only)
    std::cout << "cpu_shares=" << shares << "\n";
    return 0;
}