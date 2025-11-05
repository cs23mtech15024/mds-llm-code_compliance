// Context: LED brightness controller — Expanded program

// ------ Non-Compliant Program (010_nc.cpp)
// Context: 8-bit LED brightness print
// NC: variable and functions begin with '_'
#include <iostream>
#include <cstdint>

namespace _led_rule_010 {

static std::uint8_t _clip8(int v) {
    if (v < 0) { return 0U; }
    if (v > 255) { return 255U; }
    return static_cast<std::uint8_t>(v);
}

static void _print_brightness(std::uint8_t _brightness) {
    std::cout << "led=" << static_cast<unsigned>(_brightness) << std::endl;
}

} // namespace _led_rule_010

int main() {
    using namespace _led_rule_010;
    int raw = 300;
    std::uint8_t _brightness = _clip8(raw);
    _print_brightness(_brightness);
    return 0;
}
