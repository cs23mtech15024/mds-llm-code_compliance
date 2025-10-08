// ------ Compliant
// Seed: Non-compliant header: std::string configPath = "cfg.txt";   // Compliant header: extern std::string configPath;
// Context: Header contains only declarations; definitions are moved to implementation.
// Source (provenance): StackOverflow Q#1433204 - "How do I use extern to share variables between source files?" 
//                   : PVS-Studio / Klocwork documentation on MISRA C++:2008 Rule 8-5-2 ("Header files shall contain only declarations and macros"). 
// Compliance: Header contains only declarations (extern + prototype); definitions are in implementation section.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations
//
// Seed (header declaration): extern std::string configPath;
extern std::string configPath; // declaration only
void load_config(std::vector<std::string> &out); // prototype only
// ---------------------------------------------------------------------------

// Implementation section (compliant)
std::string configPath = "cfg.txt"; // COMPLIANT: definition in implementation file

void load_config(std::vector<std::string> &out) {
    std::istringstream iss(configPath);
    std::string token;
    while (std::getline(iss, token, ';')) {
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        if (!token.empty()) out.push_back(token);
    }
}

int main() {
    std::vector<std::string> cfg;
    load_config(cfg);
    std::cout << "[C] configPath='" << configPath << "'\n";
    for (size_t i = 0; i < cfg.size(); ++i) {
        std::cout << "[C] entry[" << i << "]=" << cfg[i] << '\n';
    }
    return 0;
}