// ------ Non-Compliant
// Seed: Non-compliant: bool _errorFlag = false;   // Compliant: bool errorFlag = false;
// Context: Error handling and logging helper in a DRDO diagnostics module.
// Violation: identifier begins with '_' — reserved/implementation identifiers must not be used.
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:10‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier reservation rules).  [oai_citation:11‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier (tool guidance).  [oai_citation:12‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          StackOverflow Q&A on underscore rules.  [oai_citation:13‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          GitHub / clang-tidy reserved-identifier discussion.  [oai_citation:14‡GitHub](https://github.com/llvm/llvm-project/issues/62650?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <atomic>

namespace drdo {
    inline void report_fault(const std::string &msg) {
        std::cerr << "[NC] FAULT: " << msg << '\n';
    }
}

// Non-compliant error helper: uses identifier beginning with underscore (seed)
void diagnostics_task_NC(std::atomic<bool>& stop_flag) {
    static bool _errorFlag = false; // NON-COMPLIANT: leading underscore in identifier (seed)

    std::ofstream log("diag_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    int cycle = 0;
    while (!stop_flag.load()) {
        // deterministic simulated checks
        if ((cycle % 7) == 0) {
            // simulate a spurious error condition
            _errorFlag = ((cycle / 7) % 2 == 0);
        }

        if (_errorFlag) {
            drdo::report_fault("Sensor calibration error detected");
            log << "[NC] cycle=" << cycle << " ERROR=1\n";
        } else {
            log << "[NC] cycle=" << cycle << " ERROR=0\n";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(6));
        ++cycle;
        if (cycle > 140) break; // bounded demo
    }

    log.close();
}

int main() {
    std::atomic<bool> stop{false};
    std::thread t(diagnostics_task_NC, std::ref(stop));
    // deterministic short demo
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    stop.store(true);
    if (t.joinable()) t.join();
    std::cout << "[NC] Done\n";
    return 0;
}