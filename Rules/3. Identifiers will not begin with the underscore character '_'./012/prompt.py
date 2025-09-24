# prompt_pair12_ident_underscore_controlgain.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: double _controlGain = 1.5;   // Compliant: double controlGain = 1.5;

CONTEXT:
PID control helper used in a DRDO guidance subsystem. Produce two self-contained .cpp files (NC and C), ~45–55 lines each, that compile with:
  g++ -std=c++17 -Wall -Wextra -pedantic
The ONLY substantive textual difference between NC and C must be `_controlGain` → `controlGain`. Do not rename other functions, change control flow, or alter formatting (except permitted NC/C header markers).

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include these in file header comments):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).  [oai_citation:1‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- C++ standard / cppreference — identifier reservation rules (leading underscore / double underscore).  [oai_citation:2‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)  
- clang-tidy `bugprone-reserved-identifier` — tooling guidance on reserved identifiers.  [oai_citation:3‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)  
- StackOverflow Q&A: rules about using an underscore in a C/C++ identifier.  [oai_citation:4‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- Microsoft “Old New Thing” blog — reserved identifier guidance and rationale.  [oai_citation:5‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)

VALIDATION HINTS (exact commands):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic nc.cpp -o nc_test
   g++ -std=c++17 -Wall -Wextra -pedantic c.cpp -o c_test
2. NC must contain `_controlGain`:
   grep -E '\b_controlGain\b' nc.cpp
3. C must contain `controlGain` and must NOT contain `_controlGain`:
   grep -E '\bcontrolGain\b' c.cpp
   ! grep -E '\b_controlGain\b' c.cpp
4. `diff -u nc.cpp c.cpp` should show only `_controlGain` → `controlGain`.

END.
'''