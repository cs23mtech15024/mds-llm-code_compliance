# Expanded MISRA C++ Program Pairs

## Overview
This dataset contains **100 expanded program pairs** demonstrating MISRA C++ Rule 8-0-1 violations and their corrections. Each pair consists of:
- A **non-compliant** version with multiple declarators per declaration (violates 8-0-1)
- A **compliant** version with one declarator per declaration (follows 8-0-1)

## Specifications
- **Total Programs**: 100 pairs (200 total programs)
- **Line Count**: 73-82 lines per program (exceeds 45-65 minimum requirement)
- **Format**: JSONL (JSON Lines) - one JSON object per line
- **Rule**: MISRA C++ 8-0-1 - "An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively"

## File Structure

### JSONL Format
Each line contains one JSON object with these fields:
```json
{
  "program": <number>,
  "context": "<domain/application context>",
  "noncompliant": "<full C++ program with 8-0-1 violations>",
  "compliant": "<full C++ program compliant with 8-0-1>"
}
```

### Program Structure
Each program includes:
- Header comments indicating compliance status
- Proper include directives
- Namespace encapsulation
- Struct definitions (where struct members are allowed multiple per line)
- Helper functions (static)
- Main execution function with loop processing
- Proper main() function

## Domain Coverage

The 100 programs span diverse industrial and embedded systems domains:

### Aerospace & Aviation
- Autonomous drone altitude control
- Spacecraft solar array tracking
- Aircraft engine thrust optimization
- Satellite orbit maintenance

### Medical & Healthcare
- Ventilator flow estimation
- Infusion pump rate control
- MRI coil temperature regulation
- Surgical robot kinematics

### Industrial Automation
- Factory conveyor monitoring
- Robotic arm trajectory planning
- CNC machine tool compensation
- Assembly line quality inspection

### Transportation
- Railway braking systems
- Automotive diagnostics
- EV charging management
- Traffic signal synchronization

### Energy & Power
- Solar panel MPPT tracking
- Wind turbine pitch control
- Battery management systems
- Nuclear reactor monitoring

### Infrastructure
- Building HVAC control
- Elevator dispatch systems
- Water treatment monitoring
- Bridge structural monitoring

### Consumer & Entertainment
- Smart thermostat control
- Gaming systems
- Audio processing
- Display calibration

And many more specialized domains including marine, mining, agricultural, security, and research applications.

## Program Types

Programs are categorized by functional type:

1. **Controllers** (~40%): PID loops, adaptive control, feedback systems
2. **Monitors** (~30%): Watchdogs, diagnostics, health checking
3. **Estimators** (~15%): Filters, analyzers, signal processing  
4. **Schedulers** (~10%): Resource allocation, task management
5. **Processors** (~5%): Data transformation, validation

## Violation Pattern

All non-compliant programs demonstrate MISRA Rule 8-0-1 violations through multiple declarators:

**Non-Compliant Example:**
```cpp
float error=0.0F, integral=0.0F;        // NC (two declarators)
double kp=1.10, ki=0.05;                // NC (two declarators)  
int samples=0, drops=0;                 // NC (two declarators)
```

**Compliant Fix:**
```cpp
float error=0.0F;                       // C
float integral=0.0F;                    // C
double kp=1.10;                         // C
double ki=0.05;                         // C
int samples=0;                          // C
int drops=0;                            // C
```

Note: Struct members are allowed to have multiple declarators per MISRA rules, so lines like:
```cpp
struct State { float alt; float vel; }; // OK
```
are compliant in both versions.

## Usage

### Loading the Dataset

**Python:**
```python
import json

programs = []
with open('expanded_misra_cpp_programs.jsonl', 'r') as f:
    for line in f:
        prog = json.loads(line)
        programs.append(prog)

print(f"Loaded {len(programs)} program pairs")
```

**Command Line:**
```bash
# Count programs
wc -l expanded_misra_cpp_programs.jsonl

# Extract specific program
sed -n '1p' expanded_misra_cpp_programs.jsonl | jq '.'

# Get all contexts
cat expanded_misra_cpp_programs.jsonl | jq -r '.context'
```

### Compiling Programs

Each program can be extracted and compiled independently:

```python
import json

# Extract program 1
with open('expanded_misra_cpp_programs.jsonl', 'r') as f:
    prog = json.loads(f.readline())

# Save non-compliant version
with open('001_nc.cpp', 'w') as f:
    f.write(prog['noncompliant'])

# Save compliant version  
with open('001_c.cpp', 'w') as f:
    f.write(prog['compliant'])
```

Compile with:
```bash
g++ -std=c++11 -Wall -Wextra 001_nc.cpp -o 001_nc
g++ -std=c++11 -Wall -Wextra 001_c.cpp -o 001_c
```

## Quality Assurance

All programs have been verified to:
- ✅ Parse as valid JSON
- ✅ Contain all required fields
- ✅ Meet 45-65+ line minimum (actual: 73-82 lines)
- ✅ Include proper MISRA 8-0-1 violations in NC versions
- ✅ Fix all violations in C versions
- ✅ Maintain functional equivalence between NC and C versions
- ✅ Compile successfully with C++11 or later
- ✅ Cover unique domains and contexts

## Statistics

- **Total Programs**: 100 pairs
- **Total Lines**: ~15,250 lines of C++ code
- **Average NC Length**: 75.3 lines
- **Average C Length**: 78.3 lines
- **File Size**: 526 KB
- **Unique Domains**: 100
- **Unique Contexts**: 100

## Applications

This dataset is suitable for:
- Training code compliance checkers
- Teaching MISRA C++ rules
- Testing static analysis tools
- Machine learning on code patterns
- Automated code refactoring research
- Safety-critical software education
- Code smell detection
- Style enforcement tool development

## Notes

1. All programs use namespaces to avoid naming conflicts
2. Programs are self-contained (compilable independently)
3. Each program outputs to stdout for verification
4. Floating-point suffixes (F, U, L) used for type safety
5. Array sizes specified with U suffix for unsigned
6. All programs follow modern C++ best practices aside from the deliberate MISRA violations

## License & Usage

These programs are generated for educational and research purposes to demonstrate MISRA C++ compliance patterns in realistic industrial contexts.

## Generated

- Date: October 26, 2025
- Generator: Automated MISRA C++ program generator
- Based on: 100 seed program contexts
- Rule: MISRA C++ 2008 Rule 8-0-1
