// Context: Graphics engine mipmap levels header

// -------- Non-Compliant Program (prog_030_nc.cpp)
// Context: Graphics engine mipmap levels
#include <iostream>
#include "seedNC.h" // seed030_mip_levels, seed030_best_mip()

namespace gfx_nc {

int clamp(int v) { return (v < 1) ? 1 : v; }

void show_levels(int sizes[], std::size_t n) { // NC
    for (std::size_t i = 0; i < n; ++i) {
        int lvl = seed030_best_mip(clamp(sizes[i]));
        std::cout << "size=" << sizes[i]
                  << " best_mip=" << lvl << "\n";
    }
}

int sum(int arr[], std::size_t n) {
    int s = 0;
    for (std::size_t i = 0; i < n; ++i) s += arr[i];
    return s;
}

} // namespace gfx_nc

int main() {
    using namespace gfx_nc;
    int sz[4] = {128,256,512,1024};
    show_levels(sz,4);
    std::cout << "sum=" << sum(sz,4) << "\n";
    return 0;
}
