// Context: LED brightness controller — Expanded program

// ------ Compliant Program (010_c.cpp)
// Context: 8-bit LED brightness print
// C: no leading underscores in identifiers
#include <iostream>
#include <cstdint>

namespace led_rule_010 {

static std::uint8_t clip8(int v) {
    if (v < 0) { return 0U; }
    if (v > 255) { return 255U; }
    return static_cast<std::uint8_t>(v);
}

static void print_brightness(std::uint8_t brightness) {
    std::cout << "led=" << static_cast<unsigned>(brightness) << std::endl;
}

} // namespace led_rule_010

int main() {
    using namespace led_rule_010;
    int raw = 300;
    std::uint8_t brightness = clip8(raw);
    print_brightness(brightness);
    return 0;
}
