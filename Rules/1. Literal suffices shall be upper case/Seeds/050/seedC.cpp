// Seed 050 (Compliant)
// Context: Drone Altitude Stabilization — Altitude Gain, Loop Delay, Max Flight Time
// Seed: Non-compliant: const float kAltitudeGain = 0.75f; const unsigned kLoopDelay = 20u; const long kMaxFlightTime = 7200l;
//         Compliant:    const float kAltitudeGain = 0.75F; const unsigned kLoopDelay = 20U; const long kMaxFlightTime = 7200L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>
int main() {
    const float kAltitudeGain = 0.75F; // compliant
    const unsigned kLoopDelay = 20U;   // compliant
    const long kMaxFlightTime = 7200L; // compliant
    std::cout << kAltitudeGain << " " << kLoopDelay << " " << kMaxFlightTime << "\n";
    return 0;
}