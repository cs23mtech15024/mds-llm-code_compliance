// ------ Non-Compliant (Seed 016)
// Context: Audio signal processing — simulate waveform normalization and gain boost.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: Lowercase 'f' suffixes on float literals and 'l' on long integers.

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

class AudioProcessor {
    std::vector<float> samples_;
    float gain_;
    long maxAmplitude_;
public:
    AudioProcessor(std::vector<float> samples, float gain)
        : samples_(std::move(samples)), gain_(gain), maxAmplitude_(10000l) {} // non-compliant 'l'

    void normalize() {
        float maxSample = 0.0f;
        for (auto s : samples_) {
            if (std::fabs(s) > maxSample) maxSample = std::fabs(s);
        }
        if (maxSample > 0.0f) {
            for (auto &s : samples_) {
                s = (s / maxSample) * gain_;
            }
        }
    }

    void print() const {
        std::cout << "Samples (normalized, gain=" << gain_ << "):\n";
        for (auto s : samples_) {
            std::cout << std::fixed << std::setprecision(2) << s * 32767.0f / static_cast<float>(maxAmplitude_) << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::vector<float> data = { -0.8f, 0.2f, 0.7f, -0.3f, 0.9f }; // non-compliant suffixes
    AudioProcessor ap(data, 1.5f);
    ap.normalize();
    ap.print();
    return 0;
}