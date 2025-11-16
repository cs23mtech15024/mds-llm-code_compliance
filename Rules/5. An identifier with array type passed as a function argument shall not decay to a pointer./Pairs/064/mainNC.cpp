// Context: PID controller gain schedule

// ------ Non-Compliant Program (064_nc.cpp)
// Context: PID gain table loader (toy)
// Rule: Array parameter decays to pointer (VIOLATED)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace pid_064_nc {

constexpr std::size_t kSlots = 9U;

static void write_slot(float *gains, std::size_t n, std::size_t idx, float v) { // NC
    if (idx < n) gains[idx] = v;
}

static float sum3(const float *gains, std::size_t n) { // NC
    float s = 0.0F; std::size_t m = (n < 3U)? n : 3U;
    for (std::size_t i = 0; i < m; ++i) s += gains[i];
    return s;
}

void load_pid_gains(float gains[]) { // NC API
    write_slot(gains, kSlots, 0U, 1.50F);
    write_slot(gains, kSlots, 1U, 0.10F);
    write_slot(gains, kSlots, 2U, 0.01F);
    std::cout << std::fixed << std::setprecision(2)
              << "kp=" << gains[0] << " sum3=" << sum3(gains, kSlots) << "\n";
}

} // namespace pid_064_nc

int main() {
    using namespace pid_064_nc;
    float schedule[kSlots] = {0};
    load_pid_gains(schedule);
    return 0;
}
