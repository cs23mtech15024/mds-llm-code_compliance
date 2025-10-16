// ------ Compliant
// Seed: Non-compliant: std::string s1, s2;   // Compliant: std::string s1; std::string s2;
// Context: Configuration loader in a DRDO component — parse / hold two config keys.
// Violation: Declaring multiple variables on the same line (MISRA C++:2008 Rule 8-0-1).
// Source: MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:3‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <thread>

// Minimal, deterministic config parser simulation.
// Compliant: each string is declared on its own line (single declarator per declaration).
void config_load_C(const std::string &src = "") {
    std::string s1;
    std::string s2;
    // (compliant: split declarations so each init-declarator-list has one declarator)

    std::vector<std::string> tokens;
    if (src.empty()) {
        // Simulated inline "file" of tokens
        tokens = {"HOST=drdo.local", "PORT=8080", "MODE=SAFE"};
    } else {
        // split on whitespace
        std::istringstream iss(src);
        std::string tok;
        while (iss >> tok) tokens.push_back(tok);
    }

    // Assign first two tokens (deterministic, safe for testing)
    if (tokens.size() > 0) {
        auto pos = tokens[0].find('=');
        s1 = (pos == std::string::npos) ? tokens[0] : tokens[0].substr(pos + 1);
    }
    if (tokens.size() > 1) {
        auto pos = tokens[1].find('=');
        s2 = (pos == std::string::npos) ? tokens[1] : tokens[1].substr(pos + 1);
    }

    // Validate: non-empty and simple checks
    bool ok1 = !s1.empty() && s1.find(" ") == std::string::npos;
    bool ok2 = !s2.empty() && s2.find(" ") == std::string::npos;

    // Log results to stdout and a simulated file
    std::ofstream out("config_c.log", std::ios::app);
    std::ostringstream report;
    report << std::boolalpha << "[C] cfg s1='" << s1 << "' ok=" << ok1
           << " | s2='" << s2 << "' ok=" << ok2 << '\n';

    std::cout << report.str();
    if (out) { out << report.str(); out.close(); }
    // small deterministic wait to mimic I/O latency
    std::this_thread::sleep_for(std::chrono::milliseconds(15));
}

int main() {
    // run deterministic simulation
    config_load_C();
    return 0;
}