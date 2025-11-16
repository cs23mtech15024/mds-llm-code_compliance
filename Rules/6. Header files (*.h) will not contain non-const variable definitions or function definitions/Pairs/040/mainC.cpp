// Context: Network latency smoothing parameter header

// -------- Compliant Program (prog_040_c.cpp)
// Context: Network latency smoothing — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
double seed040_latency_alpha = 0.7;
double seed040_smooth(double prev, double curr) {
    return seed040_latency_alpha * prev + (1 - seed040_latency_alpha) * curr;
}

namespace net_c {

template <std::size_t N>
void process(const double (&prev)[N], const double (&curr)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        double out = seed040_smooth(prev[i], curr[i]);
        std::cout << "prev=" << prev[i]
                  << " curr=" << curr[i]
                  << " out=" << out
                  << "\n";
    }
}

template <std::size_t N>
double maxd(const double (&arr)[N]) {
    double m=0; for(auto v:arr) if(v>m) m=v; return m;
}

} // namespace net_c

int main() {
    using namespace net_c;
    const double p[4] = {10,20,30,40};
    const double c[4] = {15,22,28,42};
    process(p,c);
    std::cout << "max_prev=" << maxd(p) << "\n";
    return 0;
}
