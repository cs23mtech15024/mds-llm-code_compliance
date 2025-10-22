// Context: A simple 64-bit hash utility for IDs uses constants with uppercase 'ULL' suffix,
//          compliant with MISRA C++ 2-13-4 (literal suffixes shall be upper case).
// Seed: Non-compliant: const unsigned long long kSalt = 0x9e3779b97f4a7c15ull;  // Compliant: const unsigned long long kSalt = 0x9E3779B97F4A7C15ULL;
// Rule: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.

#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>

namespace hash64 {

// Compliant uppercase suffixes (and hex digits capitalized).
static const unsigned long long kSalt  = 0x9E3779B97F4A7C15ULL; // C
static const unsigned long long kPrime = 0x100000001B3ULL;      // C

// Very small illustrative mixer (deterministic, no UB).
std::uint64_t mix(std::uint64_t x, std::uint64_t y) {
    x ^= y + kSalt + (x << 6) + (x >> 2);
    x *= kPrime;
    return x ^ (x >> 33);
}

std::uint64_t hash_span(const std::vector<std::uint64_t>& v) {
    std::uint64_t h = 0ULL; // C
    for (std::uint64_t n : v) {
        h = mix(h, n);
    }
    return h;
}

} // namespace hash64

int main() {
    std::vector<std::uint64_t> data = { 1ULL, 2ULL, 3ULL, 0xABCDEF12ULL }; // C
    std::uint64_t h = hash64::hash_span(data);

    std::cout << std::hex << std::uppercase
              << "Hash: 0x" << h << "\n";
    return 0;
}