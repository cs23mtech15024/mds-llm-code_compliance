# prompt_pair20_header_defs_config.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int config_version = 1;   // Compliant header: extern int config_version;

PROVENANCE (include in file headers):
  - StackOverflow Q#1433204: “How do I use extern to share variables between source files?”
  - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition)
  - MISRA and PVS-Studio documentation on header definition violations (best practice notes).

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include a header-like region that contains the seed `int config_version = 1;` (a non-const global definition) and a non-inline helper function definition (violations).
- C must change the header-like region to `extern int config_version;` and a prototype only; move definitions into the implementation section.
- The ONLY substantive difference between NC and C must be relocating definitions out of the header to the implementation (plus allowed log-prefix differences).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair20_nc.cpp -o pair20_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair20_c.cpp -o pair20_c
2. NC must contain the header seed `int config_version = 1;` in the header-like region.
3. C must contain `extern int config_version;` in the header-like region and define `int config_version = 1;` only in implementation.
4. diff -u pair20_nc.cpp pair20_c.cpp should show only the header→implementation relocation (plus log-prefix changes).

END.
'''