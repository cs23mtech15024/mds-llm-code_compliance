// ------ Non-Compliant
// Seed: Non-compliant: int _count = 0;   // Compliant: int count = 0;
// Context: Logging module in DRDO software that counts certain events.
// Violation: identifier begins with '_' — may be reserved (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:5‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard (identifier rules) / cppreference.  [oai_citation:6‡en.cppreference.com](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          StackOverflow discussion on underscore rules.  [oai_citation:7‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          PVS-Studio guidance (reserved identifiers).  [oai_citation:8‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)
//          Microsoft "Old New Thing" blog (reserved identifiers).  [oai_citation:9‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

void log_event_NC(int events) {
    static int _count = 0;  // NON-COMPLIANT: identifier begins with underscore (seed)
    for (int i = 0; i < events; ++i) {
        ++_count;
        std::ofstream log("event_nc.log", std::ios::app);
        if (log) {
            log << "[NC] Event " << i << ": total count = " << _count << '\n';
            log.close();
        } else {
            std::cerr << "[NC] Log open failed\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

int main() {
    log_event_NC(5);
    return 0;
}