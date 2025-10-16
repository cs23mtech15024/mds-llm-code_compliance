# prompt_pair14_header_defs_status.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: char status_msg[] = "OK";   // Compliant header: extern char status_msg[];

PROVENANCE (include in file headers):
  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (extern usage / header definitions).  
  - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition).

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include the header-like region containing the seed `char status_msg[] = "OK";` (a non-const global definition) and a non-inline function definition in that region (violation).
- C must change the header-like region to `extern char status_msg[];` and a prototype only; move the definition and the function into the implementation area.
- The ONLY substantive textual difference between NC and C should be relocating definitions out of the header-like region into the implementation area (and allowed NC/C log prefix differences).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair14_nc.cpp -o pair14_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair14_c.cpp -o pair14_c
2. NC must contain the header seed `char status_msg[] = "OK";` in the header-like region.
3. C must contain `extern char status_msg[];` in the header-like region and the definition `char status_msg[] = "OK";` only in implementation area.
4. diff -u pair14_nc.cpp pair14_c.cpp should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''