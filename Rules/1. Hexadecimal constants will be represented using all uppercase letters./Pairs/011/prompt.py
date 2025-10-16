# prompt_pair11.py
PROMPT = """
SYSTEM:
You are an expert C++ programmer and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK (Pair 11 — literal suffix uppercase):
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) that illustrate the rule:
  "Literal suffixes shall be upper case" (MISRA C++ Rule 2-13-4).

Required seed (MUST appear verbatim at top of both files):
// Pair 11 — Seed: 5u -> 5U
// Context: FIR filter template for signal conditioning in instrumentation.
// Violation: lowercase 'u' suffix.

REQUIREMENTS:
- Produce two labelled outputs in this order:
  1) // ------ Non-Compliant followed by a full .cpp file.
  2) // ------ Compliant followed by a full .cpp file.
- Both files must:
  - Use only standard headers and compile with: g++ -std=c++17 -Wall -Wextra -pedantic.
  - Be ~50 lines each (±10).
  - Demonstrate a template-based FIR filter where the seed literal appears (e.g., filter length).
- The ONLY substantive change allowed between NC and C:
  - Change `5u` → `5U`.
- Do NOT change program logic, identifiers, or structure other than that suffix change.
- Avoid undefined behaviour; keep code deterministic and testable.

VALIDATION HINTS:
1. NC must contain `\b5u\b`; C must contain `\b5U\b` and no `\b5u\b`.
2. `diff -u` should show only the suffix-case change.

SOURCE:
- MISRA C++ Rule 2-13-4 (literal suffixes upper case) and common static-analysis guidance.

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the literal(s) changed and the rule(s) satisfied.
END.
"""