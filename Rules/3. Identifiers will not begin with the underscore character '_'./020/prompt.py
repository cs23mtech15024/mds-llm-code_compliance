# prompt_pair20_ident_underscore_checksum.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: unsigned _checksum = 0u;   // Compliant: unsigned checksum = 0u;

CONTEXT:
Message integrity helper used in a DRDO telemetry link — computes a simple deterministic checksum per packet. Produce two self-contained .cpp files (NC and C), ~45–55 lines each, that compile with:
  g++ -std=c++17 -Wall -Wextra -pedantic

CONSTRAINT:
The ONLY substantive textual difference between NC and C must be the identifier `_checksum` → `checksum`. Do not rename other functions, change control flow, or alter formatting (aside from NC/C header markers and allowed NC/C log prefixes).

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).  [oai_citation:1‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- cppreference — C++ identifier reservation rules (double underscore, underscore + uppercase).  [oai_citation:2‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)  
- PVS-Studio note: identifiers that start with '__' or '_[A-Z]' are reserved.  [oai_citation:3‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)  
- StackOverflow Q&A: rules about using an underscore in a C++ identifier.  [oai_citation:4‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- SEI/CERT DCL37 / DCL51 guidance on reserved identifiers.  [oai_citation:5‡wiki.sei.cmu.edu](https://wiki.sei.cmu.edu/confluence/display/cplusplus/DCL51-CPP.%2BDo%2Bnot%2Bdeclare%2Bor%2Bdefine%2Ba%2Breserved%2Bidentifier?utm_source=chatgpt.com)

VALIDATION HINTS (exact commands):
1. Compile:
   g++ -std=c++17 -Wall -Wextra -pedantic pair20_nc.cpp -o pair20_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair20_c.cpp -o pair20_c
2. NC must contain `_checksum`:
   grep -E '\b_checksum\b' pair20_nc.cpp
3. C must contain `checksum` and must NOT contain `_checksum`:
   grep -E '\bchecksum\b' pair20_c.cpp
   ! grep -E '\b_checksum\b' pair20_c.cpp
4. `diff -u pair20_nc.cpp pair20_c.cpp` should show only `_checksum` → `checksum`.

END.
'''