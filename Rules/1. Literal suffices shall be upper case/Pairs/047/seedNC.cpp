// Seed 047 (Non-Compliant)
// Context: Engine Temperature Regulation — Gain Factor, Sample Interval, Max Safe Temp
// Seed: Non-compliant: const float kGain = 1.2f; const unsigned kInterval = 50u; const long kMaxTemp = 120l;
//         Compliant:    const float kGain = 1.2F; const unsigned kInterval = 50U; const long kMaxTemp = 120L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Lowercase 'f', 'u', and 'l' suffixes.

#include <iostream>

int main() {
    const float kGain = 1.2f;       // non-compliant
    const unsigned kInterval = 50u; // non-compliant
    const long kMaxTemp = 120l;     // non-compliant
    std::cout << kGain << " " << kInterval << " " << kMaxTemp << "\n";
    return 0;
}