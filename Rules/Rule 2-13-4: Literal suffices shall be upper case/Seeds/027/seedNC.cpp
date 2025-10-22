// Seed 027 (Non-Compliant)
// Context: Networking — exponential backoff constants for HTTP retry scheduler.
// Seed: Non-compliant: const unsigned maxRetries = 3u;   // Compliant: const unsigned maxRetries = 3U
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'u' suffix for an unsigned literal.

#include <iostream>

int main() {
    const unsigned maxRetries = 3u; // non-compliant
    std::cout << maxRetries << "\n";
    return 0;
}