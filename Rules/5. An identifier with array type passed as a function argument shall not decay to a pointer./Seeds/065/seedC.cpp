// Context: Doppler radar velocity bins

// Seed 065 — C: velocity bins by reference
#include <iostream>
float extract_velocity(float (&bins)[128]) { // C
    return bins[0];
}
int main(){
    float doppler_bins[128] = {25.5F};
    std::cout << "velocity=" << extract_velocity(doppler_bins) << "\n";
    return 0;
}