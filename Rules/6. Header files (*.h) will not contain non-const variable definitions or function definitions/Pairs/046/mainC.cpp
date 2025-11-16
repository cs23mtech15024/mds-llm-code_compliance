// Context: Robotic vacuum mapping resolution header

// -------- Compliant Program (prog_046_c.cpp)
// Context: Robotic vacuum map resolution logic — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed046_map_resolution = 50;
int seed046_cells(int meters){ return meters * seed046_map_resolution; }

namespace vac_c {

template <std::size_t N>
void compute(const int (&meters)[N]) {
    for (auto m : meters) {
        int cells = seed046_cells(m);
        std::cout << "m=" << m
                  << " resolution=" << seed046_map_resolution
                  << " cells=" << cells << "\n";
    }
}

template <std::size_t N>
int sum(const int (&arr)[N]){
    int s=0; for(auto v:arr)s+=v; return s;
}

} // namespace vac_c

int main(){
    using namespace vac_c;
    const int d[5]={1,2,3,4,5};
    compute(d);
    std::cout << "sum=" << sum(d) << "\n";
    return 0;
}
