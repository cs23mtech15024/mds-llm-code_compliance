// ------ Compliant
// Seed: Non-compliant: unsigned _timeout_ms = 1000;   // Compliant: unsigned timeout_ms = 1000;
// Context: Watchdog timeout helper in a DRDO mission-control subsystem.
// Compliance: identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1.
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:18‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier rules).  [oai_citation:19‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          StackOverflow discussion on underscore rules.  [oai_citation:20‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          Microsoft "Old New Thing" blog (reserved identifiers).  [oai_citation:21‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier docs (tooling guidance).  [oai_citation:22‡clang.llvm.org](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          GitHub example showing `_timeout` usage (seed inspiration).  [oai_citation:23‡GitHub](https://github.com/activepieces/activepieces/pull/225.patch?utm_source=chatgpt.com)

#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <atomic>
#include <string>

namespace drdo {
    // minimal simulated hardware watchdog interface
    inline void trigger_watchdog_reset() {
        std::cout << "[C] Watchdog reset triggered\n";
    }
}

// Compliant: same logic, identifier without leading underscore
void watchdog_task_C(std::atomic<bool>& stop_flag) {
    static unsigned timeout_ms = 1000; // COMPLIANT: no leading underscore
    std::ofstream log("watchdog_c.log", std::ios::app);
    if (!log) {
        std::cerr << "[C] Log open failed\n";
        return;
    }

    unsigned cycle = 0u;
    while (!stop_flag.load()) {
        // deterministic check: trigger reset every N cycles based on timeout policy
        if ((cycle % 5u) == 0u) {
            log << "[C] cycle=" << cycle << " timeout_ms=" << timeout_ms << '\n';
            std::cout << "[C] cycle=" << cycle << " timeout_ms=" << timeout_ms << '\n';
        }

        // simulate watchdog countdown using sleep for deterministic timing
        std::this_thread::sleep_for(std::chrono::milliseconds(timeout_ms / 10u));

        if (cycle != 0 && (cycle % 20u) == 0u) {
            drdo::trigger_watchdog_reset();
            log << "[C] Watchdog reset at cycle=" << cycle << '\n';
        }

        // simple policy: decrease timeout to simulate adaptive behavior
        if (timeout_ms > 200u && (cycle % 17u) == 0u) {
            timeout_ms -= 50u;
        }

        ++cycle;
        if (cycle > 120u) break; // bounded for deterministic demo
    }

    log.close();
}

int main() {
    std::atomic<bool> stop{false};
    std::thread t(watchdog_task_C, std::ref(stop));
    // run deterministic short demo
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    stop.store(true);
    if (t.joinable()) t.join();
    std::cout << "[C] Done\n";
    return 0;
}