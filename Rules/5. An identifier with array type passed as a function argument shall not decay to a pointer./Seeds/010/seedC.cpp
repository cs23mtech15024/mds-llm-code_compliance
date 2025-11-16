// Context: LED matrix display buffer

// Seed 010 — C: LED buffer by reference
#include <iostream>
#include <cstdint>
void update_display(std::uint8_t (&led_matrix)[64]) { // C
    led_matrix[0] = 0xFF;
    std::cout << "led_row0=0x" << std::hex << static_cast<int>(led_matrix[0]) << "\n";
}
int main(){
    std::uint8_t display[64] = {0};
    update_display(display);
    return 0;
}