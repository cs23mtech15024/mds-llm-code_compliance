PROMPT = r'''
SYSTEM:
You are an expert C++ programmer creating configuration management code for DRDO.

TASK:
Generate a pair of C++ programs demonstrating MISRA C++:2008 Rule 8-0-1 in a configuration loader context.

REQUIRED STRUCTURE:
void config_load_X(const std::string &src = "") {
    // Non-compliant: std::string s1, s2;
    // Compliant:    std::string s1;
    //               std::string s2;
    // Configuration parsing implementation
}

CONTEXT:
- Configuration loader for DRDO system
- Key-value pair parsing
- Configuration validation
- Result logging
- Error handling

REQUIREMENTS:
- Standard headers only
- Configuration parsing logic
- Validation checks
- Log file output
- ~50 lines per file

VALIDATION:
1. Must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
2. Identical functionality between versions
3. Clear documentation
4. Source citation

SOURCE:
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1
'''