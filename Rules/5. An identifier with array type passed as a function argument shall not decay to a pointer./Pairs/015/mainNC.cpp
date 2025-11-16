// Context: LIDAR distance measurements

// ------ Non-Compliant Program (015_nc.cpp)
// Context: Find minimum distance (toy logic)
// Rule: Array shall not decay — VIOLATED (distances[] decays)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace lidar_015_nc {

static float min_first_n(const float *v, std::size_t n, std::size_t take) { // NC helper
    if (n == 0U || take == 0U) return 0.0F;
    float m = v[0];
    for (std::size_t i = 1; i < take && i < n; ++i) { if (v[i] < m) m = v[i]; }
    return m;
}

static void preview(const float *v, std::size_t n) { // NC helper
    std::cout << "preview:";
    for (std::size_t i = 0; i < n && i < 6U; ++i) std::cout << ' ' << v[i];
    std::cout << "\n";
}

float find_minimum_distance(float distances[]) { // NC API
    preview(distances, 360U);
    return min_first_n(distances, 360U, 8U);
}

} // namespace lidar_015_nc

int main() {
    using namespace lidar_015_nc;
    float lidar_data[360] = {5.5F, 6.2F, 4.8F, 7.1F, 4.9F, 6.0F};
    std::cout << std::fixed << std::setprecision(2)
              << "min_dist=" << find_minimum_distance(lidar_data) << "\n";
    return 0;
}
