// Context: X-ray detector photon counts

// ------ Non-Compliant Program (080_nc.cpp)
// Context: X-ray detector photon counts
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace xray_080_nc {

static int to_i(std::uint16_t v){ return static_cast<int>(v); }

void analyze_xray_image(std::uint16_t counts[]) { // NC API
    const std::size_t N = 65536U; (void)N;
    std::cout << "count0=" << to_i(counts[0]) << "\n";
}

static void head(const std::uint16_t *c){
    for(int i=0;i<3;i++){ std::cout << (i?",":"head:") << to_i(c[i]); }
    std::cout << "\n";
}

} // namespace xray_080_nc

int main(){
    using namespace xray_080_nc;
    std::uint16_t xray_counts[65536] = {150, 151, 149};
    analyze_xray_image(xray_counts);
    head(xray_counts);
    return 0;
}
