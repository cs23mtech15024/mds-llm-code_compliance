// ------ Non-Compliant
// Seed: Non-compliant: int _state = 0;   // Compliant: int state = 0;
// Context: Small deterministic state-machine helper in a DRDO control subsystem.
// Violation: identifier begins with '_' — reserved/implementation identifiers must not be used.
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:6‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ Standard / cppreference (identifiers rules).  [oai_citation:7‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier (tooling guidance).  [oai_citation:8‡clang.llvm.org](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          StackOverflow Q&A on underscore rules.  [oai_citation:9‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          Clang-tidy/GitHub discussion on reserved-identifier warnings.  [oai_citation:10‡GitHub](https://github.com/llvm/llvm-project/issues/62650?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

enum class Event {
    START,
    STOP,
    ERROR,
    RESET
};

// Non-compliant state machine: uses identifier beginning with underscore (seed)
void run_state_machine_NC(int cycles) {
    static int _state = 0; // NON-COMPLIANT: leading underscore in identifier (seed)

    std::ofstream log("state_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    for (int i = 0; i < cycles; ++i) {
        // deterministic event selection
        Event ev = static_cast<Event>(i % 4);

        switch (ev) {
            case Event::START:
                _state = 1;
                break;
            case Event::STOP:
                _state = 0;
                break;
            case Event::ERROR:
                _state = -1;
                break;
            case Event::RESET:
                _state = 0;
                break;
        }

        log << "[NC] cycle=" << i << " ev=" << static_cast<int>(ev) << " state=" << _state << '\n';
        std::cout << "[NC] cycle=" << i << " state=" << _state << '\n';

        // deterministic small wait
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    log.close();
}

int main() {
    run_state_machine_NC(20);
    return 0;
}