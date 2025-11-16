// Context: Laser cutting path coordinates

// ------ Non-Compliant Program (090_nc.cpp)
// Context: Laser cutting path coordinates (1000 points)
// Rule: Array parameter decays to pointer (VIOLATION)
// Issue: Path length not enforced by type
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace laser_090_nc {

static void offset_first(float *coords, std::size_t n){ if(n>0U){ coords[0] += 1.0F; } }

void execute_path(float coords[]) { // NC API
    const std::size_t N = 1000U; (void)N;
    offset_first(coords, 1000U);
    float sum = 0.0F;
    for(int i=0;i<10;i++){ sum += coords[i]; }
    std::cout << std::fixed << std::setprecision(2)
              << "x0=" << coords[0] << ", sum10=" << sum << "\n";
}

} // namespace laser_090_nc

int main(){
    using namespace laser_090_nc;
    float path[1000] = {10.5F};
    for(int i=1;i<1000;i++){ path[i] = 10.0F + static_cast<float>(i%10); }
    execute_path(path);
    return 0;
}
