// ------ Non-Compliant
// Seed: Non-compliant: unsigned long _missionID = 0;   // Compliant: unsigned long missionID = 0;
// Context: Mission state initialization helper in a DRDO mission controller.
// Violation: identifier begins with '_' — may be reserved (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:5‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier reservation rules).  [oai_citation:6‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          StackOverflow discussion on underscore rules.  [oai_citation:7‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          PVS-Studio guidance on identifiers starting with '__' or '_[A-Z]'.  [oai_citation:8‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)
//          GitHub (Zephyr) discussion on avoiding reserved names in projects.  [oai_citation:9‡GitHub](https://github.com/zephyrproject-rtos/zephyr/issues/9882?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <atomic>
#include <string>

namespace drdo {
    // Simulated platform initialization (deterministic, minimal)
    inline void initialize_subsystem(const std::string &name) {
        std::cout << "[NC] init: " << name << '\n';
    }
}

// Non-compliant: global/static identifier starts with underscore (seed)
static unsigned long _missionID = 0; // NON-COMPLIANT: leading underscore in global/static identifier (seed)

void mission_setup_NC(const std::string &missionName) {
    // record mission id (simple deterministic scheme)
    _missionID = 0x1u; // set a fixed id for deterministic demo
    std::ofstream log("mission_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    log << "[NC] Mission '" << missionName << "' started, id=0x" << std::hex << _missionID << std::dec << '\n';
    drdo::initialize_subsystem("Navigation");
    drdo::initialize_subsystem("Guidance");
    drdo::initialize_subsystem("Telemetry");

    // deterministic wait to simulate sequenced init
    std::this_thread::sleep_for(std::chrono::milliseconds(20));

    log << "[NC] Mission setup complete, id=" << _missionID << '\n';
    log.close();
}

int main() {
    mission_setup_NC("Alpha-1");
    std::cout << "[NC] mission id (internal): " << _missionID << '\n';
    return 0;
}