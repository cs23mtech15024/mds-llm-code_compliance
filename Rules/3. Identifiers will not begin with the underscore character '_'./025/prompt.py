# prompt_pair25_namespace.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: int _internalConfig = 0;   // Compliant: int internalConfig = 0;

CONTEXT:
Internal configuration variable used within a DRDO cryptographic utilities namespace. Produce two self-contained .cpp files (NC and C), ~45-55 lines each, that compile with:
  g++ -std=c++17 -Wall -Wextra -pedantic

CONSTRAINT:
The ONLY substantive textual difference between NC and C must be the namespace-scoped identifier `_internalConfig` → `internalConfig`. Do not rename other functions, change control flow, or alter formatting (aside from NC/C header markers and allowed NC/C log prefixes).

VIOLATION (namespace-scoped identifier):
Using a namespace-scoped identifier beginning with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).
- C++ standard / cppreference — identifier reservation rules (leading underscore / double underscore).
- clang-tidy `bugprone-reserved-identifier` — tooling guidance on reserved identifiers.
- StackOverflow Q&A: rules about using an underscore in a C++ identifier.
- SEI/CERT DCL51 guidance on reserved identifiers.

VALIDATION HINTS (exact commands):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic pair25_nc.cpp -o pair25_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair25_c.cpp -o pair25_c
2. NC must contain `_internalConfig`:
   grep -E '\b_internalConfig\b' pair25_nc.cpp
3. C must contain `internalConfig` and must NOT contain `_internalConfig`:
   grep -E '\binternalConfig\b' pair25_c.cpp
   ! grep -E '\b_internalConfig\b' pair25_c.cpp
4. `diff -u pair25_nc.cpp pair25_c.cpp` should show only `_internalConfig` → `internalConfig`.

END.
'''