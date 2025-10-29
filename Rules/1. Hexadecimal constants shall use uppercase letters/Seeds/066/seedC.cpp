// Context: Database B-tree node capacity limit

// Seed 080 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t capacity=0x1FF; // C
    std::cout << "node_cap=" << capacity << "\n";
    return 0;
}