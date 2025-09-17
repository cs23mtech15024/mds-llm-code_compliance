# prompt_pair02.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: double x, y;   // Compliant: double x; double y;

CONTEXT:
Guidance/trajectory helper for a DRDO mission-planning component. Provide a realistic ~45–55 line example that constructs points, computes distances between waypoints, accumulates totals and writes a small log. Use deterministic inputs.

VIOLATION (single line):
Declaring multiple member/automatic variables in one declaration (e.g., `double x, y;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCE:
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list must be single).  [oai_citation:1‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

REQUIREMENTS:
- Produce two labelled code blocks in this order:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (only standard headers).
- Target size: ~45–55 lines per file.
- **Only** split the multi-declaration into separate declarations between NC and C. Do not change function names, variable names, comments (except to mark NC/C), control flow, or algorithmic behavior.
- Avoid undefined behaviour; keep logic deterministic and testable.

VALIDATION HINTS:
1. NC file must contain the exact seed `double x, y;`.
2. C file must not contain `double x, y;` but must contain `double x;` and `double y;`.
3. Both files must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration line split.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the changed line(s) and the MISRA rule satisfied.
END.
'''