// ------ Compliant
// Seed: Non-compliant: size_t _bufferSize = 1024;   // Compliant: size_t bufferSize = 1024;
// Context: Buffer management helper for DRDO data stream preprocessing.
// Compliance: identifier renamed to avoid leading underscore — complies with MISRA C++ Rule 17-0-1.
// Sources: MathWorks / Polyspace (MISRA C++ Rule 17-0-1).  [oai_citation:8‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier reservation rules).  [oai_citation:9‡en.cppreference.com](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          PVS-Studio guidance on reserved identifiers.  [oai_citation:10‡PVS-Studio](https://pvs-studio.com/en/pvs-studio/sast/misra/?utm_source=chatgpt.com)
//          Example GitHub usage showing `_bufferSize` in real projects (Microsoft Bond output_buffer.h).  [oai_citation:11‡Microsoft GitHub](https://microsoft.github.io/bond/reference/cpp/output__buffer_8h_source.html?utm_source=chatgpt.com)

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

// Compliant helper: same logic, identifier without leading underscore
void process_stream_C(size_t items) {
    static size_t bufferSize = 1024; // COMPLIANT: no leading underscore
    std::vector<char> buffer(bufferSize);

    std::ofstream log("buffer_c.log", std::ios::app);
    if (!log) {
        std::cerr << "[C] Log open failed\n";
        return;
    }

    for (size_t i = 0; i < items; ++i) {
        drdo::fill_pattern(buffer, static_cast<char>('A' + (i % 26)));
        // pretend to process buffer chunks
        log << "[C] chunk " << i << " size=" << bufferSize << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
        // adaptively grow buffer (simple policy)
        if (bufferSize < 8192 && (i % 4 == 3)) {
            bufferSize = std::min(static_cast<size_t>(bufferSize * 3 / 2), static_cast<size_t>(8192));
        }
        buffer.resize(bufferSize);
    }

    log.close();
}

int main() {
    process_stream_C(12);
    std::cout << "[C] Done\n";
    return 0;
}