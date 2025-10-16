// ------ Non-Compliant
// Seed: Non-compliant: int _configParam = 42;   // Compliant: int configParam = 42;
// Context: Configuration parameter loader and validator in a DRDO subsystem.
// Violation: identifier begins with '_' — may be reserved by implementation (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:6‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier reservation rules).  [oai_citation:7‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier (tool guidance).  [oai_citation:8‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          StackOverflow Q&A on underscore rules.  [oai_citation:9‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          Microsoft "Old New Thing" blog (reserved identifiers).  [oai_citation:10‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)
//          LLVM/GitHub reserved-identifier discussion.  [oai_citation:11‡GitHub](https://github.com/llvm/llvm-project/issues/62650?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// Non-compliant loader: uses identifier beginning with underscore (seed)
int load_config_NC(const std::string &cfgLine) {
    static int _configParam = 42; // NON-COMPLIANT: leading underscore in identifier (seed)

    // parse a single integer token from line (deterministic, simple)
    std::istringstream iss(cfgLine);
    int val = 0;
    if (!(iss >> val)) {
        // if parse fails, keep previous _configParam for deterministic resilience
        std::cerr << "[NC] parse failed, using previous value=" << _configParam << '\n';
        return _configParam;
    }

    // validate: accept only multiples of 2 between 0 and 100
    if (val < 0 || val > 100 || (val % 2) != 0) {
        std::cerr << "[NC] invalid config value " << val << " — ignoring\n";
        return _configParam;
    }

    // update persistent config parameter
    _configParam = val;

    std::cout << "[NC] config updated to " << _configParam << '\n';
    return _configParam;
}

int main() {
    std::vector<std::string> inputs = {"10", "abc", "25", "64", "-1"};
    for (const auto &line : inputs) {
        int v = load_config_NC(line);
        std::cout << "[NC] active config = " << v << '\n';
    }
    return 0;
}