// Context: Data compression dictionary size header

// -------- Non-Compliant Program (prog_044_nc.cpp)
// Context: Compression dictionary logic
#include <iostream>
#include "seedNC.h" // seed044_dict_size, seed044_max_code()

namespace dict_nc {

void show(int vals[], std::size_t n) { // NC
    for(size_t i=0;i<n;++i){
        int code = seed044_max_code();
        std::cout << "in=" << vals[i]
                  << " dict=" << seed044_dict_size
                  << " code=" << code << "\n";
    }
}

int sum(int arr[], std::size_t n){int s=0;for(size_t i=0;i<n;++i)s+=arr[i];return s;}

} // namespace dict_nc

int main(){
    using namespace dict_nc;
    int d[4]={1,2,3,4};
    show(d,4);
    std::cout << "sum=" << sum(d,4) <<"\n";
    return 0;
}
