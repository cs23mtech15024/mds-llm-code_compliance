// ------ Non-Compliant
// Seed: Non-compliant: size_t _bufferSize = 1024;   // Compliant: size_t bufferSize = 1024;
// Context: Buffer management helper for DRDO data stream preprocessing.
// Violation: identifier begins with '_' — reserved/implementation identifiers must not be used.
// Sources: MathWorks / Polyspace (MISRA C++ Rule 17-0-1).  [oai_citation:4‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier reservation rules).  [oai_citation:5‡en.cppreference.com](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          PVS-Studio guidance on reserved identifiers.  [oai_citation:6‡PVS-Studio](https://pvs-studio.com/en/pvs-studio/sast/misra/?utm_source=chatgpt.com)
//          Example GitHub usage showing `_bufferSize` in real projects (Microsoft Bond output_buffer.h).  [oai_citation:7‡Microsoft GitHub](https://microsoft.github.io/bond/reference/cpp/output__buffer_8h_source.html?utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <thread>

namespace drdo {
    // Simulated IO fill that writes a repeated pattern to the destination buffer
    void fill_pattern(std::vector<char>& dst, char pattern) {
        std::fill(dst.begin(), dst.end(), pattern);
    }
}

// Non-compliant helper: uses a name that begins with underscore (seed)
void process_stream_NC(size_t items) {
    static size_t _bufferSize = 1024; // NON-COMPLIANT: leading underscore in identifier (seed)
    std::vector<char> buffer(_bufferSize);

    std::ofstream log("buffer_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    for (size_t i = 0; i < items; ++i) {
        drdo::fill_pattern(buffer, static_cast<char>('A' + (i % 26)));
        // pretend to process buffer chunks
        log << "[NC] chunk " << i << " size=" << _bufferSize << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
        // adaptively grow buffer (simple policy)
        if (_bufferSize < 8192 && (i % 4 == 3)) {
            _bufferSize = std::min(static_cast<size_t>(_bufferSize * 3 / 2), static_cast<size_t>(8192));
        }
        buffer.resize(_bufferSize);
    }

    log.close();
}

int main() {
    process_stream_NC(12);
    std::cout << "[NC] Done\n";
    return 0;
}