// ------ Non-Compliant (Seed 037)
// Context: Graphics — apply simple gamma correction to an 8-bit grayscale row,
// then pack a masked flag into the result. Demonstrates suffix case violations.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f', 'u', 'l' suffixes; lowercase hex digits in 0xa5u.

#include <iostream>
#include <array>
#include <cmath>
#include <cstdint>
#include <iomanip>

struct SrgbConfig {
    float gamma;        // gamma exponent
    unsigned flagMask;  // bitmask for tagging pixels
    long scale;         // fixed-point scaling factor
};

uint8_t applyGamma(uint8_t v, const SrgbConfig& cfg) {
    // normalize to [0,1]
    float n = static_cast<float>(v) / 255.0f;  // non-compliant 'f'
    // gamma correct
    float g = std::pow(n, 1.0f / cfg.gamma);   // non-compliant 'f'
    // scale and clamp
    long fixed = static_cast<long>(g * static_cast<float>(cfg.scale)); // 'f'
    if (fixed < 0l) fixed = 0l;                // non-compliant 'l'
    if (fixed > 1024l) fixed = 1024l;          // non-compliant 'l'
    // tag lowest bit using mask
    unsigned tagged = (static_cast<unsigned>(fixed) & 0xFFu) | (cfg.flagMask & 0xa5u); // non-compliant 'u' + hex
    return static_cast<uint8_t>(tagged & 0xFFu); // non-compliant
}

int main() {
    SrgbConfig cfg{2.2f, 0xa5u, 1024l}; // non-compliant suffixes/hex
    std::array<uint8_t, 5> row{0u, 64u, 128u, 192u, 255u}; // non-compliant 'u'
    for (auto v : row) {
        auto o = applyGamma(v, cfg);
        std::cout << std::setw(3) << static_cast<int>(o) << " ";
    }
    std::cout << "\n";
    return 0;
}