// ------ Non-Compliant (Seed 046)
// Context: Drone Telemetry Smoothing — compute EMA on altitude samples with cap on packet count
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'f', 'u', 'l' suffixes in literals.

#include <iostream>
#include <vector>
#include <iomanip>

struct TelemetryConfig {
    float alpha;         // smoothing factor, e.g., 0.75f
    unsigned maxPackets; // cap, e.g., 64u
    long baseTs;         // base timestamp, e.g., 1000l
};

class EmaFilter {
public:
    explicit EmaFilter(float a) : alpha_(a), initialized_(false), ema_(0.0f) {} // non-compliant
    float update(float sample) {
        if (!initialized_) { ema_ = sample; initialized_ = true; }
        else { ema_ = alpha_ * sample + (1.0f - alpha_) * ema_; } // non-compliant (1.0f)
        return ema_;
    }
private:
    float alpha_;
    bool initialized_;
    float ema_;
};

int main() {
    TelemetryConfig cfg{0.75f, 64u, 1000l}; // non-compliant
    std::vector<float> samples{100.0f, 101.5f, 99.8f, 102.2f, 101.0f}; // non-compliant
    if (samples.size() > cfg.maxPackets) samples.resize(cfg.maxPackets);

    EmaFilter filter(cfg.alpha);
    long ts = cfg.baseTs; // non-compliant
    for (unsigned i = 0u; i < samples.size(); ++i) { // non-compliant
        float s = filter.update(samples[i]);
        std::cout << std::fixed << std::setprecision(2)
                  << "t=" << ts << " alt=" << s << "\n";
        ts += 20l; // non-compliant
    }
    return 0;
}