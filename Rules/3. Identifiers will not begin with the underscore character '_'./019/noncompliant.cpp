// ------ Non-Compliant
// Seed: Non-compliant: int _missionPhase = 0;   // Compliant: int missionPhase = 0;
// Context: Mission-phase sequencing helper in a DRDO mission control subsystem (deterministic demo).
// Violation: identifier begins with '_' — may be reserved by the implementation (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:6‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          cppreference (identifier reservation rules).  [oai_citation:7‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          PVS-Studio: identifiers that start with '__' or '_[A-Z]' are reserved.  [oai_citation:8‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)
//          StackOverflow: rules about underscore usage in C++ identifiers.  [oai_citation:9‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          SEI / CERT guidance on reserved identifiers.  [oai_citation:10‡wiki.sei.cmu.edu](https://wiki.sei.cmu.edu/confluence/display/c/DCL37-C.%2BDo%2Bnot%2Bdeclare%2Bor%2Bdefine%2Ba%2Breserved%2Bidentifier?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <string>

// Non-compliant static identifier starts with underscore (seed)
static int _missionPhase = 0; // NON-COMPLIANT: leading underscore in identifier (seed)

namespace drdo {
    inline void engage_subsystem(const std::string &name, int phase) {
        // deterministic message to simulate action
        std::cout << "[NC] engage " << name << " for phase " << phase << '\n';
    }
}

// Non-compliant mission sequencer: uses _missionPhase (seed)
void mission_sequencer_NC(const std::vector<std::string> &stages) {
    std::ofstream log("mission_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    for (size_t i = 0; i < stages.size(); ++i) {
        // set phase deterministically based on index
        if (i == 0) _missionPhase = 0;
        else if (i % 3 == 0) _missionPhase += 2;
        else _missionPhase += 1;

        if (_missionPhase > 10) _missionPhase = 10;

        drdo::engage_subsystem(stages[i], _missionPhase);
        log << "[NC] step=" << i << " stage=" << stages[i] << " phase=" << _missionPhase << '\n';

        // deterministic wait to emulate staged sequencing
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }

    log.close();
}

int main() {
    std::vector<std::string> stages = {
        "PowerOn", "SelfTest", "NavigationAlign", "CommEstablish", "PayloadCheck",
        "FinalGo", "Execute", "Monitor", "Terminate"
    };
    mission_sequencer_NC(stages);
    std::cout << "[NC] Final mission phase = " << _missionPhase << '\n';
    return 0;
}