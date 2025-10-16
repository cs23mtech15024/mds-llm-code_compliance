# prompt_pair3_ident_underscore_buffer.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: size_t _bufferSize = 1024;   // Compliant: size_t bufferSize = 1024;

CONTEXT:
IO / buffering helper in DRDO data path. Produce two self-contained .cpp files (NC and C), ~45–55 lines each, compiling with:
  g++ -std=c++17 -Wall -Wextra -pedantic
The ONLY substantive textual difference between NC and C must be the identifier `_bufferSize` → `bufferSize`. Do not rename other functions or change control flow or formatting (except NC/C header marker comments).

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).  
- C++ standard / cppreference — identifiers and reserved names (leading underscore / double underscore).  
- PVS-Studio guidance — identifiers starting with '__' or '_[A-Z]' are reserved.  
- Example GitHub usage showing `_bufferSize` variable in real projects (seed inspiration).

VALIDATION HINTS (exact):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic nc.cpp -o nc_test
   g++ -std=c++17 -Wall -Wextra -pedantic c.cpp -o c_test
2. NC must contain `_bufferSize`:
   grep -E '\b_bufferSize\b' nc.cpp
3. C must contain `bufferSize` and must NOT contain `_bufferSize`:
   grep -E '\bbufferSize\b' c.cpp
   ! grep -E '\b_bufferSize\b' c.cpp
4. diff -u nc.cpp c.cpp should show only `_bufferSize` → `bufferSize`.

END.
'''