// ------ Compliant (Seed 028)
// Context: Graphics — simulate pixel shader brightness scaling on a 2D image buffer.
//          Demonstrates use of float literals in color transformations.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all suffixes changed to uppercase F and hex digits to uppercase.

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdint>
#include <algorithm>

struct Pixel {
    uint8_t r, g, b;
};

static uint32_t packColor(const Pixel& p) {
    return (static_cast<uint32_t>(p.r) << 16) |
           (static_cast<uint32_t>(p.g) << 8) |
           (static_cast<uint32_t>(p.b));
}

static Pixel applyIntensity(const Pixel& p, float intensity) {
    Pixel result;
    result.r = static_cast<uint8_t>(std::min(255.0F, p.r * intensity)); // compliant
    result.g = static_cast<uint8_t>(std::min(255.0F, p.g * intensity)); // compliant
    result.b = static_cast<uint8_t>(std::min(255.0F, p.b * intensity)); // compliant
    return result;
}

int main() {
    std::vector<Pixel> image = {
        {128, 200, 255},
        {80, 160, 240},
        {60, 100, 220}
    };

    const float intensity = 0.75F; // compliant
    const uint32_t mask = 0X00FFFFFFU; // compliant

    std::cout << "Applying intensity scaling: " << intensity << "\n";
    for (std::size_t i = 0; i < image.size(); ++i) {
        const Pixel adjusted = applyIntensity(image[i], intensity);
        uint32_t color = packColor(adjusted) & mask;
        std::cout << "Pixel " << i << ": "
                  << "RGB(" << static_cast<int>(adjusted.r) << ", "
                  << static_cast<int>(adjusted.g) << ", "
                  << static_cast<int>(adjusted.b) << ") -> 0x"
                  << std::hex << std::setw(6) << std::setfill('0') << color << "\n";
    }

    return 0;
}