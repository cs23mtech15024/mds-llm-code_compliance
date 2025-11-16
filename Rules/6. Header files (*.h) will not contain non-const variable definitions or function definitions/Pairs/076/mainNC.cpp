// Context: Smart grid load balancing threshold header

// -------- Non-Compliant Program (prog_076_nc.cpp)
#include <iostream>
#include "seedNC.h" // seed076_load_limit, seed076_overload()

namespace grid_nc {

void inspect(int loads[], std::size_t n) { // NC
    for (std::size_t i=0;i<n;++i) {
        bool o = seed076_overload(loads[i]);
        std::cout << "load=" << loads[i]
                  << " limit=" << seed076_load_limit
                  << " overload=" << (o?"YES":"NO") << "\n";
    }
}

int sum(int a[], std::size_t n){ int s=0; for(size_t i=0;i<n;++i) s+=a[i]; return s; }

} // namespace grid_nc

int main(){
    using namespace grid_nc;
    int loads[5] = {1200, 3400, 3600, 3000, 2000};
    inspect(loads,5);
    std::cout << "total=" << sum(loads,5) << "\n";
    return 0;
}
