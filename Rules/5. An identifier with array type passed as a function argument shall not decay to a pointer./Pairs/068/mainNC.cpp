// Context: Digital potentiometer tap settings

// ------ Non-Compliant Program (068_nc.cpp)
// Context: Set digipot taps and print head
// Rule: Array parameter decays to pointer (VIOLATED)
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace pot_068_nc {

constexpr std::size_t kCh = 4U;

static void set_mid(std::uint8_t *t, std::size_t n) { // NC helper
    if (n) t[0] = 128U;
}

static void dump(const std::uint8_t *t, std::size_t n) {
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << (i?" ":"") << static_cast<int>(t[i]);
    }
    std::cout << "\n";
}

void set_pot_values(std::uint8_t taps[]) { // NC API
    set_mid(taps, kCh);
    taps[1] = 200U;
    dump(taps, 3U);
}

} // namespace pot_068_nc

int main() {
    using namespace pot_068_nc;
    std::uint8_t digipot_taps[kCh] = {0,0,0,0};
    set_pot_values(digipot_taps);
    return 0;
}
