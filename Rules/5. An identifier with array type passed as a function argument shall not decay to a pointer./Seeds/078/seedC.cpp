// Context: Chromatography retention times

// Seed 078 — C: retention times by reference
#include <iostream>
float identify_peak(float (&retention_times)[50]) { // C
    return retention_times[0];
}
int main(){
    float gc_retention[50] = {3.45F};
    std::cout << "rt=" << identify_peak(gc_retention) << "\n";
    return 0;
}