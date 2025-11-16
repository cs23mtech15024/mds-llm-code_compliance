// Context: Medical device alarm thresholds

// -------- Non-Compliant Program (prog_016_nc.cpp)
// Context: Medical device alarm thresholds
#include <iostream>
#include <iomanip>
#include "seedNC.h"  // seed016_hr_threshold, seed016_is_alarm()

namespace med_nc {

float normalize(float hr) {
    return (hr < 0.0F) ? 0.0F : hr;
}

void evaluate(float readings[], std::size_t n) { // NC: array decay
    for (std::size_t i = 0; i < n; ++i) {
        float hr = normalize(readings[i]);
        bool alarm = seed016_is_alarm(hr); // header-defined function (NC)
        std::cout << "HR=" << std::fixed << std::setprecision(1)
                  << hr << " alarm=" << (alarm ? "YES" : "NO") << "\n";
    }
}

float max_hr(float arr[], std::size_t n) { // NC
    float m = 0.0F;
    for (std::size_t i = 0; i < n; ++i)
        if (arr[i] > m) m = arr[i];
    return m;
}

} // namespace med_nc

int main() {
    using namespace med_nc;
    float hrs[6] = {80.0F, 95.0F, 110.0F, 121.0F, 130.0F, 118.0F};
    evaluate(hrs, 6);
    std::cout << "max= " << max_hr(hrs, 6) << "\n";
    return 0;
}
