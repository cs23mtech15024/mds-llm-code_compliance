# PROGRAM Meta Prompt Template (Generic MISRA C++ Rule)

You are an expert C++ programmer and dataset engineer.  
Your goal is to generate two complete `.cpp` programs — one **Non-Compliant** and one **Compliant** — demonstrating a specific MISRA C++ rule violation and its fix.

---

## RULE CONFIGURATION (Fill these in):
```
RULE_NUMBER: {{RULE_NUMBER}}
RULE_DESCRIPTION: {{RULE_DESCRIPTION}}
VIOLATION_TYPE: {{VIOLATION_TYPE}}
FIX_PATTERN: {{FIX_PATTERN}}
```

---

## INPUT FORMAT

You will receive seed data in JSONL format with these fields:
- `seed`: unique seed number
- `context`: domain-specific context description (e.g., "UAV altitude hold control")
- `noncompliant`: minimal seed code (8-15 lines) showing the violation
- `compliant`: minimal seed code (8-15 lines) with the fix

**Example seed input:**
```json
{"seed":1,"context":"Autonomous drone altitude hold loop","noncompliant":"#include <iostream>\nint main(){\n    float error=0.0F, integral=0.0F; // NC\n    double kp=1.1, ki=0.05; // NC\n    int samples=0, drops=0; // NC\n    error += 0.2F; integral += error;\n    std::cout<<kp<<\",\"<<ki<<\",\"<<samples<<\",\"<<drops<<\"\\n\";\n    return 0;\n}\n","compliant":"#include <iostream>\nint main(){\n    float error=0.0F; // C\n    float integral=0.0F; // C\n    double kp=1.1; // C\n    double ki=0.05; // C\n    int samples=0; // C\n    int drops=0; // C\n    error += 0.2F; integral += error;\n    std::cout<<kp<<\",\"<<ki<<\",\"<<samples<<\",\"<<drops<<\"\\n\";\n    return 0;\n}\n"}
```

---

## TASK: EXPAND SEED INTO FULL PROGRAMS

For each seed input, **expand** it into two complete 40-60 line programs:

### **Step 1: Extract from seed**
- Use `seed` number as the program number
- Use `context` for the domain
- Use `noncompliant` code as the foundation for NC program
- Use `compliant` code as the foundation for C program

### **Step 2: Expand the seed code**
Take the minimal seed code (8-15 lines) and expand it by adding:
- Domain-specific type definitions (structs/classes)
- Helper functions (clamp, wrap, calculate, etc.)
- Wrap seed logic in a named function inside a namespace
- Add loops, conditionals, and calculations
- Add realistic output statements
- Expand to 40-60 lines total

### **Step 3: Maintain structural identity**
Both NC and C versions must be **identical** except for:
- Header comment (NC vs C)
- The specific rule violation/fix from the seed
- Comment markers (`// NC` vs `// C`)

---

## PROGRAM STRUCTURE TEMPLATE

### Non-Compliant Program:
```cpp
// ------ Non-Compliant Program ({{SEED_NUM}}_nc.cpp)
// Seed {{SEED_NUM}} — Context: {{CONTEXT}}
// Reference: MISRA C++ {{RULE_NUMBER}} — {{RULE_DESCRIPTION}}
// Violation: {{VIOLATION_TYPE}}

#include <iostream>
#include <vector>
#include <cmath>
// Add other headers as needed based on seed code

namespace app_{{SEED_NUM}} {
    // Type definitions (domain-appropriate)
    struct {{DomainType}} { /* fields matching context */ };
    
    // Helper functions (expand seed logic)
    static {{ReturnType}} helperFunction({{params}}) {
        // Implementation supporting main logic
    }
    
    // Main logic function (wrap seed code here)
    void mainFunction() {
        // EXPAND SEED NONCOMPLIANT CODE HERE
        // Keep the violations from seed: float a=1, b=2; // NC
        
        // Add loops, calculations, conditionals around seed logic
        
        // Output showing results
        std::cout << /* results */ << "\n";
    }
}

int main() {
    app_{{SEED_NUM}}::mainFunction();
    return 0;
}
```

### Compliant Program:
```cpp
// ------ Compliant Program ({{SEED_NUM}}_c.cpp)
// Seed {{SEED_NUM}} — Context: {{CONTEXT}}
// Reference: MISRA C++ {{RULE_NUMBER}} — {{RULE_DESCRIPTION}}
// Fix: {{FIX_PATTERN}}

#include <iostream>
#include <vector>
#include <cmath>
// Add other headers as needed (same as NC)

namespace app_{{SEED_NUM}} {
    // Type definitions (IDENTICAL to NC)
    struct {{DomainType}} { /* fields matching context */ };
    
    // Helper functions (IDENTICAL to NC)
    static {{ReturnType}} helperFunction({{params}}) {
        // Implementation supporting main logic
    }
    
    // Main logic function (wrap seed code here)
    void mainFunction() {
        // EXPAND SEED COMPLIANT CODE HERE
        // Apply the fix from seed: float a=1; float b=2; // C
        
        // Add loops, calculations, conditionals (IDENTICAL to NC)
        
        // Output showing results (IDENTICAL to NC)
        std::cout << /* results */ << "\n";
    }
}

int main() {
    app_{{SEED_NUM}}::mainFunction();
    return 0;
}
```

---

## EXPANSION GUIDELINES

When expanding the seed code (8-15 lines → 40-60 lines), add:

1. **Domain-specific types** based on `context`:
   - UAV/drone → `struct State { float alt; float vel; }`
   - Factory/industrial → `struct Event { int code; std::string msg; }`
   - Medical → `struct Sample { double flow; double pressure; }`

2. **Helper functions** that support the seed logic:
   - `clamp()` for range limiting
   - `wrap()` for angle wrapping
   - `avg()` for calculations
   - Domain-specific utilities

3. **Expanded main logic**:
   - Wrap seed variable declarations in a named function
   - Add loops (for, while) around the seed logic
   - Add conditionals based on calculations
   - Add arrays/vectors for data processing
   - Keep output statements meaningful

4. **Preserve seed violations/fixes**:
   - Keep exact violations from seed noncompliant code
   - Keep exact fixes from seed compliant code
   - Mark with `// NC` or `// C` comments

---

## CONSTRAINTS

1. **Code Length**: 40-60 lines per program (including headers and comments)

2. **Structural Identity**: Both NC and C versions must be identical except for:
   - The comment headers (NC vs C)
   - The specific rule violation/fix from the seed
   - The inline comment markers (`// NC` vs `// C`)

3. **Compilation**: Both versions must compile with:
   ```bash
   g++ -std=c++17 -Wall -Wextra -pedantic -fsyntax-only program.cpp
   ```

4. **Use seed as foundation**:
   - Extract variables, types, and logic from seed code
   - Expand around it, don't replace it
   - Keep the violation/fix pattern from the seed

5. **Namespacing**: Use `app_{{SEED_NUM}}` format

6. **Standard library only**: No external dependencies

---

## JSONL OUTPUT FORMAT

Generate output as JSONL with fields: `program`, `context`, `noncompliant`, `compliant`

```json
{"program":{{SEED_NUM}},"context":"{{CONTEXT}}","noncompliant":"{{ESCAPED_NC_CODE}}","compliant":"{{ESCAPED_C_CODE}}"}
```

**Escaping rules:**
- Use `\n` for newlines (single backslash)
- Escape double quotes: `"` → `\"`
- Escape backslashes: `\` → `\\`
- Each JSONL line must be valid JSON

---

## EXAMPLE: SEED TO PROGRAM EXPANSION

**Input seed:**
```json
{"seed":1,"context":"Autonomous drone altitude hold loop","noncompliant":"#include <iostream>\nint main(){\n    float error=0.0F, integral=0.0F; // NC\n    double kp=1.1, ki=0.05; // NC\n    int samples=0, drops=0; // NC\n    error += 0.2F; integral += error;\n    std::cout<<kp<<\",\"<<ki<<\",\"<<samples<<\",\"<<drops<<\"\\n\";\n    return 0;\n}\n","compliant":"..."}
```

**Output expanded program:**
```json
{"program":1,"context":"Autonomous drone altitude hold loop","noncompliant":"// ------ Non-Compliant Program (001_nc.cpp)\n// Seed 1 — Context: Autonomous drone altitude hold loop\n// Rule: MISRA C++ 8-0-1 — Each declaration shall declare no more than one declarator\n// Violation: multiple declarators per declaration\n\n#include <iostream>\n#include <iomanip>\n#include <array>\n#include <cstddef>\n\nnamespace alt_001 {\n    struct State { float alt; float vel; };\n    static float clamp(float v, float lo, float hi){ return v < lo ? lo : (v > hi ? hi : v); }\n    \n    void step(){\n        float error=0.0F, integral=0.0F;        // NC (from seed)\n        double kp=1.10, ki=0.05;                // NC (from seed)\n        int samples=0, drops=0;                 // NC (from seed)\n        State s{0.0F, 0.0F};\n        const float dt=0.02F;\n        std::array<float,6U> refs{1.0F,1.1F,0.9F,1.2F,1.0F,0.8F};\n        \n        for (std::size_t i=0U; i<refs.size(); ++i){\n            float set=refs[i];\n            error = set - s.alt;\n            integral += error * dt;\n            float u = static_cast<float>(kp)*error + static_cast<float>(ki)*integral;\n            u = clamp(u,-2.0F,2.0F);\n            s.vel += u * dt;\n            s.alt += s.vel * dt;\n            samples++;\n            if ((i%3U)==0U) { drops++; }\n            if ((i%2U)==0U) {\n                std::cout<<\"t=\"<<i<<\" alt=\"<<std::fixed<<std::setprecision(2)<<s.alt\n                         <<\" err=\"<<error<<\" u=\"<<u<<\"\\n\";\n            }\n        }\n        std::cout<<\"done samples=\"<<samples<<\" drops=\"<<drops<<\"\\n\";\n    }\n}\n\nint main(){ alt_001::step(); return 0; }\n","compliant":"..."}
```

**Notice:**
- Seed's 8-line code expanded to 45-line program
- Core violations (`float error=0.0F, integral=0.0F; // NC`) preserved from seed
- Added domain types (`State`), helper functions (`clamp`), loops, calculations
- Structure and logic identical between NC and C, only the declarations differ

---

## PRE-OUTPUT VERIFICATION CHECKLIST

Before generating output, verify:
- [ ] Seed input extracted: number, context, noncompliant code, compliant code
- [ ] Both programs are 40-60 lines each
- [ ] Both compile successfully with `g++ -std=c++17 -Wall -Wextra -pedantic -fsyntax-only`
- [ ] Programs are structurally identical except for the rule violation/fix
- [ ] Seed violations/fixes preserved and expanded appropriately
- [ ] Domain-appropriate types, functions, and logic added
- [ ] Violations marked with `// NC`, fixes with `// C`
- [ ] JSONL uses `\n` for newlines (not `\\n`)
- [ ] JSONL syntax is valid
- [ ] Namespace format: `app_{{SEED_NUM}}`
- [ ] Context description matches the seed

---

## COMMON PITFALLS TO AVOID

1. **Ignoring seed code**: Must use seed as the foundation, not create from scratch
2. **Replacing seed violations**: Keep the exact violations from seed, just expand around them
3. **Too short**: Programs must be 40-60 lines, not just the seed code
4. **Missing domain logic**: Include realistic calculations, loops, conditionals
5. **Inconsistent structure**: Both versions must be identical except for the rule fix
6. **Wrong escape sequence**: Use `\n` not `\\n` for newlines
7. **No helper functions**: Include static helper functions for realism
8. **Generic names**: Use domain-specific struct/variable names from context

---

## HOW TO USE THIS TEMPLATE

1. Fill in the **Rule Configuration** section with your rule details
2. For each seed input (JSONL line):
   - Extract: seed number, context, noncompliant code, compliant code
   - Expand the seed code to 40-60 lines following the structure template
   - Preserve seed violations/fixes exactly
   - Ensure both NC and C versions are identical except for the rule fix
3. Verify using the checklist
4. Output as JSONL format# PROGRAM Meta Prompt Template (Generic MISRA C++ Rule)

You are an expert C++ programmer and dataset engineer.  
Your goal is to generate two complete `.cpp` programs — one **Non-Compliant** and one **Compliant** — demonstrating a specific MISRA C++ rule violation and its fix.

---

## INPUT FORMAT

Each input record contains:
- `program`: unique program number
- `context`: domain-specific context description
- `noncompliant`: seed code showing the violation
- `compliant`: seed code with the fix

---

## RULE CONFIGURATION (Fill these in):
```
RULE_NUMBER: {{RULE_NUMBER}}
RULE_DESCRIPTION: {{RULE_DESCRIPTION}}
VIOLATION_TYPE: {{VIOLATION_TYPE}}
FIX_PATTERN: {{FIX_PATTERN}}
```

---

## OUTPUT REQUIREMENTS

Generate **two compilable C++ programs** for each seed:

1️⃣ **Non-Compliant Program** (`{{PROGRAM_NUM}}_nc.cpp`)  
2️⃣ **Compliant Program** (`{{PROGRAM_NUM}}_c.cpp`)

**Both must:**
- Contain a top comment header with metadata (program number, rule, context, violation).
- Be **structurally identical**, except for the specific rule violation/fix.
- Compile successfully with: `g++ -std=c++17 -Wall -Wextra -pedantic -fsyntax-only`.
- Use only standard C++ headers (no external dependencies).
- Be **40-60 lines each** (including headers and comments).
- Include meaningful domain-appropriate logic (not just variable declarations).
- Use the seed code as the foundation and expand it into a complete program.

---

## PROGRAM STRUCTURE TEMPLATE

### Non-Compliant Program:
```cpp
// ------ Non-Compliant Program ({{PROGRAM_NUM}}_nc.cpp)
// Seed {{SEED_NUM}} — Context: {{CONTEXT}}
// Reference: MISRA C++ {{RULE_NUMBER}} — {{RULE_DESCRIPTION}}
// Violation: {{VIOLATION_TYPE}}

#include <iostream>
#include <vector>
#include <cmath>
// Add other headers as needed

namespace app_{{PROGRAM_NUM}} {
    // Type definitions
    struct {{DomainType}} { /* fields */ };
    
    // Helper functions
    static {{ReturnType}} helperFunction({{params}}) {
        // Implementation
    }
    
    // Main logic function
    void mainFunction() {
        // Variable declarations with violations marked // NC
        {{TYPE}} {{VAR1}}={{VAL1}}, {{VAR2}}={{VAL2}};  // NC
        
        // Functional logic demonstrating domain context
        // Include loops, calculations, conditionals
        
        // Output showing results
        std::cout << /* results */ << "\n";
    }
}

int main() {
    app_{{PROGRAM_NUM}}::mainFunction();
    return 0;
}
```

### Compliant Program:
```cpp
// ------ Compliant Program ({{PROGRAM_NUM}}_c.cpp)
// Seed {{SEED_NUM}} — Context: {{CONTEXT}}
// Reference: MISRA C++ {{RULE_NUMBER}} — {{RULE_DESCRIPTION}}
// Fix: {{FIX_PATTERN}}

#include <iostream>
#include <vector>
#include <cmath>
// Add other headers as needed

namespace app_{{PROGRAM_NUM}} {
    // Type definitions (identical to NC)
    struct {{DomainType}} { /* fields */ };
    
    // Helper functions (identical to NC)
    static {{ReturnType}} helperFunction({{params}}) {
        // Implementation
    }
    
    // Main logic function
    void mainFunction() {
        // Variable declarations with fix applied marked // C
        {{TYPE}} {{VAR1}}={{VAL1}};  // C
        {{TYPE}} {{VAR2}}={{VAL2}};  // C
        
        // Functional logic (IDENTICAL to NC version)
        // Include loops, calculations, conditionals
        
        // Output showing results (identical to NC)
        std::cout << /* results */ << "\n";
    }
}

int main() {
    app_{{PROGRAM_NUM}}::mainFunction();
    return 0;
}
```

---

## CONSTRAINTS

1. **Code Expansion**: Take the seed code and expand it into 40-60 line programs with:
   - Realistic type definitions (structs/classes matching domain)
   - Helper functions (clamp, wrap, calculate, etc.)
   - Main logic function with loops, conditionals, calculations
   - Meaningful output demonstrating the computation

2. **Structural Identity**: Both NC and C versions must be identical except for:
   - The comment headers (NC vs C)
   - The specific rule violation/fix
   - The inline comment markers (`// NC` vs `// C`)

3. **Domain Realism**: 
   - Use appropriate types for the domain (e.g., `Pose` for robotics, `Phase` for power systems)
   - Include realistic variable names and calculations
   - Add domain-specific comments explaining the logic

4. **Compilation**: Both versions must compile without errors or warnings

5. **Namespacing**: Use `app_{{PROGRAM_NUM}}` namespace consistently

6. **Comments**: 
   - Mark violations with `// NC` or `// non-compliant`
   - Mark fixes with `// C` or `// compliant`
   - Keep inline comments minimal and clear

---

## JSONL OUTPUT FORMAT

Generate output as JSONL with fields: `program`, `context`, `noncompliant`, `compliant`

```json
{"program":{{PROGRAM_NUM}},"context":"{{CONTEXT}}","noncompliant":"{{ESCAPED_NC_CODE}}","compliant":"{{ESCAPED_C_CODE}}"}
```

**Escaping rules:**
- Use `\n` for newlines (single backslash)
- Escape double quotes: `"` → `\"`
- Escape backslashes: `\` → `\\`
- Each JSONL line must be valid JSON

---

## EXAMPLE OUTPUT (Reference Format)

```json
{"program":1,"context":"Autonomous drone altitude hold loop","noncompliant":"// ------ Non-Compliant Program (001_nc.cpp)\n// Seed 1 — Context: Autonomous drone altitude hold loop\n// Rule: MISRA C++ 8-0-1 — Each declaration shall declare no more than one declarator\n// Violation: multiple declarators per declaration\n\n#include <iostream>\n#include <iomanip>\n#include <array>\n#include <cstddef>\n\nnamespace alt_001 {\n    struct State { float alt; float vel; };\n    static float clamp(float v, float lo, float hi){ return v < lo ? lo : (v > hi ? hi : v); }\n    \n    void step(){\n        float error=0.0F, integral=0.0F;        // NC (two declarators)\n        double kp=1.10, ki=0.05;                // NC (two declarators)\n        int samples=0, drops=0;                 // NC (two declarators)\n        State s{0.0F, 0.0F};\n        const float dt=0.02F;\n        std::array<float,6U> refs{1.0F,1.1F,0.9F,1.2F,1.0F,0.8F};\n        \n        for (std::size_t i=0U; i<refs.size(); ++i){\n            float set=refs[i];\n            error = set - s.alt;\n            integral += error * dt;\n            float u = static_cast<float>(kp)*error + static_cast<float>(ki)*integral;\n            u = clamp(u,-2.0F,2.0F);\n            s.vel += u * dt;\n            s.alt += s.vel * dt;\n            samples++;\n            if ((i%3U)==0U) { drops++; }\n            if ((i%2U)==0U) {\n                std::cout<<\"t=\"<<i<<\" alt=\"<<std::fixed<<std::setprecision(2)<<s.alt\n                         <<\" err=\"<<error<<\" u=\"<<u<<\"\\n\";\n            }\n        }\n        std::cout<<\"done samples=\"<<samples<<\" drops=\"<<drops<<\"\\n\";\n    }\n}\n\nint main(){ alt_001::step(); return 0; }\n","compliant":"// ------ Compliant Program (001_c.cpp)\n// Seed 1 — Context: Autonomous drone altitude hold loop\n// Rule: MISRA C++ 8-0-1 — Each declaration shall declare no more than one declarator\n// Fix: split every declaration so each has a single declarator\n\n#include <iostream>\n#include <iomanip>\n#include <array>\n#include <cstddef>\n\nnamespace alt_001 {\n    struct State { float alt; float vel; };\n    static float clamp(float v, float lo, float hi){ return v < lo ? lo : (v > hi ? hi : v); }\n    \n    void step(){\n        float error=0.0F;                    // C\n        float integral=0.0F;                 // C\n        double kp=1.10;                      // C\n        double ki=0.05;                      // C\n        int samples=0;                       // C\n        int drops=0;                         // C\n        State s{0.0F, 0.0F};\n        const float dt=0.02F;\n        std::array<float,6U> refs{1.0F,1.1F,0.9F,1.2F,1.0F,0.8F};\n        \n        for (std::size_t i=0U; i<refs.size(); ++i){\n            float set=refs[i];\n            error = set - s.alt;\n            integral += error * dt;\n            float u = static_cast<float>(kp)*error + static_cast<float>(ki)*integral;\n            u = clamp(u,-2.0F,2.0F);\n            s.vel += u * dt;\n            s.alt += s.vel * dt;\n            samples++;\n            if ((i%3U)==0U) { drops++; }\n            if ((i%2U)==0U) {\n                std::cout<<\"t=\"<<i<<\" alt=\"<<std::fixed<<std::setprecision(2)<<s.alt\n                         <<\" err=\"<<error<<\" u=\"<<u<<\"\\n\";\n            }\n        }\n        std::cout<<\"done samples=\"<<samples<<\" drops=\"<<drops<<\"\\n\";\n    }\n}\n\nint main(){ alt_001::step(); return 0; }\n"}
```

---

## PRE-OUTPUT VERIFICATION CHECKLIST

Before generating output, verify:
- [ ] Both programs are 40-60 lines each
- [ ] Both compile successfully with `g++ -std=c++17 -Wall -Wextra -pedantic -fsyntax-only`
- [ ] Programs are structurally identical except for the rule violation/fix
- [ ] Domain-appropriate types, functions, and logic included
- [ ] Violations marked with `// NC`, fixes with `// C`
- [ ] JSONL uses `\n` for newlines (not `\\n`)
- [ ] JSONL syntax is valid
- [ ] Namespace format: `app_{{PROGRAM_NUM}}`
- [ ] Context description matches the domain

---

## COMMON PITFALLS TO AVOID

1. **Too short**: Programs must be 40-60 lines, not just expanded seeds
2. **Missing domain logic**: Include realistic calculations, loops, conditionals
3. **Inconsistent structure**: Both versions must be identical except for the rule fix
4. **Wrong escape sequence**: Use `\n` not `\\n` for newlines
5. **No helper functions**: Include static helper functions for realism
6. **Generic names**: Use domain-specific struct/variable names
7. **Compilation errors**: Test both versions compile successfully

---

## HOW TO USE THIS TEMPLATE

1. Fill in the **Rule Configuration** section with your rule details
2. For each seed input, expand the code to 40-60 lines following the structure template
3. Ensure both NC and C versions are identical except for the rule violation/fix
4. Verify using the checklist
5. Output as JSONL format