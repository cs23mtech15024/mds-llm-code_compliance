# prompt_pair7_ident_underscore_state.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: int _state = 0;   // Compliant: int state = 0;

CONTEXT:
Small state-machine helper used in a DRDO control subsystem (deterministic transitions and logging). Produce two self-contained .cpp files (NC and C), ~45–55 lines each, compilable with:
  g++ -std=c++17 -Wall -Wextra -pedantic

The ONLY substantive textual difference between NC and C must be the identifier `_state` → `state`. Do not rename other functions, do not change control flow, and keep formatting identical except for the NC/C header comment.

VIOLATION (one line):
Using an identifier that begins with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).  [oai_citation:1‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- C++ Standard / cppreference — identifier reservation rules (leading underscore / double underscore).  [oai_citation:2‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)  
- clang-tidy `bugprone-reserved-identifier` — tooling guidance.  [oai_citation:3‡clang.llvm.org](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)  
- StackOverflow — community Q&A on underscore rules in C/C++.  [oai_citation:4‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- GitHub / clang-tidy issue discussing reserved-identifier warnings.  [oai_citation:5‡GitHub](https://github.com/llvm/llvm-project/issues/62650?utm_source=chatgpt.com)

VALIDATION HINTS (exact commands):
1. `g++ -std=c++17 -Wall -Wextra -pedantic pair7_nc.cpp -o pair7_nc` (must exit 0)
2. `g++ -std=c++17 -Wall -Wextra -pedantic pair7_c.cpp -o pair7_c` (must exit 0)
3. NC must contain `_state` (grep -E '\b_state\b' pair7_nc.cpp)
4. C must contain `state` and must NOT contain `_state` (grep -E '\bstate\b' pair7_c.cpp && ! grep -E '\b_state\b' pair7_c.cpp)
5. `diff -u pair7_nc.cpp pair7_c.cpp` should show only the identifier change `_state` → `state`.

END.
'''