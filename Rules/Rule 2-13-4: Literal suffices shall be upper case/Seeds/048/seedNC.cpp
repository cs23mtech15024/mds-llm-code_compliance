// Seed 048 (Non-Compliant)
// Context: Battery Management System — SOC smoothing (alpha), sample cap, and max charge seconds
// Seed: Non-compliant: const float kAlpha = 0.05f; const unsigned kCap = 100u; const long kMaxSecs = 3600l;
//         Compliant:    const float kAlpha = 0.05F; const unsigned kCap = 100U; const long kMaxSecs = 3600L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Lowercase 'f', 'u', and 'l' suffixes.

#include <iostream>
int main() {
    const float kAlpha = 0.05f;   // non-compliant
    const unsigned kCap = 100u;   // non-compliant
    const long kMaxSecs = 3600l;  // non-compliant
    std::cout << kAlpha << " " << kCap << " " << kMaxSecs << "\n";
    return 0;
}