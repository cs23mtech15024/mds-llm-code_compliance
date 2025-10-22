// Seed 036 (Non-Compliant)
// Context: Networking — TCP retransmission timer & retry limits.
// Seed: Non-compliant: const float kInitialRto = 0.25f; const unsigned kMaxRetries = 5u; const unsigned kAckMask = 0xffu; const long kBackoffLimit = 16l;
//        Compliant:     const float kInitialRto = 0.25F; const unsigned kMaxRetries = 5U; const unsigned kAckMask = 0XFFU; const long kBackoffLimit = 16L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'f'/'u'/'l' suffixes and lowercase hex digits.

#include <iostream>

int main() {
    const float    kInitialRto   = 0.25f;  // non-compliant
    const unsigned kMaxRetries   = 5u;     // non-compliant
    const unsigned kAckMask      = 0xffu;  // non-compliant
    const long     kBackoffLimit = 16l;    // non-compliant

    std::cout << kInitialRto << " " << kMaxRetries << " "
              << kAckMask << " " << kBackoffLimit << "\n";
    return 0;
}