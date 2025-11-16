// Context: Image pixel buffer manipulation

// ------ Non-Compliant Program (002_nc.cpp)
// Context: Image pixel buffer manipulation
// NC: pixels[] decays to pointer; helpers use pointer/length
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <cstdint>

namespace img_002_nc {

static void brighten(unsigned char *pixels, std::size_t n, unsigned char add) { // NC
    for (std::size_t i = 0; i < n; ++i) {
        unsigned int v = static_cast<unsigned int>(pixels[i]) + add;
        pixels[i] = static_cast<unsigned char>((v > 255U) ? 255U : v);
    }
}

void apply_filter(unsigned char pixels[]) { // NC
    const std::size_t N = 100U;
    pixels[0] = 255U;
    brighten(pixels, N, 16U);
    std::cout << "pixel=" << static_cast<int>(pixels[0]) << "\n";
}

static void dump_head(const unsigned char *pixels, std::size_t n) {
    for (std::size_t i = 0; i < n; ++i) { std::cout << (i?" ":"") << static_cast<int>(pixels[i]); }
    std::cout << "\n";
}

} // namespace img_002_nc

int main() {
    using namespace img_002_nc;
    unsigned char image[100] = {};
    apply_filter(image);
    dump_head(image, 8U);
    return 0;
}
