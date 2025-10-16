# prompt_pair12_header_defs_feature.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: bool featureEnabled = true;   // Compliant header: extern bool featureEnabled;

PROVENANCE (include in file headers):
  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files).
  - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition).
  - PVS-Studio / Klocwork guidance on header best practices (static-analysis docs).

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must include the header-like region that contains the seed `bool featureEnabled = true;` (a non-const global definition) and a non-inline function definition in the header-like region (violation).
- C must change the header-like region to `extern bool featureEnabled;` and function prototype only; move definitions into the implementation area.
- The ONLY substantive textual difference between NC and C should be relocating definitions out of the header into the implementation area (and allowed log-prefix changes).
- Avoid undefined behavior; keep logic deterministic and testable.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair12_nc.cpp -o pair12_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair12_c.cpp -o pair12_c
2. NC must contain the header seed `bool featureEnabled = true;` in the header-like region.
3. C must contain `extern bool featureEnabled;` in the header-like region and the definition `bool featureEnabled = true;` only in implementation area.
4. diff -u pair12_nc.cpp pair12_c.cpp should show only the header→implementation relocation (plus allowed log-prefix differences).

END.
'''