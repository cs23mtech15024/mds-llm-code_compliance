# prompt_pair4_ident_underscore_timeout.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: unsigned _timeout_ms = 1000;   // Compliant: unsigned timeout_ms = 1000;

CONTEXT:
A mission-control watchdog timeout helper in a DRDO subsystem. Produce two self-contained `.cpp` files (NC and C), ~45–55 lines each, that compile with:
  g++ -std=c++17 -Wall -Wextra -pedantic
The ONLY substantive textual difference between NC and C must be the identifier `_timeout_ms` -> `timeout_ms`. Do not rename other functions, change behavior, or alter formatting (except NC/C header markers).

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) may be reserved by the implementation and thus violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).  [oai_citation:6‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- C++ Standard / cppreference — identifier reservation rules (double underscore, leading underscore + uppercase).  [oai_citation:7‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)  
- StackOverflow — explanation of underscore rules.  [oai_citation:8‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- Microsoft “Old New Thing” blog — reserved identifier rationale.  [oai_citation:9‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)  
- clang-tidy `bugprone-reserved-identifier` docs — tooling guidance.  [oai_citation:10‡clang.llvm.org](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)  
- Example GitHub usage showing `_timeout`-style variables (seed inspiration).  [oai_citation:11‡GitHub](https://github.com/activepieces/activepieces/pull/225.patch?utm_source=chatgpt.com)

VALIDATION HINTS (exact):
1. `g++ -std=c++17 -Wall -Wextra -pedantic nc.cpp -o nc_test` and similarly for `c.cpp` must compile with exit code 0.
2. `grep -E '\b_timeout_ms\b' nc.cpp` must succeed (NC must contain `_timeout_ms`).
3. `grep -E '\btimeout_ms\b' c.cpp` must succeed AND `grep -E '\b_timeout_ms\b' c.cpp` must fail (C must not contain `_timeout_ms`).
4. `diff -u nc.cpp c.cpp` should show only the identifier change (`_timeout_ms` → `timeout_ms`) and no other identifier renames or formatting changes.

END.
'''