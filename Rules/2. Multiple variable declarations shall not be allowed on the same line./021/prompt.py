# prompt_pair21.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: class Sensor { int status, error; };   // Compliant: class Sensor { int status; int error; };

CONTEXT:
Class member declarations for a DRDO sensor object. Create a realistic ~45–55 line example that defines a Sensor class, uses member variables in deterministic initialization/diagnostic code, logs results to a file, and prints deterministic summary data.

VIOLATION (one line):
Declaring multiple class members in the same member-declarator-list (e.g., `int status, error;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCE (one-line, include in file headers):
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (member-declarator-list must consist of a single member-declarator).  [oai_citation:1‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
Also consider SEI CERT guidance discouraging multi-declarations for clarity.  [oai_citation:2‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

REQUIREMENTS:
- Output two labelled code blocks in this order:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (use only standard headers).
- Target size: ~45–55 lines per file.
- The ONLY substantive difference between NC and C must be splitting the class member declaration (no renames, no algorithm changes).
- Avoid undefined behaviour; keep logic deterministic and testable.

VALIDATION HINTS:
1. NC must contain the exact seed `int status, error;` in a class member declaration.
2. C must **not** contain the seed and must contain `int status;` and `int error;`.
3. Both files must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration change.

END.
'''