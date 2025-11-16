// Context: Flow meter volume readings

// ------ Non-Compliant Program (038_nc.cpp)
// Context: Sum volume from two meters, echo inputs
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace flow_038_nc {

static void echo2(const float *v, std::size_t n) { if (n) std::cout << "v0=" << v[0]; if (n>1) std::cout << ", v1=" << v[1]; std::cout << "\n"; }

float calculate_total_flow(float volumes[]) { // NC API
    echo2(volumes, 12U);
    return volumes[0] + volumes[1];
}

} // namespace flow_038_nc

int main() {
    using namespace flow_038_nc;
    float flow_volumes[12] = {10.5F, 11.2F};
    std::cout << std::fixed << std::setprecision(2) << "total_volume=" << calculate_total_flow(flow_volumes) << "\n";
    return 0;
}
