// Context: Data packet sequence number — Expanded program

// ------ Compliant Program (019_c.cpp)
// Context: Sequence number bump
// C: identifiers do not begin with '_'
#include <iostream>
#include <cstdint>

namespace seq_rule_019 {

static std::uint16_t inc(std::uint16_t v) {
    return static_cast<std::uint16_t>(v + 1U);
}

static void print(std::uint16_t sequence_num) {
    std::cout << "seq=" << sequence_num << std::endl;
}

} // namespace seq_rule_019

int main() {
    using namespace seq_rule_019;
    std::uint16_t sequence_num = 1024U;
    sequence_num = inc(sequence_num);
    print(sequence_num);
    return 0;
}
