// ------ Compliant
// Seed: Non-compliant: int _state = 0;   // Compliant: int state = 0;
// Context: Small deterministic state-machine helper in a DRDO control subsystem.
// Compliance: identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1.
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:11‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ Standard / cppreference (identifiers rules).  [oai_citation:12‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier (tooling guidance).  [oai_citation:13‡clang.llvm.org](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          StackOverflow Q&A on underscore rules.  [oai_citation:14‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          Clang-tidy/GitHub discussion on reserved-identifier warnings.  [oai_citation:15‡GitHub](https://github.com/llvm/llvm-project/issues/62650?utm_source=chatgpt.com)

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

// Compliant state machine: same behavior, identifier without leading underscore
void run_state_machine_C(int cycles) {
    static int state = 0; // COMPLIANT: no leading underscore
    std::ofstream log("state_c.log", std::ios::app);
    if (!log) {
        std::cerr << "[C] Log open failed\n";
        return;
    }

    for (int i = 0; i < cycles; ++i) {
        // deterministic event selection
        Event ev = static_cast<Event>(i % 4);

        switch (ev) {
            case Event::START:
                state = 1;
                break;
            case Event::STOP:
                state = 0;
                break;
            case Event::ERROR:
                state = -1;
                break;
            case Event::RESET:
                state = 0;
                break;
        }

        log << "[C] cycle=" << i << " ev=" << static_cast<int>(ev) << " state=" << state << '\n';
        std::cout << "[C] cycle=" << i << " state=" << state << '\n';

        // deterministic small wait
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    log.close();
}

int main() {
    run_state_machine_C(20);
    return 0;
}