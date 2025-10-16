// ------ Non-Compliant
// Seed: Non-compliant: int _internalState = 0;   // Compliant: int internalState = 0;
// Context: State tracking helper used in a DRDO embedded controller module (deterministic demo).
// Violation: identifier begins with '_' — may be reserved by the implementation (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:5‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier rules).  [oai_citation:6‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier (tool guidance).  [oai_citation:7‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          StackOverflow Q&A on underscore rules.  [oai_citation:8‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          PVS-Studio guidance on reserved identifiers.  [oai_citation:9‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

// Non-compliant module: uses a static identifier that begins with underscore (seed)
static int _internalState = 0; // NON-COMPLIANT: leading underscore in identifier (seed)

namespace drdo {
    // Deterministic helper that transitions the state machine deterministically.
    inline void apply_action(int action) {
        (void)action;
        // In real code this would affect hardware; here we print a deterministic message.
    }
}

void run_controller_NC(const std::vector<int>& actions) {
    std::ofstream log("controller_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    for (size_t i = 0; i < actions.size(); ++i) {
        int a = actions[i];
        // simple deterministic state update policy using _internalState
        if (a == 0) {
            _internalState = 0;
        } else if (a % 5 == 0) {
            _internalState += 2;
        } else {
            _internalState += 1;
        }

        // bounded for demo
        if (_internalState > 10) _internalState = 10;

        // log and simulate action application
        log << "[NC] step=" << i << " action=" << a << " state=" << _internalState << '\n';
        std::cout << "[NC] step=" << i << " state=" << _internalState << '\n';
        drdo::apply_action(a);

        // deterministic small delay
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    log.close();
}

int main() {
    // deterministic action sequence for demo purposes
    std::vector<int> actions = {1,2,5,3,0,7,5,2,1,4};
    run_controller_NC(actions);
    return 0;
}