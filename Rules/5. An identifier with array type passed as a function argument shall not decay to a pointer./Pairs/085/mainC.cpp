// Context: Glucose monitor trend data

// ------ Compliant Program (085_c.cpp)
// Context: Glucose monitor trend data (288 samples/day)
// Status: Array passed by reference (COMPLIANT)
// Result: Interface guarantees 288-sample buffer
#include <iostream>
#include <iomanip>

namespace glucose_085_c {

static float clamp_glucose(float mgdl){ return (mgdl<40.0F?40.0F:(mgdl>400.0F?400.0F:mgdl)); }

static void fix_first(float (&r)[288]){ r[0] = clamp_glucose(r[0]); r[1] = clamp_glucose(r[1]); }

void analyze_trend(float (&readings)[288]) { // C API
    fix_first(readings);
    float delta = readings[1] - readings[0];
    float sum = 0.0F;
    for(int i=0;i<5;i++){ sum += readings[i]; }
    float ma5 = sum / 5.0F;
    std::cout << std::fixed << std::setprecision(1)
              << "d1=" << delta << ", ma5=" << ma5 << "\n";
}

static void show_head(const float (&r)[288]){
    for(int i=0;i<6;i++){ std::cout << (i?",":"head:") << r[i]; }
    std::cout << "\n";
}

} // namespace glucose_085_c

int main(){
    using namespace glucose_085_c;
    float log288[288] = {95.0F, 98.0F};
    for(int i=2;i<288;i++){ log288[i] = 90.0F + static_cast<float>((i*3)%15); }
    analyze_trend(log288);
    show_head(log288);
    return 0;
}
