// ------ Compliant
// Seed: Non-compliant: int _configParam = 42;   // Compliant: int configParam = 42;
// Context: Configuration parameter loader and validator in a DRDO subsystem.
// Compliance: identifier renamed to avoid leading underscore — complies with MISRA C++:2008 Rule 17-0-1.
// Sources: MathWorks / Polyspace (MISRA 17-0-1).  [oai_citation:12‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)
//          C++ standard / cppreference (identifier reservation rules).  [oai_citation:13‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)
//          clang-tidy bugprone-reserved-identifier (tool guidance).  [oai_citation:14‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)
//          StackOverflow Q&A on underscore rules.  [oai_citation:15‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)
//          Microsoft "Old New Thing" blog (reserved identifiers).  [oai_citation:16‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)
//          LLVM/GitHub reserved-identifier discussion.  [oai_citation:17‡GitHub](https://github.com/llvm/llvm-project/issues/62650?utm_source=chatgpt.com)

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// Compliant loader: same logic, identifier without leading underscore
int load_config_C(const std::string &cfgLine) {
    static int configParam = 42; // COMPLIANT: no leading underscore
    std::istringstream iss(cfgLine);
    int val = 0;
    if (!(iss >> val)) {
        std::cerr << "[C] parse failed, using previous value=" << configParam << '\n';
        return configParam;
    }

    // validate: accept only multiples of 2 between 0 and 100
    if (val < 0 || val > 100 || (val % 2) != 0) {
        std::cerr << "[C] invalid config value " << val << " — ignoring\n";
        return configParam;
    }

    // update persistent config parameter
    configParam = val;

    std::cout << "[C] config updated to " << configParam << '\n';
    return configParam;
}

int main() {
    std::vector<std::string> inputs = {"10", "abc", "25", "64", "-1"};
    for (const auto &line : inputs) {
        int v = load_config_C(line);
        std::cout << "[C] active config = " << v << '\n';
    }
    return 0;
}