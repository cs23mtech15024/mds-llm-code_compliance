// Context: Weather station hourly readings

// ------ Non-Compliant Program (081_nc.cpp)
// Context: Weather station hourly readings
// Rule: Array parameter decays to pointer (VIOLATION)
// Note: Size information is lost at call site
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace weather_081_nc {

// Clamp a value into a plausible ambient range
static float clamp_temp(float t){ return (t < -80.0F ? -80.0F : (t > 60.0F ? 60.0F : t)); }

// Helper mutates first element using only a count parameter
static void normalize_first(float *a, std::size_t n){ if(n>0U){ a[0] = clamp_temp(a[0]); } }

// NC: array parameter decays to pointer; no compile-time bound check
void daily_summary(float readings[]) { // NC API
    const std::size_t HOURS = 24U; (void)HOURS; // pretend we know size
    normalize_first(readings, 24U);
    // compute min, max and 6-hour average using first 6 samples
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

// Inspect head of series for quick glance
static void print_head(const float *r){
    for(int i=0;i<8;i++){ std::cout << (i?",":"head:") << r[i]; }
    std::cout << "\n";
}

} // namespace weather_081_nc

int main(){
    using namespace weather_081_nc;
    float hourly[24] = {18.5F, 19.2F, 20.1F, 21.0F, 22.3F, 23.1F};
    for(int i=6;i<24;i++){ hourly[i] = 18.0F + static_cast<float>((i*7)%9); }
    daily_summary(hourly);
    print_head(hourly);
    return 0;
}
