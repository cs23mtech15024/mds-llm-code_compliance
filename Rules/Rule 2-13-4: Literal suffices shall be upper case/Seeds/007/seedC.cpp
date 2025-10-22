// Context: Telemetry packet ID builder uses 64-bit constants with uppercase 'ULL' suffix.
// Seed: Non-compliant: const unsigned long long base = 1ull;   // Compliant: const unsigned long long base = 1ULL;
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Fix: All unsigned long long literals use uppercase ‘ULL’.

#include <iostream>

int main() {
    const unsigned long long base = 1ULL;  // C
    const unsigned long long mask = 0ULL;  // C (example)
    std::cout << (base + mask) << "\n";
    return 0;
}