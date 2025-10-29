// Context: Climate model atmospheric layer index

// Seed 092 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t layer=0x1F; // C
    std::cout << "layer=" << static_cast<unsigned>(layer) << "\n";
    return 0;
}