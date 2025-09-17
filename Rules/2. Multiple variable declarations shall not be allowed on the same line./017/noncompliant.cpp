// ------ Non-Compliant
// Seed: Non-compliant: std::unique_ptr<int> r1, r2;   // Compliant: std::unique_ptr<int> r1; std::unique_ptr<int> r2;
// Context: Resource holders using std::unique_ptr in a DRDO platform helper.
// Violation: Declaring multiple variables in a single declaration (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
//         SEI CERT — DCL04-C: Do not declare more than one variable per declaration.  [oai_citation:4‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <thread>

// Simulated resource user: owns integer resources via unique_ptr
void resource_user_NC(const std::string &logpath = "res_nc.log") {
    // seed:
    std::unique_ptr<int> r1, r2; // NON-COMPLIANT: multiple declarators in one declaration

    // allocate deterministic resources before use (avoid UB)
    r1 = std::make_unique<int>(10);
    r2 = std::make_unique<int>(20);

    // process: simple deterministic arithmetic using both resources
    int sum = (*r1) + (*r2);
    int diff = (*r2) - (*r1);
    int prod = (*r1) * (*r2);

    std::ostringstream ss;
    ss << std::fixed << std::setprecision(0);
    ss << "[NC] r1=" << *r1 << " r2=" << *r2 << " sum=" << sum << " diff=" << diff << " prod=" << prod << '\n';

    std::cout << ss.str();
    std::ofstream out(logpath, std::ios::app);
    if (out) { out << ss.str(); out.close(); }
    else { std::cerr << "[NC] Failed to open log\n"; }

    // simulate deterministic cleanup/hand-off (unique_ptr auto-manages)
    std::this_thread::sleep_for(std::chrono::milliseconds(8));
}

int main() {
    resource_user_NC();
    return 0;
}