# prompt_pair13_header_defs_connections.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int max_connections = 10;   // Compliant header: extern int max_connections;

PROVENANCE (include in file headers):
  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (example of extern vs definition).  
  - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition).  
  - PVS-Studio / static-analysis guidance on definitions in headers (header best practices).

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include a header-like region that contains the seed `int max_connections = 10;` (a non-const global definition) and a non-inline helper function definition (violations).
- C must change the header-like region to `extern int max_connections;` and a function prototype only; the actual definitions must be in the implementation area.
- The ONLY substantive textual difference between NC and C should be relocating definitions out of the header to the implementation (and allowed NC/C log prefix differences).
- Use only standard headers; avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair13_nc.cpp -o pair13_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair13_c.cpp -o pair13_c
2. NC must contain the header seed `int max_connections = 10;` in the header-like region.
3. C must contain `extern int max_connections;` in the header-like region and define `int max_connections = 10;` only in implementation area.
4. diff -u pair13_nc.cpp pair13_c.cpp should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''