// Context: Chromatography retention times

// ------ Non-Compliant Program (078_nc.cpp)
// Context: Chromatography retention times
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>

namespace chrom_078_nc {

float identify_peak(float retention_times[]) { // NC API
    return retention_times[0];
}

static void show_first2(const float *r){
    std::cout << std::fixed << std::setprecision(2)
              << "rt0=" << r[0] << " rt1=" << r[1] << "\n";
}

} // namespace chrom_078_nc

int main(){
    using namespace chrom_078_nc;
    float gc_retention[50] = {3.45F, 3.60F};
    std::cout << "rt_peak=" << identify_peak(gc_retention) << "\n";
    show_first2(gc_retention);
    return 0;
}
