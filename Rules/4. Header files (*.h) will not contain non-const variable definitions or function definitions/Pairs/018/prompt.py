# prompt_pair18_header_defs_block.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int block_size = 256;   // Compliant header: extern int block_size;

PROVENANCE (include in file headers):
  - StackOverflow discussion on using 'extern' vs defining globals in headers (example guidance).
  - cppreference: One Definition Rule / Definitions and ODR (reference for header-definition issues).

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include the header-like region containing the seed `int block_size = 256;` and a non-inline helper function definition (violations).
- C must change the header-like region to `extern int block_size;` and a function prototype only; move definitions into the implementation area.
- The ONLY substantive textual difference between NC and C must be relocating definitions out of the header to the implementation area (and allowed NC/C log prefix differences).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair18_nc.cpp -o pair18_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair18_c.cpp -o pair18_c
2. NC must contain the header seed `int block_size = 256;` in the header-like region.
3. C must contain `extern int block_size;` in the header-like region and the definition `int block_size = 256;` only in the implementation area.
4. diff -u pair18_nc.cpp pair18_c.cpp should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''