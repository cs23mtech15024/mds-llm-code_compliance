# prompt_pair16.py
PROMPT = """
SYSTEM:
You are an expert C++ programmer and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK (Pair 16 — literal suffix uppercase):
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating the rule:
  "Literal suffixes shall be upper case" (MISRA C++ Rule 2-13-4).

Required seed (MUST appear verbatim at top of both files):
// Pair 16 — Seed: 128ul -> 128UL
// Context: Access control mask in Maya OS security module.
// Violation: lowercase 'ul' suffix inconsistent within kernel code.

REQUIREMENTS:
- Produce two labelled outputs in this order:
  1) // ------ Non-Compliant followed by a full .cpp file.
  2) // ------ Compliant followed by a full .cpp file.
- Both files must:
  - Use only standard headers, compile with: g++ -std=c++17 -Wall -Wextra -pedantic.
  - Be approximately 50 lines each (±10).
  - Contain a realistic access-control mask routine where the seed literal is used.
- The ONLY substantive textual/semantic differences allowed between NC and C:
  - Change `128ul` → `128UL` (and other suffix case changes if present).
  - Do NOT alter logic, identifiers, function names, or program structure otherwise.
- Avoid undefined behaviour; keep code deterministic and testable.

VALIDATION HINTS:
1. NC must contain the seed `128ul`; C must contain `128UL` and not `128ul`.
2. `diff -u nc.cpp c.cpp` should show only literal-case changes.

SOURCE:
- MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).
- PVS-Studio / coding-style guidance about suffix consistency.

OUTPUT:
Return the two .cpp code blocks (NC then C) and a short 1–2 sentence explanation naming the literal(s) changed and the rule(s) satisfied.
END.
"""