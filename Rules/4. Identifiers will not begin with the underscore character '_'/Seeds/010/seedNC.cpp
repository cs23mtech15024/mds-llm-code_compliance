// Context: LED brightness controller

// Seed 010 — NC: variable starts with underscore
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t _brightness = 128; // NC
    std::cout << "led=" << static_cast<unsigned>(_brightness) << "\n";
    return 0;
}