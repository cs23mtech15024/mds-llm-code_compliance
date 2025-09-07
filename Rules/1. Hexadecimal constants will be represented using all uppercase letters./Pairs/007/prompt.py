# prompt_pair7.py
PROMPT = """
SYSTEM:
You are an expert C++ programmer and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK (Pair 7 — literal suffix uppercase):
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating the rule:
  "Literal suffixes shall be upper case" (MISRA C++ Rule 2-13-4).

Required seed (MUST appear verbatim at top of both files):
// Pair 7 — Seed: 64UL -> 64ull (in reverse for demonstration)
// Context: Circular buffer for sensor data in DRDO embedded system.
// Violation: lowercase 'ull' suffix.

REQUIREMENTS:
- Output two labelled results in this order:
  1) // ------ Non-Compliant followed by a full .cpp file.
  2) // ------ Compliant followed by a full .cpp file.
- Both files must:
  - Use only standard headers, compile with: g++ -std=c++17 -Wall -Wextra -pedantic.
  - Be ~50 lines each (±10).
  - Contain a realistic circular buffer for sensor data where the seed literal is used.
- The ONLY substantive difference allowed between NC and C:
  - Non-Compliant uses `64ull`, Compliant uses `64ULL`.
- Avoid undefined behaviour; deterministic and testable.

VALIDATION HINTS:
1. NC must contain `64ull`; C must contain `64ULL` and not `64ull`.
2. `diff -u` should show only suffix-case change.

SOURCE reference:
- MISRA C++ Rule 2-13-4 (literal suffixes upper case).
- PVS-Studio diagnostics flag lowercase `ull`.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the literal(s) changed and the rule(s) satisfied.
END.
"""