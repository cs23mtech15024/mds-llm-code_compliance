// Context: Telemetry packet ID builder uses 64-bit constants with lowercase 'ull' suffix.
// Seed: Non-compliant: const unsigned long long base = 1ull;   // Compliant: const unsigned long long base = 1ULL;
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase ‘ull’ suffix on unsigned long long literals.

#include <iostream>

int main() {
    const unsigned long long base = 1ull;  // NC
    const unsigned long long mask = 0ull;  // NC (example)
    std::cout << (base + mask) << "\n";
    return 0;
}