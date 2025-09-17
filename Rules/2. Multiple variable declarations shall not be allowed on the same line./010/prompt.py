# prompt_pair10.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: char *src = 0, c = 0;   // Compliant: char *src = 0; char c = 0;

CONTEXT:
String/byte buffer handling in a DRDO text-processing helper. Provide a realistic ~45–55 line example that fills a small buffer, uses a pointer to walk it, counts occurrences of a character, logs results, and avoids undefined behaviour (assign pointer to buffer before use). Demonstrate both NC and C variants with identical logic except for the declaration split.

VIOLATION (single line):
Declaring mixed pointer and non-pointer variables in a single declaration (e.g., `char *src = 0, c = 0;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCES (one-line each; include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list must be single).  [oai_citation:1‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
- SEI CERT — DCL04-C: Do not declare more than one variable per declaration (pointer/non-pointer example).  [oai_citation:2‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

REQUIREMENTS:
- Output two labelled code blocks **in this order**:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (use only standard headers).
- Target size: ~45–55 lines per file.
- **Only** substantive change between NC and C: split the multi-declaration into separate declarations. Do not change variable names, function names, comments (except NC/C markers), algorithms, or behaviour.
- Avoid undefined behaviour: ensure pointer is assigned before dereference; use deterministic buffers and no dynamic allocations.

VALIDATION HINTS:
1. NC must contain the exact seed `char *src = 0, c = 0;`.
2. C must not contain that seed and must contain `char *src = 0;` and `char c = 0;`.
3. Both files must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration line split.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation of the change and the rule satisfied.
END.
'''