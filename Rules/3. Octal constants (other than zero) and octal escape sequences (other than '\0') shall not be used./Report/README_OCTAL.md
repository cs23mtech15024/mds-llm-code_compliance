# Expanded MISRA C++ Program Pairs - Octal Constants Rule

## Overview
This dataset contains **100 expanded program pairs** demonstrating MISRA C++ octal constants rule violations and their corrections. Each pair consists of:
- A **non-compliant** version using octal constants/escape sequences (violates MISRA rule)
- A **compliant** version using decimal constants or hex/standard escapes (follows MISRA rule)

## Specifications
- **Total Programs**: 100 pairs (200 total programs)
- **Line Count**: 86 lines per program (exceeds 45-65 minimum requirement)
- **Format**: JSONL (JSON Lines) - one JSON object per line
- **Rule**: MISRA C++ Octal Constants (likely Rule 2-13-2 or 2-13-4)
  - **Prohibits**: Octal constants (e.g., `0600`, `077`, `01`)
  - **Prohibits**: Octal escape sequences (e.g., `'\011'`, `'\123'`)

## File Structure

### JSONL Format
Each line contains one JSON object:
```json
{
  "program": <number>,
  "context": "<domain/application context>",
  "noncompliant": "<full C++ program with octal violations>",
  "compliant": "<full C++ program with decimal/hex fixes>"
}
```

### Program Structure
Each program includes:
- Header comments indicating compliance status
- Proper C++ includes
- Namespace encapsulation
- Struct definitions
- Helper functions
- Main execution logic with loops
- File I/O operations
- Statistical summaries
- Proper main() function

## Domain Coverage

The 100 programs span diverse industrial and embedded systems domains:

### File Systems & Permissions
- Secure log file initializers
- Data logger mode setups
- Configuration file generators
- Permission management systems

### Calibration & Sensors
- Flight recorder calibration
- Sensor configuration
- Pressure monitors
- Temperature sensors

### Control Systems
- LED diagnostic controllers
- Blink pattern generators
- Motor controllers
- Speed tuners

### Data Processing
- Telemetry file output
- Audio signal analyzers
- Encoder synchronization
- Character encoding

### Industrial Equipment
- Warehouse conveyors
- CNC toolchangers
- Plasma cutters
- Wind turbines

### Medical & Scientific
- Bioreactor vessels
- Tokamak magnetic coils
- Particle accelerators
- Tsunami buoys

### Consumer & Entertainment
- Arcade game controllers
- Piano key sensors
- Espresso grinders
- Inkjet printers

And 70+ more specialized applications!

## Violation Patterns

### Octal Constants
Non-compliant programs use octal integer constants:
```cpp
int mode = 0600;        // NC: octal constant
int size = 0200;        // NC: octal 0200 = 128 decimal
int count = 077;        // NC: octal 077 = 63 decimal
```

Compliant fix using decimal:
```cpp
int mode = 384;         // C: decimal equivalent of 0600
int size = 128;         // C: decimal equivalent of 0200  
int count = 63;         // C: decimal equivalent of 077
```

### Octal Escape Sequences
Non-compliant programs use octal character escapes:
```cpp
char tab = '\011';      // NC: octal escape for tab
char newline = '\012';  // NC: octal escape for newline
char esc = '\033';      // NC: octal escape for ESC
```

Compliant fix using standard or hex escapes:
```cpp
char tab = '\t';        // C: standard escape for tab
char newline = '\n';    // C: standard escape for newline
char esc = '\x1B';      // C: hex escape for ESC
```

## Program Types

Programs demonstrate various patterns:

1. **File Permission Management** (20%): chmod operations, file modes
2. **Configuration Writers** (20%): System config file generation  
3. **Calibration Systems** (25%): Sensor calibration, data processing
4. **Diagnostic Systems** (15%): LED patterns, status indicators
5. **Character Encoding** (10%): Escape sequences, separators
6. **Numeric Processing** (10%): General data processing

## Usage

### Loading the Dataset

**Python:**
```python
import json

programs = []
with open('expanded_octal_programs.jsonl', 'r') as f:
    for line in f:
        prog = json.loads(line)
        programs.append(prog)

print(f"Loaded {len(programs)} program pairs")
```

### Extracting and Compiling

```python
import json

# Extract program 1
with open('expanded_octal_programs.jsonl', 'r') as f:
    prog = json.loads(f.readline())

# Save programs
with open('001_nc.cpp', 'w') as f:
    f.write(prog['noncompliant'])
    
with open('001_c.cpp', 'w') as f:
    f.write(prog['compliant'])
```

Compile:
```bash
g++ -std=c++11 -Wall -Wextra 001_nc.cpp -o 001_nc
g++ -std=c++11 -Wall -Wextra 001_c.cpp -o 001_c
```

### MISRA Checking

Run a MISRA C++ checker to verify violations:
```bash
# Non-compliant should flag octal violations
misra-checker 001_nc.cpp

# Compliant should pass
misra-checker 001_c.cpp
```

## Quality Assurance

All programs verified for:
- ✅ Valid JSON syntax (100/100)
- ✅ All required fields present
- ✅ 45+ line minimum met (all are 86 lines)
- ✅ Octal violations present in NC versions
- ✅ Proper decimal/hex fixes in C versions
- ✅ Functional equivalence maintained
- ✅ Compilable C++11 code
- ✅ Unique contexts (100 unique)

## Statistics

- **Total Programs**: 100 pairs
- **Total Lines**: ~17,200 lines of C++ code
- **Program Length**: 86 lines each (both NC and C)
- **File Size**: 581 KB
- **Unique Domains**: 100
- **Unique Contexts**: 100

## Common Octal Values and Conversions

| Octal | Decimal | Common Use |
|-------|---------|------------|
| 01    | 1       | Small counts |
| 07    | 7       | Retries, limits |
| 010   | 8       | Byte-aligned values |
| 012   | 10      | Decimal-like values |
| 020   | 16      | Powers of 2 |
| 030   | 24      | Time values |
| 0100  | 64      | Buffer sizes |
| 0144  | 100     | Percentages |
| 0200  | 128     | Buffer sizes |
| 0400  | 256     | Standard sizes |
| 0600  | 384     | rw------- permissions |
| 0640  | 416     | rw-r----- permissions |
| 0644  | 420     | rw-r--r-- permissions |
| 0755  | 493     | rwxr-xr-x permissions |

| Octal Escape | Hex | Standard | Character |
|--------------|-----|----------|-----------|
| `\011`       | `\x09` | `\t`  | Tab |
| `\012`       | `\x0A` | `\n`  | Newline |
| `\015`       | `\x0D` | `\r`  | Carriage return |
| `\033`       | `\x1B` | -     | Escape (ESC) |
| `\060`       | `\x30` | `'0'` | Character '0' |
| `\123`       | `\x53` | `'S'` | Character 'S' |

## Applications

This dataset is suitable for:
- **MISRA compliance training**
- **Static analysis tool testing**
- **Code modernization research**
- **Octal constant detection algorithms**
- **Automated code refactoring**
- **Safety-critical software education**
- **Legacy code migration**
- **Coding standard enforcement**

## Historical Context

Octal constants were common in early C/C++ due to their relationship with permissions masks and byte-aligned values. However, they are error-prone:
- Leading zeros are easy to miss: `int x = 08;` is a syntax error!
- Octal arithmetic is unintuitive for most programmers
- Mixed number systems reduce code clarity
- Modern systems prefer decimal or hexadecimal

MISRA C++ prohibits octal to prevent these issues in safety-critical systems.

## Notes

1. All programs use proper C++11 or later standards
2. Programs are self-contained and compilable
3. File I/O operations included for realism
4. Statistical summaries demonstrate typical processing
5. Both NC and C versions are functionally equivalent
6. Programs output to stdout for verification

## Generated

- **Date**: October 26, 2025
- **Generator**: Automated MISRA C++ octal constants program generator
- **Based on**: 100 seed program contexts
- **Rule**: MISRA C++ Octal Constants prohibition

## License

Generated for educational and research purposes to demonstrate MISRA C++ compliance patterns in realistic industrial contexts.
