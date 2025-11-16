// Context: Robotics wheel encoder conversion factors

// -------- Non-Compliant Program (prog_033_nc.cpp)
// Context: Robotics wheel encoder conversion
#include <iostream>
#include <cmath>
#include "seedNC.h" // seed033_ticks_per_rev, seed033_to_radians()

namespace enc_nc {

double radians_to_deg(double r) {
    return r * (180.0 / 3.14159);
}

void convert(int ticks[], std::size_t n) { // NC
    for (std::size_t i = 0; i < n; ++i) {
        double r = seed033_to_radians(ticks[i]); // header fn (NC)
        std::cout << "ticks=" << ticks[i]
                  << " rad=" << r
                  << " deg=" << radians_to_deg(r) << "\n";
    }
}

double max_ticks(int arr[], std::size_t n) { // NC
    int m = 0;
    for (std::size_t i = 0; i < n; ++i)
        if (arr[i] > m) m = arr[i];
    return m;
}

} // namespace enc_nc

int main() {
    using namespace enc_nc;
    int t[5] = {100,500,1024,2048,4096};
    convert(t,5);
    std::cout << "max=" << max_ticks(t,5) << "\n";
    return 0;
}
