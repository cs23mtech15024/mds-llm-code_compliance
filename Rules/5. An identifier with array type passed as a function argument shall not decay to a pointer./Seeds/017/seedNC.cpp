// Context: RGB color palette manager

// Seed 017 — NC: color palette decays to pointer
#include <iostream>
#include <cstdint>
void set_palette_color(std::uint32_t palette[]) { // NC
    palette[0] = 0xFF0000;
    std::cout << "color0=0x" << std::hex << palette[0] << "\n";
}
int main(){
    std::uint32_t colors[256] = {0};
    set_palette_color(colors);
    return 0;
}