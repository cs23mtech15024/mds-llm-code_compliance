// Context: Home automation lighting profile

// -------- Non-Compliant Program (prog_009_nc.cpp)
// Context: Home automation lighting profile
#include <iostream>
#include <string>
#include "seedNC.h" // seed009_default_level, enum seed009_mode, seed009_get_level()

namespace light_nc {

std::string mode_name(seed009_mode m) {
    return (m == SEED009_DAY) ? "DAY" : "NIGHT";
}

void show_levels(seed009_mode modes[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) {
        int v = seed009_get_level(modes[i]);
        std::cout << "mode=" << mode_name(modes[i])
                  << " level=" << v << "\n";
    }
}

int sum_levels(seed009_mode modes[], std::size_t n) { // NC
    int s = 0;
    for (std::size_t i = 0; i < n; ++i) s += seed009_get_level(modes[i]);
    return s;
}

} // namespace light_nc

int main() {
    using namespace light_nc;
    seed009_mode arr[4] = {SEED009_DAY,SEED009_NIGHT,SEED009_NIGHT,SEED009_DAY};
    show_levels(arr,4);
    std::cout << "sum=" << sum_levels(arr,4) << "\n";
    return 0;
}
