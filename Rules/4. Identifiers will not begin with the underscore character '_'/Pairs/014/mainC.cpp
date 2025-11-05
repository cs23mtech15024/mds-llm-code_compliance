// Context: Audio sample rate converter — Expanded program

// ------ Compliant Program (014_c.cpp)
// Context: Duration to sample count calculator
// C: identifiers have no leading '_'
#include <iostream>
#include <vector>

namespace aud_rule_014 {

static int clipRate(int r) {
    if (r < 8000) { return 8000; }
    if (r > 192000) { return 192000; }
    return r;
}

static long samplesFor(int sample_rate, float duration) {
    return static_cast<long>(static_cast<double>(clipRate(sample_rate)) * duration);
}

static void report(const std::vector<float> &durs, int sample_rate) {
    for (float d : durs) {
        std::cout << "samples=" << samplesFor(sample_rate, d) << std::endl;
    }
}

} // namespace aud_rule_014

int main() {
    using namespace aud_rule_014;
    std::vector<float> dur = {0.5F, 1.0F, 2.0F};
    report(dur, 44100);
    return 0;
}
