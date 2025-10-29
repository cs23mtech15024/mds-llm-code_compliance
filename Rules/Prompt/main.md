# MISRA C++ Rule — PROGRAM Meta Prompt

You are an expert MISRA C++ dataset engineer.
Generate **program pairs** (non-compliant/compliant) showing a MISRA rule violation and its fix in realistic, production-like code.

---
## RULE CONFIG
```
RULE_NUMBER: {{RULE_NUMBER}}
RULE_DESCRIPTION: {{RULE_DESCRIPTION}}
VIOLATION_TYPE: {{VIOLATION_TYPE}}
FIX_PATTERN: {{FIX_PATTERN}}
RANGE_START: {{RANGE_START}}
RANGE_END: {{RANGE_END}}
SEED_FILE: {{SEED_FILE}}  # Path to corresponding seed JSONL file
```

---
## GOAL
For each program ({{RANGE_START}}–{{RANGE_END}}), output realistic C++ code pairs (45–65 lines) that:
- **Expand on the corresponding seed** with production-like complexity
- Show **one clear violation** (`// NC`) and its fix (`// C`)
- Are **domain-realistic**, compilable with `g++ -std=c++17 -fsyntax-only`
- Use **same domain, program, and functionality** as the seed
- Have **minimal differences** between non-compliant and compliant versions

---
## RELATIONSHIP TO SEEDS

### Core Principle
Each program is a **realistic expansion** of its corresponding seed:
- **Same seed number** → Same program number
- **Same domain** → Keep the application area (Financial, Automotive, etc.)
- **Same program/functionality** → Keep the system/feature (risk encoder, brake monitor, etc.)
- **Same technical context** → Keep the specific implementation purpose

### Expansion Strategy
Transform the minimal seed (5-15 lines) into a production-quality program (45-65 lines) by adding:
1. **Multiple functions** (3-5 functions typical)
2. **Helper routines** (validation, calculation, formatting)
3. **Data structures** (structs, arrays, multiple variables)
4. **Realistic logic flow** (initialization, processing, validation, output)
5. **Error handling** (basic checks, boundary conditions)
6. **Comments** (function headers, complex logic explanation)
7. **Production patterns** (const correctness, namespaces, proper types)

### Example Transformation

**Seed (12 lines):**
```cpp
// Seed 001 — NC: lowercase hex A–F
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t credit=0xa5, liquid=0x1f, market=0xbe; // NC
    std::uint8_t code = static_cast<std::uint8_t>(credit ^ market ^ liquid);
    std::cout << "risk=0x" << std::hex << static_cast<unsigned>(code) << "\n";
    return 0;
}
```

**Program (52 lines):**
```cpp
// Program 001 — NC: lowercase hex in financial risk encoding
#include <cstdint>
#include <iostream>
#include <array>

namespace risk_analysis {
    // Risk category bit flags - NC: lowercase hex
    constexpr std::uint8_t CREDIT_RISK = 0xa5;      // NC
    constexpr std::uint8_t LIQUIDITY_RISK = 0x1f;  // NC
    constexpr std::uint8_t MARKET_RISK = 0xbe;     // NC
    constexpr std::uint8_t OPERATIONAL_RISK = 0x3c; // NC
    
    struct RiskProfile {
        std::uint8_t credit_score;
        std::uint8_t liquidity_score;
        std::uint8_t market_score;
        std::uint8_t operational_score;
    };
    
    // Calculate composite risk code
    std::uint8_t calculate_risk_code(const RiskProfile& profile) {
        std::uint8_t composite = static_cast<std::uint8_t>(
            profile.credit_score ^ profile.market_score ^ profile.liquidity_score
        );
        composite = static_cast<std::uint8_t>(composite | profile.operational_score);
        return composite;
    }
    
    // Validate risk thresholds
    bool validate_thresholds(const RiskProfile& profile) {
        const std::uint8_t MAX_THRESHOLD = 0xff; // NC
        return (profile.credit_score <= MAX_THRESHOLD &&
                profile.liquidity_score <= MAX_THRESHOLD &&
                profile.market_score <= MAX_THRESHOLD &&
                profile.operational_score <= MAX_THRESHOLD);
    }
    
    // Format risk output
    void print_risk_report(const RiskProfile& profile, std::uint8_t code) {
        std::cout << "Risk Assessment Report\n";
        std::cout << "----------------------\n";
        std::cout << "Credit Risk:      0x" << std::hex 
                  << static_cast<unsigned>(profile.credit_score) << "\n";
        std::cout << "Liquidity Risk:   0x" 
                  << static_cast<unsigned>(profile.liquidity_score) << "\n";
        std::cout << "Market Risk:      0x" 
                  << static_cast<unsigned>(profile.market_score) << "\n";
        std::cout << "Operational Risk: 0x" 
                  << static_cast<unsigned>(profile.operational_score) << "\n";
        std::cout << "Composite Code:   0x" << static_cast<unsigned>(code) << "\n";
    }
}

int main() {
    risk_analysis::RiskProfile profile{
        risk_analysis::CREDIT_RISK,
        risk_analysis::LIQUIDITY_RISK,
        risk_analysis::MARKET_RISK,
        risk_analysis::OPERATIONAL_RISK
    };
    
    if (risk_analysis::validate_thresholds(profile)) {
        std::uint8_t code = risk_analysis::calculate_risk_code(profile);
        risk_analysis::print_risk_report(profile, code);
    }
    
    return 0;
}
```

---
## UNIQUENESS REQUIREMENTS ⚠️ CRITICAL

Each program inherits uniqueness from its corresponding seed:

### 1. Domain Consistency
Must match the seed's domain exactly.
- Seed: "Financial risk-bucket encoder" → Program: Financial domain

### 2. Program/Functionality Consistency  
Must match the seed's program/functionality exactly.
- Seed: "risk-bucket encoder" → Program: same risk encoding system

### 3. Technical Context Consistency
Must match the seed's technical implementation purpose.
- Seed: "hex flags" → Program: continues to work with hex flag encoding

### 4. Expansion Uniqueness
While maintaining consistency with seed, ensure:
- Function names are unique and descriptive
- Variable names reflect the specific domain
- Logic flow is realistic for that application
- Data structures match domain requirements

---
## CODE REQUIREMENTS

### Structure (45-65 lines)
```cpp
// Program XXX — NC: <violation description>
#include <necessary_headers>
#include <cstdint>
#include <iostream>
#include <array>  // or other STL as needed

namespace domain_specific {
    // Constants with violations // NC
    constexpr std::uint8_t CONST1 = 0xab; // NC
    constexpr std::uint16_t CONST2 = 0xcd; // NC
    
    // Data structures
    struct DomainData {
        std::uint8_t field1;
        std::uint16_t field2;
        // 2-4 fields typical
    };
    
    // Helper function 1
    ReturnType helper_function_1(params) {
        // Implementation with violations where applicable
        return result;
    }
    
    // Helper function 2
    ReturnType helper_function_2(params) {
        // Implementation
        return result;
    }
    
    // Main processing function
    ReturnType process_data(params) {
        // Core logic using helper functions
        return result;
    }
    
    // Output/formatting function
    void display_results(params) {
        // Format and display
    }
}

int main() {
    // Initialize data
    domain_specific::DomainData data{...};
    
    // Process
    auto result = domain_specific::process_data(data);
    
    // Display
    domain_specific::display_results(result);
    
    return 0;
}
```

Compliant version: **identical structure** except fixes with `// C` comments.

### Guidelines
1. **Length**: 45–65 lines total (including comments, blank lines)
2. **Functions**: 3-5 functions typical
   - Constants/configuration
   - Helper functions (1-3)
   - Main processing function
   - Display/output function
3. **Data structures**: 1-2 structs with 2-4 fields
4. **Namespace**: Use domain-specific namespace
5. **Comments**: Function purpose, complex logic
6. **Error handling**: Basic validation, boundary checks
7. **One violation type**: All violations should be the same rule issue
8. **Compilable**: Must pass `g++ -std=c++17 -fsyntax-only`

### Expansion Elements to Add

**From Seed to Program, add:**
- ✅ Namespace wrapping
- ✅ Multiple related constants (not just 1-2)
- ✅ Struct/class for data organization
- ✅ Helper functions (calculation, validation, formatting)
- ✅ Main processing function
- ✅ Output formatting function
- ✅ `main()` that orchestrates the workflow
- ✅ Domain-appropriate variable names
- ✅ Realistic logic flow
- ✅ Basic error handling
- ✅ Comments explaining non-obvious logic

**Don't add:**
- ❌ Unrelated complexity
- ❌ Multiple violation types
- ❌ External dependencies
- ❌ File I/O (keep self-contained)
- ❌ Complex algorithms unrelated to domain
- ❌ Template metaprogramming
- ❌ Advanced C++ features unnecessarily

### Code Characteristics
- Use production-quality style (const correctness, clear naming)
- Include multiple instances of the violation throughout the code
- Keep violations consistent with the rule being demonstrated
- Ensure all violations are in the same category (e.g., all hex literals)
- Make variable/function names domain-specific and realistic
- Add logical coherence (functions work together)
- Include realistic computations for the domain

### Diversity Requirements
Across programs, vary:
- Number of functions (3-5 range)
- Struct complexity (2-4 fields)
- Number of constants (4-8 typical)
- Processing complexity (simple to moderate)
- Output format (cout, formatted tables, reports)
- Validation approaches (threshold checks, range validation)

---
## SPECIAL RULE NOTES

**Rule-Specific Adaptations:**
- **Declarator rules (8-0-1)**: Multiple functions, each with split declarations
- **Literal suffix rules (2-13-4)**: Show lowercase → uppercase literal fixes across multiple constants
- **Hex literal case (2-13-2)**: Vary hex patterns across constants, variables, and literals throughout
- **Other rules**: Adapt code structure to show violation in production context

---
## JSONL OUTPUT FORMAT

```json
{"program":N,"context":"<same as seed>","noncompliant":"<escaped code>","compliant":"<escaped code>"}
```

**Escaping Rules:**
- Newlines: `\\n`
- Backslashes: `\\\\`
- Quotes: `\\"`
- One JSON object per line (JSONL format)

**Example:**
```json
{"program":1,"context":"Financial risk-bucket encoder (hex flags)","noncompliant":"// Program 001 — NC: lowercase hex in financial risk encoding\\n#include <cstdint>\\n#include <iostream>\\n...","compliant":"// Program 001 — C: uppercase hex in financial risk encoding\\n#include <cstdint>\\n#include <iostream>\\n..."}
```

---
## VALIDATION CHECKLIST

Before outputting each program, verify:
- ✅ Program number matches corresponding seed number
- ✅ **Domain + program/functionality + context matches seed exactly**
- ✅ Code is 45-65 lines (count all lines including comments)
- ✅ Has 3-5 functions in domain-specific namespace
- ✅ Code compiles: `g++ -std=c++17 -fsyntax-only`
- ✅ Multiple violations of same rule throughout code
- ✅ Compliant version fixes ALL violations consistently
- ✅ Variable/function names match domain context
- ✅ Logic is realistic and coherent for the domain
- ✅ JSON is properly escaped and valid
- ✅ Difference between NC/C is clear (only the rule violations)
- ✅ No unrelated code quality issues

---
## GENERATION WORKFLOW

1. **Load corresponding seed** (seed N → program N)
2. **Extract domain, program/functionality, and context** from seed
3. **Design production-level expansion**:
   - Identify 3-5 related functions
   - Design appropriate data structure
   - Plan realistic logic flow
   - Determine where violations will appear (constants, variables, etc.)
4. **Write non-compliant version** (45-65 lines):
   - Add namespace
   - Define constants with violations
   - Create struct/data types
   - Implement helper functions
   - Implement main processing
   - Implement output function
   - Write `main()` orchestration
5. **Create compliant version**: Fix only the rule violations
6. **Verify compilation** and rule adherence
7. **Count lines** (must be 45-65)
8. **Format as JSONL** with proper escaping
9. **Validate** against checklist
10. **Output** single-line JSON object

**Critical**: Each program must be a natural, realistic expansion of its seed while maintaining the exact same domain, program/functionality, and technical context.

---
## QUALITY STANDARDS

- **Accuracy**: Code must correctly demonstrate rule violations in production context
- **Clarity**: Violations should be distributed throughout the code naturally
- **Realism**: Code should look like actual production safety-critical software
- **Consistency**: Program must align perfectly with its corresponding seed
- **Simplicity**: Avoid unnecessary complexity; focus on the rule demonstration
- **Completeness**: Every program must be self-contained and compilable
- **Domain-appropriate**: Use terminology, patterns, and logic from the specific domain

---
## SEED-TO-PROGRAM MAPPING

**Process:**
1. Read seed N from {{SEED_FILE}}
2. Extract: domain, program/functionality, context
3. Understand the minimal violation demonstrated in seed
4. Expand into realistic program maintaining same context
5. Output as program N with identical context field

**Example Mapping:**
```
Seed 1: "Financial risk-bucket encoder (hex flags)"
  → Simple code with 3 hex constants, basic XOR operation
  
Program 1: "Financial risk-bucket encoder (hex flags)" 
  → Full risk analysis system with:
     - Multiple risk category constants (all hex)
     - RiskProfile struct
     - Calculation function
     - Validation function
     - Formatting function
     - Complete workflow in main()
```

---
## OUTPUT

Generate {{RANGE_END - RANGE_START + 1}} programs in JSONL format.
Each line contains one complete program JSON object.
Each program corresponds to its seed with the same number.
Ensure all programs are realistic expansions of their seeds while maintaining exact context consistency.