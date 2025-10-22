// Seed 037 (Compliant)
// Context: Graphics — Gamma correction & sRGB transfer parameters.
// Seed: Non-compliant: const float kGamma = 2.2f; const unsigned kMask = 0xa5u; const long kScale = 1024l;
//        Compliant:     const float kGamma = 2.2F; const unsigned kMask = 0XA5U; const long kScale = 1024L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const float    kGamma = 2.2F;   // compliant
    const unsigned kMask  = 0XA5U;  // compliant
    const long     kScale = 1024L;  // compliant
    std::cout << kGamma << " " << kMask << " " << kScale << "\n";
    return 0;
}