# prompt_pair21_pointer_header.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int* ptr = nullptr;   // Compliant header: extern int* ptr;

PROVENANCE (include in file headers):
  - StackOverflow: advice on extern and global definitions (e.g. "How do I use extern to share variables between source files?").
  - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition).
  - cppreference: nullptr description (https://en.cppreference.com/w/cpp/language/nullptr).

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include a header-like region containing the seed `int* ptr = nullptr;` (a non-const pointer definition) — this is the violation.
- C must have the header-like region contain `extern int* ptr;` and only a prototype/declaration; the definition must be in implementation area.
- The ONLY substantive difference between NC and C is relocating the pointer definition out of the header-like region into implementation (and allowed log-prefix differences).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair21_nc.cpp -o pair21_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair21_c.cpp -o pair21_c
2. NC must contain the seed `int* ptr = nullptr;` in the header-like region.
3. C must contain `extern int* ptr;` in the header-like region and the definition `int* ptr = nullptr;` only in implementation area.
4. diff -u pair21_nc.cpp pair21_c.cpp should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''