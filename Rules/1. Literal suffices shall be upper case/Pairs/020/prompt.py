# prompt_pair20.py
PROMPT = """
SYSTEM:
You are an expert C++ programmer and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK (Pair 20 — hex letters & suffix uppercase):
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating the rule:
  "Literal suffixes shall be upper case" (MISRA C++ Rule 2-13-4) and uppercase hex letters for readability.

Required seed (MUST appear verbatim at top of both files):
// Pair 20 — Seed: 0x1Afu -> 0x1AFU
// Context: Checksum mask for tactical communication frames in a DRDO secure-comm module.
// Violation: lowercase hex letters and lowercase 'u' suffix reduce readability.

REQUIREMENTS:
- Produce two labelled outputs in this order:
  1) // ------ Non-Compliant followed by a full .cpp file.
  2) // ------ Compliant followed by a full .cpp file.
- Both files must:
  - Use only standard headers and compile with: g++ -std=c++17 -Wall -Wextra -pedantic.
  - Be approximately 50 lines each (±10).
  - Contain a compact secure-comm helper that computes/verifies a simple checksum mask using the seed literal.
- The ONLY substantive textual/semantic change allowed between NC and C:
  - Change `0x1Afu` -> `0x1AFU` (uppercase hex letters and suffix). Do not change logic, names, structure, or comments other than marking NC/C and the seed comment.
- Avoid undefined behaviour; keep code deterministic and testable.

VALIDATION HINTS:
1. NC must contain the lowercase form `0x1Afu` (grep "\\b0x1Afu\\b").
2. C must contain `0x1AFU` and not `0x1Afu`.
3. Compile both files to ensure they are syntactically valid.

SOURCE:
- MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case) and JSF-AV hex-letter uppercase guidance.

OUTPUT:
Return the two code blocks (NC then C) and a short explanation (1–2 sentences) naming the changed literal(s) and the rule(s) satisfied.
END.
"""