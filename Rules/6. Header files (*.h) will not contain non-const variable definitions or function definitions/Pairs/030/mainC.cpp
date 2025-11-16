// Context: Graphics engine mipmap levels header

// -------- Compliant Program (prog_030_c.cpp)
// Context: Graphics engine mipmap levels — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed030_mip_levels = 8;
int seed030_best_mip(int size) { return (size <= 256) ? seed030_mip_levels : seed030_mip_levels - 2; }

namespace gfx_c {

int clamp(int v) { return (v < 1) ? 1 : v; }

template <std::size_t N>
void show_levels(const int (&sizes)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        int lvl = seed030_best_mip(clamp(sizes[i]));
        std::cout << "size=" << sizes[i]
                  << " best_mip=" << lvl << "\n";
    }
}

template <std::size_t N>
int sum(const int (&arr)[N]) {
    int s = 0;
    for (auto v : arr) s += v;
    return s;
}

} // namespace gfx_c

int main() {
    using namespace gfx_c;
    const int sz[4] = {128,256,512,1024};
    show_levels(sz);
    std::cout << "sum=" << sum(sz) << "\n";
    return 0;
}
