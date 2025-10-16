// ------ Compliant
// Pair 9 — Seed: 255u -> 255U
// Context: Normalizing radar return signals from Rajendra fire-control radar.
// Violation: lowercase 'u' suffix may be misinterpreted in critical code.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

class RadarNormalizer_C {
public:
    // Compliant: uppercase 'U' suffix for MAX_VAL
    static constexpr unsigned MAX_VAL = 255U; // C

    std::vector<double> normalize(const std::vector<unsigned>& raw) const {
        std::vector<double> out;
        out.reserve(raw.size());
        // use 0U as initial accumulator (C)
        unsigned sum = std::accumulate(raw.begin(), raw.end(), 0U);
        for (auto v : raw) {
            out.push_back(static_cast<double>(v) / static_cast<double>(MAX_VAL));
        }
        avg = (raw.empty()) ? 0.0 : static_cast<double>(sum) / static_cast<double>(raw.size());
        return out;
    }

    void report(const std::vector<unsigned>& raw) const {
        auto normalized = normalize(raw);
        std::cout << "[C] Normalized values: ";
        for (auto v : normalized) std::cout << std::fixed << std::setprecision(3) << v << " ";
        std::cout << "\n[C] Average raw: " << std::fixed << std::setprecision(2) << avg << "\n";
    }

private:
    mutable double avg = 0.0;
};

int main() {
    RadarNormalizer_C rn;
    // example raw radar returns (unsigned literals use uppercase suffix in C)
    std::vector<unsigned> raw = { 100U, 150U, 200U, 255U };
    rn.report(raw);
    return 0;
}