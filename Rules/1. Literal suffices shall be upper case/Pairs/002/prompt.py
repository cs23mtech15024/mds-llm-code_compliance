prompt = 

"""
SYSTEM:
You are an expert C++ programmer and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Return only the requested artifacts.

TASK (Pair 2 — literal suffix uppercase):
Use the exact seed below and generate TWO self-contained .cpp files (Non-Compliant and Compliant).

SEED (MUST APPEAR verbatim at top of both files):
// Seed: 1u -> 1U
// Context: Recursive directory search for configuration files in DRDO systems.
// Violation: lowercase 'u' suffix unclear.

REQUIREMENTS:
- Output two labelled blocks, in order:
  1) `// ------ Non-Compliant` then the full .cpp content.
  2) `// ------ Compliant` then the full .cpp content.
- The only textual/semantic change allowed between NC and C: convert literal suffix case from lower → upper (`1u` → `1U`). 
- Do NOT change program logic, identifiers, or structure other than that suffix change.
- Use only standard headers; keep each file ~50 lines (±10).
- Both files must compile: `g++ -std=c++17 -Wall -Wextra -pedantic file.cpp -o file`.

VALIDATION HINTS:
1. NC contains `\b1u\b`; C contains `\b1U\b` and no `\b1u\b`.
2. `diff -u nc.cpp c.cpp` should show only the suffix change.

SOURCE (for reviewers):
- MISRA C++ Rule 2-13-4 — “Literal suffixes shall be upper case.” (MathWorks / Polyspace). 
- PVS-Studio diagnostic examples: lowercase `u` flagged as poor style.

OUTPUT:
Return the two code blocks and then one short explanation (1–2 sentences) naming which literal(s) were changed and which rule(s) are satisfied.
END.

"""