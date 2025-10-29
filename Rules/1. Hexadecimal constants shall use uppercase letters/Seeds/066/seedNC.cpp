// Context: Database B-tree node capacity limit

// Seed 080 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t capacity=0x1ff; // NC: 511
    std::cout << "node_cap=" << capacity << "\n";
    return 0;
}