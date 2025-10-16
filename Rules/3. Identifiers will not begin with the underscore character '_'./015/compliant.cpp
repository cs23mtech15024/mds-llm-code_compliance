// ------ Compliant
// Seed: Non-compliant: int _deviceHandle = -1;   // Compliant: int deviceHandle = -1;
// Context: Device open/close helper used in a DRDO embedded subsystem test harness.
// Compliance: identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1.
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:15‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifiers & reserved names).  [oai_citation:16‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier docs.  [oai_citation:17‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          StackOverflow: rules about underscores in C/C++ identifiers.  [oai_citation:18‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          PVS-Studio: reserved identifier guidance.  [oai_citation:19‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)

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

// Compliant: static/global variable name without leading underscore
static int deviceHandle = -1; // COMPLIANT: no leading underscore
static std::mutex g_mutex;

void device_session_C(const std::string &devName) {
    std::ofstream log("device_c.log", std::ios::app);
    if (!log) {
        std::cerr << "[C] Log open failed\n";
        return;
    }

    {
        std::lock_guard<std::mutex> lk(g_mutex);
        if (deviceHandle < 0) {
            deviceHandle = drdo::open_device(devName);
            log << "[C] Opened device '" << devName << "' handle=" << deviceHandle << '\n';
        } else {
            log << "[C] Reusing device handle=" << deviceHandle << '\n';
        }
    }

    // deterministic simulated work using handle
    for (int i = 0; i < 5; ++i) {
        log << "[C] working with handle=" << deviceHandle << " step=" << i << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }

    {
        std::lock_guard<std::mutex> lk(g_mutex);
        drdo::close_device(deviceHandle);
        log << "[C] Closed device handle=" << deviceHandle << '\n';
        deviceHandle = -1;
    }

    log.close();
}

int main() {
    device_session_C("DRDO_SIM_DEV");
    std::cout << "[C] Done\n";
    return 0;
}