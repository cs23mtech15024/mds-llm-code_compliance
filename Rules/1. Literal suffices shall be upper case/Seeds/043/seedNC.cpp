// Seed 043 (Non-Compliant)
// Context: Embedded Sensor Sampling — ADC Gain Factor, Data Buffer Size, and Calibration Offset
// Seed: Non-compliant: const float kGain = 2.5f; const unsigned kBufferSize = 512u; const long kOffset = -15l;
//         Compliant:    const float kGain = 2.5F; const unsigned kBufferSize = 512U; const long kOffset = -15L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Lowercase suffixes 'f', 'u', and 'l' used in literals.

#include <iostream>

int main() {
    const float kGain = 2.5f;         // non-compliant
    const unsigned kBufferSize = 512u; // non-compliant
    const long kOffset = -15l;        // non-compliant
    std::cout << kGain << " " << kBufferSize << " " << kOffset << "\n";
    return 0;
}