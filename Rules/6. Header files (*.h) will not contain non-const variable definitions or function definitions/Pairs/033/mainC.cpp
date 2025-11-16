// Context: Robotics wheel encoder conversion factors

// -------- Compliant Program (prog_033_c.cpp)
// Context: Robotics wheel encoder conversion — COMPLIANT
#include <iostream>
#include <cmath>
#include "seedC.h"

// Definitions
double seed033_ticks_per_rev = 2048.0;
double seed033_to_radians(int ticks) { return (ticks * 3.14159 * 2) / seed033_ticks_per_rev; }

namespace enc_c {

double radians_to_deg(double r) { return r * (180.0 / 3.14159); }

template <std::size_t N>
void convert(const int (&ticks)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        double r = seed033_to_radians(ticks[i]);
        std::cout << "ticks=" << ticks[i]
                  << " rad=" << r
                  << " deg=" << radians_to_deg(r) << "\n";
    }
}

template <std::size_t N>
int max_ticks(const int (&arr)[N]) {
    int m = 0;
    for (auto v : arr) if (v > m) m = v;
    return m;
}

} // namespace enc_c

int main() {
    using namespace enc_c;
    const int t[5] = {100,500,1024,2048,4096};
    convert(t);
    std::cout << "max=" << max_ticks(t) << "\n";
    return 0;
}
