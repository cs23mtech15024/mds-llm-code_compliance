// Context: Display brightness profile header

// -------- Non-Compliant Program (prog_025_nc.cpp)
// Context: Display brightness profile
#include <iostream>
#include "seedNC.h" // seed025_default_brightness, seed025_adjust_brightness()

namespace disp_nc {

void apply(int ambient[], std::size_t n) { // NC
    for (std::size_t i = 0; i < n; ++i) {
        int adj = seed025_adjust_brightness(ambient[i]);
        std::cout << "ambient=" << ambient[i]
                  << " adj=" << adj << "\n";
    }
}

int total(int arr[], std::size_t n) {
    int s = 0;
    for (std::size_t i = 0; i < n; ++i) s += arr[i];
    return s;
}

} // namespace disp_nc

int main() {
    using namespace disp_nc;
    int amb[4] = {150,250,180,300};
    apply(amb,4);
    std::cout << "total=" << total(amb,4) << "\n";
    return 0;
}
