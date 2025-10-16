// Seed 037 (Non-Compliant)
// Context: Graphics — Gamma correction & sRGB transfer parameters.
// Seed: Non-compliant: const float kGamma = 2.2f; const unsigned kMask = 0xa5u; const long kScale = 1024l;
//        Compliant:     const float kGamma = 2.2F; const unsigned kMask = 0XA5U; const long kScale = 1024L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'f'/'u'/'l' suffixes and lowercase hex digits.

#include <iostream>

int main() {
    const float    kGamma = 2.2f;   // non-compliant
    const unsigned kMask  = 0xa5u;  // non-compliant
    const long     kScale = 1024l;  // non-compliant
    std::cout << kGamma << " " << kMask << " " << kScale << "\n";
    return 0;
}