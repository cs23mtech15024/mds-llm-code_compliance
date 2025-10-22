// Context: This module evaluates whether storage usage exceeds warning or critical thresholds
//          using floating-point literals with uppercase suffixes (compliant with MISRA C++ 2-13-4).
// Seed: Non-compliant: const float warn_limit = 70.0f;  // Compliant: const float warn_limit = 70.0F;
// Rule: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.
// Fix: All lowercase ‘f’ suffixes have been replaced by uppercase ‘F’.

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
        float avg = std::accumulate(usage_samples.begin(), usage_samples.end(), 0.0F) / usage_samples.size(); // C: '0.0F'
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
    StorageMonitor monitor{70.0F, 90.0F}; // C: uppercase 'F'
    monitor.add_sample(65.5F);
    monitor.add_sample(72.3F);
    monitor.add_sample(91.8F);
    monitor.add_sample(83.2F);
    monitor.report();
    return 0;
}