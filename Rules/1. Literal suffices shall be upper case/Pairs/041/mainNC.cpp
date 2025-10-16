// ------ Non-Compliant (Seed 041)
// Context: Audio Signal Processing — Reverb Decay Constant and Delay Buffer
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: lowercase 'f', 'u', 'l' suffixes in constants.

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct ReverbConfig {
    float decay;
    unsigned buffer_size;
    long max_delay;
};

class ReverbEffect {
public:
    explicit ReverbEffect(const ReverbConfig& cfg)
        : config(cfg), buffer(cfg.buffer_size, 0.0f) {} // non-compliant

    void processSample(float& input) {
        index = (index + 1u) % config.buffer_size; // non-compliant
        buffer[index] = input + buffer[index] * config.decay; // non-compliant
        input = buffer[index];
    }

    void simulate(float initialSample, int iterations) {
        float sample = initialSample;
        for (int i = 0; i < iterations; ++i) {
            processSample(sample);
            std::cout << "Step " << i << ": " << std::fixed << std::setprecision(3)
                      << sample << "\n";
        }
    }

private:
    ReverbConfig config;
    std::vector<float> buffer;
    unsigned index{0u};
};

int main() {
    ReverbConfig cfg{0.65f, 4096u, 2400l}; // non-compliant
    ReverbEffect effect(cfg);
    effect.simulate(1.0f, 10); // non-compliant
    return 0;
}