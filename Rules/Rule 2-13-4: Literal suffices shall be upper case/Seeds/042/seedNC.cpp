// Seed 042 (Non-Compliant)
// Context: Networking Backoff — Timeout Factor, Default Port, Max Retries
// Seed: Non-compliant: const float kFactor = 1.25f; const unsigned kPort = 5353u; const long kMaxRetries = 12l;
//         Compliant:    const float kFactor = 1.25F; const unsigned kPort = 5353U; const long kMaxRetries = 12L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Lowercase 'f', 'u', and 'l' suffixes.

#include <iostream>

int main() {
    const float kFactor = 1.25f;      // non-compliant
    const unsigned kPort = 5353u;     // non-compliant
    const long kMaxRetries = 12l;     // non-compliant
    std::cout << kFactor << " " << kPort << " " << kMaxRetries << "\n";
    return 0;
}