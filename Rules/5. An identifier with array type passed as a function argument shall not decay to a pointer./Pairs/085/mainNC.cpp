// Context: Glucose monitor trend data

// ------ Non-Compliant Program (085_nc.cpp)
// Context: Glucose monitor trend data (288 samples/day)
// Rule: Array parameter decays to pointer (VIOLATION)
// Problem: Trend math assumes 288 samples but type does not
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace glucose_085_nc {

static float clamp_glucose(float mgdl){ return (mgdl<40.0F?40.0F:(mgdl>400.0F?400.0F:mgdl)); }

static void fix_first(float *r, std::size_t n){ if(n>1U){ r[0] = clamp_glucose(r[0]); r[1] = clamp_glucose(r[1]); } }

void analyze_trend(float readings[]) { // NC API
    const std::size_t N = 288U; (void)N;
    fix_first(readings, 288U);
    float delta = readings[1] - readings[0];
    // compute small moving average over 5 samples
    float sum = 0.0F;
    for(int i=0;i<5;i++){ sum += readings[i]; }
    float ma5 = sum / 5.0F;
    std::cout << std::fixed << std::setprecision(1)
              << "d1=" << delta << ", ma5=" << ma5 << "\n";
}

static void show_head(const float *r){
    for(int i=0;i<6;i++){ std::cout << (i?",":"head:") << r[i]; }
    std::cout << "\n";
}

} // namespace glucose_085_nc

int main(){
    using namespace glucose_085_nc;
    float log288[288] = {95.0F, 98.0F};
    for(int i=2;i<288;i++){ log288[i] = 90.0F + static_cast<float>((i*3)%15); }
    analyze_trend(log288);
    show_head(log288);
    return 0;
}
