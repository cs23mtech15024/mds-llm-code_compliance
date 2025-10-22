// Seed 034 (Non-Compliant)
// Context: Compression — LZ77 window & match thresholds.
// Seed: Non-compliant: const float kMinCompressRatio = 0.85f; const unsigned kMaxMatches = 64u; const unsigned kMask = 0x00ffu; const long kWindowSize = 1024l;
//        Compliant:     const float kMinCompressRatio = 0.85F; const unsigned kMaxMatches = 64U; const unsigned kMask = 0X00FFU; const long kWindowSize = 1024L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'f'/'u'/'l' suffixes and lowercase hex digits.

#include <iostream>

int main() {
    const float    kMinCompressRatio = 0.85f;  // non-compliant
    const unsigned kMaxMatches       = 64u;    // non-compliant
    const unsigned kMask             = 0x00ffu;// non-compliant
    const long     kWindowSize       = 1024l;  // non-compliant

    std::cout << kMinCompressRatio << " " << kMaxMatches << " "
              << kMask << " " << kWindowSize << "\n";
    return 0;
}