# prompt_pair7_header_defs_odr.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int g_value = 42;   // Compliant header: extern int g_value;

PROVENANCE (include in file headers):
  - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition).  [oai_citation:0‡en.cppreference.com](https://en.cppreference.com/w/cpp/language/definition.html?utm_source=chatgpt.com)
  - StackOverflow: "Multiple definition error on variable that is declared and defined in header file" (https://stackoverflow.com/questions/55238194/multiple-definition-error-on-variable-that-is-declared-and-defined-in-header-fil).  [oai_citation:1‡Stack Overflow](https://stackoverflow.com/questions/55238194/multiple-definition-error-on-variable-that-is-declared-and-defined-in-header-fil?utm_source=chatgpt.com)

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include the header-like region with the seed `int g_value = 42;` and a non-inline function definition in that region (both are violations for headers).
- C must have the header-like region with `extern int g_value;` and a function prototype only; definitions must be in the implementation area.
- The ONLY substantive textual change between NC and C should be relocating definitions out of the header to the implementation area (and allowed log prefix changes).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair7_nc.cpp -o pair7_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair7_c.cpp -o pair7_c
2. NC must contain `int g_value = 42;` in the header-like region.
3. C must contain `extern int g_value;` in the header-like region and `int g_value = 42;` only in implementation area.
4. diff -u pair7_nc.cpp pair7_c.cpp should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''