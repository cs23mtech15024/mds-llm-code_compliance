// ------ Compliant (Seed 042)
// Context: Networking Backoff — compute exponential backoff schedule for UDP retries
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fix: Converted 'f'→'F', 'u'→'U', 'l'→'L' in all literals.

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdint>

struct BackoffConfig {
    float factor;         // e.g., 1.25F (compliant)
    unsigned base_ms;     // e.g., 200U (compliant)
    long max_retries;     // e.g., 12L (compliant)
    unsigned port;        // e.g., 5353U (compliant)
};

class BackoffPlanner {
public:
    explicit BackoffPlanner(const BackoffConfig& cfg) : cfg_(cfg) {}

    std::vector<unsigned> schedule() const {
        std::vector<unsigned> seq;
        seq.reserve(static_cast<std::size_t>(cfg_.max_retries > 0L ? cfg_.max_retries : 0L));
        float delay = static_cast<float>(cfg_.base_ms); // starting delay in ms
        for (long i = 0L; i < cfg_.max_retries; ++i) {
            seq.push_back(static_cast<unsigned>(delay));
            delay *= cfg_.factor;
        }
        return seq;
    }

    void print() const {
        auto seq = schedule();
        std::cout << "UDP port " << cfg_.port << " backoff (ms):\n";
        for (std::size_t i = 0U; i < seq.size(); ++i) {
            std::cout << "  try " << i << " -> " << seq[i] << " ms\n";
        }
    }

private:
    BackoffConfig cfg_;
};

int main() {
    BackoffConfig cfg{
        1.25F,   // factor (compliant)
        200U,    // base delay in ms (compliant)
        12L,     // max retries (compliant)
        5353U    // UDP port (compliant)
    };

    BackoffPlanner planner(cfg);
    planner.print();

    // Sanity check to avoid UB or unused warnings
    volatile float probe = 0.0F; // compliant
    probe += cfg.factor;
    std::cout << std::fixed << std::setprecision(2) << "Probe: " << probe << "\n";
    return 0;
}