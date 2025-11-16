// Context: Digital potentiometer tap settings

// ------ Compliant Program (068_c.cpp)
// Context: Set digipot taps and print head
// Rule: Preserve array via reference (COMPLIANT)
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace pot_068_c {

constexpr std::size_t kCh = 4U;

template <std::size_t N>
static void set_mid(std::uint8_t (&t)[N]) {
    static_assert(N == 4U, "expect 4 taps");
    t[0] = 128U;
}

template <std::size_t N>
static void dump(const std::uint8_t (&t)[N], std::size_t m) {
    for (std::size_t i = 0; i < m && i < N; ++i) {
        std::cout << (i?" ":"") << static_cast<int>(t[i]);
    }
    std::cout << "\n";
}

void set_pot_values(std::uint8_t (&taps)[kCh]) { // C API
    set_mid(taps);
    taps[1] = 200U;
    dump(taps, 3U);
}

} // namespace pot_068_c

int main() {
    using namespace pot_068_c;
    std::uint8_t digipot_taps[kCh] = {0,0,0,0};
    set_pot_values(digipot_taps);
    return 0;
}
