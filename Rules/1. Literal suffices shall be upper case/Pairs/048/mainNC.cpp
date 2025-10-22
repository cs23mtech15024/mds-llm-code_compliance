// ------ Non-Compliant (Seed 048)
// Context: Battery Management System — smooth State-of-Charge (SOC) updates,
// enforce sample cap, abort if charging exceeds a maximum duration.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: lowercase suffixes 'f', 'u', 'l' in numeric literals.

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

struct BmsConfig {
    float alpha;        // smoothing factor for SOC
    unsigned cap;       // maximum processed samples
    long maxSeconds;    // max allowed charge duration
};

class BmsController {
public:
    explicit BmsController(const BmsConfig& cfg)
        : cfg_(cfg), soc_(50.0f), // non-compliant
          elapsed_(0l)            // non-compliant
    {}

    void process(const std::vector<float>& currents) {
        unsigned processed = 0u; // non-compliant
        for (float i : currents) {
            if (processed >= cfg_.cap) break;
            // Simple SOC update: soc += alpha * current (clamped to 0..100)
            soc_ += cfg_.alpha * i; // non-compliant
            // Fixed: Using std::min/max instead of std::clamp for C++11 compatibility
            soc_ = std::min(std::max(soc_, 0.0f), 100.0f); // non-compliant

            elapsed_ += 1l; // pretend each sample is 1 second (non-compliant)
            if (elapsed_ > cfg_.maxSeconds) {
                std::cout << "Abort: charge window exceeded at t=" << elapsed_ << "s\n";
                return;
            }
            ++processed;
        }

        std::cout << std::fixed << std::setprecision(2)
                  << "Processed: " << processed
                  << " samples, SOC=" << soc_ << "%, t=" << elapsed_ << "s\n";
    }

private:
    BmsConfig cfg_;
    float soc_;
    long elapsed_;
};

int main() {
    // Non-compliant suffixes in configuration and test data:
    BmsConfig cfg{0.05f, 100u, 3600l};               // non-compliant
    std::vector<float> samples{0.8f, 1.2f, -0.6f};   // non-compliant

    BmsController ctrl(cfg);
    ctrl.process(samples);
    return 0;
}