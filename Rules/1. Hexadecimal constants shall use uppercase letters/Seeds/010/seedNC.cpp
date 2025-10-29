// Context: Thermal unit conversion aid (metadata tag)

// Seed 012 — NC: lowercase hex metadata tag
#include <cstdint>
#include <iostream>
int main(){
    unsigned scale_num=0x9, scale_den=0x5; // 9/5
    unsigned tag=0xaf; // NC
    float c=25.0F;
    float f = c*static_cast<float>(scale_num)/static_cast<float>(scale_den) + 32.0F;
    std::cout << c << "C->" << f << "F tag=0x" << std::hex << tag << "\n";
    return 0;
}