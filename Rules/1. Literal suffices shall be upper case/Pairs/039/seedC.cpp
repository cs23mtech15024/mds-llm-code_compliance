// Seed 039 (Compliant)
// Context: Networking — TCP RTO backoff computation constants.
// Seed: Non-compliant: const float kAlpha = 0.125f; const float kBeta = 1.5f; const unsigned kColorMask = 0xffu; const long kMsPerSec = 1000l;
//        Compliant:     const float kAlpha = 0.125F; const float kBeta = 1.5F; const unsigned kColorMask = 0XFFU; const long kMsPerSec = 1000L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const float kAlpha = 0.125F;       // compliant
    const float kBeta  = 1.5F;         // compliant
    const unsigned kColorMask = 0XFFU; // compliant
    const long kMsPerSec = 1000L;      // compliant
    std::cout << kAlpha << " " << kBeta << " " << kColorMask << " " << kMsPerSec << "\n";
    return 0;
}