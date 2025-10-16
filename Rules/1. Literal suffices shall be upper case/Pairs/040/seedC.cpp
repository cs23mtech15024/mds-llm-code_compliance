// Seed 040 (Compliant)
// Context: Sensor Fusion — Accelerometer smoothing and drift compensation.
// Seed: Non-compliant: const float kAlpha = 0.2f; const unsigned kStatusMask = 0x7fu; const long kSampleRate = 200l;
//        Compliant:     const float kAlpha = 0.2F; const unsigned kStatusMask = 0X7FU; const long kSampleRate = 200L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const float kAlpha = 0.2F;          // compliant
    const unsigned kStatusMask = 0X7FU; // compliant
    const long kSampleRate = 200L;      // compliant
    std::cout << kAlpha << " " << kStatusMask << " " << kSampleRate << "\n";
    return 0;
}