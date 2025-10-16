// ------ Compliant
// Seed: Non-compliant: unsigned long _missionID = 0;   // Compliant: unsigned long missionID = 0;
// Context: Mission state initialization helper in a DRDO mission controller.
// Compliance: identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1.
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:10‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier reservation rules).  [oai_citation:11‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          StackOverflow discussion on underscore rules.  [oai_citation:12‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          PVS-Studio guidance on identifiers starting with '__' or '_[A-Z]'.  [oai_citation:13‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)
//          GitHub (Zephyr) discussion on avoiding reserved names in projects.  [oai_citation:14‡GitHub](https://github.com/zephyrproject-rtos/zephyr/issues/9882?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <atomic>
#include <string>

namespace drdo {
    // Simulated platform initialization (deterministic, minimal)
    inline void initialize_subsystem(const std::string &name) {
        std::cout << "[C] init: " << name << '\n';
    }
}

// Compliant: same global/static storage, identifier without leading underscore
static unsigned long missionID = 0; // COMPLIANT: no leading underscore

void mission_setup_C(const std::string &missionName) {
    // record mission id (simple deterministic scheme)
    missionID = 0x1u; // set a fixed id for deterministic demo
    std::ofstream log("mission_c.log", std::ios::app);
    if (!log) {
        std::cerr << "[C] Log open failed\n";
        return;
    }

    log << "[C] Mission '" << missionName << "' started, id=0x" << std::hex << missionID << std::dec << '\n';
    drdo::initialize_subsystem("Navigation");
    drdo::initialize_subsystem("Guidance");
    drdo::initialize_subsystem("Telemetry");

    // deterministic wait to simulate sequenced init
    std::this_thread::sleep_for(std::chrono::milliseconds(20));

    log << "[C] Mission setup complete, id=" << missionID << '\n';
    log.close();
}

int main() {
    mission_setup_C("Alpha-1");
    std::cout << "[C] mission id (internal): " << missionID << '\n';
    return 0;
}