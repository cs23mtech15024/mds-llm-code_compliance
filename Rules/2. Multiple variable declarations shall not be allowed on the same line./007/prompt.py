# prompt_pair07.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: std::vector<int> a, b;   // Compliant: std::vector<int> a; std::vector<int> b;

CONTEXT:
Packet buffers for two channels in a DRDO comm subsystem. Write a ~45–55 line deterministic example that fills two buffers, merges or inspects them, logs counts, and produces deterministic output.

VIOLATION (single line):
Declaring multiple variables in the same declaration (e.g., `std::vector<int> a, b;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCE (include one-line citation in file headers):
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list must be single).  [oai_citation:1‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

REQUIREMENTS:
- Output two labelled code blocks in this order:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (use only standard headers).
- Target size: ~45–55 lines per file.
- **Only** change: split the multi-declaration into separate declarations between NC and C. Do not alter names, algorithms, control flow, or other comments except to mark NC/C.
- Avoid undefined behaviour; make code deterministic and testable.

VALIDATION HINTS:
1. NC must contain `std::vector<int> a, b;`.
2. C must not contain that seed and must contain `std::vector<int> a;` and `std::vector<int> b;`.
3. Both files must compile with the provided flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration line(s) split.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the changed line(s) and the MISRA rule satisfied.
END.
'''