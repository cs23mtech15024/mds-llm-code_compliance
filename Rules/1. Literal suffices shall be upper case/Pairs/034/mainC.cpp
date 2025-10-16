// ------ Compliant (Seed 034)
// Context: Compression — toy LZ77: compute match budget from window size, cap matches, and gate flags with mask.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all literal suffixes changed to uppercase ('F','U','L'), and hex digits to uppercase (0X00FFU).

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

    float estimateRatio(const std::vector<uint8_t>& data) const {
        if (data.empty()) return 1.0F; // compliant
        std::size_t repeats = 0U; // compliant
        for (std::size_t i = 1U; i < data.size(); i += 3U) { // compliant
            repeats += (data[i] == data[i-1]) ? 1U : 0U;     // compliant
        }
        const float repeat_factor = static_cast<float>(repeats) / static_cast<float>(data.size());
        float ratio = 1.0F - 0.5F * repeat_factor; // compliant
        return std::max(0.1F, std::min(ratio, 1.0F)); // compliant
    }

    unsigned matchBudget(long lookahead) const {
        long base = std::min(pol_.window_size, lookahead + 256L); // compliant
        unsigned budget = static_cast<unsigned>(base / 32L);      // compliant
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
    pol.min_compress_ratio = 0.85F;    // compliant
    pol.max_matches        = 64U;      // compliant
    pol.flag_mask          = 0X00FFU;  // compliant (hex + 'U')
    pol.window_size        = 1024L;    // compliant

    LZEstimator est(pol);

    std::vector<uint8_t> data = {1U,1U,2U,3U,3U,3U,4U,5U,5U,6U,7U,7U}; // compliant
    float ratio = est.estimateRatio(data);
    std::cout << std::fixed << std::setprecision(2)
              << "estRatio=" << ratio << " min=" << pol.min_compress_ratio << "\n";

    if (ratio <= pol.min_compress_ratio) {
        std::cout << "skip compression\n";
        return 0;
    }

    unsigned budget = est.matchBudget(300L); // compliant
    std::cout << "matchBudget=" << budget << "\n";

    uint16_t flags = 0X00FFU; // compliant
    std::cout << std::boolalpha << "features=" << est.featureEnabled(flags) << "\n";
    return 0;
}