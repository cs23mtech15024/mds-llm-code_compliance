# prompt_pair15_header_defs_retry.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int retry_limit = 3;   // Compliant header: extern int retry_limit;

PROVENANCE (include in file headers):
  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (extern usage / header definitions).
  - cppreference: One Definition Rule / Definitions and ODR (header/definition guidance).
  - PVS-Studio / static-analysis notes on header best practices.

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include a header-like region that contains the seed `int retry_limit = 3;` (a non-const global definition) and a non-inline function definition in that region (violation).
- C must change the header-like region to `extern int retry_limit;` and a function prototype only; move the definitions into the implementation section.
- The ONLY substantive textual difference between NC and C should be relocating definitions out of the header to the implementation (and allowed log-prefix differences).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair15_nc.cpp -o pair15_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair15_c.cpp -o pair15_c
2. NC must contain the header seed `int retry_limit = 3;` in the header-like region.
3. C must contain `extern int retry_limit;` in the header-like region and the definition `int retry_limit = 3;` only in implementation area.
4. diff -u pair15_nc.cpp pair15_c.cpp should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''