# prompt_pair05.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: int a = 1, b = 2, c = 3;   // Compliant: int a = 1; int b = 2; int c = 3;

CONTEXT:
Calibration constants for DRDO sensor driver. Provide a realistic ~45–55 line example that initializes constants, runs a deterministic calibration routine over sample data, logs per-step results to a file and prints final stats.

VIOLATION (single line):
Declaring more than one variable in a single declaration (e.g., `int a = 1, b = 2, c = 3;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCE (include one-line citation in file headers):
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list/member-declarator-list must be single).  [oai_citation:1‡MathWorks](https://it.mathworks.com/help/bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

REQUIREMENTS:
- Produce two labelled code blocks in this order:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (only standard headers).
- Target size: ~45–55 lines per file.
- The **only substantive** difference between NC and C must be splitting the multi-declaration into separate declarations (no renames, no logic changes, no other edits except NC/C markers).
- Avoid undefined behaviour; keep code deterministic and testable.

VALIDATION HINTS:
1. NC must contain the exact seed `int a = 1, b = 2, c = 3;`.
2. C must **not** contain that seed and must contain `int a = 1; int b = 2; int c = 3;`.
3. Both files must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration line split.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the changed line(s) and the MISRA rule satisfied.
END.
'''