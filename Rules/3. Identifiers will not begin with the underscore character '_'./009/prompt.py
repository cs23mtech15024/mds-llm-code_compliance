# prompt_pair9_ident_underscore_radar.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: int _radarSignal = 0;   // Compliant: int radarSignal = 0;

CONTEXT:
Radar-signal normalization helper for a DRDO signal-processing module. Produce two self-contained .cpp files (NC and C), ~45–55 lines each, compilable with:
  g++ -std=c++17 -Wall -Wextra -pedantic

CONSTRAINT:
The ONLY substantive textual difference between NC and C must be the identifier `_radarSignal` → `radarSignal`. Do not rename other functions, change control flow, or alter formatting (except the NC/C header comment markers).

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) may be reserved by the implementation and thus violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).  [oai_citation:0‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- C++ standard / cppreference — identifier reservation rules (leading underscore / double underscore).  [oai_citation:1‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)  
- StackOverflow — explanation of underscore rules in C/C++.  [oai_citation:2‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- clang-tidy `bugprone-reserved-identifier` docs — tool guidance.  [oai_citation:3‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)  
- GitHub Gist showing radar processing examples (seed inspiration).  [oai_citation:4‡Gist](https://gist.github.com/wradlib?direction=asc&sort=updated&utm_source=chatgpt.com)

VALIDATION HINTS (exact):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic pair9_nc.cpp -o pair9_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair9_c.cpp -o pair9_c
2. NC must contain `_radarSignal`:
   grep -E '\b_radarSignal\b' pair9_nc.cpp
3. C must contain `radarSignal` and must NOT contain `_radarSignal`:
   grep -E '\bradarSignal\b' pair9_c.cpp
   ! grep -E '\b_radarSignal\b' pair9_c.cpp
4. `diff -u pair9_nc.cpp pair9_c.cpp` should show only `_radarSignal` → `radarSignal`.

END.
'''