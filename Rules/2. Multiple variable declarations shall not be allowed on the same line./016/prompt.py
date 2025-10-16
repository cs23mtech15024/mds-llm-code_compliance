# prompt_pair16.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: float f1 = 1.0f, f2 = 2.0f;   // Compliant: float f1 = 1.0f; float f2 = 2.0f;

CONTEXT:
Two floating-point calibration factors used in a DRDO signal normalization routine. Create a realistic ~45–55 line example that reads deterministic sample values, applies the two factors in parallel computations, logs per-step results to a file, and prints final aggregates. Keep NC/C files identical except for splitting the multi-declaration.

VIOLATION (single line):
Declaring multiple variables in one declaration (e.g., `float f1 = 1.0f, f2 = 2.0f;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCES (include one-line citations in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list must be single).  [oai_citation:0‡MathWorks](https://it.mathworks.com/help/bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)  
- SEI CERT — DCL04-C: Do not declare more than one variable per declaration.  [oai_citation:1‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

REQUIREMENTS:
- Output two labelled code blocks **in this order**:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (only standard headers).
- Target size: ~45–55 lines per file.
- **Only** substantive change between NC and C: split the multi-declaration into separate declarations. Do not change variable names, function names, control flow, algorithm, or comments except NC/C markers.
- Avoid undefined behaviour; use deterministic inputs and safe operations.

VALIDATION HINTS:
1. NC file must contain the exact seed `float f1 = 1.0f, f2 = 2.0f;`.
2. C file must not contain that seed and must contain `float f1 = 1.0f;` and `float f2 = 2.0f;`.
3. Both files must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration line split.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation of what changed and the MISRA rule satisfied.
END.
'''