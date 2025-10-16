// ------ Non-Compliant
// Seed: Non-compliant header: std::string configPath = "cfg.txt";   // Compliant header: extern std::string configPath;
// Context: Header incorrectly contains a non-const string definition and a function definition.
// Source (provenance): StackOverflow Q#1433204 - "How do I use extern to share variables between source files?" 
//                   : PVS-Studio / Klocwork documentation on MISRA C++:2008 Rule 8-5-2 ("Header files shall contain only declarations and macros"). 
// Violation: Header defines a non-const global variable and a non-inline function.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): std::string configPath = "cfg.txt";
std::string configPath = "cfg.txt"; // NON-COMPLIANT: non-const variable defined in header

// NON-COMPLIANT: function defined directly in header
void load_config(std::vector<std::string> &out) {
    std::istringstream iss(configPath);
    std::string token;
    while (std::getline(iss, token, ';')) {
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        if (!token.empty()) out.push_back(token);
    }
}
// ---------------------------------------------------------------------------

int main() {
    std::vector<std::string> cfg;
    load_config(cfg);
    std::cout << "[NC] configPath='" << configPath << "'\n";
    for (size_t i = 0; i < cfg.size(); ++i) {
        std::cout << "[NC] entry[" << i << "]=" << cfg[i] << '\n';
    }
    return 0;
}