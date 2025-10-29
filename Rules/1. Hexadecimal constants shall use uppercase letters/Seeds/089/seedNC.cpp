// Context: XML parser entity expansion depth limit

// Seed 094 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t depth=0xff; // NC: max 255
    std::cout << "xml_depth=" << static_cast<unsigned>(depth) << "\n";
    return 0;
}