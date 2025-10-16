# prompt_pair5_ident_underscore_priority.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: int _priority = 5;   // Compliant: int priority = 5;

CONTEXT:
Task scheduler helper in a DRDO real-time module. Produce two self-contained .cpp files (NC and C), ~45-55 lines each, compiling with:
  g++ -std=c++17 -Wall -Wextra -pedantic
The ONLY substantive textual difference between NC and C must be the identifier `_priority` → `priority`. Do not rename other functions or change formatting/behavior (aside from allowed NC/C header markers).

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).  [oai_citation:1‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- C++ Standard / cppreference — identifier rules (leading underscore / double underscore reserved).  [oai_citation:2‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)  
- clang-tidy bugprone-reserved-identifier — tooling guidance on reserved identifiers.  [oai_citation:3‡clang.llvm.org](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)  
- StackOverflow Q&A: rules about underscores in C/C++ identifiers.  [oai_citation:4‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- GitHub examples (seed inspiration).  [oai_citation:5‡GitHub](https://github.com/vinitjames/circularbuffer?utm_source=chatgpt.com)

VALIDATION HINTS (exact):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic nc.cpp -o nc_test
   g++ -std=c++17 -Wall -Wextra -pedantic c.cpp -o c_test
2. NC must contain `_priority`:
   grep -E '\b_priority\b' nc.cpp
3. C must contain `priority` and must NOT contain `_priority`:
   grep -E '\bpriority\b' c.cpp
   ! grep -E '\b_priority\b' c.cpp
4. diff -u nc.cpp c.cpp should show only `_priority` → `priority`.

END.
'''