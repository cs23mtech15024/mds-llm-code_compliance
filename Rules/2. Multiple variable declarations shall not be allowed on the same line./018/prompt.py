# prompt_pair18.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: std::map<int,int> m1, m2;   // Compliant: std::map<int,int> m1; std::map<int,int> m2;

CONTEXT:
Two mapping tables used by a DRDO telemetry translator (channel-to-code mappings). Provide a realistic ~45–55 line example that prepares deterministic mappings, performs lookups/merges, logs results deterministically to a file, and prints a summary.

VIOLATION (single line):
Declaring multiple variables of the same complex type in one declaration (e.g., `std::map<int,int> m1, m2;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCE (include one-line citation in file headers):
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list must be single).  [oai_citation:1‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)  
(SEI CERT DCL04-C recommends one declaration per variable for clarity).  [oai_citation:2‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

REQUIREMENTS:
- Produce two labelled code blocks **in this order**:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (only standard headers).
- Target size: ~45–55 lines per file.
- The **only** substantive difference allowed between NC and C: split the multi-declaration into separate declarations (do not change names, algorithms, behavior, or other comments except to mark NC/C).
- Avoid undefined behaviour; keep logic deterministic and testable.

VALIDATION HINTS:
1. NC file must contain the exact seed `std::map<int,int> m1, m2;`.
2. C file must **not** contain that seed and must contain `std::map<int,int> m1;` and `std::map<int,int> m2;`.
3. Both files must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration line(s) split.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation of the change and the rule satisfied.
END.
'''