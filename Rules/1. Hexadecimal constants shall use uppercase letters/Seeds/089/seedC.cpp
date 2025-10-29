// Context: XML parser entity expansion depth limit

// Seed 094 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t depth=0xFF; // C
    std::cout << "xml_depth=" << static_cast<unsigned>(depth) << "\n";
    return 0;
}