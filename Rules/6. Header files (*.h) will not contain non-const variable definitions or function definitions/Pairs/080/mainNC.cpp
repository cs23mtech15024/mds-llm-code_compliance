// Context: Biometric fingerprint scanner quality threshold

// -------- Non-Compliant Program (prog_080_nc.cpp)
#include <iostream>
#include "seedNC.h" // seed080_quality_threshold, seed080_is_valid()

namespace fp_nc {

void evaluate(int quals[], std::size_t n) { // NC
    for (std::size_t i=0;i<n;++i) {
        bool v = seed080_is_valid(quals[i]);
        std::cout << "q=" << quals[i]
                  << " thresh=" << seed080_quality_threshold
                  << " valid=" << (v?"Y":"N") << "\n";
    }
}

int maxv(int a[], std::size_t n){ int m=a[0]; for(size_t i=1;i<n;++i) if(a[i]>m)m=a[i]; return m; }

} // namespace fp_nc

int main(){
    using namespace fp_nc;
    int q[6] = {60, 70, 72, 85, 71, 73};
    evaluate(q,6);
    std::cout << "best=" << maxv(q,6) << "\n";
    return 0;
}
