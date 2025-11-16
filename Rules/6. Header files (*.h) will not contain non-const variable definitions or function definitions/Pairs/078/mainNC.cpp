// Context: Warehouse barcode scanner retry config

// -------- Non-Compliant Program (prog_078_nc.cpp)
#include <iostream>
#include "seedNC.h" // seed078_max_retries, seed078_allow_retry()

namespace scan_nc {

void attempt(int counts[], std::size_t n) { // NC
    for (std::size_t i=0;i<n;++i) {
        bool ok = seed078_allow_retry(counts[i]);
        std::cout << "attempts=" << counts[i]
                  << " max=" << seed078_max_retries
                  << " allow_retry=" << (ok?"Y":"N") << "\n";
    }
}

int maxv(int a[], std::size_t n){ int m=a[0]; for(size_t i=1;i<n;++i) if(a[i]>m)m=a[i]; return m; }

} // namespace scan_nc

int main(){
    using namespace scan_nc;
    int tries[5] = {0,1,2,3,4};
    attempt(tries,5);
    std::cout << "max=" << maxv(tries,5) << "\n";
    return 0;
}
