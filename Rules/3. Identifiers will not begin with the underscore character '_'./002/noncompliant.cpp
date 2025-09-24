// ------ Non-Compliant
// Seed: Non-compliant: static int _index = 0;   // Compliant: static int index = 0;
// Context: Packet parser loop in a DRDO telemetry module; uses a static index/counter across invocations.
// Violation: identifier begins with '_' — may be reserved (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:20‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard (identifier rules) / cppreference.  [oai_citation:21‡en.cppreference.com](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          StackOverflow discussion on underscore rules.  [oai_citation:22‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          PVS-Studio guidance (reserved identifiers).  [oai_citation:23‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)
//          Microsoft "Old New Thing" blog (reserved identifiers).  [oai_citation:24‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

void parse_packets_NC(const std::vector<int>& packets) {
    static int _index = 0; // NON-COMPLIANT: identifier begins with underscore (seed)
    std::ofstream out("parser_nc.log", std::ios::app);
    if (!out) std::cerr << "[NC] Log open failed\n";

    for (size_t i = 0; i < packets.size(); ++i) {
        int p = packets[i];
        _index += (p % 3 == 0) ? 1 : 0;

        if (i % 2 == 0) {
            std::cout << "[NC] pkt[" << i << "] val=" << p << " idx=" << _index << '\n';
            if (out) out << "[NC] pkt[" << i << "] val=" << p << " idx=" << _index << '\n';
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }

    if (out) out.close();
}

int main() {
    std::vector<int> packets = {10, 15, 18, 21, 25, 30, 35, 40};
    parse_packets_NC(packets);
    return 0;
}