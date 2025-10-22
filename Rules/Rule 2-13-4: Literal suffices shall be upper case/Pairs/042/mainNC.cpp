// ------ Non-Compliant (Seed 042)
// Context: Networking Backoff — compute exponential backoff schedule for UDP retries
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: lowercase 'f', 'u', and 'l' suffixes in literals.

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdint>

struct BackoffConfig {
    float factor;         // e.g., 1.25f (non-compliant)
    unsigned base_ms;     // e.g., 200u (non-compliant)
    long max_retries;     // e.g., 12l (non-compliant)
    unsigned port;        // e.g., 5353u (non-compliant)
};

class BackoffPlanner {
public:
    explicit BackoffPlanner(const BackoffConfig& cfg) : cfg_(cfg) {}

    std::vector<unsigned> schedule() const {
        std::vector<unsigned> seq;
        seq.reserve(static_cast<std::size_t>(cfg_.max_retries > 0l ? cfg_.max_retries : 0l)); // non-compliant
        float delay = static_cast<float>(cfg_.base_ms); // starting delay in ms
        for (long i = 0l; i < cfg_.max_retries; ++i) {  // non-compliant
            seq.push_back(static_cast<unsigned>(delay));
            delay *= cfg_.factor; // non-compliant
        }
        return seq;
    }

    void print() const {
        auto seq = schedule();
        std::cout << "UDP port " << cfg_.port << " backoff (ms):\n";
        for (std::size_t i = 0u; i < seq.size(); ++i) { // non-compliant
            std::cout << "  try " << i << " -> " << seq[i] << " ms\n";
        }
    }

private:
    BackoffConfig cfg_;
};

int main() {
    BackoffConfig cfg{
        1.25f,   // factor (non-compliant)
        200u,    // base delay in ms (non-compliant)
        12l,     // max retries (non-compliant)
        5353u    // UDP port (non-compliant)
    };

    BackoffPlanner planner(cfg);
    planner.print();

    // Sanity check to avoid UB or unused warnings
    volatile float probe = 0.0f; // non-compliant
    probe += cfg.factor;
    std::cout << std::fixed << std::setprecision(2) << "Probe: " << probe << "\n";
    return 0;
}