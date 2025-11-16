// Context: Conveyor belt speed sensors

// ------ Compliant Program (096_c.cpp)
// Context: Conveyor belt speed sensors (12 readings)
// Status: Array passed by reference (COMPLIANT)
// Advantage: Enforces correct array size at compile time
#include <iostream>
#include <iomanip>

namespace conveyor_096_c {

static float clamp_speed(float v){ return (v<0.0F?0.0F:(v>5.0F?5.0F:v)); }

static void init_first(float (&s)[12]){ s[0] = clamp_speed(1.2F); }

void synchronize(float (&speeds)[12]) { // C API
    init_first(speeds);
    float sum = 0.0F;
    for(int i=0;i<12;i++){ sum += speeds[i]; }
    float avg = sum/12.0F;
    std::cout << std::fixed << std::setprecision(2)
              << "first=" << speeds[0] << "m/s, avg=" << avg << "m/s\n";
}

static void head(const float (&s)[12]){
    for(int i=0;i<6;i++){ std::cout << (i?",":"speeds:") << s[i]; }
    std::cout << "\n";
}

} // namespace conveyor_096_c

int main(){
    using namespace conveyor_096_c;
    float belt[12] = {};
    for(int i=0;i<12;i++){ belt[i] = 0.5F + static_cast<float>(i)*0.1F; }
    synchronize(belt);
    head(belt);
    return 0;
}
