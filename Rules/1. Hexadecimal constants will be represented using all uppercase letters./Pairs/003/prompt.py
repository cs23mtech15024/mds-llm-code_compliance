# prompt_pair3.py
PROMPT = """
SYSTEM:
You are an expert C++ programmer and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK (Pair 3 — hex literals & suffix uppercase):
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) that illustrate the rule:
  "Literal suffixes shall be upper case and hex digits should be uppercase" (MISRA C++ Rule 2-13-4 and JSF-AV hex convention).

Required seed (MUST appear verbatim at top of both files):
  // Pair 3 — Seed: 0x12bu -> 0x12BU
  // Context: Applies bitmask for sensor calibration in DRDO data acquisition.
  // Violation: lowercase hex letters and lowercase 'u' suffix inconsistent with JSF/DRDO readability rules.

REQUIREMENTS:
- Produce two labelled outputs in this order:
  1) // ------ Non-Compliant  followed by a complete .cpp source (self-contained).
  2) // ------ Compliant    followed by a complete .cpp source (self-contained).
- Both files must:
  - Use only standard headers and compile with: g++ -std=c++17 -Wall -Wextra -pedantic.
  - Be ~50 lines each (±10).
  - Contain a realistic DRDO-relevant function/class demonstrating sensor calibration that uses the seed literal.
- The ONLY substantive textual/semantic change allowed between NC and C is letter/suffix case:
  - e.g., change `0x12bu` → `0x12BU` (hex digits uppercased if any are letters, and suffix U uppercase).
  - Do NOT alter logic, control flow, variable names, comments (except to mark NC/C and include seed comment).
- Avoid undefined behaviour; keep behavior deterministic and testable.

VALIDATION HINTS:
1. NC must contain the seed `0x12bu` (grep for "\b0x12bu\b").
2. C must contain `0x12BU` and must NOT contain `0x12bu`.
3. Compile both files to ensure they are syntactically valid.

SOURCE reference (for reviewers):
- MISRA C++ Rule 2-13-4 (literal suffixes upper case) and JSF AV hex convention (hex digits uppercase for readability in safety-critical code).

OUTPUT:
Return the two code blocks (NC then C) and a 1-2 sentence explanation naming the literal(s) changed and the rule(s) satisfied.
"""
