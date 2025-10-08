# prompt_pair17_header_defs_session.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int session_id = 0;   // Compliant header: extern int session_id;

PROVENANCE (include in file headers):
  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files).
  - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition).
  - PVS-Studio / static analyzer guidance on header best practices.

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include a header-like region containing the seed `int session_id = 0;` (non-const global definition) and a non-inline function definition (violation).
- C must change the header-like region to `extern int session_id;` and a prototype only; move definitions into the implementation area.
- The ONLY substantive textual difference between NC and C is relocating definitions out of the header to the implementation area (and allowed NC/C log prefix differences).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair17_nc.cpp -o pair17_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair17_c.cpp -o pair17_c
2. NC must contain the header seed `int session_id = 0;` in the header-like region.
3. C must contain `extern int session_id;` in the header-like region and the definition `int session_id = 0;` only in the implementation area.
4. diff -u pair17_nc.cpp pair17_c.cpp should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''