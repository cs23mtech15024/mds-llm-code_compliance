// Context: QR code module bitmap

// ------ Non-Compliant Program (052_nc.cpp)
// Context: QR code module bitmap (21x21 -> 441 modules)
// Rule: Array decays to pointer (VIOLATED)
// NC: generate_qr uses decayed pointer and length implicit
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace qr_052_nc {

static void place_finder(std::uint8_t *m, std::size_t n) { // NC
    if (n >= 1U) { m[0] = 1U; }
}

void generate_qr(std::uint8_t modules[]) { // NC API
    const std::size_t N = 441U;
    place_finder(modules, N);
    std::cout << "module0=" << static_cast<int>(modules[0]) << "\n";
}

} // namespace qr_052_nc

int main() {
    using namespace qr_052_nc;
    std::uint8_t qr_bitmap[441] = {0};
    generate_qr(qr_bitmap);
    return 0;
}
