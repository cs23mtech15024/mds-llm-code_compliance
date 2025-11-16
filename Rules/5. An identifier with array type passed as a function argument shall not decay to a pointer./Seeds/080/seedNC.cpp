// Context: X-ray detector photon counts

// Seed 080 — NC: photon counts decay to pointer
#include <iostream>
#include <cstdint>
void analyze_xray_image(std::uint16_t counts[]) { // NC
    std::cout << "count0=" << counts[0] << "\n";
}
int main(){
    std::uint16_t xray_counts[65536] = {150};
    analyze_xray_image(xray_counts);
    return 0;
}