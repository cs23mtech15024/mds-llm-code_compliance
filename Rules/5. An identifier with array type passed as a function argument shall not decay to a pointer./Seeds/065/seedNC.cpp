// Context: Doppler radar velocity bins

// Seed 065 — NC: velocity bins decay to pointer
#include <iostream>
float extract_velocity(float bins[]) { // NC
    return bins[0];
}
int main(){
    float doppler_bins[128] = {25.5F};
    std::cout << "velocity=" << extract_velocity(doppler_bins) << "\n";
    return 0;
}