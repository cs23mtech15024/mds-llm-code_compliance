// Context: Weather station hourly readings

// ------ Compliant Program (081_c.cpp)
// Context: Weather station hourly readings
// Status: Array passed by reference (COMPLIANT)
// Benefit: Compiler enforces exactly 24 samples
#include <iostream>
#include <iomanip>

namespace weather_081_c {

static float clamp_temp(float t){ return (t < -80.0F ? -80.0F : (t > 60.0F ? 60.0F : t)); }

static void normalize_first(float (&a)[24]){ a[0] = clamp_temp(a[0]); }

void daily_summary(float (&readings)[24]) { // C API
    normalize_first(readings);
    float mn = readings[0];
    float mx = readings[0];
    float sum = 0.0F;
    for(int i=0;i<6;i++){
        if(readings[i] < mn) mn = readings[i];
        if(readings[i] > mx) mx = readings[i];
        sum += readings[i];
    }
    float avg6 = sum / 6.0F;
    std::cout << std::fixed << std::setprecision(1)
              << "min=" << mn << ", max=" << mx << ", avg6=" << avg6 << "\n";
}

static void print_head(const float (&r)[24]){
    for(int i=0;i<8;i++){ std::cout << (i?",":"head:") << r[i]; }
    std::cout << "\n";
}

} // namespace weather_081_c

int main(){
    using namespace weather_081_c;
    float hourly[24] = {18.5F, 19.2F, 20.1F, 21.0F, 22.3F, 23.1F};
    for(int i=6;i<24;i++){ hourly[i] = 18.0F + static_cast<float>((i*7)%9); }
    daily_summary(hourly);
    print_head(hourly);
    return 0;
}
