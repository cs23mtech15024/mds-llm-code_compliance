// Context: Display brightness profile header

// -------- Compliant Program (prog_025_c.cpp)
// Context: Display brightness profile — COMPLIANT
#include <iostream>
#include "seedC.h" // extern seed025_default_brightness, seed025_adjust_brightness()

// Definitions
int seed025_default_brightness = 80;
int seed025_adjust_brightness(int ambient) {
    return (ambient > 200) ? seed025_default_brightness + 10 : seed025_default_brightness;
}

namespace disp_c {

template <std::size_t N>
void apply(const int (&ambient)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        int adj = seed025_adjust_brightness(ambient[i]);
        std::cout << "ambient=" << ambient[i]
                  << " adj=" << adj << "\n";
    }
}

template <std::size_t N>
int total(const int (&arr)[N]) {
    int s = 0;
    for (auto v : arr) s += v;
    return s;
}

} // namespace disp_c

int main() {
    using namespace disp_c;
    const int amb[4] = {150,250,180,300};
    apply(amb);
    std::cout << "total=" << total(amb) << "\n";
    return 0;
}
