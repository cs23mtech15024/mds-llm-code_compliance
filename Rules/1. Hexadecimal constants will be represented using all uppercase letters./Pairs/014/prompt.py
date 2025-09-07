# prompt_pair14.py
PROMPT = """
SYSTEM:
You are an expert C++ programmer and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK (Pair 14 — literal suffix uppercase):
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating the rule:
  "Literal suffixes shall be upper case" (MISRA C++ Rule 2-13-4).

Required seed (MUST appear verbatim at top of both files):
// Pair 14 — Seed: 1u -> 1U
// Context: Task ID for scheduling in DRDO onboard real-time operating system.
// Violation: lowercase 'u' suffix may impede static analysis.

REQUIREMENTS:
- Output two labelled results in this order:
  1) // ------ Non-Compliant followed by a full .cpp file.
  2) // ------ Compliant followed by a full .cpp file.
- Both files must:
  - Use only standard headers, compile with: g++ -std=c++17 -Wall -Wextra -pedantic.
  - Be ~50 lines each (±10).
  - Demonstrate a small task-scheduling module where the seed literal appears (task ID, loop bounds).
- The ONLY substantive difference allowed between NC and C:
  - Change `1u` → `1U`.
- Do NOT change program logic, identifiers, or structure other than that suffix change.
- Avoid undefined behaviour; keep behavior deterministic and testable.

VALIDATION HINTS:
1. NC must contain `\b1u\b`; C must contain `\b1U\b` and no `\b1u\b`.
2. `diff -u` between nc/c files should show only the suffix case change.

SOURCE:
- MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the literal(s) changed and the rule(s) satisfied.
END.
"""