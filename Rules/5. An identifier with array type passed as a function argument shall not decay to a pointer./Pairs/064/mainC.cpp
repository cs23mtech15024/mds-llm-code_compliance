// Context: PID controller gain schedule

// ------ Compliant Program (064_c.cpp)
// Context: PID gain table loader (toy)
// Rule: Preserve array via reference (COMPLIANT)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace pid_064_c {

constexpr std::size_t kSlots = 9U;

template <std::size_t N>
static void write_slot(float (&gains)[N], std::size_t idx, float v) {
    static_assert(N == 9U, "expect 9-slot schedule");
    if (idx < N) gains[idx] = v;
}

template <std::size_t N>
static float sum3(const float (&gains)[N]) {
    float s = 0.0F; std::size_t m = (N < 3U)? N : 3U;
    for (std::size_t i = 0; i < m; ++i) s += gains[i];
    return s;
}

void load_pid_gains(float (&gains)[kSlots]) { // C API
    write_slot(gains, 0U, 1.50F);
    write_slot(gains, 1U, 0.10F);
    write_slot(gains, 2U, 0.01F);
    std::cout << std::fixed << std::setprecision(2)
              << "kp=" << gains[0] << " sum3=" << sum3(gains) << "\n";
}

} // namespace pid_064_c

int main() {
    using namespace pid_064_c;
    float schedule[kSlots] = {0};
    load_pid_gains(schedule);
    return 0;
}
