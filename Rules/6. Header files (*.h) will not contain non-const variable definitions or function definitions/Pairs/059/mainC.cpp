// Context: Camera white-balance preset header

// -------- Compliant Program (prog_059_c.cpp)
// Context: WB preset — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed059_wb_temp = 5500;
int seed059_adjust(int ambient){ return seed059_wb_temp + (ambient/100); }

namespace wb_c {

template <std::size_t N>
void test(const int (&a)[N]){
    for(auto v:a){
        int out = seed059_adjust(v);
        std::cout << "amb=" << v
                  << " base=" << seed059_wb_temp
                  << " out=" << out <<"\n";
    }
}

template <std::size_t N>
int maxv(const int (&arr)[N]){int m=0;for(auto v:arr)if(v>m)m=v;return m;}

} // namespace wb_c

int main(){
    using namespace wb_c;
    const int a[5]={100,200,300,150,50};
    test(a);
    std::cout << "max=" << maxv(a)<<"\n";
    return 0;
}
