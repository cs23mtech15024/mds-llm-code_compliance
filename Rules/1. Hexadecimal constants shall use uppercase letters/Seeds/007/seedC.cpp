// Context: Graphics RGB/alpha color swatch encoder

// Seed 009 — C: uppercase hex
#include <iostream>
int main(){
    unsigned RGB=0xFF00FF; // C
    unsigned argb = (RGB & 0x00FFFFFFU) | (0x80U<<24); // C mask
    std::cout << std::hex << argb << "\n";
    return 0;
}