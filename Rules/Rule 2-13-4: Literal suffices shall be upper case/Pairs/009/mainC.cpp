// Context: UI color utilities using hex masks and constants for ARGB components.
// Rule satisfied: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.
// Seed: Non-compliant: const unsigned rgb = 0xff00ffu;   // Compliant: const unsigned rgb = 0XFF00FFU;

#include <iostream>
#include <iomanip>
#include <cstdint>

namespace ui {
    // ARGB masks (compliant: uppercase 'U' and hex digits/prefix)
    constexpr std::uint32_t MASK_A = 0XFF000000U;
    constexpr std::uint32_t MASK_R = 0X00FF0000U;
    constexpr std::uint32_t MASK_G = 0X0000FF00U;
    constexpr std::uint32_t MASK_B = 0X000000FFU;

    // Sample colors (compliant suffix/prefix case)
    constexpr std::uint32_t MAGENTA = 0XFF00FFU;
    constexpr std::uint32_t OPAQUE  = 0XFF000000U;

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
    std::uint32_t c = ui::OPAQUE | ui::MAGENTA; // 0XFF00FF with alpha
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