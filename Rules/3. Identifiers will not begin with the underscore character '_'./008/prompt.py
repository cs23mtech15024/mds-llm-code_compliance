# prompt_pair8_ident_underscore_errorflag.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: bool _errorFlag = false;   // Compliant: bool errorFlag = false;

CONTEXT:
Error handling and logging helper in a DRDO diagnostics module. Produce two self-contained .cpp files (NC and C), ~45-55 lines each, that compile with:
  g++ -std=c++17 -Wall -Wextra -pedantic
The ONLY substantive textual difference between NC and C must be the identifier `_errorFlag` → `errorFlag`. Keep all other identifiers, formatting, behavior, and comments identical except NC/C header markers.

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1.  [oai_citation:5‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- C++ standard / cppreference — identifier reservation rules (leading underscore/double underscore).  [oai_citation:6‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)  
- clang-tidy check `bugprone-reserved-identifier`.  [oai_citation:7‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)  
- StackOverflow Q&A: rules about underscores in C/C++ identifiers.  [oai_citation:8‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- GitHub discussion / clang-tidy issue on reserved identifiers (tool warnings).  [oai_citation:9‡GitHub](https://github.com/llvm/llvm-project/issues/62650?utm_source=chatgpt.com)

VALIDATION HINTS (exact commands):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic nc.cpp -o nc_test
   g++ -std=c++17 -Wall -Wextra -pedantic c.cpp -o c_test
2. NC must contain `_errorFlag`:
   grep -E '\b_errorFlag\b' nc.cpp
3. C must contain `errorFlag` and must NOT contain `_errorFlag`:
   grep -E '\berrorFlag\b' c.cpp
   ! grep -E '\b_errorFlag\b' c.cpp
4. `diff -u nc.cpp c.cpp` should show only `_errorFlag` → `errorFlag` and no other identifier renames or formatting changes.

END.
'''