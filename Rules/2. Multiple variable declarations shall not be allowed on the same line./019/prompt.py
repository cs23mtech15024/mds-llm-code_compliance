# prompt_pair19.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: std::array<int,4> buf1, buf2;   // Compliant: std::array<int,4> buf1; std::array<int,4> buf2;

CONTEXT:
DMA buffer handling in a DRDO telemetry ingestion component. Provide a realistic ~45–55 line example that fills two small buffers deterministically, performs simple checksum and merging logic, logs to a file, and prints final statistics. The only substantive difference between Non-Compliant and Compliant files must be the declaration split (i.e., `std::array<int,4> buf1, buf2;` → `std::array<int,4> buf1; std::array<int,4> buf2;`).

VIOLATION (one line):
Declaring multiple variables in one declaration (e.g., `std::array<int,4> buf1, buf2;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list must be single).  [oai_citation:1‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)  
- SEI CERT — DCL04-C: Do not declare more than one variable per declaration.  [oai_citation:2‡SEI External Wiki](https://wiki.sei.cmu.edu/confluence/display/c/DCL04-C.%2BDo%2Bnot%2Bdeclare%2Bmore%2Bthan%2Bone%2Bvariable%2Bper%2Bdeclaration?utm_source=chatgpt.com)

REQUIREMENTS:
- Produce two labelled code blocks in this order:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (only standard headers).
- Target size: ~45–55 lines per file.
- **Only** substantive change between NC and C: split the multi-declaration into separate declarations.
- Avoid undefined behaviour: initialize arrays, bounds-checked loops, deterministic behavior for testing.

VALIDATION HINTS:
1. NC file must contain the exact seed `std::array<int,4> buf1, buf2;`.
2. C file must **not** contain that seed and must contain `std::array<int,4> buf1;` and `std::array<int,4> buf2;`.
3. Both files must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration line split.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the changed line(s) and the MISRA rule satisfied.
END.
'''