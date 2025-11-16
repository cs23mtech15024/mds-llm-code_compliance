// Context: Energy meter sample buffer parameters

// -------- Non-Compliant Program (prog_020_nc.cpp)
// Context: Energy meter sample buffer params
#include <iostream>
#include <cstddef>
#include "seedNC.h" // seed020_samples, seed020_half()

namespace meter_nc {

std::size_t used_samples(std::size_t total) {
    return total / 3;
}

void analyze(std::size_t buf[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) {
        std::size_t used = used_samples(buf[i]);
        std::size_t half = seed020_half(); // NC header function
        std::cout << "buf=" << buf[i] << " used=" << used
                  << " half=" << half << "\n";
    }
}

std::size_t sum(std::size_t arr[], std::size_t n) { // NC
    std::size_t s = 0;
    for (std::size_t i = 0; i < n; ++i) s += arr[i];
    return s;
}

} // namespace meter_nc

int main() {
    using namespace meter_nc;
    std::size_t b[4] = {1024,512,2048,4096};
    analyze(b,4);
    std::cout << "sum=" << sum(b,4) << "\n";
    return 0;
}
