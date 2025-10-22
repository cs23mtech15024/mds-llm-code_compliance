// Seed 035 (Compliant)
// Context: Filesystem — log rotation policy (size cap, rotation count, permission mask, time epsilon).
// Seed: Non-compliant: const float kRotateEpsilon = 0.25f; const unsigned kMaxRotations = 7u; const unsigned kPermMask = 0x0a5au; const long kMaxFileSize = 1048576l;
//        Compliant:     const float kRotateEpsilon = 0.25F; const unsigned kMaxRotations = 7U; const unsigned kPermMask = 0X0A5AU; const long kMaxFileSize = 1048576L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const float    kRotateEpsilon = 0.25F;    // compliant
    const unsigned kMaxRotations  = 7U;       // compliant
    const unsigned kPermMask      = 0X0A5AU;  // compliant
    const long     kMaxFileSize   = 1048576L; // compliant

    std::cout << kRotateEpsilon << " " << kMaxRotations << " "
              << kPermMask << " " << kMaxFileSize << "\n";
    return 0;
}