// ------ Compliant (Seed 045)
// Context: Battery Charge Simulation — Incremental voltage accumulation model
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fix: Converted all literal suffixes to uppercase 'F', 'U', and 'L'.

#include <iostream>
#include <vector>
#include <iomanip>

struct BatteryConfig {
    float voltage_step;   
    unsigned steps;       
    long base_charge;     
};

class BatterySimulator {
public:
    explicit BatterySimulator(const BatteryConfig& cfg)
        : cfg_(cfg), voltages(cfg.steps, 0.0F) {}

    void simulate() {
        for (unsigned i = 0U; i < cfg_.steps; ++i) {
            voltages[i] = cfg_.base_charge + static_cast<float>(i) * cfg_.voltage_step;
        }
    }

    void printResults() const {
        for (unsigned i = 0U; i < voltages.size(); ++i) {
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
    BatteryConfig cfg{0.5F, 10U, 100L};
    BatterySimulator sim(cfg);
    sim.simulate();
    sim.printResults();
    return 0;
}