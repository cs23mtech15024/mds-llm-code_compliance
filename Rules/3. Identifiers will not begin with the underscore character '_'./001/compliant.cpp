// ------ Compliant
// Seed: Non-compliant: int _count = 0;   // Compliant: int count = 0;
// Context: Logging module in DRDO software that counts certain events.
// Compliance: identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1.
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:10‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard (identifier rules) / cppreference.  [oai_citation:11‡en.cppreference.com](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          StackOverflow discussion on underscore rules.  [oai_citation:12‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          PVS-Studio guidance (reserved identifiers).  [oai_citation:13‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)
//          Microsoft "Old New Thing" blog (reserved identifiers).  [oai_citation:14‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

void log_event_C(int events) {
    static int count = 0;  // COMPLIANT: identifier does not begin with underscore
    for (int i = 0; i < events; ++i) {
        ++count;
        std::ofstream log("event_c.log", std::ios::app);
        if (log) {
            log << "[C] Event " << i << ": total count = " << count << '\n';
            log.close();
        } else {
            std::cerr << "[C] Log open failed\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

int main() {
    log_event_C(5);
    return 0;
}