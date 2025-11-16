// Context: MIDI note velocity buffer

// ------ Non-Compliant Program (076_nc.cpp)
// Context: MIDI note velocity buffer
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace midi_076_nc {

static int to_int(std::uint8_t b){ return static_cast<int>(b); }

void process_midi_notes(std::uint8_t velocities[]) { // NC API
    const std::size_t N = 128U; (void)N;
    std::cout << "vel0=" << to_int(velocities[0]) << "\n";
}

static void head(const std::uint8_t *v){
    for (int i=0;i<4;i++){ std::cout << (i?" ":"head:") << to_int(v[i]); }
    std::cout << "\n";
}

} // namespace midi_076_nc

int main(){
    using namespace midi_076_nc;
    std::uint8_t midi_vels[128] = {64, 0, 127, 96};
    process_midi_notes(midi_vels);
    head(midi_vels);
    return 0;
}
