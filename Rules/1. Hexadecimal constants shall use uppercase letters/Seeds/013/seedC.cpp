// Context: Controller integral cap register

// Seed 015 — C: uppercase hex cap
#include <cstdint>
#include <iostream>
int main(){
    std::uint32_t cap=0x3E8; // C
    std::cout << "icap=" << cap << "\n";
    return 0;
}