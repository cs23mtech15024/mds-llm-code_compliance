// Context: Timer capture register values

// ------ Compliant Program (039_c.cpp)
// Context: Read capture time of channel 0 and summarize
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <cstdint>
#include <iomanip>

namespace tcap_039_c {

static void dump_first_two(const std::uint32_t (&captures)[4]) {
    std::cout << "c0=" << captures[0] << ", c1=" << captures[1] << "\n";
}

std::uint32_t get_capture_time(std::uint32_t (&captures)[4]) { // C API
    dump_first_two(captures);
    return captures[0];
}

} // namespace tcap_039_c

int main() {
    using namespace tcap_039_c;
    std::uint32_t timer_captures[4] = {12345U, 23456U, 0U, 0U};
    std::cout << "capture0=" << get_capture_time(timer_captures) << "\n";
    return 0;
}
