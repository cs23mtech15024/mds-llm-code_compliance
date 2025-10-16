// ------ Compliant
// Seed: Non-compliant: std::string _sessionKey = "S1";   // Compliant: std::string sessionKey = "S1";
// Context: Session/key handling helper for a DRDO secure communication pre-processor.
// Compliance: identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1.
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:10‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier reservation rules).  [oai_citation:11‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier (tool guidance).  [oai_citation:12‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          StackOverflow Q&A: rules about underscores in C/C++ identifiers.  [oai_citation:13‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          Microsoft "Old New Thing" blog: reserved identifier rationale.  [oai_citation:14‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>

// Compliant module: same logic, identifier without leading underscore
static std::string sessionKey = "S1"; // COMPLIANT: no leading underscore

namespace drdo {
    // Deterministic key expansion (toy example, not cryptographic)
    inline std::string expand_key(const std::string &k, int round) {
        std::string out = k;
        for (int i = 0; i < round; ++i) {
            // simple deterministic rotate-and-xor-like transform (toy)
            std::rotate(out.begin(), out.begin() + 1, out.end());
            for (size_t j = 0; j < out.size(); ++j) {
                out[j] = static_cast<char>((out[j] ^ (0x5A + j)) & 0x7F);
            }
        }
        return out;
    }
}

void preprocess_messages_C(const std::vector<std::string>& msgs) {
    std::ofstream log("session_c.log", std::ios::app);
    if (!log) {
        std::cerr << "[C] Log open failed\n";
        return;
    }

    for (size_t i = 0; i < msgs.size(); ++i) {
        // deterministic per-message derived key
        std::string derived = drdo::expand_key(sessionKey, static_cast<int>(i % 4));
        std::string out = msgs[i] + ":" + derived.substr(0, 4);

        log << "[C] msg=" << i << " key=" << sessionKey << " out=" << out << '\n';
        std::cout << "[C] processed msg " << i << " len=" << out.size() << '\n';

        // deterministic short delay
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
    }

    log.close();
}

int main() {
    std::vector<std::string> messages = {
        "CMD:STATUS", "CMD:SYNC", "DATA:READ", "CMD:RESET", "DATA:STREAM"
    };
    preprocess_messages_C(messages);
    std::cout << "[C] Done\n";
    return 0;
}