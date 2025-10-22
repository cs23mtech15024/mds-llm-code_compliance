// Seed 046 (Compliant)
// Context: Drone Telemetry Smoothing — alpha factor, packet limit, base timestamp
// Seed: Non-compliant: const float kAlpha = 0.75f; const unsigned kMaxPackets = 64u; const long kBaseTs = 1000l;
//         Compliant:    const float kAlpha = 0.75F; const unsigned kMaxPackets = 64U; const long kBaseTs = 1000L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>
int main() {
    const float kAlpha = 0.75F;     // compliant
    const unsigned kMaxPackets = 64U; // compliant
    const long kBaseTs = 1000L;     // compliant
    std::cout << kAlpha << " " << kMaxPackets << " " << kBaseTs << "\n";
    return 0;
}