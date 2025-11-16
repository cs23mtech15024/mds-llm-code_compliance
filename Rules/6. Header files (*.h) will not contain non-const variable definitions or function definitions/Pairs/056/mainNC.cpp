// Context: Smart lock retry timeout header

// -------- Non-Compliant Program (prog_056_nc.cpp)
// Context: Smart lock timeout system
#include <iostream>
#include "seedNC.h" // seed056_retry_timeout_ms, seed056_timeout_expired()

namespace lock_nc {

void test(int arr[], std::size_t n){ // NC
    for(size_t i=0;i<n;++i){
        bool ex = seed056_timeout_expired(arr[i]);
        std::cout << "elapsed=" << arr[i]
                  << " limit=" << seed056_retry_timeout_ms
                  << " expired=" << (ex?"Y":"N") << "\n";
    }
}

int maxv(int a[], std::size_t n){int m=0;for(size_t i=0;i<n;++i)if(a[i]>m)m=a[i];return m;}

} // namespace lock_nc

int main(){
    using namespace lock_nc;
    int e[5]={500,2000,3500,1000,3000};
    test(e,5);
    std::cout << "max=" << maxv(e,5)<<"\n";
    return 0;
}
