// Context: Data packet sequence number — Expanded program

// ------ Non-Compliant Program (019_nc.cpp)
// Context: Sequence number bump
// MISRA: Identifiers must not begin with '_'
// NC: variable and helpers begin with '_'
#include <iostream>
#include <cstdint>

namespace _seq_rule_019 {

static std::uint16_t _inc(std::uint16_t v) {
    return static_cast<std::uint16_t>(v + 1U);
}

static void _print(std::uint16_t _sequence_num) {
    std::cout << "seq=" << _sequence_num << std::endl;
}

} // namespace _seq_rule_019

int main() {
    using namespace _seq_rule_019;
    std::uint16_t _sequence_num = 1024U;
    _sequence_num = _inc(_sequence_num);
    _print(_sequence_num);
    return 0;
}
