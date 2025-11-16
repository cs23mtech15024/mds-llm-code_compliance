// Context: Display color temperature adjustment header

// -------- Non-Compliant Program (prog_050_nc.cpp)
// Context: Display color temperature
#include <iostream>
#include "seedNC.h" // seed050_color_temp, seed050_adjust()

namespace temp_nc {

void test(int amb[], std::size_t n) { // NC
    for(size_t i=0;i<n;++i){
        int out = seed050_adjust(amb[i]);
        std::cout << "amb=" << amb[i]
                  << " base=" << seed050_color_temp
                  << " out=" << out <<"\n";
    }
}

int maxv(int a[], std::size_t n){int m=0;for(size_t i=0;i<n;++i)if(a[i]>m)m=a[i];return m;}

} // namespace temp_nc

int main(){
    using namespace temp_nc;
    int a[5]={100,200,300,150,50};
    test(a,5);
    std::cout << "max=" << maxv(a,5)<<"\n";
    return 0;
}
