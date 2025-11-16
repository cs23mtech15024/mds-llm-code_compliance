// Context: Greenhouse CO₂ regulation threshold header

// -------- Non-Compliant Program (prog_071_nc.cpp)
#include <iostream>
#include "seedNC.h" // seed071_co2_limit, seed071_exceeds()

namespace gh_nc {

void monitor(int readings[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) {
        bool ex = seed071_exceeds(readings[i]);
        std::cout << "ppm=" << readings[i]
                  << " limit=" << seed071_co2_limit
                  << " exceed=" << (ex ? "YES" : "NO") << "\n";
    }
}

int maxv(int arr[], std::size_t n) { int m = arr[0]; for (std::size_t i=1;i<n;++i) if (arr[i]>m) m=arr[i]; return m; }

} // namespace gh_nc

int main() {
    using namespace gh_nc;
    int readings[6] = {420, 780, 910, 880, 950, 870};
    monitor(readings, 6);
    std::cout << "peak=" << maxv(readings,6) << "\n";
    return 0;
}
