// Context: Temperature sensor array processor

// ------ Non-Compliant Program (001_nc.cpp)
// Context: Temperature sensor array processor
// Rule: Identifier with array type shall not decay to a pointer (VIOLATED)
// NC: temps[] and helpers accept decayed arrays/pointers
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace temp_001_nc {

static int first(const int temps[], std::size_t n) { // NC
    return (n > 0U) ? temps[0] : 0;
}

static int min_v(const int temps[], std::size_t n) { // NC
    int m = (n > 0U) ? temps[0] : 0;
    for (std::size_t i = 1; i < n; ++i) { if (temps[i] < m) { m = temps[i]; } }
    return m;
}

static int max_v(const int temps[], std::size_t n) { // NC
    int m = (n > 0U) ? temps[0] : 0;
    for (std::size_t i = 1; i < n; ++i) { if (temps[i] > m) { m = temps[i]; } }
    return m;
}

void process_temperatures(int temps[]) { // NC
    const std::size_t N = 5U;
    std::cout << "temp0=" << first(temps, N) << "\n";
    std::cout << "min=" << min_v(temps, N) << " max=" << max_v(temps, N) << "\n";
    int sum = 0;
    for (std::size_t i = 0; i < N; ++i) { sum += temps[i]; }
    std::cout << "avg=" << std::fixed << std::setprecision(2)
              << (static_cast<float>(sum) / static_cast<float>(N)) << "\n";
}

} // namespace temp_001_nc

int main() {
    using namespace temp_001_nc;
    int sensor_data[5] = {20, 21, 22, 23, 24};
    process_temperatures(sensor_data);
    return 0;
}
