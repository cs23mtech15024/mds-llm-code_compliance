// Context: MIDI note velocity buffer

// Seed 076 — C: MIDI velocities by reference
#include <iostream>
#include <cstdint>
void process_midi_notes(std::uint8_t (&velocities)[128]) { // C
    std::cout << "vel0=" << static_cast<int>(velocities[0]) << "\n";
}
int main(){
    std::uint8_t midi_vels[128] = {64};
    process_midi_notes(midi_vels);
    return 0;
}