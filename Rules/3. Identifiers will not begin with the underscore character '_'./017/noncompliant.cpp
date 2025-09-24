// ------ Non-Compliant
// Seed: Non-compliant: size_t _deviceCount = 0;   // Compliant: size_t deviceCount = 0;
// Context: Device management helper in a DRDO embedded monitoring system.
// Violation: identifier begins with '_' — may be reserved by implementation (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace — MISRA 17-0-1.  [oai_citation:6‡MathWorks](https://kr.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
//          PVS-Studio: identifiers that start with '__' or '_[A-Z]' are reserved.  [oai_citation:7‡PVS-Studio](https://pvs-studio.com/en/pvs-studio/sast/misra/?utm_source=chatgpt.com)  
//          C++ standard / cppreference — identifier reservation rules.  [oai_citation:8‡SciTools Documentation](https://docs.scitools.com/codecheck/path_7.html?utm_source=chatgpt.com)  
//          StackOverflow: identifiers starting with underscore.  [oai_citation:9‡Stack Overflow](https://stackoverflow.com/questions/6397780/names-starting-with-underscore-shows-errors-page-doesnot-exists-for-gh-pages-bra?utm_source=chatgpt.com)  

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

// Non-compliant: static identifier with leading underscore (seed)
static size_t _deviceCount = 0; // NON-COMPLIANT: leading underscore in identifier (seed)

void monitor_devices_NC(const std::vector<size_t>& devIDs) {
    std::ofstream log("monitor_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    for (size_t id : devIDs) {
        if (drdo::is_device_active(id)) {
            ++_deviceCount;
            log << "[NC] id=" << id << " active, count=" << _deviceCount << '\n';
        } else {
            log << "[NC] id=" << id << " inactive, count=" << _deviceCount << '\n';
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
    }
    log.close();
}

int main() {
    std::vector<size_t> ids = {1,2,3,4,5,6,7,8,9,10};
    monitor_devices_NC(ids);
    std::cout << "[NC] Total active devices = " << _deviceCount << '\n';
    return 0;
}