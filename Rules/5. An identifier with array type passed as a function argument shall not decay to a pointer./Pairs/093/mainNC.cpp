// Context: Water level sensor array

// ------ Non-Compliant Program (093_nc.cpp)
// Context: Water level sensor array (8 tanks)
// Rule: Array parameter decays to pointer (VIOLATION)
// Consequence: Callee assumes 8, type does not
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace water_093_nc {

static float clamp_pct(float v){ return (v<0.0F?0.0F:(v>100.0F?100.0F:v)); }

static void cap_first(float *lvl, std::size_t n){ if(n>0U){ lvl[0] = clamp_pct(lvl[0]); } }

void monitor_levels(float levels[]) { // NC API
    const std::size_t N = 8U; (void)N;
    cap_first(levels, 8U);
    float sum = 0.0F;
    for(int i=0;i<8;i++){ sum += levels[i]; }
    float avg = sum/8.0F;
    std::cout << std::fixed << std::setprecision(1)
              << "tank0=" << levels[0] << "%, avg=" << avg << "%\n";
}

static void print_all(const float *l){
    for(int i=0;i<8;i++){ std::cout << (i?",":"levels:") << l[i]; }
    std::cout << "\n";
}

} // namespace water_093_nc

int main(){
    using namespace water_093_nc;
    float tanks[8] = {75.5F, 44.0F, 60.0F, 90.0F, 10.0F, 50.0F, 30.0F, 99.0F};
    monitor_levels(tanks);
    print_all(tanks);
    return 0;
}
