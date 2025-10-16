PROMPT = r'''
SYSTEM:
You are an expert C++ programmer implementing communication handlers for DRDO.

TASK:
Generate a pair of C++ programs demonstrating MISRA C++:2008 Rule 8-0-1 with pointer/non-pointer declarations.

REQUIRED STRUCTURE:
void comm_handler_X() {
    // Non-compliant: int *p, q;
    // Compliant:    int *p;
    //               int q;
    // Buffer processing implementation
}

CONTEXT:
- DRDO communication handler
- Buffer pointer and size management
- Processing function implementation
- Result logging
- Error handling

REQUIREMENTS:
- Standard headers only
- Buffer processing logic
- Logging functionality
- Deterministic behavior
- ~50 lines per file
- No undefined behavior with pointers

VALIDATION:
1. Must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
2. Identical functionality between versions
3. Clear documentation
4. Source citation

SOURCE:
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1
'''