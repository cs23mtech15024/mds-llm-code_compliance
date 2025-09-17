# prompt_pair11.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: char c1 = 'A', c2 = 'B';   // Compliant: char c1 = 'A'; char c2 = 'B';

CONTEXT:
Header/flag characters used in DRDO packet framing — implement a deterministic small routine that inspects and counts header characters in a static buffer, logs results to a file, and prints a summary. Keep example realistic (~45–55 lines) and deterministic.

VIOLATION (single line):
Declaring multiple variables in one declaration (e.g., `char c1 = 'A', c2 = 'B';`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCE (include in file header):
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list must be single).  [oai_citation:1‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)  
(SEI CERT also recommends one declaration per variable for clarity in mixed declarations).  [oai_citation:2‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

REQUIREMENTS:
- Output two labelled code blocks **in this order**:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (use only standard headers).
- Target size: ~45–55 lines per file.
- **Only** substantive change allowed between NC and C: split the multi-declaration into separate declarations. Do not rename variables, change logic, or alter comments (except NC/C markers).
- Avoid undefined behaviour; keep code deterministic and testable.

VALIDATION HINTS:
1. NC must contain the exact seed `char c1 = 'A', c2 = 'B';`.
2. C must not contain that seed and must contain `char c1 = 'A';` and `char c2 = 'B';`.
3. Both files must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration line(s) split.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the changed line(s) and the MISRA rule satisfied.
END.
'''