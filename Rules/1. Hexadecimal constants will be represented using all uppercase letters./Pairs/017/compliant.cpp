// ------ Compliant
// Pair 17 — Seed: 1u -> 1U
// Context: Filter threshold count for hit detection in NETRA system.
// Violation: lowercase 'u' suffix may be missed in audit.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

class HitFilter_C {
public:
    HitFilter_C(unsigned threshold = 1U) // C: uppercase 'U' seed used in default
      : threshold_(threshold) {}

    // Process a frame of detector confidences (0..255), count hits above threshold
    unsigned countHits(const std::vector<unsigned>& confidences) const {
        unsigned hits = 0U; // C
        for (auto c : confidences) {
            if (c >= threshold_) ++hits;
        }
        return hits;
    }

    void demo() {
        // generate some synthetic confidences
        std::mt19937 rng(123);
        std::uniform_int_distribution<int> dist(0, 255);
        std::vector<unsigned> frame;
        frame.reserve(16U);
        for (unsigned i = 0U; i < 16U; ++i) frame.push_back(static_cast<unsigned>(dist(rng)));

        unsigned hits = countHits(frame);
        std::cout << "[C] Threshold = " << threshold_ << ", Hits = " << hits << "\n";
    }

private:
    unsigned threshold_;
};

int main() {
    HitFilter_C filter; // uses default threshold with uppercase suffix in its definition
    filter.demo();
    return 0;
}