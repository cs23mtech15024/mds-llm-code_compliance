// Context: Camera white-balance preset header

// -------- Non-Compliant Program (prog_059_nc.cpp)
// Context: White balance temperature logic
#include <iostream>
#include "seedNC.h" // seed059_wb_temp, seed059_adjust()

namespace wb_nc {

void test(int a[], std::size_t n){ // NC
    for(size_t i=0;i<n;++i){
        int out = seed059_adjust(a[i]);
        std::cout << "amb=" << a[i]
                  << " base=" << seed059_wb_temp
                  << " out=" << out <<"\n";
    }
}

int maxv(int a[], std::size_t n){int m=0;for(size_t i=0;i<n;++i)if(a[i]>m)m=a[i];return m;}

} // namespace wb_nc

int main(){
    using namespace wb_nc;
    int a[5]={100,200,300,150,50};
    test(a,5);
    std::cout << "max=" << maxv(a,5)<<"\n";
    return 0;
}
