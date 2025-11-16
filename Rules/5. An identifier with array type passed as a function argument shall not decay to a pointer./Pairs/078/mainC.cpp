// Context: Chromatography retention times

// ------ Compliant Program (078_c.cpp)
// Context: Chromatography retention times
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace chrom_078_c {

float identify_peak(float (&retention_times)[50]) { // C API
    return retention_times[0];
}

static void show_first2(const float (&r)[50]){
    std::cout << std::fixed << std::setprecision(2)
              << "rt0=" << r[0] << " rt1=" << r[1] << "\n";
}

} // namespace chrom_078_c

int main(){
    using namespace chrom_078_c;
    float gc_retention[50] = {3.45F, 3.60F};
    std::cout << "rt_peak=" << identify_peak(gc_retention) << "\n";
    show_first2(gc_retention);
    return 0;
}
