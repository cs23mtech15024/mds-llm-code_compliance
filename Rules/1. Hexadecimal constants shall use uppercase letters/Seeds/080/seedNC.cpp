// Context: Climate model atmospheric layer index

// Seed 092 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t layer=0x1f; // NC: 31 layers
    std::cout << "layer=" << static_cast<unsigned>(layer) << "\n";
    return 0;
}