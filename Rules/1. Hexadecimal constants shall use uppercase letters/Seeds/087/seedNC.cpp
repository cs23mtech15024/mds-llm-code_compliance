// Context: Smart home Z-Wave device node identifier

// Seed 095 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t node=0x2f; // NC: node 47
    std::cout << "zwave_node=0x" << std::hex << static_cast<unsigned>(node) << "\n";
    return 0;
}