# prompt_pair22.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: struct Reg { unsigned flags:3, mode:5; };   // Compliant: struct Reg { unsigned flags:3; unsigned mode:5; };

CONTEXT:
Hardware register bit-field declarations in an embedded DRDO module. Provide a realistic ~45–55 line example that defines a struct with two bit-fields, populates instances deterministically, computes/prints combined values and logs results. Keep NC and C versions identical except for splitting the member-declarator-list.

VIOLATION (one line):
Declaring multiple bit-field members in one member-declarator-list (e.g., `unsigned flags:3, mode:5;`) — violates MISRA C++:2008 Rule 8-0-1 (applies to member-declarator-lists).

SOURCES (include in file headers):
- MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (member-declarator-list must be single).  [oai_citation:1‡es.mathworks.com](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)  
- SEI CERT / C community guidance: bit-fields are implementation-defined and care should be taken; prefer explicit signedness and clear declarations.  [oai_citation:2‡SEI Wiki](https://wiki.sei.cmu.edu/confluence/display/c/EXP11-C.%2BDo%2Bnot%2Bmake%2Bassumptions%2Bregarding%2Bthe%2Blayout%2Bof%2Bstructures%2Bwith%2Bbit-fields?utm_source=chatgpt.com)

REQUIREMENTS:
- Output two labelled code blocks in this order:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (use only standard headers).
- Target size: ~45–55 lines per file.
- The ONLY substantive difference between NC and C is splitting the multi-member declaration into separate declarations. Do not change names, algorithms, or comments except to mark NC/C and the seed.
- Avoid undefined behaviour; use unsigned bit-fields and deterministic operations.

VALIDATION HINTS:
1. NC must contain the exact seed `unsigned flags:3, mode:5;`.
2. C must **not** contain that seed and must contain `unsigned flags:3;` and `unsigned mode:5;`.
3. Both files must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration change.

END.
'''