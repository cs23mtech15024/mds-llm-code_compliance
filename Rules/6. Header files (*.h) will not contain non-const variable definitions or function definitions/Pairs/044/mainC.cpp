// Context: Data compression dictionary size header

// -------- Compliant Program (prog_044_c.cpp)
// Context: Compression dictionary logic — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed044_dict_size = 4096;
int seed044_max_code(){ return seed044_dict_size - 1; }

namespace dict_c {

template <std::size_t N>
void show(const int (&vals)[N]) {
    for(auto v:vals){
        int code = seed044_max_code();
        std::cout << "in=" << v
                  << " dict=" << seed044_dict_size
                  << " code=" << code << "\n";
    }
}

template <std::size_t N>
int sum(const int (&arr)[N]){int s=0; for(auto v:arr)s+=v; return s;}

} // namespace dict_c

int main(){
    using namespace dict_c;
    const int d[4]={1,2,3,4};
    show(d);
    std::cout << "sum=" << sum(d)<<"\n";
    return 0;
}
