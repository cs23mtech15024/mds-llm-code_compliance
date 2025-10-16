PROMPT = r'''
SYSTEM:
You are an expert C++ programmer creating telemetry system code for DRDO.

TASK:
Generate a pair of C++ programs demonstrating MISRA C++:2008 Rule 8-0-1 in a telemetry counter context.

REQUIRED STRUCTURE:
void telemetry_aggregate_X(const std::string &logfile) {
    // Non-compliant: int a, b;
    // Compliant:    int a;
    //              int b;
    // Counter implementation
}

CONTEXT:
- Telemetry counter implementation
- Sample aggregation
- Log file output
- Error handling
- Statistics computation

REQUIREMENTS:
- Standard headers only
- Deterministic behavior
- Clear violation example
- Proper error handling
- ~50 lines per file

VALIDATION:
1. Must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
2. Identical functionality between versions
3. Clear documentation
4. Source citation

SOURCE:
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1
'''