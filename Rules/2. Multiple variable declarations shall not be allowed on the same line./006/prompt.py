# prompt_pair06.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: auto x = 1, y = 2;   // Compliant: auto x = 1; auto y = 2;

CONTEXT:
Small DRDO test-harness that uses type-deduction via `auto` for counters in a deterministic loop that processes sensor-like samples. The example should be realistic (~45–55 lines), deterministic, and safe for compilation and automated testing.

VIOLATION (single line):
Declaring more than one variable in a single init-declarator-list (e.g., `auto x = 1, y = 2;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCE:
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list must be single).  [oai_citation:1‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

REQUIREMENTS:
- Produce two labelled code blocks **in this order**:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (use only standard headers).
- Target size: ~45–55 lines per file.
- **Only** split the multi-declaration into separate declarations between NC and C. Do not change variable/ function names, control flow, comments (except to mark NC/C), or algorithmic behavior.
- Avoid undefined behaviour; keep behavior deterministic and testable.

VALIDATION HINTS:
1. NC file must contain the exact seed `auto x = 1, y = 2;`.
2. C file must **not** contain the seed and must contain `auto x = 1;` and `auto y = 2;`.
3. Both files must compile with the provided flags.
4. `diff -u nc.cpp c.cpp` should show only the split declaration lines.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the changed line and the MISRA rule satisfied.
END.
'''