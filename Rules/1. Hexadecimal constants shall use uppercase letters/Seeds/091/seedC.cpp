// Context: MIDI note velocity intensity level

// Seed 096 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t vel=0x7F; // C
    std::cout << "midi_vel=" << static_cast<unsigned>(vel) << "\n";
    return 0;
}