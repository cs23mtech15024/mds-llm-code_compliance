// Context: Optical encoder quadrature states

// ------ Non-Compliant Program (055_nc.cpp)
// Context: Optical encoder quadrature states (A,B transitions)
// Rule: Array decays to pointer (VIOLATED)
// NC: decode_quadrature accepts pointer, prints first state
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace quad_055_nc {

static int to_int(std::uint8_t v) { return static_cast<int>(v); }

void decode_quadrature(std::uint8_t states[]) { // NC API
    std::cout << "state=" << to_int(states[0]) << "\n";
}

} // namespace quad_055_nc

int main() {
    using namespace quad_055_nc;
    std::uint8_t quad_states[4] = {0, 1, 3, 2};
    decode_quadrature(quad_states);
    return 0;
}
