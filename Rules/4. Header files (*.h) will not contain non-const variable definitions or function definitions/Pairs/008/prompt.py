# prompt_pair8_header_defs_buffer.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int buffer_size = 1024;   // Compliant header: extern int buffer_size;

PROVENANCE (include in file headers):
  - cppreference: One Definition Rule / Definitions and ODR (general reference to header-definition issues).
  - StackOverflow / static-analyzer docs: common multiple-definition examples when globals are defined in headers.

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- The NC file must include a header-like region that contains the seed `int buffer_size = 1024;` (a non-const global definition) and also a non-inline helper function implemented in the header region (violations).
- The C file must have the header-like region changed to `extern int buffer_size;` and only a function prototype; the definitions must be placed in the implementation section.
- The ONLY substantive textual difference between NC and C must be the relocation of definitions out of the header-like region into the implementation region (and allowed NC/C log prefix differences).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair8_nc.cpp -o pair8_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair8_c.cpp -o pair8_c
2. NC must contain the header seed `int buffer_size = 1024;` in the header-like region.
3. C must contain `extern int buffer_size;` in the header-like region and the definition `int buffer_size = 1024;` only in the implementation area.
4. diff -u pair8_nc.cpp pair8_c.cpp should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''