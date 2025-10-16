// Seed 002 (C) — Non-Compliant: const unsigned long base_timeout_ms = 1000ul;  // Compliant: const unsigned long base_timeout_ms = 1000UL
// Reference: MISRA C++:2008 Rule 2-13-4 — Literal suffixes shall be upper case. (e.g., Polyspace summary)
// Fix: Uses upper-case integer suffixes 'U'/'UL' (e.g., 1000UL, 3U) to comply.

#include <iostream>
#include <vector>
#include <numeric>

int main() {
    const unsigned long base_timeout_ms = 1000UL; // C: 'UL'
    const unsigned max_retries = 3U;              // C: 'U'
    const unsigned active_mask = 0x1U;            // C: 'U'

    std::vector<unsigned long> schedule;
    for (unsigned i = 0U; i < max_retries; ++i) { // C: 'U'
        schedule.push_back(base_timeout_ms * (i + 1U)); // C: 'U'
    }

    std::cout << "Mask: " << active_mask << "\n";
    std::cout << "Schedule (ms):";
    for (auto v : schedule) std::cout << " " << v;
    std::cout << "\nTotal: "
              << std::accumulate(schedule.begin(), schedule.end(), 0UL) // C: 'UL'
              << " ms\n";
    return 0;
}