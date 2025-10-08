# prompt_pair10_header_defs_cache.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: std::vector<int> cache = {1,2};   // Compliant header: extern std::vector<int> cache;

PROVENANCE (include in file headers):
  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files).  
  - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition).  
  - PVS-Studio guidance on definitions in headers and header best practices (pvs-studio.com).

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC: header-like region must contain the seed `std::vector<int> cache = {1,2};` and a non-inline function definition (violation).
- C: header-like region must contain only `extern std::vector<int> cache;` and a function prototype; definitions must be in implementation area.
- The ONLY substantive change between NC and C is relocating definitions out of header to implementation (and allowed log prefix differences).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair10_nc.cpp -o pair10_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair10_c.cpp -o pair10_c
2. NC must contain the header seed `std::vector<int> cache = {1,2};`.
3. C must contain `extern std::vector<int> cache;` in header-like region and `std::vector<int> cache = {1,2};` only in implementation area.
4. diff -u pair10_nc.cpp pair10_c.cpp should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''