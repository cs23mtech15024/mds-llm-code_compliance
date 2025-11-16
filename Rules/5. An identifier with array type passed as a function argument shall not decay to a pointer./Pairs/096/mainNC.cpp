// Context: Conveyor belt speed sensors

// ------ Non-Compliant Program (096_nc.cpp)
// Context: Conveyor belt speed sensors (12 readings)
// Rule: Array parameter decays to pointer (VIOLATION)
// Problem: Function assumes 12 sensors without enforcing array size
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace conveyor_096_nc {

static float clamp_speed(float v){ return (v<0.0F?0.0F:(v>5.0F?5.0F:v)); }

static void init_first(float *s, std::size_t n){ if(n>0U){ s[0] = clamp_speed(1.2F); } }

void synchronize(float speeds[]) { // NC API
    const std::size_t N = 12U; (void)N;
    init_first(speeds, 12U);
    float sum = 0.0F;
    for(int i=0;i<12;i++){ sum += speeds[i]; }
    float avg = sum/12.0F;
    std::cout << std::fixed << std::setprecision(2)
              << "first=" << speeds[0] << "m/s, avg=" << avg << "m/s\n";
}

static void head(const float *s){
    for(int i=0;i<6;i++){ std::cout << (i?",":"speeds:") << s[i]; }
    std::cout << "\n";
}

} // namespace conveyor_096_nc

int main(){
    using namespace conveyor_096_nc;
    float belt[12] = {};
    for(int i=0;i<12;i++){ belt[i] = 0.5F + static_cast<float>(i)*0.1F; }
    synchronize(belt);
    head(belt);
    return 0;
}
