# prompt_pair14_ident_underscore_timeoutvalue.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: int _timeoutValue = 500;   // Compliant: int timeoutValue = 500;

CONTEXT:
Timeout configuration helper in a DRDO comms module that manages retry/backoff intervals. Produce two self-contained `.cpp` files (NC and C), ~45-55 lines each, compiled with:
  g++ -std=c++17 -Wall -Wextra -pedantic

CONSTRAINT:
The **only** substantive textual difference between NC and C must be the identifier `_timeoutValue` → `timeoutValue`. Do not rename other functions, change control flow, or alter formatting except allowed NC/C header comment markers and log‐prefixes.

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).  [oai_citation:4‡MathWorks](https://kr.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- C++ standard / cppreference — identifier reservation rules (leading underscore / uppercase / double underscores).  [oai_citation:5‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- Microsoft “Old New Thing” — reserved identifier guidance.  [oai_citation:6‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)  
- StackOverflow: rules about underscores in identifiers.  [oai_citation:7‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  

VALIDATION HINTS (exact commands):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic nc.cpp -o nc_test
   g++ -std=c++17 -Wall -Wextra -pedantic c.cpp -o c_test
2. NC must contain `_timeoutValue`:
   grep -E '\b_timeoutValue\b' nc.cpp
3. C must contain `timeoutValue` and must NOT contain `_timeoutValue`:
   grep -E '\btimeoutValue\b' c.cpp
   ! grep -E '\b_timeoutValue\b' c.cpp
4. `diff -u nc.cpp c.cpp` should show only the identifier change (`_timeoutValue` → `timeoutValue`).

END.
'''