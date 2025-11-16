// Context: Medical device alarm thresholds

// -------- Compliant Program (prog_016_c.cpp)
// Context: Medical device alarm thresholds — COMPLIANT
#include <iostream>
#include <iomanip>
#include "seedC.h"  // extern seed016_hr_threshold, seed016_is_alarm()

// Definitions
float seed016_hr_threshold = 120.0F;
bool seed016_is_alarm(float hr) { return hr > seed016_hr_threshold; }

namespace med_c {

float normalize(float hr) {
    return (hr < 0.0F) ? 0.0F : hr;
}

template <std::size_t N>
void evaluate(const float (&readings)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        float hr = normalize(readings[i]);
        bool alarm = seed016_is_alarm(hr);
        std::cout << "HR=" << std::fixed << std::setprecision(1)
                  << hr << " alarm=" << (alarm ? "YES" : "NO") << "\n";
    }
}

template <std::size_t N>
float max_hr(const float (&arr)[N]) {
    float m = 0.0F;
    for (auto v : arr) if (v > m) m = v;
    return m;
}

} // namespace med_c

int main() {
    using namespace med_c;
    const float hrs[6] = {80.0F,95.0F,110.0F,121.0F,130.0F,118.0F};
    evaluate(hrs);
    std::cout << "max= " << max_hr(hrs) << "\n";
    return 0;
}
