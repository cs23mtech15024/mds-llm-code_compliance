// Context: Electric scooter speed governor

// -------- Non-Compliant Program (prog_074_nc.cpp)
#include <iostream>
#include "seedNC.h" // seed074_speed_cap, seed074_limit_speed()

namespace scooter_nc {

void apply(int speeds[], std::size_t n) { // NC
    for (std::size_t i=0;i<n;++i) {
        int out = seed074_limit_speed(speeds[i]);
        std::cout << "req=" << speeds[i]
                  << " cap=" << seed074_speed_cap
                  << " out=" << out << "\n";
    }
}

int maxv(int a[], std::size_t n){ int m=a[0]; for(size_t i=1;i<n;++i) if(a[i]>m)m=a[i]; return m; }

} // namespace scooter_nc

int main(){
    using namespace scooter_nc;
    int requested[5] = {10, 24, 30, 18, 27};
    apply(requested,5);
    std::cout << "peak=" << maxv(requested,5) << "\n";
    return 0;
}
