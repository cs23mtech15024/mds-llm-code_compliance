// ------ Non-Compliant
// Seed: Non-compliant: char c1 = 'A', c2 = 'B';   // Compliant: char c1 = 'A'; char c2 = 'B';
// Context: Header/flag characters used in DRDO packet framing — small deterministic inspector.
// Violation: Declaring multiple variables in one declaration (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
// Note: SEI CERT also recommends one declaration per variable for clarity.  [oai_citation:4‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <array>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cstring>

// Non-compliant: two header chars declared in one init-declarator-list (seed)
void header_inspect_NC(const std::string &logpath = "hdr_nc.log") {
    // seed:
    char c1 = 'A', c2 = 'B'; // NON-COMPLIANT: multiple declarators in one declaration

    // deterministic static frame buffer
    static const char frame[] = "A|B|A|X|B|A|C|B|A|B|A|Z";
    const size_t len = std::strlen(frame);

    // count occurrences of each header char (only for c1 and c2 here)
    size_t count1 = 0;
    size_t count2 = 0;
    for (size_t i = 0; i < len; ++i) {
        if (frame[i] == c1) ++count1;
        if (frame[i] == c2) ++count2;
    }

    // prepare a deterministic report
    std::ostringstream ss;
    ss << std::boolalpha;
    ss << "[NC] header '" << c1 << "' count=" << count1 << " | header '" << c2 << "' count=" << count2
       << " | len=" << len << '\n';

    // print and log
    std::cout << ss.str();
    std::ofstream out(logpath, std::ios::app);
    if (out) { out << ss.str(); out.close(); }
    else { std::cerr << "[NC] Failed to open log\n"; }

    // deterministic tiny delay to simulate I/O
    std::this_thread::sleep_for(std::chrono::milliseconds(8));
}

int main() {
    header_inspect_NC();
    return 0;
}