// ------ Compliant
// Seed: Non-compliant: int _timeoutValue = 500;   // Compliant: int timeoutValue = 500;
// Context: Timeout configuration helper in a DRDO comms module that manages retry/backoff intervals.
// Compliance: identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1.
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:12‡MathWorks](https://kr.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier reservation rules).  [oai_citation:13‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          Microsoft “Old New Thing” — reserved identifier guidance.  [oai_citation:14‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)
//          StackOverflow: rules about underscores in identifiers.  [oai_citation:15‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include <string>

namespace drdo {
    inline void applyTimeout(int ms) {
        std::cout << "[C] Applying timeout (ms): " << ms << std::endl;
    }
}

void retry_loop_C(int attempts) {
    static int timeoutValue = 500; // COMPLIANT: no leading underscore
    std::ofstream log("timeout_c.log", std::ios::app);
    if (!log) {
        std::cerr << "[C] Log open failed\n";
        return;
    }

    for (int i = 0; i < attempts; ++i) {
        log << "[C] attempt=" << i << " timeout=" << timeoutValue << "ms\n";
        std::cout << "[C] attempt=" << i << " timeout=" << timeoutValue << "ms\n";

        drdo::applyTimeout(timeoutValue);

        // backoff: deterministic simple doubling with cap
        if (timeoutValue < 2000) {
            timeoutValue *= 2;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    log.close();
}

int main() {
    retry_loop_C(4);
    return 0;
}