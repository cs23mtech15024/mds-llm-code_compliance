// Context: Battery charge cycle counters header

// -------- Non-Compliant Program (prog_051_nc.cpp)
// Context: Battery cycle counting logic
#include <iostream>
#include "seedNC.h" // seed051_cycle_count, seed051_increment()

namespace batt_nc {

void simulate(unsigned int ops[], std::size_t n) { // NC decay
    for (std::size_t i=0;i<n;++i) {
        for (unsigned int j=0;j<ops[i];++j) {
            seed051_increment(); // defined in header (NC)
        }
        std::cout << "ops=" << ops[i] << " total=" << seed051_cycle_count << "\n";
    }
}

unsigned int sum(unsigned int arr[], std::size_t n){ unsigned int s=0; for(size_t i=0;i<n;++i)s+=arr[i]; return s; }

} // namespace batt_nc

int main(){
    using namespace batt_nc;
    unsigned int a[4]={1,2,3,1};
    simulate(a,4);
    std::cout << "sum=" << sum(a,4) << "\n";
    return 0;
}
