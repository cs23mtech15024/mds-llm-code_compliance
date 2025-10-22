// ------ Compliant (Seed 016)
// Context: Audio signal processing — simulate waveform normalization and gain boost.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fix: All floating and long suffixes updated to uppercase (F, L).

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
        : samples_(std::move(samples)), gain_(gain), maxAmplitude_(10000L) {} // compliant 'L'

    void normalize() {
        float maxSample = 0.0F;
        for (auto s : samples_) {
            if (std::fabs(s) > maxSample) maxSample = std::fabs(s);
        }
        if (maxSample > 0.0F) {
            for (auto &s : samples_) {
                s = (s / maxSample) * gain_;
            }
        }
    }

    void print() const {
        std::cout << "Samples (normalized, gain=" << gain_ << "):\n";
        for (auto s : samples_) {
            std::cout << std::fixed << std::setprecision(2) << s * 32767.0F / static_cast<float>(maxAmplitude_) << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::vector<float> data = { -0.8F, 0.2F, 0.7F, -0.3F, 0.9F }; // compliant suffixes
    AudioProcessor ap(data, 1.5F);
    ap.normalize();
    ap.print();
    return 0;
}