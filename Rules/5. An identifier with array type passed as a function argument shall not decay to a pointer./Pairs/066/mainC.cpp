// Context: USB endpoint buffer descriptors

// ------ Compliant Program (066_c.cpp)
// Context: Configure USB endpoint descriptors (demo)
// Rule: Preserve array with reference (COMPLIANT)
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <iomanip>

namespace usb_066_c {

constexpr std::size_t kEPs = 8U;

template <std::size_t N>
static void set_flag(std::uint32_t (&d)[N], std::size_t idx, std::uint32_t m) {
    static_assert(N == 8U, "expect 8 endpoints");
    if (idx < N) d[idx] |= m;
}

template <std::size_t N>
static void clear_flag(std::uint32_t (&d)[N], std::size_t idx, std::uint32_t m) {
    if (idx < N) d[idx] &= ~m;
}

void configure_endpoints(std::uint32_t (&descriptors)[kEPs]) { // C API
    set_flag(descriptors, 0U, 0x80U);
    clear_flag(descriptors, 0U, 0x40U);
    std::cout << "ep0=0x" << std::hex << std::uppercase << descriptors[0] << "\n";
}

} // namespace usb_066_c

int main() {
    using namespace usb_066_c;
    std::uint32_t eps[kEPs] = {0};
    configure_endpoints(eps);
    return 0;
}
