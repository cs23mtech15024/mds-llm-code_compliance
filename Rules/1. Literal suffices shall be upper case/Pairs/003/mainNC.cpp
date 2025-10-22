// Context: This module evaluates whether storage usage exceeds warning or critical thresholds
//          using floating-point literals with lowercase suffixes (violates MISRA C++ 2-13-4).
// Seed: Non-compliant: const float warn_limit = 70.0f;  // Compliant: const float warn_limit = 70.0F;
// Rule: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.
// Violation: ‘f’ suffix in floating literals must be uppercase ‘F’.

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>

struct StorageMonitor {
    float warn_limit;
    float critical_limit;
    std::vector<float> usage_samples;

    void add_sample(float sample) {
        usage_samples.push_back(sample);
    }

    void report() const {
        float avg = std::accumulate(usage_samples.begin(), usage_samples.end(), 0.0f) / usage_samples.size(); // NC: '0.0f'
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Average usage: " << avg << "%\n";
        if (avg > critical_limit)
            std::cout << "CRITICAL: storage usage exceeds " << critical_limit << "%\n";
        else if (avg > warn_limit)
            std::cout << "Warning: usage exceeds " << warn_limit << "%\n";
        else
            std::cout << "OK\n";
    }
};

int main() {
    StorageMonitor monitor{70.0f, 90.0f}; // NC: lowercase 'f'
    monitor.add_sample(65.5f);
    monitor.add_sample(72.3f);
    monitor.add_sample(91.8f);
    monitor.add_sample(83.2f);
    monitor.report();
    return 0;
}