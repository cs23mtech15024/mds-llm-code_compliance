// Context: X-ray detector photon counts

// ------ Compliant Program (080_c.cpp)
// Context: X-ray detector photon counts
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <cstdint>

namespace xray_080_c {

static int to_i(std::uint16_t v){ return static_cast<int>(v); }

void analyze_xray_image(std::uint16_t (&counts)[65536]) { // C API
    std::cout << "count0=" << to_i(counts[0]) << "\n";
}

static void head(const std::uint16_t (&c)[65536]){
    for(int i=0;i<3;i++){ std::cout << (i?",":"head:") << to_i(c[i]); }
    std::cout << "\n";
}

} // namespace xray_080_c

int main(){
    using namespace xray_080_c;
    std::uint16_t xray_counts[65536] = {150, 151, 149};
    analyze_xray_image(xray_counts);
    head(xray_counts);
    return 0;
}
