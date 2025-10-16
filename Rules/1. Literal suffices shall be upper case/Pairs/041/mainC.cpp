// ------ Compliant (Seed 041)
// Context: Audio Signal Processing — Reverb Decay Constant and Delay Buffer
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fix: Converted all suffixes to uppercase 'F', 'U', and 'L'.

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
        : config(cfg), buffer(cfg.buffer_size, 0.0F) {}

    void processSample(float& input) {
        index = (index + 1U) % config.buffer_size;
        buffer[index] = input + buffer[index] * config.decay;
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
    unsigned index{0U};
};

int main() {
    ReverbConfig cfg{0.65F, 4096U, 2400L};
    ReverbEffect effect(cfg);
    effect.simulate(1.0F, 10);
    return 0;
}