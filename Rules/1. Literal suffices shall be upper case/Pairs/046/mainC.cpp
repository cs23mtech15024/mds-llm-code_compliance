// ------ Compliant (Seed 046)
// Context: Drone Telemetry Smoothing — compute EMA on altitude samples with cap on packet count
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fix: All literal suffixes changed to uppercase 'F', 'U', 'L'.

#include <iostream>
#include <vector>
#include <iomanip>

struct TelemetryConfig {
    float alpha;
    unsigned maxPackets;
    long baseTs;
};

class EmaFilter {
public:
    explicit EmaFilter(float a) : alpha_(a), initialized_(false), ema_(0.0F) {}
    float update(float sample) {
        if (!initialized_) { ema_ = sample; initialized_ = true; }
        else { ema_ = alpha_ * sample + (1.0F - alpha_) * ema_; }
        return ema_;
    }
private:
    float alpha_;
    bool initialized_;
    float ema_;
};

int main() {
    TelemetryConfig cfg{0.75F, 64U, 1000L};
    std::vector<float> samples{100.0F, 101.5F, 99.8F, 102.2F, 101.0F};
    if (samples.size() > cfg.maxPackets) samples.resize(cfg.maxPackets);

    EmaFilter filter(cfg.alpha);
    long ts = cfg.baseTs;
    for (unsigned i = 0U; i < samples.size(); ++i) {
        float s = filter.update(samples[i]);
        std::cout << std::fixed << std::setprecision(2)
                  << "t=" << ts << " alt=" << s << "\n";
        ts += 20L;
    }
    return 0;
}