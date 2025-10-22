// ------ Compliant (Seed 037)
// Context: Graphics — apply simple gamma correction to an 8-bit grayscale row,
// then pack a masked flag into the result. Literal suffixes/hex digits fixed.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>
#include <array>
#include <cmath>
#include <cstdint>
#include <iomanip>

struct SrgbConfig {
    float gamma;
    unsigned flagMask;
    long scale;
};

uint8_t applyGamma(uint8_t v, const SrgbConfig& cfg) {
    float n = static_cast<float>(v) / 255.0F;        // compliant
    float g = std::pow(n, 1.0F / cfg.gamma);         // compliant
    long fixed = static_cast<long>(g * static_cast<float>(cfg.scale));
    if (fixed < 0L) fixed = 0L;                       // compliant
    if (fixed > 1024L) fixed = 1024L;                 // compliant
    unsigned tagged = (static_cast<unsigned>(fixed) & 0XFFU) | (cfg.flagMask & 0XA5U); // compliant
    return static_cast<uint8_t>(tagged & 0XFFU);      // compliant
}

int main() {
    SrgbConfig cfg{2.2F, 0XA5U, 1024L};              // compliant
    std::array<uint8_t, 5> row{0U, 64U, 128U, 192U, 255U}; // compliant
    for (auto v : row) {
        auto o = applyGamma(v, cfg);
        std::cout << std::setw(3) << static_cast<int>(o) << " ";
    }
    std::cout << "\n";
    return 0;
}