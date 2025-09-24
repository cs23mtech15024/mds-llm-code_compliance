// ------ Non-Compliant
// Seed: Non-compliant: int _deviceHandle = -1;   // Compliant: int deviceHandle = -1;
// Context: Device open/close helper used in a DRDO embedded subsystem test harness.
// Violation: identifier begins with '_' — may be reserved (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:10‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifiers & reserved names).  [oai_citation:11‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier docs.  [oai_citation:12‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          StackOverflow: rules about underscores in C/C++ identifiers.  [oai_citation:13‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          PVS-Studio: reserved identifier guidance.  [oai_citation:14‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

namespace drdo {
    // Minimal deterministic fake device API (no real hardware)
    inline int open_device(const std::string &name) {
        static int next_id = 1;
        return next_id++; // return deterministic unique handle
    }
    inline void close_device(int handle) {
        (void)handle;
    }
}

// Non-compliant: static/global variable name starts with underscore (seed)
static int _deviceHandle = -1; // NON-COMPLIANT: leading underscore in identifier (seed)
static std::mutex g_mutex;

void device_session_NC(const std::string &devName) {
    std::ofstream log("device_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    {
        std::lock_guard<std::mutex> lk(g_mutex);
        if (_deviceHandle < 0) {
            _deviceHandle = drdo::open_device(devName);
            log << "[NC] Opened device '" << devName << "' handle=" << _deviceHandle << '\n';
        } else {
            log << "[NC] Reusing device handle=" << _deviceHandle << '\n';
        }
    }

    // deterministic simulated work using handle
    for (int i = 0; i < 5; ++i) {
        log << "[NC] working with handle=" << _deviceHandle << " step=" << i << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }

    {
        std::lock_guard<std::mutex> lk(g_mutex);
        drdo::close_device(_deviceHandle);
        log << "[NC] Closed device handle=" << _deviceHandle << '\n';
        _deviceHandle = -1;
    }

    log.close();
}

int main() {
    device_session_NC("DRDO_SIM_DEV");
    std::cout << "[NC] Done\n";
    return 0;
}