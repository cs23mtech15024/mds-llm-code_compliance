// Seed 049 (Compliant)
// Context: Satellite Orientation Control — PID Gains, Update Limit, Base Time Constant
// Seed: Non-compliant: const float kPgain = 0.8f; const unsigned kMaxUpdates = 100u; const long kBaseTime = 10000l;
//         Compliant:    const float kPgain = 0.8F; const unsigned kMaxUpdates = 100U; const long kBaseTime = 10000L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>
int main() {
    const float kPgain = 0.8F;       // compliant
    const unsigned kMaxUpdates = 100U; // compliant
    const long kBaseTime = 10000L;   // compliant
    std::cout << kPgain << " " << kMaxUpdates << " " << kBaseTime << "\n";
    return 0;
}