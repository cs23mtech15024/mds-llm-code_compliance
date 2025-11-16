// Context: Smart grid load balancing threshold header

// -------- Compliant Program (prog_076_c.cpp)
#include <iostream>
#include "seedC.h"

int seed076_load_limit = 3500;
bool seed076_overload(int watts) { return watts > seed076_load_limit; }

namespace grid_c {

template <std::size_t N>
void inspect(const int (&loads)[N]){
    for(auto v:loads){
        bool o = seed076_overload(v);
        std::cout << "load=" << v
                  << " limit=" << seed076_load_limit
                  << " overload=" << (o?"YES":"NO") << "\n";
    }
}

template <std::size_t N>
int sum(const int (&a)[N]){ int s=0; for(auto v:a) s+=v; return s; }

} // namespace grid_c

int main(){
    using namespace grid_c;
    const int loads[5] = {1200, 3400, 3600, 3000, 2000};
    inspect(loads);
    std::cout << "total=" << sum(loads) << "\n";
    return 0;
}
