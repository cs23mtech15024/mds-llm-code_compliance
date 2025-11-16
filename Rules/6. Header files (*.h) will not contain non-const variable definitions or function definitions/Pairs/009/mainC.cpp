// Context: Home automation lighting profile

// -------- Compliant Program (prog_009_c.cpp)
// Context: Home automation lighting profile — COMPLIANT
#include <iostream>
#include <string>
#include "seedC.h"

// Definitions
int seed009_default_level = 75;
int seed009_get_level(seed009_mode m) {
    return (m == SEED009_DAY) ? 100 : seed009_default_level;
}

namespace light_c {

std::string mode_name(seed009_mode m) {
    return (m == SEED009_DAY) ? "DAY" : "NIGHT";
}

template <std::size_t N>
void show_levels(const seed009_mode (&modes)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        int v = seed009_get_level(modes[i]);
        std::cout << "mode=" << mode_name(modes[i])
                  << " level=" << v << "\n";
    }
}

template <std::size_t N>
int sum_levels(const seed009_mode (&modes)[N]) {
    int s = 0;
    for (auto m : modes) s += seed009_get_level(m);
    return s;
}

} // namespace light_c

int main() {
    using namespace light_c;
    const seed009_mode arr[4] = {SEED009_DAY,SEED009_NIGHT,SEED009_NIGHT,SEED009_DAY};
    show_levels(arr);
    std::cout << "sum=" << sum_levels(arr) << "\n";
    return 0;
}
