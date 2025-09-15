# Generation Prompt — MISRA C++:2008 Rule 0-1-10 (Every defined function shall be called at least once)

**Goal**: Produce *paired* C++03 examples (one **non-compliant**, one **compliant**) for MISRA C++:2008 **Rule 0-1-10**. Each pair should be minimal, compile-ready, and highlight a **distinct real-world pattern** where a function is **defined but never called**.

**Scope & Constraints**
- **Language level**: ISO C++03 (no C++11+: no auto, lambdas, range-for, attributes, etc.).
- **Focus**: Functions that are defined (free, member, static, inline, namespaced, in anonymous namespace, templates, overloads, operators, friends, etc.) and ensuring they are **invoked at least once** in the compliant version.
- **Avoid “fake calls”**: Merely declaring, taking the address of, or commenting a call is **not** a call. Operator overloads must be actually used via expressions that invoke them.
- **Build intent**: Non-compliant samples should trigger typical “defined but not referenced” diagnostics with `-Wall -Wextra -Werror` (GCC/Clang) or static analyzers (Cppcheck/Klocwork).
- **Pair format**:
  - `NN_<slug>_noncompliant.cpp` — contains at least one **defined** function that is **never called** (violates Rule 0-1-10).
  - `NN_<slug>_compliant.cpp` — fixes the same by **calling** the function at least once (or by removing the unused definition if appropriate).
- **Header comments**: Start each file with a one-line title and why it is non-compliant/compliant.
- **Self-contained**: Each file must compile standalone (provide `main()` or a callable entry).

**Diversity requirement (no overlap) — cover at least these 20 distinct patterns:**
1) Free function defined but never called  
2) File-scope `static` function never called  
3) Non-static **member** function never called  
4) **Virtual override** defined but never called  
5) **Function template** defined but never instantiated/called  
6) Function in **anonymous namespace** never called  
7) `inline` function never called  
8) **Overload set** where one overload is never called  
9) **Operator overload** defined but never used  
10) **Friend** function defined but never used  
11) **Static member** function never called  
12) **Namespaced** function never called  
13) Function intended for **function pointer** target never called  
14) **Recursive** function never called  
15) **Functor** (`operator()`) defined but never called  
16) **Template class** member function defined but never called  
17) Free function with **default parameters** never called  
18) `extern "C"` function never called  
19) Function taking **references** (side-effect) never called  
20) `static inline` “header-style” utility never called

**Output requirements**
- Generate **20 pairs (40 files)**, each pair targeting exactly one pattern above.
- The **ONLY** compliance difference is the presence/absence of at least one call to the defined function(s), or removal of the unused definition.
- Avoid introducing other rule violations.
- Add a one-sentence *rationale* per file referencing Rule 0-1-10.

**Seed usage**
- Use **different seed ideas** across pairs. You may draw inspiration from the seed examples included in `/mnt/data/Seed_Rule_0_1_10/*.cpp`. Vary identifiers, control flow, and headers to ensure uniqueness.
- Keep to C++03 portability; avoid non-standard extensions.

**Note**: Rule 0-1-10 is specified in MISRA C++:2008; ensure corrections actually invoke the functions at least once.
