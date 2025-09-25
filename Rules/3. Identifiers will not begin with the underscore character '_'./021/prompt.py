PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 17-0-1:
  "Reserved identifiers, macros and functions in the Standard Library shall not be defined, redefined or undefined."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: int _sensorReading;   // Compliant: int sensorReading;

CONTEXT:
Sensor data class used in a DRDO environmental monitoring system. Produce two self-contained .cpp files (NC and C), ~45-55 lines each, that compile with:
  g++ -std=c++17 -Wall -Wextra -pedantic

CONSTRAINT:
The ONLY substantive textual difference between NC and C must be the class member identifier `_sensorReading` → `sensorReading`. Do not rename other functions, change control flow, or alter formatting (aside from NC/C header markers and allowed NC/C log prefixes).

VIOLATION (class member):
Using a class member identifier beginning with '_' (leading underscore) may be reserved by the implementation — this violates MISRA C++:2008 Rule 17-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).
- C++ standard / cppreference — identifier reservation rules (leading underscore / double underscore).
- clang-tidy `bugprone-reserved-identifier` — tooling guidance on reserved identifiers.
- StackOverflow Q&A: rules about using an underscore in a C++ identifier.
- SEI/CERT DCL51 guidance on reserved identifiers.

VALIDATION HINTS (exact commands):
1. Compile both files:
   g++ -std=c++17 -Wall -Wextra -pedantic pair21_nc.cpp -o pair21_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair21_c.cpp -o pair21_c
2. NC must contain `_sensorReading`:
   grep -E '\b_sensorReading\b' pair21_nc.cpp
3. C must contain `sensorReading` and must NOT contain `_sensorReading`:
   grep -E '\bsensorReading\b' pair21_c.cpp
   ! grep -E '\b_sensorReading\b' pair21_c.cpp
4. `diff -u pair21_nc.cpp pair21_c.cpp` should show only `_sensorReading` → `sensorReading`.

END.
'''