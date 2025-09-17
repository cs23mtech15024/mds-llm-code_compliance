// ------ Non-Compliant
// Seed: Non-compliant: bool ok = false, error = true;   // Compliant: bool ok = false; bool error = true;
// Context: Unit/health-check status flags in a DRDO instrumentation self-test routine.
// Violation: Declaring multiple variables in a single declaration (MISRA C++:2008 Rule 8-0-1).
// Sources: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
//          SEI CERT — DCL04-C (do not declare more than one variable per declaration).  [oai_citation:4‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <thread>

// Simulated sensor checks: deterministic and safe
bool check_temperature(int reading) {
    return (reading >= -40 && reading <= 85);
}
bool check_voltage(int reading) {
    return (reading >= 110 && reading <= 240);
}
bool check_communication(int attempts) {
    return (attempts > 0 && attempts < 5);
}

// Non-compliant function: two flags declared on one line (seed)
void self_test_NC(const std::string &logpath = "selftest_nc.log") {
    // seed:
    bool ok = false, error = true; // NON-COMPLIANT: multiple declarators in one declaration

    std::ofstream out(logpath, std::ios::app);
    if (!out) std::cerr << "[NC] Failed to open log\n";

    // deterministic "sensor" inputs
    std::vector<int> temps = {25, 26, 24, 27, 23};
    std::vector<int> volts = {220, 221, 219, 218, 222};
    std::vector<int> comm_attempts = {1, 1, 2, 1, 1};

    // run a sequence of checks
    for (size_t i = 0; i < temps.size(); ++i) {
        bool t_ok = check_temperature(temps[i]);
        bool v_ok = check_voltage(volts[i]);
        bool c_ok = check_communication(comm_attempts[i]);

        // aggregate status (intentional deterministic policy)
        ok = t_ok && v_ok && c_ok;
        error = !(ok); // seed uses 'error' initialized true, but updated here

        std::ostringstream ss;
        ss << std::boolalpha << "[NC] step=" << i << " t_ok=" << t_ok
           << " v_ok=" << v_ok << " c_ok=" << c_ok << " overall_ok=" << ok << '\n';

        std::cout << ss.str();
        if (out) out << ss.str();

        // deterministic small delay to mimic processing
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }

    // final summary
    std::ostringstream fin;
    fin << std::boolalpha << "[NC] Final status ok=" << ok << " error=" << error << '\n';
    std::cout << fin.str();
    if (out) { out << fin.str(); out.close(); }
}
int main() {
    self_test_NC();
    return 0;
}