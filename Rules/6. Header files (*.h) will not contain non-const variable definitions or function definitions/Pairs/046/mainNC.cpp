// Context: Robotic vacuum mapping resolution header

// -------- Non-Compliant Program (prog_046_nc.cpp)
// Context: Robotic vacuum map resolution logic
#include <iostream>
#include "seedNC.h" // seed046_map_resolution, seed046_cells()

namespace vac_nc {

void compute(int meters[], std::size_t n) { // NC: array decay
    for (std::size_t i = 0; i < n; ++i) {
        int cells = seed046_cells(meters[i]);
        std::cout << "m=" << meters[i]
                  << " resolution=" << seed046_map_resolution
                  << " cells=" << cells << "\n";
    }
}

int sum(int arr[], std::size_t n) {
    int s=0; for(size_t i=0;i<n;++i)s+=arr[i]; return s;
}

} // namespace vac_nc

int main(){
    using namespace vac_nc;
    int d[5]={1,2,3,4,5};
    compute(d,5);
    std::cout << "sum=" << sum(d,5) << "\n";
    return 0;
}
