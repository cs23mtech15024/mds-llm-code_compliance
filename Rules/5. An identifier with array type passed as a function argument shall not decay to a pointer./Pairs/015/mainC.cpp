// Context: LIDAR distance measurements

// ------ Compliant Program (015_c.cpp)
// Context: Find minimum distance (toy logic)
// Rule: COMPLIANT (array by reference retains size)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace lidar_015_c {

static float min_first_n(const float (&v)[360], std::size_t take) { // C helper
    float m = v[0];
    for (std::size_t i = 1; i < take && i < 360U; ++i) { if (v[i] < m) m = v[i]; }
    return m;
}

static void preview(const float (&v)[360]) { // C helper
    std::cout << "preview:";
    for (std::size_t i = 0; i < 6U; ++i) std::cout << ' ' << v[i];
    std::cout << "\n";
}

float find_minimum_distance(float (&distances)[360]) { // C API
    preview(distances);
    return min_first_n(distances, 8U);
}

} // namespace lidar_015_c

int main() {
    using namespace lidar_015_c;
    float lidar_data[360] = {5.5F, 6.2F, 4.8F, 7.1F, 4.9F, 6.0F};
    std::cout << std::fixed << std::setprecision(2)
              << "min_dist=" << find_minimum_distance(lidar_data) << "\n";
    return 0;
}
