// Context: Electric scooter speed governor

// -------- Compliant Program (prog_074_c.cpp)
#include <iostream>
#include "seedC.h"

int seed074_speed_cap = 25;
int seed074_limit_speed(int s) { return (s > seed074_speed_cap) ? seed074_speed_cap : s; }

namespace scooter_c {

template <std::size_t N>
void apply(const int (&speeds)[N]){
    for(auto v:speeds){
        int out = seed074_limit_speed(v);
        std::cout << "req=" << v
                  << " cap=" << seed074_speed_cap
                  << " out=" << out << "\n";
    }
}

template <std::size_t N>
int maxv(const int (&a)[N]){ int m=a[0]; for(auto v:a) if(v>m)m=v; return m; }

} // namespace scooter_c

int main(){
    using namespace scooter_c;
    const int requested[5] = {10, 24, 30, 18, 27};
    apply(requested);
    std::cout << "peak=" << maxv(requested) << "\n";
    return 0;
}
