# prompt_pair9_header_defs_calibration.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: double calibration = 1.234;   // Compliant header: extern double calibration;

PROVENANCE (include in file headers):
  - StackOverflow Q#1433204 (extern usage / sharing globals): https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files. 
  - cppreference: One Definition Rule / Definitions and ODR: https://en.cppreference.com/w/cpp/language/definition. 
  - PVS-Studio / static analysis notes on definitions in headers (guidance on header best practices). 

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include a header-like region that contains the seed `double calibration = 1.234;` (non-const global) and a non-inline helper function defined in the header region (violations).
- C must change the header-like region to `extern double calibration;` and a prototype only; move definitions into implementation area.
- The ONLY substantive textual difference between NC and C must be moving definitions out of the header-like region into the implementation region (and allowed NC/C log prefix differences).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair9_nc.cpp -o pair9_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair9_c.cpp -o pair9_c
2. NC must contain the header seed `double calibration = 1.234;` in the header-like region.
3. C must contain `extern double calibration;` in the header-like region and the definition `double calibration = 1.234;` only in implementation area.
4. diff -u pair9_nc.cpp pair9_c.cpp should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''