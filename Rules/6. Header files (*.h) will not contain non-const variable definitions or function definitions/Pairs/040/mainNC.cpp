// Context: Network latency smoothing parameter header

// -------- Non-Compliant Program (prog_040_nc.cpp)
// Context: Network latency smoothing
#include <iostream>
#include "seedNC.h" // seed040_latency_alpha, seed040_smooth()

namespace net_nc {

void process(double prev[], double curr[], std::size_t n) { // NC: array decay
    for (std::size_t i = 0; i < n; ++i) {
        double out = seed040_smooth(prev[i], curr[i]); // NC header fn
        std::cout << "prev=" << prev[i]
                  << " curr=" << curr[i]
                  << " out=" << out
                  << "\n";
    }
}

double maxd(double arr[], std::size_t n) {
    double m=0; for(size_t i=0;i<n;++i) if(arr[i]>m) m=arr[i]; return m;
}

} // namespace net_nc

int main() {
    using namespace net_nc;
    double p[4] = {10,20,30,40};
    double c[4] = {15,22,28,42};
    process(p,c,4);
    std::cout << "max_prev=" << maxd(p,4) << "\n";
    return 0;
}
