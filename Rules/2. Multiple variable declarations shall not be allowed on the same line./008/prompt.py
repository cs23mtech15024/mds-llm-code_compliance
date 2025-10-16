# prompt_pair08.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: Point p1, p2;   // Compliant: Point p1; Point p2;

CONTEXT:
Waypoint points for mission planning in a DRDO subsystem. Provide a realistic ~45–55 line example that constructs waypoints, computes pairwise distances, and logs a small summary. Use deterministic inputs and only standard headers.

VIOLATION (single line):
Declaring multiple objects of the same type in a single declaration (e.g., `Point p1, p2;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCE (include one-line citation in file headers):
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 and community style guidance (e.g., StackOverflow) for readability/version-control concerns.  [oai_citation:0‡it.mathworks.com](https://it.mathworks.com/help/bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

REQUIREMENTS:
- Produce two labelled code blocks in this order:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (use only standard headers).
- Target size: ~45–55 lines per file.
- The **only** substantive textual/semantic difference allowed between NC and C is splitting the multi-declaration into separate declarations. Do not change identifiers, algorithm, control flow, comments (except NC/C markers), or behaviour.
- Avoid undefined behaviour; keep logic deterministic and testable.

VALIDATION HINTS:
1. NC file must contain the exact seed `Point p1, p2;`.
2. C file must **not** contain that seed and must contain `Point p1;` and `Point p2;`.
3. Both files must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration line(s) split.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the changed line(s) and the MISRA rule satisfied.
END.
'''