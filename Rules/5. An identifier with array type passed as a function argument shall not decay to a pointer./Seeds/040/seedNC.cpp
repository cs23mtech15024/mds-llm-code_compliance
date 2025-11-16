// Context: OLED display framebuffer

// Seed 040 — NC: framebuffer decays to pointer
#include <iostream>
#include <cstdint>
void clear_screen(std::uint8_t framebuffer[]) { // NC
    framebuffer[0] = 0x00;
    std::cout << "fb0=0x" << std::hex << static_cast<int>(framebuffer[0]) << "\n";
}
int main(){
    std::uint8_t oled_fb[1024] = {0xFF};
    clear_screen(oled_fb);
    return 0;
}