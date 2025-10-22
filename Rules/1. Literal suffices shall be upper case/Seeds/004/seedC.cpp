// Context: 64-bit hashing uses a fixed salt constant with an unsigned long long suffix.
// Seed: Non-compliant: const unsigned long long kSalt = 0x9e3779b97f4a7c15ull;  // Compliant: const unsigned long long kSalt = 0x9E3779B97F4A7C15ULL;
// Rule: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.
// Fix: Suffix changed to 'ULL' and hex digits capitalized.

#include <cstdint>

int main() {
    const unsigned long long kSalt = 0x9E3779B97F4A7C15ULL; // C: uppercase suffix and hex digits
    (void)kSalt;
    return 0;
}