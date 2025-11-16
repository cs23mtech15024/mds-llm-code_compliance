// Context: Display color temperature adjustment header

// -------- Compliant Program (prog_050_c.cpp)
// Context: Display color temperature — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed050_color_temp = 6500;
int seed050_adjust(int ambient){ return seed050_color_temp + ambient; }

namespace temp_c {

template <std::size_t N>
void test(const int (&amb)[N]) {
    for (auto v : amb) {
        int out = seed050_adjust(v);
        std::cout << "amb=" << v
                  << " base=" << seed050_color_temp
                  << " out=" << out <<"\n";
    }
}

template <std::size_t N>
int maxv(const int (&arr)[N]){int m=0;for(auto v:arr)if(v>m)m=v;return m;}

} // namespace temp_c

int main(){
    using namespace temp_c;
    const int a[5]={100,200,300,150,50};
    test(a);
    std::cout << "max=" << maxv(a)<<"\n";
    return 0;
}
