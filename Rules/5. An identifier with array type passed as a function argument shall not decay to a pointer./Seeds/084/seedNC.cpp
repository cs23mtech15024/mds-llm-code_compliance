// Context: Antenna beamforming phase shifts

// Seed 084 — NC: phase shifts decay to pointer
#include <iostream>
void calculate_beam_pattern(float phases[]) { // NC
    phases[0] = 45.0F;
    std::cout << "phase0=" << phases[0] << "\n";
}
int main(){
    float antenna_phases[32] = {0};
    calculate_beam_pattern(antenna_phases);
    return 0;
}