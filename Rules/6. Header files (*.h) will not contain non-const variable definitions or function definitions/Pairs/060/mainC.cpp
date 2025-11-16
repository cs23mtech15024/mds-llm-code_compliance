// Context: Bluetooth advertising interval header

// -------- Compliant Program (prog_060_c.cpp)
// Context: BT advertising — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
unsigned short seed060_adv_ms = 100;
unsigned short seed060_get_adv(){ return seed060_adv_ms; }

namespace bt_c {

template <std::size_t N>
void test(const unsigned short (&a)[N]){
    for(auto v:a){
        unsigned short out = seed060_get_adv();
        std::cout << "check=" << v
                  << " adv=" << seed060_adv_ms
                  << " out=" << out << "\n";
    }
}

template <std::size_t N>
unsigned short maxv(const unsigned short (&arr)[N]){
    unsigned short m=0; for(auto v:arr)if(v>m)m=v; return m;
}

} // namespace bt_c

int main(){
    using namespace bt_c;
    const unsigned short a[4]={50,100,150,200};
    test(a);
    std::cout << "max=" << maxv(a)<<"\n";
    return 0;
}
