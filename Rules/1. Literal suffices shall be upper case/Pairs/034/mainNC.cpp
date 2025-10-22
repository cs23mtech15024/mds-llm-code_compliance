// ------ Non-Compliant (Seed 034)
// Context: Compression — toy LZ77: compute match budget from window size, cap matches, and gate flags with mask.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations here: lowercase 'f', 'u', 'l' suffixes; lowercase hex digits in 0x00ffu.

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <iomanip>
#include <algorithm>

struct LZPolicy {
    float min_compress_ratio;  // below this, skip compression
    unsigned max_matches;      // cap per position
    unsigned flag_mask;        // bitmask for feature flags
    long window_size;          // sliding window size (bytes)
};

class LZEstimator {
public:
    explicit LZEstimator(const LZPolicy& p) : pol_(p) {}

    // Rough compression ratio estimator using a histogram-like heuristic.
    float estimateRatio(const std::vector<uint8_t>& data) const {
        if (data.empty()) return 1.0f; // non-compliant 'f'
        // Count repeated bytes in a small sample stride.
        std::size_t repeats = 0u; // non-compliant 'u'
        for (std::size_t i = 1u; i < data.size(); i += 3u) { // non-compliant 'u'
            repeats += (data[i] == data[i-1]) ? 1u : 0u;     // non-compliant 'u'
        }
        const float repeat_factor = static_cast<float>(repeats) / static_cast<float>(data.size());
        float ratio = 1.0f - 0.5f * repeat_factor; // non-compliant 'f'
        return std::max(0.1f, std::min(ratio, 1.0f)); // non-compliant 'f'
    }

    unsigned matchBudget(long lookahead) const {
        // Budget scales with window but is capped.
        long base = std::min(pol_.window_size, lookahead + 256l); // non-compliant 'l'
        unsigned budget = static_cast<unsigned>(base / 32l);      // non-compliant 'l'
        return std::min(budget, pol_.max_matches);
    }

    bool featureEnabled(uint16_t flags) const {
        return (static_cast<unsigned>(flags) & pol_.flag_mask) == pol_.flag_mask;
    }

private:
    LZPolicy pol_;
};

int main() {
    LZPolicy pol{};
    pol.min_compress_ratio = 0.85f;   // non-compliant
    pol.max_matches        = 64u;     // non-compliant
    pol.flag_mask          = 0x00ffu; // non-compliant (hex + 'u')
    pol.window_size        = 1024l;   // non-compliant

    LZEstimator est(pol);

    std::vector<uint8_t> data = {1u,1u,2u,3u,3u,3u,4u,5u,5u,6u,7u,7u}; // non-compliant 'u'
    float ratio = est.estimateRatio(data);
    std::cout << std::fixed << std::setprecision(2)
              << "estRatio=" << ratio << " min=" << pol.min_compress_ratio << "\n";

    if (ratio <= pol.min_compress_ratio) {
        std::cout << "skip compression\n";
        return 0;
    }

    unsigned budget = est.matchBudget(300l); // non-compliant 'l'
    std::cout << "matchBudget=" << budget << "\n";

    uint16_t flags = 0x00ffu; // non-compliant
    std::cout << std::boolalpha << "features=" << est.featureEnabled(flags) << "\n";
    return 0;
}