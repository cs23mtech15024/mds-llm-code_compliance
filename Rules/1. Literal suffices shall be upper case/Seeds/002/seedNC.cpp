// Seed 002 (NC) — Non-Compliant: const unsigned long base_timeout_ms = 1000ul;  // Compliant: const unsigned long base_timeout_ms = 1000UL
// Reference: MISRA C++:2008 Rule 2-13-4 — Literal suffixes shall be upper case. (e.g., Polyspace summary)
// Violation: Uses lower-case integer suffixes 'u'/'ul' (e.g., 1000ul, 3u), which is non-compliant.

#include <iostream>
#include <vector>
#include <numeric>

int main() {
    const unsigned long base_timeout_ms = 1000ul; // NC: 'ul'
    const unsigned max_retries = 3u;              // NC: 'u'
    const unsigned active_mask = 0x1u;            // NC: 'u'

    std::vector<unsigned long> schedule;
    for (unsigned i = 0u; i < max_retries; ++i) { // NC: 'u'
        schedule.push_back(base_timeout_ms * (i + 1u)); // NC: 'u'
    }

    std::cout << "Mask: " << active_mask << "\n";
    std::cout << "Schedule (ms):";
    for (auto v : schedule) std::cout << " " << v;
    std::cout << "\nTotal: "
              << std::accumulate(schedule.begin(), schedule.end(), 0ul) // NC: 'ul'
              << " ms\n";
    return 0;
}