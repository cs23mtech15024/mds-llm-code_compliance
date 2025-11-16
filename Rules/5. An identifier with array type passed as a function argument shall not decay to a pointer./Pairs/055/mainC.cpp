// Context: Optical encoder quadrature states

// ------ Compliant Program (055_c.cpp)
// Context: Optical encoder quadrature states (A,B transitions)
// Rule: Preserve array extent (COMPLIANT)
// C: decode_quadrature receives array reference
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace quad_055_c {

static int to_int(std::uint8_t v) { return static_cast<int>(v); }

void decode_quadrature(std::uint8_t (&states)[4]) { // C API exact bound
    std::cout << "state=" << to_int(states[0]) << "\n";
}

} // namespace quad_055_c

int main() {
    using namespace quad_055_c;
    std::uint8_t quad_states[4] = {0, 1, 3, 2};
    decode_quadrature(quad_states);
    return 0;
}
