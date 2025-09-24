// ------ Non-Compliant
// Seed: Non-compliant: int _timeoutValue = 500;   // Compliant: int timeoutValue = 500;
// Context: Timeout configuration helper in a DRDO comms module that manages retry/backoff intervals.
// Violation: identifier begins with '_' — may be reserved by the implementation (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:8‡MathWorks](https://kr.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier reservation rules).  [oai_citation:9‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          Microsoft “Old New Thing” — reserved identifier guidance.  [oai_citation:10‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)
//          StackOverflow: rules about underscores in identifiers.  [oai_citation:11‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include <string>

namespace drdo {
    inline void applyTimeout(int ms) {
        std::cout << "[NC] Applying timeout (ms): " << ms << std::endl;
    }
}

void retry_loop_NC(int attempts) {
    static int _timeoutValue = 500; // NON-COMPLIANT: leading underscore in identifier (seed)

    std::ofstream log("timeout_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    for (int i = 0; i < attempts; ++i) {
        log << "[NC] attempt=" << i << " timeout=" << _timeoutValue << "ms\n";
        std::cout << "[NC] attempt=" << i << " timeout=" << _timeoutValue << "ms\n";

        drdo::applyTimeout(_timeoutValue);

        // backoff: deterministic simple doubling with cap
        if (_timeoutValue < 2000) {
            _timeoutValue *= 2;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    log.close();
}

int main() {
    retry_loop_NC(4);
    return 0;
}