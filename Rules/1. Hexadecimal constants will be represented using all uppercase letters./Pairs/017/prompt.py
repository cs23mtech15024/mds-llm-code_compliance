# prompt_pair17.py
PROMPT = """
SYSTEM:
You are an expert C++ programmer and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK (Pair 17 — literal suffix uppercase):
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating the rule:
  "Literal suffixes shall be upper case" (MISRA C++ Rule 2-13-4).

Required seed (MUST appear verbatim at top of both files):
// Pair 17 — Seed: 1u -> 1U
// Context: Filter threshold count for hit detection in NETRA system.
// Violation: lowercase 'u' suffix may be missed in audit.

REQUIREMENTS:
- Output two labelled results in this order:
  1) // ------ Non-Compliant followed by a full .cpp file.
  2) // ------ Compliant followed by a full .cpp file.
- Both files must:
  - Use only standard headers and compile with: g++ -std=c++17 -Wall -Wextra -pedantic.
  - Be ~50 lines each (±10).
  - Contain a realistic filter threshold/count routine for hit detection where the seed literal appears.
- The ONLY substantive difference allowed between NC and C:
  - Change `1u` → `1U`.
- Do NOT change program logic, identifiers, or structure other than that suffix change.
- Avoid undefined behaviour; keep behavior deterministic and testable.

VALIDATION HINTS:
1. NC must contain `\b1u\b`; C must contain `\b1U\b` and no `\b1u\b`.
2. `diff -u nc.cpp c.cpp` should show only the suffix-case change.

SOURCE:
- MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the literal(s) changed and the rule(s) satisfied.
END.
"""