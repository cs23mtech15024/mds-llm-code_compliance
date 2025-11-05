// Context: Audio sample rate converter — Expanded program

// ------ Non-Compliant Program (014_nc.cpp)
// Context: Duration to sample count calculator
// MISRA: Identifiers must not begin with '_'
// NC: variable and helpers begin with '_'
#include <iostream>
#include <vector>

namespace _aud_rule_014 {

static int _clipRate(int r) {
    if (r < 8000) { return 8000; }
    if (r > 192000) { return 192000; }
    return r;
}

static long _samplesFor(int _sample_rate, float _duration) {
    return static_cast<long>(static_cast<double>(_clipRate(_sample_rate)) * _duration);
}

static void _report(const std::vector<float> &_durs, int _sample_rate) {
    for (float d : _durs) {
        std::cout << "samples=" << _samplesFor(_sample_rate, d) << std::endl;
    }
}

} // namespace _aud_rule_014

int main() {
    using namespace _aud_rule_014;
    std::vector<float> dur = {0.5F, 1.0F, 2.0F};
    _report(dur, 44100);
    return 0;
}
