// Context: Greenhouse CO₂ regulation threshold header

// -------- Compliant Program (prog_071_c.cpp)
#include <iostream>
#include "seedC.h"

int seed071_co2_limit = 900;
bool seed071_exceeds(int ppm) { return ppm > seed071_co2_limit; }

namespace gh_c {

template <std::size_t N>
void monitor(const int (&readings)[N]) {
    for (auto r : readings) {
        bool ex = seed071_exceeds(r);
        std::cout << "ppm=" << r
                  << " limit=" << seed071_co2_limit
                  << " exceed=" << (ex ? "YES" : "NO") << "\n";
    }
}

template <std::size_t N>
int maxv(const int (&arr)[N]) { int m = arr[0]; for (auto v:arr) if (v>m) m=v; return m; }

} // namespace gh_c

int main() {
    using namespace gh_c;
    const int readings[6] = {420, 780, 910, 880, 950, 870};
    monitor(readings);
    std::cout << "peak=" << maxv(readings) << "\n";
    return 0;
}
