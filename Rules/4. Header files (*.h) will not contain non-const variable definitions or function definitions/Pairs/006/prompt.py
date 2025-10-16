# prompt_pair6_header_defs_stackoverflow.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: int counter = 0;   // Compliant header: extern int counter;

PROVENANCE (must be included in both file headers):
  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files).  [oai_citation:2‡Stack Overflow](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files?utm_source=chatgpt.com)
  - MISRA / static-tool reference for Rule 8-5-2 (Klocwork / PVS-Studio docs).  [oai_citation:3‡help.klocwork.com](https://help.klocwork.com/current/en-us/concepts/misracpp2008checkerreference_nolinks.htm?utm_source=chatgpt.com)

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- The NC file must include the header-like region containing the seed `int counter = 0;` (a non-const global definition) and a non-inline function definition in the header region (violations).
- The C file must change the header-like region to `extern int counter;` and function prototype only, moving definitions to the implementation area.
- The ONLY substantive change between NC and C should be the relocation of definitions out of the header to implementation area (and allowed log prefix differences).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair6_nc.cpp -o pair6_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair6_c.cpp -o pair6_c
2. NC must contain the header seed `int counter = 0;` in the header-like region.
3. C must contain `extern int counter;` in the header-like region and the definition `int counter = 0;` only in implementation area.
4. diff -u pair6_nc.cpp pair6_c.cpp should show only the header→implementation relocation (plus allowed log prefix changes).

END.
'''