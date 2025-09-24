// ------ Compliant
// Seed: Non-compliant: size_t _deviceCount = 0;   // Compliant: size_t deviceCount = 0;
// Context: Device management helper in a DRDO embedded monitoring system.
// Compliance: identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1 (reserved identifiers).
// Sources: MathWorks / Polyspace — MISRA 17-0-1.  [oai_citation:10‡MathWorks](https://kr.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
//          PVS-Studio: identifiers that start with '__' or '_[A-Z]' are reserved.  [oai_citation:11‡PVS-Studio](https://pvs-studio.com/en/pvs-studio/sast/misra/?utm_source=chatgpt.com)  
//          C++ standard / cppreference — identifier reservation rules.  [oai_citation:12‡SciTools Documentation](https://docs.scitools.com/codecheck/path_7.html?utm_source=chatgpt.com)  
//          StackOverflow: identifiers starting with underscore.  [oai_citation:13‡Stack Overflow](https://stackoverflow.com/questions/6397780/names-starting-with-underscore-shows-errors-page-doesnot-exists-for-gh-pages-bra?utm_source=chatgpt.com)  

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>

namespace drdo {
    inline bool is_device_active(size_t id) {
        return (id % 2 == 0);
    }
}

// Compliant: static identifier without leading underscore
static size_t deviceCount = 0; // COMPLIANT: no leading underscore

void monitor_devices_C(const std::vector<size_t>& devIDs) {
    std::ofstream log("monitor_c.log", std::ios::app);
    if (!log) {
        std::cerr << "[C] Log open failed\n";
        return;
    }

    for (size_t id : devIDs) {
        if (drdo::is_device_active(id)) {
            ++deviceCount;
            log << "[C] id=" << id << " active, count=" << deviceCount << '\n';
        } else {
            log << "[C] id=" << id << " inactive, count=" << deviceCount << '\n';
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
    }
    log.close();
}

int main() {
    std::vector<size_t> ids = {1,2,3,4,5,6,7,8,9,10};
    monitor_devices_C(ids);
    std::cout << "[C] Total active devices = " << deviceCount << '\n';
    return 0;
}