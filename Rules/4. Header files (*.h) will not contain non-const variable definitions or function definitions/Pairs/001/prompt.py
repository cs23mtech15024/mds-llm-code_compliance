# prompt_pair1_header_defs.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int g_counter = 0;   // Compliant header: extern int g_counter;

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- The NC file must demonstrate a header-like section that contains a non-const variable definition and a non-inline function definition (the violation).
- The C file must move definitions out of the header-like section: header keeps only declarations (`extern int g_counter;` and function prototype), and the definitions appear in the .cpp part.
- The **only** substantive difference between NC and C should be moving the definitions out of the header area to the implementation area (and changing the header seed line accordingly).
- Use only standard headers; avoid undefined behavior.

HEADER COMMENTS (include in both files):
 - Seed line (above).
 - One-line source citation: MISRA C++ 2008 Rule 8-5-2 and cppreference explanation of header best practices.
 - One-line Violation explanation.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair1_nc.cpp -o pair1_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair1_c.cpp -o pair1_c
2. NC must include the seed text `g_counter = 0;` in the header-like top region.
3. C must include the header-like seed `extern int g_counter;` and the definition `int g_counter = 0;` must appear only in the implementation area (not in header section).
4. diff -u pair1_nc.cpp pair1_c.cpp should show only the header -> implementation relocation (and allowed log prefix changes).

END.
'''