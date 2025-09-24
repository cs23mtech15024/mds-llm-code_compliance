# prompt_pair16_ident_underscore_internalstate.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: int _internalState = 0;   // Compliant: int internalState = 0;

CONTEXT:
State tracking helper used in a DRDO embedded controller module (deterministic demo). Produce two self-contained `.cpp` files (NC and C), ~45–55 lines each, that compile with:
  g++ -std=c++17 -Wall -Wextra -pedantic

CONSTRAINT:
The ONLY substantive textual difference between NC and C must be `_internalState` → `internalState`. Do not rename other functions, change control flow or formatting (aside from NC/C header markers and allowed log prefixes).

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1.  [oai_citation:0‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- C++ standard / cppreference — identifiers and reserved names (leading underscores/double underscores).  [oai_citation:1‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)  
- clang-tidy `bugprone-reserved-identifier` — tool guidance on reserved identifiers.  [oai_citation:2‡Clang](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)  
- StackOverflow — community Q&A: rules about using an underscore in a C++ identifier.  [oai_citation:3‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- PVS-Studio guidance — identifiers that start with '__' or '_[A-Z]' are reserved.  [oai_citation:4‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)

VALIDATION HINTS (exact commands):
1. Compile:
   g++ -std=c++17 -Wall -Wextra -pedantic nc.cpp -o nc_test
   g++ -std=c++17 -Wall -Wextra -pedantic c.cpp -o c_test
2. NC must contain `_internalState`:
   grep -E '\b_internalState\b' nc.cpp
3. C must contain `internalState` and must NOT contain `_internalState`:
   grep -E '\binternalState\b' c.cpp
   ! grep -E '\b_internalState\b' c.cpp
4. `diff -u nc.cpp c.cpp` should show only `_internalState` → `internalState`.

END.
'''