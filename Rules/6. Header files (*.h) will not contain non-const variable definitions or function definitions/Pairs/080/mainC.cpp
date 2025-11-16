// Context: Biometric fingerprint scanner quality threshold

// -------- Compliant Program (prog_080_c.cpp)
#include <iostream>
#include "seedC.h"

int seed080_quality_threshold = 72;
bool seed080_is_valid(int q) { return q >= seed080_quality_threshold; }

namespace fp_c {

template <std::size_t N>
void evaluate(const int (&quals)[N]){
    for(auto v:quals){
        bool ok = seed080_is_valid(v);
        std::cout << "q=" << v
                  << " thresh=" << seed080_quality_threshold
                  << " valid=" << (ok?"Y":"N") << "\n";
    }
}

template <std::size_t N>
int maxv(const int (&a)[N]){ int m=a[0]; for(auto v:a) if(v>m)m=v; return m; }

} // namespace fp_c

int main(){
    using namespace fp_c;
    const int q[6] = {60, 70, 72, 85, 71, 73};
    evaluate(q);
    std::cout << "best=" << maxv(q) << "\n";
    return 0;
}
