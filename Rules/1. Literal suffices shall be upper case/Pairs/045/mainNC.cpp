// ------ Non-Compliant (Seed 045)
// Context: Battery Charge Simulation — Incremental voltage accumulation model
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: lowercase suffixes 'f', 'u', and 'l' appear in floating-point, unsigned, and long literals.

#include <iostream>
#include <vector>
#include <iomanip>

struct BatteryConfig {
    float voltage_step;   // e.g., 0.5f
    unsigned steps;       // e.g., 10u
    long base_charge;     // e.g., 100l
};

class BatterySimulator {
public:
    explicit BatterySimulator(const BatteryConfig& cfg)
        : cfg_(cfg), voltages(cfg.steps, 0.0f) {} // non-compliant

    void simulate() {
        for (unsigned i = 0u; i < cfg_.steps; ++i) { // non-compliant
            voltages[i] = cfg_.base_charge + static_cast<float>(i) * cfg_.voltage_step; // non-compliant
        }
    }

    void printResults() const {
        for (unsigned i = 0u; i < voltages.size(); ++i) { // non-compliant
            std::cout << "Step " << i << ": " 
                      << std::fixed << std::setprecision(2) << voltages[i] 
                      << " V\n";
        }
    }

private:
    BatteryConfig cfg_;
    std::vector<float> voltages;
};

int main() {
    BatteryConfig cfg{0.5f, 10u, 100l}; // non-compliant
    BatterySimulator sim(cfg);
    sim.simulate();
    sim.printResults();
    return 0;
}