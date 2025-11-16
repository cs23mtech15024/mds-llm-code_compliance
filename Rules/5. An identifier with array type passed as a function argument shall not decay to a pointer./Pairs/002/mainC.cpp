// Context: Image pixel buffer manipulation

// ------ Compliant Program (002_c.cpp)
// Context: Image pixel buffer manipulation
// C: pixels accepted by reference to array; helpers use array refs
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <cstdint>

namespace img_002_c {

template <std::size_t N>
static void brighten(unsigned char (&pixels)[N], unsigned char add) { // C
    for (std::size_t i = 0; i < N; ++i) {
        unsigned int v = static_cast<unsigned int>(pixels[i]) + add;
        pixels[i] = static_cast<unsigned char>((v > 255U) ? 255U : v);
    }
}

template <std::size_t N>
void apply_filter(unsigned char (&pixels)[N]) { // C
    pixels[0] = 255U;
    brighten(pixels, 16U);
    std::cout << "pixel=" << static_cast<int>(pixels[0]) << "\n";
}

template <std::size_t N>
static void dump_head(const unsigned char (&pixels)[N], std::size_t n) {
    for (std::size_t i = 0; (i < n) && (i < N); ++i) { std::cout << (i?" ":"") << static_cast<int>(pixels[i]); }
    std::cout << "\n";
}

} // namespace img_002_c

int main() {
    using namespace img_002_c;
    unsigned char image[100] = {};
    apply_filter(image);
    dump_head(image, 8U);
    return 0;
}
