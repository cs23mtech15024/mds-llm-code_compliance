// Seed 002 (NC) — Non-Compliant: const unsigned long base_timeout_ms = 1000ul;  // Compliant: const unsigned long base_timeout_ms = 1000UL
// Reference: MISRA C++:2008 Rule 2-13-4 — Literal suffixes shall be upper case. (e.g., Polyspace summary)
// Violation: Lower-case integer literal suffixes ('u', 'ul') are used throughout.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

namespace retry {

// Simple backoff policy: linear growth from base up to base * max_retries.
struct Policy {
    unsigned long base_ms;  // base timeout in ms
    unsigned retries;       // max retries
    unsigned flags;         // bit flags (e.g., active bit)

    bool is_active() const { return (flags & 0x1u) != 0u; } // NC: 'u'
};

// Build retry schedule according to policy.
std::vector<unsigned long> build_schedule(const Policy& p) {
    std::vector<unsigned long> out;
    if (!p.is_active() || p.base_ms == 0ul || p.retries == 0u) { // NC: 'ul','u'
        return out;
    }
    out.reserve(p.retries);
    for (unsigned i = 0u; i < p.retries; ++i) { // NC: 'u'
        out.push_back(p.base_ms * (1ul + static_cast<unsigned long>(i))); // NC: 'ul'
    }
    return out;
}

// Compute capped total with a soft cap constant.
unsigned long capped_total(const std::vector<unsigned long>& v) {
    const unsigned long soft_cap = 60000ul; // NC: 'ul'
    unsigned long sum = std::accumulate(v.begin(), v.end(), 0ul); // NC: 'ul'
    return std::min(sum, soft_cap);
}

} // namespace retry

int main() {
    retry::Policy p{1000ul, 5u, 0x1u}; // NC: 'ul','u'
    auto sched = retry::build_schedule(p);

    std::cout << "Active: " << std::boolalpha << p.is_active() << "\n";
    std::cout << "Schedule (ms):";
    for (auto v : sched) std::cout << " " << v;
    std::cout << "\nTotal (capped): " << retry::capped_total(sched) << " ms\n";

    // Demonstrate stable behavior even for empty schedule.
    retry::Policy off{500ul, 3u, 0x0u}; // NC
    auto empty = retry::build_schedule(off);
    std::cout << "Inactive schedule size: " << empty.size() << "\n";
    return 0;
}