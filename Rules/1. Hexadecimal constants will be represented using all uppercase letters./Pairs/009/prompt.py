# prompt_pair9.py
PROMPT = """
SYSTEM:
You are an expert C++ programmer and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK (Pair 9 — literal suffix uppercase):
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating the rule:
  "Literal suffixes shall be upper case" (MISRA C++ Rule 2-13-4).

Required seed (MUST appear verbatim at top of both files):
// Pair 9 — Seed: 255u -> 255U
// Context: Normalizing radar return signals from Rajendra fire-control radar.
// Violation: lowercase 'u' suffix may be misinterpreted in critical code.

REQUIREMENTS:
- Output two labelled results in this order:
  1) // ------ Non-Compliant followed by a full .cpp file.
  2) // ------ Compliant followed by a full .cpp file.
- Both files must:
  - Use only standard headers, compile with: g++ -std=c++17 -Wall -Wextra -pedantic.
  - Be ~50 lines each (±10).
  - Contain a realistic radar normalization routine where the seed literal is used.
- The ONLY substantive difference allowed between NC and C:
  - Change `255u` → `255U` (and any directly related unsigned literal case).
- Avoid undefined behaviour; code must be deterministic and testable.

VALIDATION HINTS:
1. NC must contain `255u`; C must contain `255U` and not `255u`.
2. `diff -u` between nc/c files should show only suffix-case changes.

SOURCE reference:
- MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).
- PVS-Studio diagnostics on lowercase suffixes.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the literal(s) changed and the rule(s) satisfied.
END.
"""