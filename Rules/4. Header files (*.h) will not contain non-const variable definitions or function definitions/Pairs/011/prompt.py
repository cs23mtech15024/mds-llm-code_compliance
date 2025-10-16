# prompt_pair11_header_defs_timeout.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ files (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int timeout_ms = 5000;   // Compliant header: extern int timeout_ms;

PROVENANCE (include in file headers):
  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files).
  - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition).
  - PVS-Studio / static-analysis guidance on definitions in headers (header best practices).

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must show a header-like region that contains:
    • `int timeout_ms = 5000;` (seed — non-const global definition)
    • a non-inline helper function definition (e.g., `bool check_timeout(int elapsed) { ... }`)
- C must change the header-like region to:
    • `extern int timeout_ms;`
    • function prototype `bool check_timeout(int elapsed);`
  and move the definitions into the implementation section.
- The ONLY substantive difference between NC and C should be the relocation of definitions from header-like region to implementation area (and allowed log-prefix changes).
- Avoid undefined behaviour; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile:
   g++ -std=c++17 -Wall -Wextra -pedantic pair11_nc.cpp -o pair11_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair11_c.cpp -o pair11_c
2. NC must contain the header seed `int timeout_ms = 5000;` in the header-like region.
3. C must contain `extern int timeout_ms;` in the header-like region and define `int timeout_ms = 5000;` only in implementation area.
4. `diff -u pair11_nc.cpp pair11_c.cpp` should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''