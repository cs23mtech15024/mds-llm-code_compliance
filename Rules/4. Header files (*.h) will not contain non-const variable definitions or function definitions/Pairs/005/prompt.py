# prompt_pair5_header_defs_with_sources.py
PROMPT = r'''
SYSTEM:
You are an expert C++ programmer, coding-standards engineer, and dataset generator for safety-critical code (audience: DRDO).
Do NOT provide chain-of-thought. Produce only the requested artifacts.

TASK:
Generate exactly ONE pair of C++ programs (Non-Compliant and Compliant) illustrating MISRA C++:2008 Rule 8-5-2:
  "A header file shall contain only declarations and macros."

REQUIRED SEED (include verbatim at the top of both files):
  // Seed: Non-compliant header: std::string configPath = "cfg.txt";   // Compliant header: extern std::string configPath;

PROVENANCE (must appear in both file headers):
  - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files) 
  - PVS-Studio / Klocwork documentation on MISRA Rule 8-5-2 ("Header files shall contain only declarations and macros"). 

CONSTRAINTS:
- Produce two self-contained .cpp files (NC and C) as code blocks.
- Both must compile with: g++ -std=c++17 -Wall -Wextra -pedantic
- Target size: ~45–55 lines per file.
- NC must show header-like region containing:
    • a non-const variable definition `std::string configPath = "cfg.txt";` (seed)
    • a non-inline function definition `void load_config()` (violations)
- C must show header-like region containing only:
    • `extern std::string configPath;`
    • prototype `void load_config();`
  and must move definitions to the implementation section.
- The ONLY substantive difference between NC and C should be relocation of definitions from header to implementation area (and allowed log-prefix differences).

HEADER COMMENTS (both files):
 - include the seed line above.
 - include the provenance references and a one-line Violation explanation.

VALIDATION HINTS:
1. Compile both:
   g++ -std=c++17 -Wall -Wextra -pedantic pair5_nc.cpp -o pair5_nc
   g++ -std=c++17 -Wall -Wextra -pedantic pair5_c.cpp -o pair5_c
2. NC must contain the header seed `std::string configPath = "cfg.txt";`
3. C must contain `extern std::string configPath;` in the header and the definition only in implementation.
4. diff -u pair5_nc.cpp pair5_c.cpp should show only the header→implementation relocation plus allowed log-prefix differences.

END.
'''