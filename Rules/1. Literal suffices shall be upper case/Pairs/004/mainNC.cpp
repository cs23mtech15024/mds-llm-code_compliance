// Context: A simple 64-bit hash utility for IDs uses constants with lowercase 'ull' suffix,
//          violating MISRA C++ 2-13-4 (literal suffixes shall be upper case).
// Seed: Non-compliant: const unsigned long long kSalt = 0x9e3779b97f4a7c15ull;  // Compliant: const unsigned long long kSalt = 0x9E3779B97F4A7C15ULL;
// Rule: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.

#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>

namespace hash64 {

// Non-compliant lowercase suffixes (and lowercase hex digits kept to stress-only-literal-change diff).
static const unsigned long long kSalt  = 0x9e3779b97f4a7c15ull; // NC
static const unsigned long long kPrime = 0x100000001b3ull;      // NC (FNV-like prime variant)

// Very small illustrative mixer (deterministic, no UB).
std::uint64_t mix(std::uint64_t x, std::uint64_t y) {
    x ^= y + kSalt + (x << 6) + (x >> 2);
    x *= kPrime;
    return x ^ (x >> 33);
}

std::uint64_t hash_span(const std::vector<std::uint64_t>& v) {
    std::uint64_t h = 0ull; // NC
    for (std::uint64_t n : v) {
        h = mix(h, n);
    }
    return h;
}

} // namespace hash64

int main() {
    std::vector<std::uint64_t> data = { 1ull, 2ull, 3ull, 0xABCDEF12ull }; // NC
    std::uint64_t h = hash64::hash_span(data);

    std::cout << std::hex << std::uppercase
              << "Hash: 0x" << h << "\n";
    return 0;
}