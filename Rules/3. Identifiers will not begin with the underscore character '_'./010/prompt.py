# prompt_pair10_ident_underscore_mission.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: unsigned long _missionID = 0;   // Compliant: unsigned long missionID = 0;

CONTEXT:
Mission state initialization helper in an avionics / mission controller module (DRDO). Provide two self-contained .cpp files (NC and C), ~45–55 lines each, that compile with:
  g++ -std=c++17 -Wall -Wextra -pedantic

CONSTRAINT:
The ONLY substantive textual difference between NC and C must be the identifier `_missionID` → `missionID`. Do not rename other functions, change control flow, or alter formatting (except NC/C header markers and NC/C log prefixes).

VIOLATION (one line):
Using an identifier beginning with '_' (leading underscore) in global/static scope may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).  [oai_citation:0‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- C++ standard / cppreference — identifier reservation rules (leading underscore/double underscore).  [oai_citation:1‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)  
- StackOverflow Q&A: rules about using an underscore in a C++ identifier.  [oai_citation:2‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- PVS-Studio guidance — identifiers that start with '__' or '_[A-Z]' are reserved.  [oai_citation:3‡PVS-Studio](https://pvs-studio.com/en/docs/warnings/v2573/?utm_source=chatgpt.com)  
- GitHub (Zephyr project) — real-world discussion about avoiding reserved names in projects.  [oai_citation:4‡GitHub](https://github.com/zephyrproject-rtos/zephyr/issues/9882?utm_source=chatgpt.com)

VALIDATION HINTS (exact commands):
1. Compile:
   g++ -std=c++17 -Wall -Wextra -pedantic nc.cpp -o nc_test
   g++ -std=c++17 -Wall -Wextra -pedantic c.cpp -o c_test
2. NC must contain `_missionID`:
   grep -E '\b_missionID\b' nc.cpp
3. C must contain `missionID` and must NOT contain `_missionID`:
   grep -E '\bmissionID\b' c.cpp
   ! grep -E '\b_missionID\b' c.cpp
4. `diff -u nc.cpp c.cpp` should show only the identifier change (`_missionID` → `missionID`).

END.
'''