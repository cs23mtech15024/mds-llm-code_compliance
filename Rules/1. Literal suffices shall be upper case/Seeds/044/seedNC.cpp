// Seed 044 (Non-Compliant)
// Context: Vehicle Speed Monitoring — Thresholds, Sampling Rate, and Alert Count
// Seed: Non-compliant: const float kSpeedThreshold = 80.5f; const unsigned kSamplingRate = 100u; const long kAlertLimit = 5l;
//         Compliant:    const float kSpeedThreshold = 80.5F; const unsigned kSamplingRate = 100U; const long kAlertLimit = 5L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Lowercase 'f', 'u', and 'l' suffixes.

#include <iostream>

int main() {
    const float kSpeedThreshold = 80.5f;  // non-compliant
    const unsigned kSamplingRate = 100u;  // non-compliant
    const long kAlertLimit = 5l;          // non-compliant
    std::cout << kSpeedThreshold << " " << kSamplingRate << " " << kAlertLimit << "\n";
    return 0;
}