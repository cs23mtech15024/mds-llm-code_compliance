// Seed 025 (Non-Compliant)
// Context: Networking — base retry backoff for a client.
// Seed: Non-compliant: const float backoff = 1.25f;   // Compliant: const float backoff = 1.25F
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'f' suffix for a floating literal.

#include <iostream>

int main() {
    const float backoff = 1.25f; // non-compliant
    std::cout << backoff << "\n";
    return 0;
}