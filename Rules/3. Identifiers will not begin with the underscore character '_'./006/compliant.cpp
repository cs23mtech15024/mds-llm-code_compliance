// ------ Compliant
// Seed: Non-compliant: double _sensorValue = 0.0;   // Compliant: double sensorValue = 0.0;
// Context: Sensor read-and-log helper in a DRDO instrumentation module.
// Compliance: identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1.
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:10‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier rules).  [oai_citation:11‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier (reserved identifier guidance).  [oai_citation:12‡clang.llvm.org](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          StackOverflow Q&A on underscore rules.  [oai_citation:13‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          Example GitHub issue showing `_sensorValue` usage (seed inspiration).  [oai_citation:14‡GitHub](https://github.com/nkolban/esp32-snippets/issues/79?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>

namespace drdo {
    // Simulated low-level sensor read (deterministic for testing)
    inline double read_raw_sensor(size_t idx) {
        // simple deterministic pseudorandom-ish pattern
        return 100.0 * std::sin(static_cast<double>(idx) * 0.1) + (idx % 5);
    }
}

// Compliant function: same logic, identifier without leading underscore
void process_sensors(size_t samples) {
    static double sensorValue = 0.0; // COMPLIANT: identifier does not begin with underscore
    std::ofstream log("sensor_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[C] Log open failed\n";
        return;
    }

    for (size_t i = 0; i < samples; ++i) {
        // read and low-pass filter (simple exponential smoothing)
        double raw = drdo::read_raw_sensor(i);
        const double alpha = 0.3;
        sensorValue = alpha * raw + (1.0 - alpha) * sensorValue;

        // compute derived metric
        double metric = std::round(sensorValue * 100.0) / 100.0;

        log << "[C] sample=" << i << " raw=" << raw << " filtered=" << metric << '\n';

        // deterministic small sleep to emulate processing time
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }

    log.close();
}

int main() {
    process_sensors(20);
    std::cout << "[C] Done\n";
    return 0;
}