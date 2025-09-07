# prompt_pair8.py
PROMPT = """
SYSTEM:
You are an expert C++ programmer and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK (Pair 8 — literal suffix uppercase):
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating the rule:
  "Literal suffixes shall be upper case" (MISRA C++ Rule 2-13-4).

Required seed (MUST appear verbatim at top of both files):
// Pair 8 — Seed: 10u -> 10U
// Context: Logging sensor readings at fixed intervals in a DRDO instrumentation system.
// Violation: lowercase 'u' suffix in timing constant.

REQUIREMENTS:
- Output two labelled results in this order:
  1) // ------ Non-Compliant followed by a full .cpp file.
  2) // ------ Compliant followed by a full .cpp file.
- Both files must:
  - Use only standard headers, compile with: g++ -std=c++17 -Wall -Wextra -pedantic.
  - Be ~50 lines each (±10).
  - Demonstrate periodic logging of sensor readings using the seed literal (10u).
- The ONLY substantive difference allowed between NC and C:
  - Change `10u` → `10U`.
- Avoid undefined behaviour; code must be deterministic and testable.

VALIDATION HINTS:
1. NC must contain `10u`; C must contain `10U` and not `10u`.
2. `diff -u` should show only suffix-case change.

SOURCE reference:
- MISRA C++ Rule 2-13-4 (literal suffixes upper case).
- PVS-Studio diagnostics on lowercase suffixes.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the literal(s) changed and which rule(s) are satisfied.
END.
"""