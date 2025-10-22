"""
SEED Meta Prompt Template (Generic MISRA C++ Rule)
This is a ready-to-use prompt that can be copied and pasted into an LLM UI.
Simply fill in the placeholder values before using.
"""

SEED_PROMPT = """
# SEED Meta Prompt Template (Generic MISRA C++ Rule)

You are an expert in MISRA C++ rule-based code generation and automated dataset creation.  
Your task is to generate **SEED pairs** demonstrating correct and incorrect compliance with a specific **MISRA C++ rule**.  
The rule details will be provided as placeholders to be filled in.  
Your output must strictly follow all constraints and produce valid JSONL lines suitable for dataset creation.

---

## Meta Prompt — SEED Generation

### **Goal:**
Generate concise seed pairs (non-compliant/compliant) illustrating the violation and fix for the selected **MISRA rule**.

### **Rule Configuration (Fill these in):**
```
RULE_NUMBER: <e.g., 8-0-1, 2-13-4>
RULE_DESCRIPTION: <e.g., "Literal suffixes shall be upper case">
VIOLATION_TYPE: <e.g., "lowercase suffixes like f, u, l">
FIX_PATTERN: <e.g., "change to uppercase F, U, L">
RANGE_START: <e.g., 1>
RANGE_END: <e.g., 100>
```

### **Inputs:**
- **Rule Number**: `{{RULE_NUMBER}}`
- **Rule Description**: `{{RULE_DESCRIPTION}}`
- **Violation Type**: `{{VIOLATION_TYPE}}`
- **Fix Pattern**: `{{FIX_PATTERN}}`
- **Seed Range**: `{{RANGE_START}}` to `{{RANGE_END}}`
- **Primeval Data File**: (Optional) Reference JSONL file with existing examples for style guidance

### **Context Domain Pool:**
Generate contexts from diverse safety-critical domains:
- **Aerospace**: UAV control, satellite systems, flight control, altitude hold
- **Automotive**: ADAS, engine control, battery management, CAN bus
- **Robotics**: path planning, SLAM, gripper control, navigation
- **Industrial**: conveyor systems, CNC machines, quality control, PLCs
- **Energy**: solar trackers, wind turbines, power grid, smart meters
- **Medical**: ventilators, infusion pumps, patient monitoring, X-ray systems
- **Marine**: ship navigation, underwater vehicles, oil spill response, sonar
- **IoT**: sensor networks, smart home, environmental monitoring, edge devices
- **Rail**: signaling systems, train control, track monitoring
- **Defense**: radar systems, missile guidance, cryptography

### **Constraints:**
1. **Numbering:** Sequential seed numbering from `{{RANGE_START}}` to `{{RANGE_END}}`.
2. **Contexts:** Each seed must have a **unique** and **domain-diverse** context (no repetition).
3. **Rule Focus:** 
   - Non-compliant code must demonstrate **exactly ONE clear instance** of `{{VIOLATION_TYPE}}`.
   - Compliant code must fix **only that violation** - no other changes.
   - Mark violations with `// NC` and fixes with `// C` in inline comments.
4. **Code Quality:**
   - 15-35 lines of C++ code (including headers, namespace, main function).
   - Must compile successfully with `g++ -std=c++17 -fsyntax-only`.
   - Use realistic variable names matching the domain context.
   - Include meaningful computation and logic, not just variable declarations.
   - Use proper C++ idioms (namespaces, const correctness, etc.).
5. **Avoid Unrelated Violations:** Focus solely on `{{RULE_NUMBER}}`.
6. **No Placeholder Code:** All code must be complete and functional.
7. **Output Format:** JSONL with fields: `seed`, `context`, `noncompliant`, `compliant`.
8. **JSON Validity:** Each line must be valid JSON, no trailing commas.

### **Code Structure Template:**
```cpp
// ------ Non-Compliant (Seed XXX)
// Context: <domain-specific context>
// Rule: MISRA C++ {{RULE_NUMBER}} — {{RULE_DESCRIPTION}}
// Violation: {{VIOLATION_TYPE}}

#include <required_headers>

namespace app_XXX {
    // Type definitions if needed
    
    void functionName() {
        // Variable declarations with violations marked // NC
        // Functional logic demonstrating the context
    }
}

int main() {
    app_XXX::functionName();
    return 0;
}
```

### **Special Considerations:**
1. **For Multiple Declarator Rules (e.g., 8-0-1):**
   - Avoid range-based for loops in compliant code: `for(auto x : vec)` → use index-based loops
   - Keep all declarations separate: `int a=1; int b=2;` not `int a=1, b=2;`
   - No multiple statements on same line with declarations

2. **For Literal Suffix Rules (e.g., 2-13-4):**
   - Include various literal types: float (f/F), unsigned (u/U), long (l/L), hex (0xff)
   - Show violations in different contexts: constants, function arguments, calculations

3. **For Other Rules:**
   - Adapt based on `{{VIOLATION_TYPE}}` and `{{FIX_PATTERN}}`

### **JSONL Escaping Rules:**
When generating JSONL output:
- Escape backslashes: `\\` → `\\\\`
- Escape double quotes: `"` → `\\"`
- Escape newlines: Use `\\n` for line breaks
- Do NOT insert actual line breaks within JSON string values
- Ensure proper JSON array/object syntax

### **Pre-Output Verification Checklist:**
Before generating output, verify:
- [ ] All contexts are unique and realistic (no duplicates)
- [ ] Each non-compliant snippet shows **exactly one** instance of `{{VIOLATION_TYPE}}`
- [ ] Each compliant snippet fixes **only** that violation (minimal diff)
- [ ] Both versions would compile with `g++ -std=c++17`
- [ ] No range-based for loops in compliant code (for declarator rules)
- [ ] No multiple statements on same line with declarations
- [ ] Code is functional with meaningful logic
- [ ] JSONL syntax is valid (test with JSON parser)
- [ ] Context descriptions are under 100 characters
- [ ] Seed numbers are sequential within range

### **Common Pitfalls to Avoid:**
1. **Range-based loops**: In compliant code, use `for(size_t i=0; i<vec.size(); ++i)` instead of `for(auto& x : vec)`
2. **Compacted declarations**: Never write `float a=1.0F; float b=2.0F;` on same line
3. **Inconsistent changes**: Only fix the target rule violation, keep everything else identical
4. **Generic contexts**: Use specific, realistic domain contexts, not "example system"
5. **Missing headers**: Include all necessary standard headers
6. **Unrealistic code**: Every snippet should look like production embedded/safety code
7. **Wrong escape sequences**: Test JSONL validity before outputting

### **Output Format:**
```
# SEED Generation for MISRA C++ {{RULE_NUMBER}}
{"seed":{{RANGE_START}},"context":"<domain context>","noncompliant":"<escaped C++ code>","compliant":"<escaped C++ code>"}
{"seed":{{RANGE_START+1}},"context":"<different domain context>","noncompliant":"<escaped C++ code>","compliant":"<escaped C++ code>"}
...
{"seed":{{RANGE_END}},"context":"<unique domain context>","noncompliant":"<escaped C++ code>","compliant":"<escaped C++ code>"}
```

### **JSONL Example (Template):**
```json
{"seed":1,"context":"UAV altitude hold control module","noncompliant":"// ------ Non-Compliant (Seed 001)\\\\n// Context: UAV altitude hold control module\\\\n// Rule: MISRA C++ {{RULE_NUMBER}} — {{RULE_DESCRIPTION}}\\\\n// Violation: {{VIOLATION_TYPE}}\\\\n\\\\n#include <iostream>\\\\n#include <cmath>\\\\n\\\\nnamespace app_001 {\\\\n    void control() {\\\\n        float gain = 1.25f;  // NC\\\\n        int samples = 100u;  // NC\\\\n        // ... functional code ...\\\\n        std::cout << gain << std::endl;\\\\n    }\\\\n}\\\\n\\\\nint main() {\\\\n    app_001::control();\\\\n    return 0;\\\\n}\\\\n","compliant":"// ------ Compliant (Seed 001)\\\\n// Context: UAV altitude hold control module\\\\n// Rule: MISRA C++ {{RULE_NUMBER}} — {{RULE_DESCRIPTION}}\\\\n// Fix: {{FIX_PATTERN}}\\\\n\\\\n#include <iostream>\\\\n#include <cmath>\\\\n\\\\nnamespace app_001 {\\\\n    void control() {\\\\n        float gain = 1.25F;  // C\\\\n        int samples = 100U;  // C\\\\n        // ... functional code ...\\\\n        std::cout << gain << std::endl;\\\\n    }\\\\n}\\\\n\\\\nint main() {\\\\n    app_001::control();\\\\n    return 0;\\\\n}\\\\n"}
```

---

## Usage Instructions:

1. **Fill in the Rule Configuration section** with your specific rule details
2. **Replace all `{{PLACEHOLDER}}` instances** with actual values
3. **Review the constraints** to ensure they match your rule's requirements
4. **Generate seeds** ensuring each context is unique and domain-diverse
5. **Validate output** using the verification checklist
6. **Test compilation** on a sample of generated code pairs

---

## Notes:
- This template is rule-agnostic and can be adapted for any MISRA C++ rule
- Adjust "Special Considerations" section based on your specific rule type
- Keep the primeval data reference if you have existing examples to learn from
- Maintain consistency in formatting and structure across all generated seeds
"""
