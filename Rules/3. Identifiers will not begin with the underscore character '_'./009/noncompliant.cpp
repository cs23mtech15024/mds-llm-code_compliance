// ------ Non-Compliant
// Seed: Non-compliant: int _radarSignal = 0;   // Compliant: int radarSignal = 0;
// Context: Radar-signal normalization helper for a DRDO signal-processing module.
// Violation: identifier begins with '_' — reserved/implementation identifiers must not be used.
// Sources: MathWorks / Polyspace (MISRA C++ Rule 17-0-1).  [oai_citation:5‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier reservation rules).  [oai_citation:6‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          StackOverflow discussion on underscore rules.  [oai_citation:7‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier (tool guidance).  [oai_citation:8‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          GitHub Gist (radar processing examples) — seed inspiration.  [oai_citation:9‡Gist](https://gist.github.com/wradlib?direction=asc&sort=updated&utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <chrono>
#include <thread>

// Non-compliant normalization helper: uses a variable name beginning with underscore (seed)
void normalize_radar_NC(const std::vector<int>& raw, std::vector<double>& out) {
    static int _radarSignal = 0; // NON-COMPLIANT: leading underscore in identifier (seed)

    std::ofstream log("radar_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    out.clear();
    out.reserve(raw.size());
    for (size_t i = 0; i < raw.size(); ++i) {
        // simple normalization pipeline (deterministic)
        int sample = raw[i];
        // running baseline update using _radarSignal
        _radarSignal = (_radarSignal * 7 + sample) / 8;
        double normalized = (static_cast<double>(sample) - _radarSignal) / (1.0 + std::abs(_radarSignal));

        // apply small non-linear scaling
        double scaled = std::copysign(std::pow(std::abs(normalized), 1.2), normalized);

        out.push_back(scaled);
        log << "[NC] i=" << i << " raw=" << sample << " baseline=" << _radarSignal
            << " norm=" << scaled << '\n';

        // deterministic micro-wait to emulate sampling timing
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }

    log.close();
}

int main() {
    // deterministic synthetic input resembling radar return magnitudes
    std::vector<int> raw = {120, 130, 128, 200, 215, 210, 180, 160, 145, 155};
    std::vector<double> processed;
    normalize_radar_NC(raw, processed);

    std::cout << "[NC] Processed " << processed.size() << " samples\n";
    for (size_t i = 0; i < processed.size(); ++i)
        std::cout << "[NC] sample[" << i << "] = " << processed[i] << '\n';

    return 0;
}