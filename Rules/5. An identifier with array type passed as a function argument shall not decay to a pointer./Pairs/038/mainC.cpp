// Context: Flow meter volume readings

// ------ Compliant Program (038_c.cpp)
// Context: Sum volume from two meters, echo inputs
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace flow_038_c {

static void echo2(const float (&v)[12]) { std::cout << "v0=" << v[0] << ", v1=" << v[1] << "\n"; }

float calculate_total_flow(float (&volumes)[12]) { // C API
    echo2(volumes);
    return volumes[0] + volumes[1];
}

} // namespace flow_038_c

int main() {
    using namespace flow_038_c;
    float flow_volumes[12] = {10.5F, 11.2F};
    std::cout << std::fixed << std::setprecision(2) << "total_volume=" << calculate_total_flow(flow_volumes) << "\n";
    return 0;
}
