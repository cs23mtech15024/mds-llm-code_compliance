// ------ Non-Compliant
// Seed: Non-compliant: class Sensor { int status, error; };   // Compliant: class Sensor { int status; int error; };
// Context: Class member declarations for a DRDO sensor object; deterministic diagnostic routine.
// Violation: Declaring multiple class members in a single member-declarator-list (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
// Note: SEI CERT also recommends one declaration per variable for clarity.  [oai_citation:4‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <chrono>
#include <thread>
#include <sstream>

// Non-compliant: class with two members declared in one member-declarator-list (seed)
class Sensor {
public:
    Sensor(int id_, double gain_) : id(id_), gain(gain_), readings() {}
    void addReading(int r) { readings.push_back(r); }
    void diagnose(std::ofstream &out) const {
        // compute simple diagnostics
        double avg = 0.0;
        if (!readings.empty()) {
            int sum = 0;
            for (int v : readings) sum += v;
            avg = static_cast<double>(sum) / readings.size();
        }
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(2);
        ss << "[NC] sensor=" << id << " gain=" << gain << " status=" << status
           << " error=" << error << " avg=" << avg << " count=" << readings.size() << '\n';
        std::cout << ss.str();
        if (out) out << ss.str();
    }

    // seed:
    int status, error; // NON-COMPLIANT: two members declared in one member-declarator-list (seed)

private:
    int id;
    double gain;
    std::vector<int> readings;
};

// Non-compliant usage function (keeps same behavior as compliant version)
void run_diagnostics_NC() {
    std::ofstream out("sensor_nc.log", std::ios::app);
    if (!out) std::cerr << "[NC] Failed to open log\n";

    Sensor s(42, 1.25);
    // deterministic readings
    for (int v : {10, 12, 11, 13, 12, 14}) s.addReading(v);

    // set members deterministically
    s.status = 0; // nominal
    s.error = 0;  // no error

    s.diagnose(out);

    // deterministic small pause
    std::this_thread::sleep_for(std::chrono::milliseconds(8));
}

int main() {
    run_diagnostics_NC();
    return 0;
}