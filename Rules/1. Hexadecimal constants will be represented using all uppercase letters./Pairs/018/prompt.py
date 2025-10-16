# prompt_pair18.py
PROMPT = """
SYSTEM:
You are an expert C++ programmer and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK (Pair 18 — literal suffix uppercase):
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating the rule:
  "Literal suffixes shall be upper case" (MISRA C++ Rule 2-13-4).

Required seed (MUST appear verbatim at top of both files):
// Pair 18 — Seed: 256u -> 256U
// Context: Block size for onboard image compression in surveillance UAV system.
// Violation: lowercase 'u' suffix.

REQUIREMENTS:
- Output two labelled results in this order:
  1) // ------ Non-Compliant followed by a complete .cpp file.
  2) // ------ Compliant followed by a complete .cpp file.
- Both files must:
  - Use only standard headers, compile with: g++ -std=c++17 -Wall -Wextra -pedantic.
  - Be ~50 lines each (±10).
  - Demonstrate a realistic block-based image compression helper where the seed literal is used (block size constant).
- The ONLY substantive difference allowed between NC and C:
  - Change `256u` → `256U` (lower → upper suffix).
- Do NOT change program logic, identifiers, or structure other than that suffix change.
- Avoid undefined behaviour; keep logic deterministic and testable.

VALIDATION HINTS:
1. NC must contain `\b256u\b`; C must contain `\b256U\b` and not `\b256u\b`.
2. `diff -u` should show only the suffix-case change.
3. Both files should compile cleanly.

SOURCE:
- MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).
- PVS-Studio guidance (lowercase suffixes discouraged).

OUTPUT:
Return the two code blocks (NC then C) and a 1–2 sentence explanation naming the literal(s) changed and the rule(s) satisfied.
END.
"""