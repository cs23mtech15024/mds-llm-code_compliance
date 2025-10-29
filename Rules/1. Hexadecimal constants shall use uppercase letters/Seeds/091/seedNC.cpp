// Context: MIDI note velocity intensity level

// Seed 096 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t vel=0x7f; // NC: max velocity 127
    std::cout << "midi_vel=" << static_cast<unsigned>(vel) << "\n";
    return 0;
}