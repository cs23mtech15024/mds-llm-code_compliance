// Context: LED brightness controller

// Seed 010 — C: variable without underscore prefix
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t brightness = 128; // C
    std::cout << "led=" << static_cast<unsigned>(brightness) << "\n";
    return 0;
}