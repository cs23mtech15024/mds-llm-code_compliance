// Context: MIDI note velocity buffer

// ------ Compliant Program (076_c.cpp)
// Context: MIDI note velocity buffer
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <cstdint>

namespace midi_076_c {

static int to_int(std::uint8_t b){ return static_cast<int>(b); }

void process_midi_notes(std::uint8_t (&velocities)[128]) { // C API
    std::cout << "vel0=" << to_int(velocities[0]) << "\n";
}

static void head(const std::uint8_t (&v)[128]){
    for (int i=0;i<4;i++){ std::cout << (i?" ":"head:") << to_int(v[i]); }
    std::cout << "\n";
}

} // namespace midi_076_c

int main(){
    using namespace midi_076_c;
    std::uint8_t midi_vels[128] = {64, 0, 127, 96};
    process_midi_notes(midi_vels);
    head(midi_vels);
    return 0;
}
