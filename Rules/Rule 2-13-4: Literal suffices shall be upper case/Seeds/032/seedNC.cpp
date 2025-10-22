// Seed 032 (Non-Compliant)
// Context: Cybersecurity — TLS handshake timeout & retry backoff constants.
// Seed: Non-compliant: const float kBaseTimeout = 0.5f; const unsigned kMaxRetries = 3u; const unsigned kMask = 0xffu;
//        Compliant:     const float kBaseTimeout = 0.5F; const unsigned kMaxRetries = 3U; const unsigned kMask = 0XFFU
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'f'/'u' suffixes and lowercase hex digits in a hex literal.

#include <iostream>

int main() {
    const float kBaseTimeout = 0.5f;   // non-compliant
    const unsigned kMaxRetries = 3u;   // non-compliant
    const unsigned kMask = 0xffu;      // non-compliant
    std::cout << kBaseTimeout << " " << kMaxRetries << " " << kMask << "\n";
    return 0;
}