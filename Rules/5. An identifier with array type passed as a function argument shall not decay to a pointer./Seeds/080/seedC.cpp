// Context: X-ray detector photon counts

// Seed 080 — C: photon counts by reference
#include <iostream>
#include <cstdint>
void analyze_xray_image(std::uint16_t (&counts)[65536]) { // C
    std::cout << "count0=" << counts[0] << "\n";
}
int main(){
    std::uint16_t xray_counts[65536] = {150};
    analyze_xray_image(xray_counts);
    return 0;
}