// ------ Compliant
// Seed: Non-compliant: static int _index = 0;   // Compliant: static int index = 0;
// Context: Packet parser loop in a DRDO telemetry module; uses a static index/counter across invocations.
// Compliance: identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1.
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:25‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard (identifier rules) / cppreference.  [oai_citation:26‡en.cppreference.com](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          StackOverflow discussion on underscore rules.  [oai_citation:27‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          PVS-Studio guidance (reserved identifiers).  [oai_citation:28‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)
//          Microsoft "Old New Thing" blog (reserved identifiers).  [oai_citation:29‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

void parse_packets_C(const std::vector<int>& packets) {
    static int index = 0; // COMPLIANT: identifier does not begin with underscore
    std::ofstream out("parser_c.log", std::ios::app);
    if (!out) std::cerr << "[C] Log open failed\n";

    for (size_t i = 0; i < packets.size(); ++i) {
        int p = packets[i];
        index += (p % 3 == 0) ? 1 : 0;

        if (i % 2 == 0) {
            std::cout << "[C] pkt[" << i << "] val=" << p << " idx=" << index << '\n';
            if (out) out << "[C] pkt[" << i << "] val=" << p << " idx=" << index << '\n';
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }

    if (out) out.close();
}

int main() {
    std::vector<int> packets = {10, 15, 18, 21, 25, 30, 35, 40};
    parse_packets_C(packets);
    return 0;
}