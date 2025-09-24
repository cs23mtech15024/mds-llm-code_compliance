# prompt_pair13_ident_underscore_session.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: std::string _sessionKey = \"S1\";   // Compliant: std::string sessionKey = \"S1\";

CONTEXT:
Session/key handling helper for a DRDO secure communication pre-processor. Produce two self-contained .cpp files (NC and C), ~45–55 lines each, compile with:
  g++ -std=c++17 -Wall -Wextra -pedantic

CONSTRAINT:
The ONLY substantive textual difference between NC and C must be the identifier `_sessionKey` → `sessionKey`. Do not rename other functions or change control flow; keep formatting identical except NC/C header markers and allowed log prefixes.

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) in program/static/global scope may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).  [oai_citation:0‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- C++ standard / cppreference — identifier reservation rules (leading underscore / double underscore).  [oai_citation:1‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)  
- clang-tidy `bugprone-reserved-identifier` — tooling guidance on reserved identifiers.  [oai_citation:2‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)  
- StackOverflow — what are the rules about using an underscore in a C++ identifier?  [oai_citation:3‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- Microsoft “Old New Thing” — notes on names reserved by the C and C++ languages.  [oai_citation:4‡Microsoft for Developers](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685&utm_source=chatgpt.com)

VALIDATION HINTS (exact):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic nc.cpp -o nc_test
   g++ -std=c++17 -Wall -Wextra -pedantic c.cpp -o c_test
2. NC must contain `_sessionKey`:
   grep -E '\b_sessionKey\b' nc.cpp
3. C must contain `sessionKey` and must NOT contain `_sessionKey`:
   grep -E '\bsessionKey\b' c.cpp
   ! grep -E '\b_sessionKey\b' c.cpp
4. `diff -u nc.cpp c.cpp` should show only `_sessionKey` → `sessionKey`.

END.
'''