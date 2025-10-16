# prompt_pair12.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: bool ok = false, error = true;   // Compliant: bool ok = false; bool error = true;

CONTEXT:
Unit/health-check status flags in a DRDO instrumentation self-test routine. Create a realistic ~45–55 line example that runs deterministic checks on simulated sensors, updates two status flags, logs step-by-step results, and prints a final health summary.

VIOLATION (one line):
Declaring multiple variables in a single declaration (e.g., `bool ok = false, error = true;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCE (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1.  [oai_citation:1‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)  
- SEI CERT — DCL04-C (“Do not declare more than one variable per declaration”).  [oai_citation:2‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

REQUIREMENTS:
- Produce two labelled code blocks in this order:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (only standard headers).
- Target size: ~45–55 lines per file.
- **Only** substantive edit between NC and C: split the multi-declaration into separate declarations (no renames, no algorithmic or comment changes except NC/C markers).
- Avoid undefined behaviour; keep deterministic behavior and safe initialization.

VALIDATION HINTS:
1. NC file must contain the exact seed `bool ok = false, error = true;`.
2. C file must **not** contain that seed; must contain `bool ok = false;` and `bool error = true;`.
3. Both files must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration line(s) split.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation stating which line(s) were changed and the MISRA rule satisfied.
END.
'''