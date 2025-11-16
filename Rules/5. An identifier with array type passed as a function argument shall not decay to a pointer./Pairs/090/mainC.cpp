// Context: Laser cutting path coordinates

// ------ Compliant Program (090_c.cpp)
// Context: Laser cutting path coordinates (1000 points)
// Status: Array passed by reference (COMPLIANT)
// Result: Enforced compile-time array bound
#include <iostream>
#include <iomanip>

namespace laser_090_c {

static void offset_first(float (&coords)[1000]){ coords[0] += 1.0F; }

void execute_path(float (&coords)[1000]) { // C API
    offset_first(coords);
    float sum = 0.0F;
    for(int i=0;i<10;i++){ sum += coords[i]; }
    std::cout << std::fixed << std::setprecision(2)
              << "x0=" << coords[0] << ", sum10=" << sum << "\n";
}

} // namespace laser_090_c

int main(){
    using namespace laser_090_c;
    float path[1000] = {10.5F};
    for(int i=1;i<1000;i++){ path[i] = 10.0F + static_cast<float>(i%10); }
    execute_path(path);
    return 0;
}
