# prompt_pair3_header_defs.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: static int connectionCount = 0;   // Compliant header: extern int connectionCount;

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include a header-like region that contains:
    - a non-const variable definition: `static int connectionCount = 0;` (seed)
    - a non-inline function definition in the header (e.g., `void report_connection()` defined non-inline)
- C must contain only declarations in the header-like region:
    - `extern int connectionCount;`
    - `void report_connection();` prototype
  and move definitions into the implementation area.
- The ONLY substantive change between NC and C should be relocating definitions out of the header (and updating the seed line accordingly).
- Use only standard headers and avoid undefined behavior.

HEADER COMMENTS (both files):
 - include the seed line above.
 - include one-line citation to MISRA C++:2008 Rule 8-5-2.
 - include a one-line Violation explanation.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair3_nc.cpp -o pair3_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair3_c.cpp -o pair3_c
2. NC must contain the seed text `connectionCount = 0;` in the header-like region.
3. C must contain `extern int connectionCount;` in the header-like region and the definition `int connectionCount = 0;` only in implementation area.
4. `diff -u pair3_nc.cpp pair3_c.cpp` should show only the header → implementation relocation (plus allowed log prefix differences).

END.
'''