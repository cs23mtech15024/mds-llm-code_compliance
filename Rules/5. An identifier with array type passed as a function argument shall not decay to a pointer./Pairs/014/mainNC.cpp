// Context: Stepper motor step sequence

// ------ Non-Compliant Program (014_nc.cpp)
// Context: Emit first step pattern for a 4-phase motor
// Rule: Array shall not decay — VIOLATED (sequence[] decays)
#include <iostream>
#include <cstdint>
#include <iomanip>
#include <cstddef>

namespace step_014_nc {

static void dump_seq(const std::uint8_t *seq, std::size_t n) { // NC helper
    std::cout << "seq:";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << ' ' << std::hex << std::uppercase << static_cast<int>(seq[i]);
    }
    std::cout << std::dec << "\n";
}

void execute_steps(std::uint8_t sequence[]) { // NC API
    dump_seq(sequence, 4U);
    std::cout << "step0=0x" << std::hex << std::uppercase
              << static_cast<int>(sequence[0]) << std::dec << "\n";
}

} // namespace step_014_nc

int main() {
    using namespace step_014_nc;
    std::uint8_t motor_steps[4] = {0x01, 0x02, 0x04, 0x08};
    execute_steps(motor_steps);
    return 0;
}
