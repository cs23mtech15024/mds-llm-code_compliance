// Context: MIDI note velocity buffer

// Seed 076 — NC: MIDI velocities decay to pointer
#include <iostream>
#include <cstdint>
void process_midi_notes(std::uint8_t velocities[]) { // NC
    std::cout << "vel0=" << static_cast<int>(velocities[0]) << "\n";
}
int main(){
    std::uint8_t midi_vels[128] = {64};
    process_midi_notes(midi_vels);
    return 0;
}