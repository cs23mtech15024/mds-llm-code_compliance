// Context: USB endpoint buffer descriptors

// ------ Non-Compliant Program (066_nc.cpp)
// Context: Configure USB endpoint descriptors (demo)
// Rule: Array parameter decays to pointer (VIOLATED)
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <iomanip>

namespace usb_066_nc {

constexpr std::size_t kEPs = 8U;

static void set_flag(std::uint32_t *d, std::size_t n, std::size_t idx, std::uint32_t m) { // NC
    if (idx < n) d[idx] |= m;
}

static void clear_flag(std::uint32_t *d, std::size_t n, std::size_t idx, std::uint32_t m) { // NC
    if (idx < n) d[idx] &= ~m;
}

void configure_endpoints(std::uint32_t descriptors[]) { // NC API
    set_flag(descriptors, kEPs, 0U, 0x80U);
    clear_flag(descriptors, kEPs, 0U, 0x40U);
    std::cout << "ep0=0x" << std::hex << std::uppercase << descriptors[0] << "\n";
}

} // namespace usb_066_nc

int main() {
    using namespace usb_066_nc;
    std::uint32_t eps[kEPs] = {0};
    configure_endpoints(eps);
    return 0;
}
