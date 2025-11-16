// Context: QR code module bitmap

// ------ Compliant Program (052_c.cpp)
// Context: QR code module bitmap (21x21 -> 441 modules)
// Rule: Preserve array extent via references (COMPLIANT)
// C: All functions operate on array references
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace qr_052_c {

template <std::size_t N>
static void place_finder(std::uint8_t (&m)[N]) { if (N >= 1U) { m[0] = 1U; } }

void generate_qr(std::uint8_t (&modules)[441]) { // C API exact bound
    place_finder(modules);
    std::cout << "module0=" << static_cast<int>(modules[0]) << "\n";
}

} // namespace qr_052_c

int main() {
    using namespace qr_052_c;
    std::uint8_t qr_bitmap[441] = {0};
    generate_qr(qr_bitmap);
    return 0;
}
