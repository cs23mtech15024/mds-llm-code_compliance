// Seed 047 (Compliant)
// Context: Engine Temperature Regulation — Gain Factor, Sample Interval, Max Safe Temp
// Seed: Non-compliant: const float kGain = 1.2f; const unsigned kInterval = 50u; const long kMaxTemp = 120l;
//         Compliant:    const float kGain = 1.2F; const unsigned kInterval = 50U; const long kMaxTemp = 120L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const float kGain = 1.2F;       // compliant
    const unsigned kInterval = 50U; // compliant
    const long kMaxTemp = 120L;     // compliant
    std::cout << kGain << " " << kInterval << " " << kMaxTemp << "\n";
    return 0;
}