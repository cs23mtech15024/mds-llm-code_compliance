// Context: Energy meter sample buffer parameters

// -------- Compliant Program (prog_020_c.cpp)
// Context: Energy meter sample buffer params — COMPLIANT
#include <iostream>
#include <cstddef>
#include "seedC.h"

// Definitions
std::size_t seed020_samples = 1024;
std::size_t seed020_half() { return seed020_samples / 2; }

namespace meter_c {

std::size_t used_samples(std::size_t total) {
    return total / 3;
}

template <std::size_t N>
void analyze(const std::size_t (&buf)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        std::size_t used = used_samples(buf[i]);
        std::size_t half = seed020_half();
        std::cout << "buf=" << buf[i] << " used=" << used
                  << " half=" << half << "\n";
    }
}

template <std::size_t N>
std::size_t sum(const std::size_t (&arr)[N]) {
    std::size_t s = 0;
    for (auto v : arr) s += v;
    return s;
}

} // namespace meter_c

int main() {
    using namespace meter_c;
    const std::size_t b[4] = {1024,512,2048,4096};
    analyze(b);
    std::cout << "sum=" << sum(b) << "\n";
    return 0;
}
