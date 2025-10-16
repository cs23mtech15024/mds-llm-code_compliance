# prompt_pair19_header_defs_flag.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: bool debug_flag = false;   // Compliant header: extern bool debug_flag;

PROVENANCE (include in file headers):
  - StackOverflow Q#1433204: “How do I use extern to share variables between source files?” (https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files).
  - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition).
  - PVS-Studio / static analyzer guidance: “Avoid variable definitions in headers” (MISRA-related note).

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include a header-like region containing the seed `bool debug_flag = false;` (a non-const global definition) and a non-inline helper function definition (violation).
- C must change the header-like region to `extern bool debug_flag;` and a prototype only; move the definitions into the implementation section.
- The ONLY substantive textual difference between NC and C must be relocating definitions out of the header to the implementation area (and allowed NC/C log prefix differences).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair19_nc.cpp -o pair19_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair19_c.cpp -o pair19_c
2. NC must contain the header seed `bool debug_flag = false;` in the header-like region.
3. C must contain `extern bool debug_flag;` in the header-like region and the definition `bool debug_flag = false;` only in implementation area.
4. diff -u pair19_nc.cpp pair19_c.cpp should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''