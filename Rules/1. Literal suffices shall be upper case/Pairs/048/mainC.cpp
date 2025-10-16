// ------ Compliant (Seed 048)
// Context: Battery Management System — smooth State-of-Charge (SOC) updates,
// enforce sample cap, abort if charging exceeds a maximum duration.
// Fix: Converted 'f', 'u', 'l' to uppercase 'F', 'U', 'L'.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

struct BmsConfig {
    float alpha;
    unsigned cap;
    long maxSeconds;
};

class BmsController {
public:
    explicit BmsController(const BmsConfig& cfg)
        : cfg_(cfg), soc_(50.0F),
          elapsed_(0L)
    {}

    void process(const std::vector<float>& currents) {
        unsigned processed = 0U;
        for (float i : currents) {
            if (processed >= cfg_.cap) break;
            soc_ += cfg_.alpha * i;
            // Fixed: Using std::min/max for clamping (C++11 compatible)
            soc_ = std::min(std::max(soc_, 0.0F), 100.0F);

            elapsed_ += 1L; // each sample = 1 second
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
    BmsConfig cfg{0.05F, 100U, 3600L};
    std::vector<float> samples{0.8F, 1.2F, -0.6F};

    BmsController ctrl(cfg);
    ctrl.process(samples);
    return 0;
}