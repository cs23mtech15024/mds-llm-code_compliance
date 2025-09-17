# prompt_pair17.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: std::unique_ptr<int> r1, r2;   // Compliant: std::unique_ptr<int> r1; std::unique_ptr<int> r2;

CONTEXT:
Resource holders using std::unique_ptr in a DRDO platform helper. Provide a realistic ~45–55 line example that creates two resources, initializes them deterministically, performs simple processing, logs results, and prints a final summary. Keep both files identical except for splitting the multi-declaration.

VIOLATION (single line):
Declaring multiple variables in a single declaration (e.g., `std::unique_ptr<int> r1, r2;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCES (one-line each; include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list must be single).  [oai_citation:1‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)
- SEI CERT — DCL04-C: Do not declare more than one variable per declaration.  [oai_citation:2‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

REQUIREMENTS:
- Produce two labelled code blocks **in this order**:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (use only standard headers).
- Target size: ~45–55 lines per file.
- **Only** substantive edit between NC and C: split the multi-declaration into separate declarations. Do not change identifiers, function names, algorithm, or comments (except NC/C markers).
- Avoid undefined behaviour; allocate unique_ptrs before dereference; keep deterministic behavior and testable.

VALIDATION HINTS:
1. NC file must contain the exact seed `std::unique_ptr<int> r1, r2;`.
2. C file must not contain that seed and must contain `std::unique_ptr<int> r1;` and `std::unique_ptr<int> r2;`.
3. Both files must compile with `g++ -std=c++17 -Wall -Wextra -pedantic`.
4. `diff -u nc.cpp c.cpp` should show only the declaration line split.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the changed line(s) and the MISRA rule satisfied.
END.
'''