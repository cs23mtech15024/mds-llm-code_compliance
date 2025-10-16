// ------ Compliant
// Seed: Non-compliant: char *src = 0, c = 0;   // Compliant: char *src = 0; char c = 0;
// Context: String/byte buffer handling in a DRDO text-processing helper.
// Violation: Mixed pointer and non-pointer variables declared on the same line (MISRA C++:2008 Rule 8-0-1).
// Sources: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:5‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
//          SEI CERT — DCL04-C (do not declare more than one variable per declaration).  [oai_citation:6‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <thread>

// Compliant example: pointer and plain char declared on separate lines
void buffer_count_C(const std::string &logpath = "count_c.log") {
    char *src = 0;
    char c = 0;
    // (compliant: each init-declarator-list has a single declarator)

    // deterministic static buffer (safe, local storage)
    static char buffer[] = "DRDO: telemetry payload sample 0123456789";
    // assign pointer before use (avoid UB)
    src = buffer;
    c = '0'; // we will count occurrences of character '0'

    size_t count = 0;
    for (size_t i = 0; src[i] != '\0'; ++i) {
        if (src[i] == c) ++count;
    }

    // write deterministic log entry
    std::ostringstream ss;
    ss << "[C] looking for '" << c << "' found=" << count << " len=" << std::strlen(buffer) << '\n';
    std::cout << ss.str();

    std::ofstream out(logpath, std::ios::app);
    if (out) { out << ss.str(); out.close(); }
    else { std::cerr << "[C] Failed to open log\n"; }

    // mimic safe processing latency
    std::this_thread::sleep_for(std::chrono::milliseconds(8));
}

int main() {
    buffer_count_C();
    return 0;
}