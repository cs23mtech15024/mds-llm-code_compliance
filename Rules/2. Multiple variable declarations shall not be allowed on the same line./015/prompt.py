# prompt_pair15.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: uint32_t mask = 0u, flags = 0u;   // Compliant: uint32_t mask = 0u; uint32_t flags = 0u;

CONTEXT:
Access-control mask and flags for a DRDO security module. Create a realistic ~45–55 line example that initializes a small access table, applies mask/flags to simulated entries, logs deterministic output to a file, and prints a summary. The NC/C files must be identical except for splitting the multi-declaration.

VIOLATION (single line):
Declaring multiple variables in the same declaration (e.g., `uint32_t mask = 0u, flags = 0u;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCES (include one-line citations in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list must be single).  [oai_citation:1‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)  
- SEI CERT — DCL04-C: Do not declare more than one variable per declaration.  [oai_citation:2‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

REQUIREMENTS:
- Produce two labelled code blocks in this order:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (use only standard headers).
- Target size: ~45–55 lines per file.
- **Only** substantive edit allowed between NC and C: split the multi-declaration into separate declarations.
- Avoid undefined behaviour; keep behavior deterministic and testable.

VALIDATION HINTS:
1. NC must contain the exact seed `uint32_t mask = 0u, flags = 0u;`.
2. C must not contain that seed and must contain `uint32_t mask = 0u;` and `uint32_t flags = 0u;`.
3. Both files must compile with the flags above.
4. `diff -u nc.cpp c.cpp` should show only the declaration line(s) split.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation of the change and the MISRA rule satisfied.
END.
'''