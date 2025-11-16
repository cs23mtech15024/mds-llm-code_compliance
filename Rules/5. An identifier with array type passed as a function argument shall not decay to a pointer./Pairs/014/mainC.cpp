// Context: Stepper motor step sequence

// ------ Compliant Program (014_c.cpp)
// Context: Emit first step pattern for a 4-phase motor
// Rule: COMPLIANT (array by reference preserves extent)
#include <iostream>
#include <cstdint>
#include <iomanip>
#include <cstddef>

namespace step_014_c {

static void dump_seq(const std::uint8_t (&seq)[4]) { // C helper
    std::cout << "seq:";
    for (std::size_t i = 0; i < 4U; ++i) {
        std::cout << ' ' << std::hex << std::uppercase << static_cast<int>(seq[i]);
    }
    std::cout << std::dec << "\n";
}

void execute_steps(std::uint8_t (&sequence)[4]) { // C API
    dump_seq(sequence);
    std::cout << "step0=0x" << std::hex << std::uppercase
              << static_cast<int>(sequence[0]) << std::dec << "\n";
}

} // namespace step_014_c

int main() {
    using namespace step_014_c;
    std::uint8_t motor_steps[4] = {0x01, 0x02, 0x04, 0x08};
    execute_steps(motor_steps);
    return 0;
}
