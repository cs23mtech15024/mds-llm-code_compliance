# prompt_pair2_ident_underscore.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: static int _index = 0;   // Compliant: static int index = 0;

CONTEXT:
Packet parser loop in a DRDO telemetry module. Produce two self-contained .cpp files (NC and C), ~45–55 lines, compile with:
  g++ -std=c++17 -Wall -Wextra -pedantic
The ONLY substantive textual difference between NC and C must be `_index` → `index`. Keep all other identifiers, behavior, comments and formatting identical (aside from NC/C header markers).

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1.  [oai_citation:15‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- C++ standard / cppreference (identifiers, reserved names).  [oai_citation:16‡en.cppreference.com](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)  
- StackOverflow explanation of underscore rules.  [oai_citation:17‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- PVS-Studio guidance (reserved identifiers).  [oai_citation:18‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)  
- Microsoft “Old New Thing” blog (reserved identifiers).  [oai_citation:19‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)

VALIDATION HINTS (exact):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic nc.cpp -o nc_test
   g++ -std=c++17 -Wall -Wextra -pedantic c.cpp -o c_test
2. NC must contain `_index`:
   grep -E '\b_index\b' nc.cpp
3. C must contain `index` and must NOT contain `_index`:
   grep -E '\bindex\b' c.cpp
   ! grep -E '\b_index\b' c.cpp
4. `diff -u nc.cpp c.cpp` should show only `_index` → `index`.

END.
'''