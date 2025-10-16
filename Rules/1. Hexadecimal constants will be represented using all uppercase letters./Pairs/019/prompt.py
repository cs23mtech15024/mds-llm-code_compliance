# prompt_pair19.py
PROMPT = """
SYSTEM:
You are an expert C++ programmer and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK (Pair 19 — literal suffix uppercase):
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating the rule:
  "Literal suffixes shall be upper case" (MISRA C++ Rule 2-13-4).

Required seed (MUST appear verbatim at top of both files):
// Pair 19 — Seed: 0u -> 0U
// Context: State initialization for missile autopilot state machine.
// Violation: lowercase 'u' suffix.

REQUIREMENTS:
- Output two labelled results in this order:
  1) // ------ Non-Compliant followed by a full .cpp file.
  2) // ------ Compliant followed by a full .cpp file.
- Both files must:
  - Use only standard headers, compile with: g++ -std=c++17 -Wall -Wextra -pedantic.
  - Be ~50 lines each (±10).
  - Demonstrate an autopilot state-machine initialization where the seed literal appears (e.g., initial counters, flags).
- The ONLY substantive difference allowed between NC and C:
  - Change `0u` → `0U`.
- Do NOT change program logic, identifiers, or structure other than that suffix change.
- Avoid undefined behaviour; keep behavior deterministic and testable.

VALIDATION HINTS:
1. NC must contain `\b0u\b`; C must contain `\b0U\b` and not `\b0u\b`.
2. `diff -u nc.cpp c.cpp` should show only literal-case changes.

SOURCE:
- MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the literal(s) changed and the rule(s) satisfied.
END.
"""