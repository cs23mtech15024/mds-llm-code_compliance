// ------ Non-Compliant
// Seed: Non-compliant: char *src = 0, c = 0;   // Compliant: char *src = 0; char c = 0;
// Context: String/byte buffer handling in a DRDO text-processing helper.
// Violation: Mixed pointer and non-pointer variables declared on the same line (MISRA C++:2008 Rule 8-0-1).
// Sources: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
//          SEI CERT — DCL04-C (do not declare more than one variable per declaration).  [oai_citation:4‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <thread>

// Non-compliant example: pointer and plain char declared on single line (seed)
void buffer_count_NC(const std::string &logpath = "count_nc.log") {
    // seed:
    char *src = 0, c = 0; // NON-COMPLIANT: mixed pointer and non-pointer declarators on same line

    // deterministic static buffer (safe, local storage)
    static char buffer[] = "DRDO: telemetry payload sample 0123456789";
    // assign pointer before use (avoid UB despite the non-compliant declaration form)
    src = buffer;
    c = '0'; // we will count occurrences of character '0'

    size_t count = 0;
    for (size_t i = 0; src[i] != '\0'; ++i) {
        if (src[i] == c) ++count;
    }

    // write deterministic log entry
    std::ostringstream ss;
    ss << "[NC] looking for '" << c << "' found=" << count << " len=" << std::strlen(buffer) << '\n';
    std::cout << ss.str();

    std::ofstream out(logpath, std::ios::app);
    if (out) { out << ss.str(); out.close(); }
    else { std::cerr << "[NC] Failed to open log\n"; }

    // mimic safe processing latency
    std::this_thread::sleep_for(std::chrono::milliseconds(8));
}

int main() {
    buffer_count_NC();
    return 0;
}