prompt = """

"SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought or private reasoning. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating the rule:
  "Literal suffixes shall be upper case" (MISRA C++ Rule 2-13-4).

Required seed (use this exactly and include it at the top of both files):
  // Seed: Non-compliant: const int a = 0l;   // Compliant: const int a = 0L

Top comment block (both files) must include:
  - Seed line above (as shown).
  - Source citation (one-line) pointing to MathWorks Polyspace MISRA C++ Rule 2-13-4 (or equivalent).
  - A single-line Violation explanation (why '0l' is non-compliant).

Generation constraints:
  - Produce two self-contained .cpp files (Non-Compliant and Compliant) as code blocks.
  - Each file must compile with: g++ -std=c++17 -Wall -Wextra -pedantic (no proprietary headers).
  - Use only standard headers.
  - Target size: ~50 lines per file (±10 lines).
  - The **only** substantive textual/semantic differences between the NC and C files must be: changing literal suffix case (lower → upper) and/or uppercase hex digits if used. Do not change program structure, variable names, algorithms, or comments except to mark NC/C and the seed comment.
  - Avoid undefined behavior; keep logic deterministic and testable.

Validation hints (for automated checks):
  1. Compile both files with `g++ -std=c++17 -Wall -Wextra -pedantic` — must exit 0.
  2. NC file must contain the seed `0l` (lowercase L) somewhere (grep `\b0l\b`).
  3. C file must contain `0L` (uppercase L) instead (grep `\b0L\b`) and **no** `\b0l\b` occurrences.
  4. Use diff to confirm only literal-character changes: `diff -u nc.cpp c.cpp` should show only character-case changes in literals.

Output format:
  - Two labelled code blocks in the following order:
    1. `// ------ Non-Compliant` then the full .cpp code.
    2. `// ------ Compliant` then the full .cpp code.
  - After the two blocks include a 1–2 sentence explanation stating which literal(s) were changed and which rule(s) are satisfied.

Seed & authoritative source:
  - Seed: `const int a = 0l; -> const int a = 0L`
  - Reference: MathWorks / Polyspace summary of MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case). :contentReference[oaicite:0]{index=0}

END.

"""