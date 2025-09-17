# prompt_pair13.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-0-1:
  "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively."

REQUIRED SEED (include verbatim at top of both files):
  // Seed: Non-compliant: unsigned u1 = 0u, u2 = 1u;   // Compliant: unsigned u1 = 0u; unsigned u2 = 1u;

CONTEXT:
Two unsigned counters used for packet/telemetry channel indexing in a DRDO data-collector module. Build a deterministic example (~45–55 lines) that consumes a fixed set of packet sizes, updates the two counters, logs per-iteration info to a file, and prints a final report.

VIOLATION (single line):
Declaring multiple variables in a single declaration (e.g., `unsigned u1 = 0u, u2 = 1u;`) — violates MISRA C++:2008 Rule 8-0-1.

SOURCE (include one-line citation in each file header):
MathWorks / Polyspace — MISRA C++:2008 Rule 8-0-1 (init-declarator-list must be single).  [oai_citation:1‡MathWorks](https://es.mathworks.com/help///bugfinder/ref/misrac2008rule801.html?utm_source=chatgpt.com)

REQUIREMENTS:
- Produce two labelled code blocks **in this order**:
  1) `// ------ Non-Compliant` then the full .cpp file.
  2) `// ------ Compliant` then the full .cpp file.
- Both files must be self-contained and compile with:
    g++ -std=c++17 -Wall -Wextra -pedantic
  (only standard headers).
- Target size: ~45–55 lines per file.
- The **only** substantive difference allowed between NC and C is splitting the multi-declaration into separate declarations (do not change names, algorithms, control flow or comments except to mark NC/C).
- Avoid undefined behaviour; keep behavior deterministic and testable.

VALIDATION HINTS:
1. NC file must contain the exact seed `unsigned u1 = 0u, u2 = 1u;`.
2. C file must **not** contain that seed and must contain `unsigned u1 = 0u;` and `unsigned u2 = 1u;`.
3. Both files must compile with the given flags.
4. `diff -u nc.cpp c.cpp` should show only the declaration line split.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation of what changed and the rule satisfied.
END.
'''