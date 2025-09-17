# prompt_pair09.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: int i = 0, j = 0, k = 0;   // Compliant: int i = 0; int j = 0; int k = 0;

CONTEXT:
Loop counters across three parallel processing channels in a DRDO signal-processing routine. Provide a realistic ~45–55 line example that uses the counters in deterministic loops, accumulates simple stats, writes logs, and prints a final report.

VIOLATION (single line):
Declaring multiple variables in one declaration (e.g., `int i = 0, j = 0, k = 0;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCE (include one-line citation in file headers):
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list must be single).  [oai_citation:1‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

REQUIREMENTS:
- Produce two labelled code blocks in this order:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (use only standard headers).
- Target size: ~45–55 lines per file.
- **Only** change between NC and C: split the multi-declaration into separate declarations (no renames, no logic changes, no other edits except NC/C markers).
- Avoid undefined behaviour; keep logic deterministic and testable.

VALIDATION HINTS:
1. NC must contain the exact seed `int i = 0, j = 0, k = 0;`.
2. C must NOT contain that seed but must contain `int i = 0;` `int j = 0;` and `int k = 0;`.
3. Both files must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration line split.

OUTPUT:
Return the two code blocks (NC then C) followed by a 1–2 sentence explanation naming the changed lines and the MISRA rule satisfied.
END.
'''