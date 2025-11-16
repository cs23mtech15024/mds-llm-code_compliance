// Context: Water level sensor array

// ------ Compliant Program (093_c.cpp)
// Context: Water level sensor array (8 tanks)
// Status: Array passed by reference (COMPLIANT)
// Advantage: Size safety for 8 tanks
#include <iostream>
#include <iomanip>

namespace water_093_c {

static float clamp_pct(float v){ return (v<0.0F?0.0F:(v>100.0F?100.0F:v)); }

static void cap_first(float (&lvl)[8]){ lvl[0] = clamp_pct(lvl[0]); }

void monitor_levels(float (&levels)[8]) { // C API
    cap_first(levels);
    float sum = 0.0F;
    for(int i=0;i<8;i++){ sum += levels[i]; }
    float avg = sum/8.0F;
    std::cout << std::fixed << std::setprecision(1)
              << "tank0=" << levels[0] << "%, avg=" << avg << "%\n";
}

static void print_all(const float (&l)[8]){
    for(int i=0;i<8;i++){ std::cout << (i?",":"levels:") << l[i]; }
    std::cout << "\n";
}

} // namespace water_093_c

int main(){
    using namespace water_093_c;
    float tanks[8] = {75.5F, 44.0F, 60.0F, 90.0F, 10.0F, 50.0F, 30.0F, 99.0F};
    monitor_levels(tanks);
    print_all(tanks);
    return 0;
}
