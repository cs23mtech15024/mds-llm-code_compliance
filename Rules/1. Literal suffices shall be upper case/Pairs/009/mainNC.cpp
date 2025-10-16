// Context: UI color utilities using hex masks and constants for ARGB components.
// Rule violated: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.
// Seed: Non-compliant: const unsigned rgb = 0xff00ffu;   // Compliant: const unsigned rgb = 0XFF00FFU;

#include <iostream>
#include <iomanip>
#include <cstdint>

namespace ui {
    // ARGB masks (non-compliant: lowercase 'u' and hex digits)
    constexpr std::uint32_t MASK_A = 0xff000000u;
    constexpr std::uint32_t MASK_R = 0x00ff0000u;
    constexpr std::uint32_t MASK_G = 0x0000ff00u;
    constexpr std::uint32_t MASK_B = 0x000000ffu;

    // Sample colors (non-compliant suffix/prefix case)
    constexpr std::uint32_t MAGENTA = 0xff00ffu;
    constexpr std::uint32_t OPAQUE  = 0xff000000u;

    constexpr std::uint32_t make_argb(std::uint8_t a, std::uint8_t r,
                                      std::uint8_t g, std::uint8_t b) {
        return (static_cast<std::uint32_t>(a) << 24) |
               (static_cast<std::uint32_t>(r) << 16) |
               (static_cast<std::uint32_t>(g) <<  8) |
               (static_cast<std::uint32_t>(b)      );
    }

    std::uint8_t chan(std::uint32_t c, std::uint32_t m, unsigned shift) {
        return static_cast<std::uint8_t>((c & m) >> shift);
    }
}

int main() {
    std::uint32_t c = ui::OPAQUE | ui::MAGENTA; // 0xFF00FF with alpha
    std::cout << std::hex << std::setfill('0');

    std::cout << "A=" << std::setw(2)
              << static_cast<unsigned>(ui::chan(c, ui::MASK_A, 24)) << " ";
    std::cout << "R=" << std::setw(2)
              << static_cast<unsigned>(ui::chan(c, ui::MASK_R, 16)) << " ";
    std::cout << "G=" << std::setw(2)
              << static_cast<unsigned>(ui::chan(c, ui::MASK_G, 8))  << " ";
    std::cout << "B=" << std::setw(2)
              << static_cast<unsigned>(ui::chan(c, ui::MASK_B, 0))  << "\n";

    return 0;
}