// Seed 023 (Non-Compliant)
// Context: Networking — exponential backoff base multiplier.
// Seed: Non-compliant: const float baseBackoff = 0.25f;   // Compliant: const float baseBackoff = 0.25F
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'f' suffix for a floating literal.

#include <iostream>

int main() {
    const float baseBackoff = 0.25f; // non-compliant
    std::cout << baseBackoff << "\n";
    return 0;
}