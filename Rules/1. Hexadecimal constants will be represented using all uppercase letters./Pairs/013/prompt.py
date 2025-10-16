# prompt_pair13.py
PROMPT = """
SYSTEM:
You are an expert C++ programmer and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK (Pair 13 — hex suffix & hex digits case):
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating the rule:
  "Literal suffixes shall be upper case" (MISRA C++ Rule 2-13-4) and JSF-AV hex convention (uppercase hex digits).

Required seed (include this verbatim at top of both files):
// Pair 13 — Seed: 0xffU -> 0xffu
// Context: Model of mesh packet routing table in DRDO SDR-based Tactical Communication System.
// Violation: lowercase 'u' suffix hindering clarity.

Clarification (generator): The NC file must contain a lowercase-suffix lowercase-hex form (e.g., `0xffu`). 
The C file must contain the corrected uppercase-hex uppercase-suffix form (e.g., `0xFFU`).

REQUIREMENTS:
- Output two labelled blocks in this order:
  1) // ------ Non-Compliant  then the full .cpp file.
  2) // ------ Compliant    then the full .cpp file.
- Both files must:
  - Use only standard headers and compile with: g++ -std=c++17 -Wall -Wextra -pedantic.
  - Be ~50 lines each (±10).
  - Contain a short, realistic SDR routing-table example that uses the seed literal.
- The ONLY substantive textual/semantic differences between NC and C:
  - Change `0xffu` -> `0xFFU` (hex digits uppercase and suffix uppercase). Do not change logic, identifiers, or control flow.
- Avoid undefined behavior; keep behavior deterministic and testable.

VALIDATION HINTS:
1. NC must contain the lowercase form `0xffu` (grep \b0xffu\b).
2. C must contain the compliant form `0xFFU` and not `0xffu`.
3. Compile both files to verify syntax.

SOURCE:
- MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case) and JSF-AV hex uppercase guidance.

OUTPUT:
Return the two code blocks (NC then C) and then a 1–2 sentence explanation naming the changed literal(s) and rule(s) satisfied.
END.
"""