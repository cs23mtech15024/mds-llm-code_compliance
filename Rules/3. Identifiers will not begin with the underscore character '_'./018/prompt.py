# prompt_pair18_ident_underscore_packetid.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: unsigned _packetId = 0;   // Compliant: unsigned packetId = 0;

CONTEXT:
Packet header processing helper used in a DRDO tactical link-layer module. Produce two self-contained .cpp files (NC and C), ~45–55 lines each, that compile with:
  g++ -std=c++17 -Wall -Wextra -pedantic

CONSTRAINT:
The ONLY substantive textual difference between NC and C must be the identifier `_packetId` → `packetId`. Do not rename other functions, change control flow, or alter formatting (except NC/C header comment markers and small NC/C log prefixes).

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).  [oai_citation:4‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- cppreference — identifier reservation rules (leading underscore / double underscore).  [oai_citation:5‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)  
- StackOverflow — rules about using an underscore in a C++ identifier.  [oai_citation:6‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- PVS-Studio — guidance: identifiers starting with '__' or '_[A-Z]' are reserved.  [oai_citation:7‡PVS-Studio](https://pvs-studio.com/en/docs/manual/full/?utm_source=chatgpt.com)

VALIDATION HINTS (exact):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic pair18_nc.cpp -o pair18_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair18_c.cpp -o pair18_c
2. NC must contain `_packetId`:
   grep -E '\b_packetId\b' pair18_nc.cpp
3. C must contain `packetId` and must NOT contain `_packetId`:
   grep -E '\bpacketId\b' pair18_c.cpp
   ! grep -E '\b_packetId\b' pair18_c.cpp
4. `diff -u pair18_nc.cpp pair18_c.cpp` should show only `_packetId` → `packetId`.

END.
'''