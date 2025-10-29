// Context: Graphics RGB/alpha color swatch encoder

// Seed 009 — NC: lowercase hex
#include <iostream>
int main(){
    unsigned RGB=0xff00ff; // NC
    unsigned argb = (RGB & 0x00ffffffU) | (0x80U<<24); // NC mask
    std::cout << std::hex << argb << "\n";
    return 0;
}