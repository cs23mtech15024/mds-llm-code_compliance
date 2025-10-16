# prompt_pair20.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: volatile uint32_t regA = 0u, regB = 0u;   // Compliant: volatile uint32_t regA = 0u; volatile uint32_t regB = 0u;

CONTEXT:
Simulated memory-mapped register handling for DRDO embedded control: prepare two volatile register variables, apply deterministic writes/masks to them, log steps to a file and print a final summary. Provide a realistic ~45–55 line example that is deterministic, safe, and compiles with g++ -std=c++17 -Wall -Wextra -pedantic.

VIOLATION (single line):
Declaring multiple volatile register variables in one declaration (e.g., `volatile uint32_t regA = 0u, regB = 0u;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCE (one-line each; include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (single declarator per declaration).  [oai_citation:1‡MathWorks](https://it.mathworks.com/help/bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)  
- SEI CERT — DCL04-C: Do not declare more than one variable per declaration.  [oai_citation:2‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

REQUIREMENTS:
- Produce two labelled code blocks in this order:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (use only standard headers).
- Target size: ~45–55 lines per file.
- The **only** substantive textual/semantic difference between NC and C must be splitting the multi-declaration into separate declarations. Do not rename functions, variables (except to mark NC/C), algorithms, or comments except for NC/C markers and the seed comment.
- Avoid undefined behaviour; initialize before use, bounds-check, deterministic outputs.

VALIDATION HINTS:
1. NC must contain the exact seed `volatile uint32_t regA = 0u, regB = 0u;`.
2. C must contain `volatile uint32_t regA = 0u; volatile uint32_t regB = 0u;` and **not** the NC seed.
3. Both files must compile with the provided flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration line split.

END.
'''