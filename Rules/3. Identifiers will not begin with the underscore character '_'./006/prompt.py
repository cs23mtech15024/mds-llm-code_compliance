# prompt_pair6_ident_underscore_sensor.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: double _sensorValue = 0.0;   // Compliant: double sensorValue = 0.0;

CONTEXT:
Sensor read-and-log helper in a DRDO instrumentation module. Produce two self-contained .cpp files (NC and C), ~45–55 lines each, that compile with:
  g++ -std=c++17 -Wall -Wextra -pedantic
The ONLY substantive textual difference between NC and C must be `_sensorValue` → `sensorValue`. Do not change other identifiers, function names, control flow, or formatting (except allowed NC/C header marker comments).

VIOLATION (one line):
Using an identifier that begins with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).  [oai_citation:0‡MathWorks](https://www.mathworks.com/help/bugfinder/ref/misrac2008rule1701.html?utm_source=chatgpt.com)  
- C++ Standard (identifiers page) / cppreference — identifier reservation rules.  [oai_citation:1‡Cppreference](https://en.cppreference.com/w/cpp/language/identifiers.html?utm_source=chatgpt.com)  
- clang-tidy `bugprone-reserved-identifier` — tool guidance on reserved identifier usage.  [oai_citation:2‡clang.llvm.org](https://clang.llvm.org/extra/clang-tidy/checks/bugprone/reserved-identifier.html?utm_source=chatgpt.com)  
- StackOverflow Q&A: rules about using underscores in C/C++ identifiers.  [oai_citation:3‡Stack Overflow](https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier?utm_source=chatgpt.com)  
- GitHub issue showing `_sensorValue` usage / seed inspiration (esp32-snippets issue).  [oai_citation:4‡GitHub](https://github.com/nkolban/esp32-snippets/issues/79?utm_source=chatgpt.com)

VALIDATION HINTS (exact):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic nc.cpp -o nc_test
   g++ -std=c++17 -Wall -Wextra -pedantic c.cpp -o c_test
2. NC must contain `_sensorValue`:
   grep -E '\b_sensorValue\b' nc.cpp
3. C must contain `sensorValue` and must NOT contain `_sensorValue`:
   grep -E '\bsensorValue\b' c.cpp
   ! grep -E '\b_sensorValue\b' c.cpp
4. `diff -u nc.cpp c.cpp` should show only the identifier change (`_sensorValue` → `sensorValue`).

END.
'''