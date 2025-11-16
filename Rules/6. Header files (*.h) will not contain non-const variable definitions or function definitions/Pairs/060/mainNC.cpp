// Context: Bluetooth advertising interval header

// -------- Non-Compliant Program (prog_060_nc.cpp)
// Context: BT advertising interval logic
#include <iostream>
#include "seedNC.h" // seed060_adv_ms, seed060_get_adv()

namespace bt_nc {

void test(unsigned short a[], std::size_t n){ // NC
    for(size_t i=0;i<n;++i){
        unsigned short out = seed060_get_adv();
        std::cout << "check=" << a[i]
                  << " adv=" << seed060_adv_ms
                  << " out=" << out << "\n";
    }
}

unsigned short maxv(unsigned short a[], std::size_t n){unsigned short m=0;for(size_t i=0;i<n;++i)if(a[i]>m)m=a[i];return m;}

} // namespace bt_nc

int main(){
    using namespace bt_nc;
    unsigned short a[4]={50,100,150,200};
    test(a,4);
    std::cout << "max=" << maxv(a,4)<<"\n";
    return 0;
}
