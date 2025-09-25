# prompt_pair23_function_param.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: void process(int _inputData)   // Compliant: void process(int inputData)

CONTEXT:
Data validation function used in a DRDO communication protocol handler. Produce two self-contained .cpp files (NC and C), ~45-55 lines each, that compile with:
  g++ -std=c++17 -Wall -Wextra -pedantic

CONSTRAINT:
The ONLY substantive textual difference between NC and C must be the function parameter identifier `_inputData` → `inputData`. Do not rename other functions, change control flow, or alter formatting (aside from NC/C header markers and allowed NC/C log prefixes).

VIOLATION (function parameter):
Using a function parameter identifier beginning with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).
- C++ standard / cppreference — identifier reservation rules (leading underscore / double underscore).
- clang-tidy `bugprone-reserved-identifier` — tooling guidance on reserved identifiers.
- StackOverflow Q&A: rules about using an underscore in a C++ identifier.
- SEI/CERT DCL51 guidance on reserved identifiers.

VALIDATION HINTS (exact commands):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic pair23_nc.cpp -o pair23_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair23_c.cpp -o pair23_c
2. NC must contain `_inputData`:
   grep -E '\b_inputData\b' pair23_nc.cpp
3. C must contain `inputData` and must NOT contain `_inputData`:
   grep -E '\binputData\b' pair23_c.cpp
   ! grep -E '\b_inputData\b' pair23_c.cpp
4. `diff -u pair23_nc.cpp pair23_c.cpp` should show only `_inputData` → `inputData`.

END.
'''