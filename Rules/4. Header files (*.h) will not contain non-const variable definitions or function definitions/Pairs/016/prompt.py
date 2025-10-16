# prompt_pair16_header_defs_mask.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int access_mask = 0xFF;   // Compliant header: extern int access_mask;

PROVENANCE (include in file headers):
  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (extern usage / header definitions).
  - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition).

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include a header-like region that contains the seed `int access_mask = 0xFF;` (a non-const global definition) and also a non-inline function definition in that region (violation).
- C must change the header-like region to `extern int access_mask;` and a prototype only; move the definitions into the implementation area.
- The ONLY substantive textual difference between NC and C must be relocating definitions out of the header to the implementation area (and allowed NC/C log prefix differences).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair16_nc.cpp -o pair16_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair16_c.cpp -o pair16_c
2. NC must contain the header seed `int access_mask = 0xFF;` in the header-like region.
3. C must contain `extern int access_mask;` there and define `int access_mask = 0xFF;` only in implementation area.
4. diff -u pair16_nc.cpp pair16_c.cpp should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''