// Context: Medical CT scan Hounsfield unit offset

// Seed 086 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t offset=0x3e8; // NC: 1000
    std::cout << "HU_offset=" << offset << "\n";
    return 0;
}