# MISRA C++ Rule — SEED Meta Prompt

You are an expert MISRA C++ dataset engineer.
Generate **seed pairs** (non-compliant/compliant) showing a MISRA rule violation and its fix.

---
## RULE CONFIG
```
RULE_NUMBER: {{RULE_NUMBER}}
RULE_DESCRIPTION: {{RULE_DESCRIPTION}}
VIOLATION_TYPE: {{VIOLATION_TYPE}}
FIX_PATTERN: {{FIX_PATTERN}}
RANGE_START: {{RANGE_START}}
RANGE_END: {{RANGE_END}}
```

---
## GOAL
For each seed ({{RANGE_START}}–{{RANGE_END}}), output minimal C++ code pairs (5–15 lines) that:
- Show **one clear violation** (`// NC`) and its fix (`// C`)
- Are **domain-realistic**, compilable with `g++ -std=c++17 -fsyntax-only`
- Use **diverse contexts** across safety-critical domains
- Have **minimal differences** between non-compliant and compliant versions

---
## UNIQUENESS REQUIREMENTS ⚠️ CRITICAL

Each seed must be unique across **THREE dimensions**:

### 1. Domain Uniqueness
The high-level application area. Examples:
- Financial, Genomics, Blockchain, Cryptography
- Automotive, Aerospace, Robotics, Marine, Rail
- Medical, Industrial, Energy, IoT
- Graphics, Audio, Video, Gaming
- Networking, Security, Telecommunications
- Scientific Computing, Compiler, Filesystem

**Rule**: Prefer unique domains, but same domain can appear multiple times IF program/functionality differs.

### 2. Program/Functionality Uniqueness
The specific system or feature within the domain. Examples:
- Financial: risk-bucket encoder, credit scoring engine, portfolio optimizer
- Genomics: base-call quality mask, DNA alignment scorer, protein folding simulator
- Automotive: fuel injection controller, brake system monitor, ADAS lane detector
- Blockchain: transaction validator, mining pool manager, wallet key generator

**Rule**: Each **domain + program/functionality combination** must be completely unique across all seeds.

### 3. Technical Context Specificity
The precise technical implementation detail. Examples:
- "Financial risk-bucket encoder (hex flags)" ← specific: hex flags
- "Genomics base-call quality mask" ← specific: quality mask
- "Telemetry ID composer for satellite bus" ← specific: ID composer

**Rule**: Context string should be 4-10 words, technically precise, and describe the exact code purpose.

---

## CONTEXT GENERATION PATTERN

**Format**: `<Domain> <program/functionality> <technical detail>`

**Examples**:
- ✅ "Financial risk-bucket encoder (hex flags)"
- ✅ "Genomics base-call quality mask"
- ✅ "Robotic warehouse bin-label checksum"
- ✅ "Camera Bayer pattern ratio helper"
- ✅ "Blockchain transaction validation nonce"
- ❌ "Aerospace system" (too vague)
- ❌ "Financial encoder" (missing technical detail)
- ❌ "Hash function" (missing domain context)

---

## DOMAIN REFERENCE LIST

Use diverse domains across safety-critical, embedded, and technical systems:

**Safety-Critical Embedded:**
- Aerospace, Automotive, Robotics, Medical, Rail, Marine, Industrial, Aviation, Nuclear

**IoT & Sensors:**
- IoT, Sensor networks, Smart home, Agriculture, Environmental monitoring, Wearables

**Networking & Infrastructure:**
- Network DMA, Protocol processing, Firewall, Load balancer, Packet filter, Router

**Security & Cryptography:**
- Encryption, Authentication, TLS/SSL, Key management, Access control, RFID, NFC

**Financial & Trading:**
- Trading systems, Risk analysis, Credit scoring, Portfolio management, Payment processing, EMV

**Blockchain & Distributed:**
- Blockchain, Consensus, Mining, Wallet, Smart contracts, P2P networks, BitTorrent

**Multimedia:**
- Graphics, Audio DSP, Video encoding, Image processing, Camera ISP, Gaming engine, AR/VR

**Data & Scientific:**
- Genomics, Bioinformatics, Climate modeling, Simulations, ML inference, Data analytics

**Development Tools:**
- Compiler, Debugger, Profiler, Static analyzer, Build system, Version control

**Storage & Filesystems:**
- Filesystem, Database, Object storage, Cache, RAID, Backup system

**Communication Protocols:**
- CAN, MQTT, DICOM, mDNS, GPS, Bluetooth, WiFi, NFC, SSH, WebAssembly

**Industrial & Control:**
- CNC, PLC, SCADA, HMI, Servo control, Motor controller, Grid controller, Ventilator

**Emerging Tech:**
- Drone, Autonomous vehicle, Electric charging, Battery management, Quantum computing

**Each seed must have a unique domain + program/functionality combination.**

---
## CODE REQUIREMENTS

### Structure
```cpp
// Seed XXX — NC: <violation description>
#include <necessary_headers>
int main(){
    // Minimal, focused code showing violation // NC
    // Domain-appropriate variable names and logic
    return 0;
}
```

Compliant version: **identical** except the fix with `// C` comment.

### Guidelines
1. **Minimal code**: 5–15 lines in `main()`, no unnecessary complexity
2. **Self-contained**: Complete programs with proper headers
3. **One violation**: Only demonstrate the specific rule violation
4. **Domain-appropriate**: Use realistic variable names and operations for context
5. **Compilable**: Must pass `g++ -std=c++17 -fsyntax-only`
6. **No namespaces needed**: Keep it simple unless rule-specific

### Diversity Requirements
Vary across seeds:
- Variable types (`std::uint8_t`, `std::uint16_t`, `std::uint32_t`, `std::uint64_t`, `unsigned`, `long`)
- Operations (bitwise, arithmetic, logical, casts)
- Literal patterns (different hex values, combinations)
- Code complexity (simple single-variable to multi-variable operations)

---
## SPECIAL RULE NOTES

**Rule-Specific Adaptations:**
- **Declarator rules (8-0-1)**: Split declarations, avoid range-based loops
- **Literal suffix rules (2-13-4)**: Show lowercase → uppercase literal fixes  
- **Hex literal case (2-13-2)**: Vary hex patterns (0xa5 → 0xA5, 0xff → 0xFF)
- **Other rules**: Adapt code structure to clearly show violation/fix

---
## JSONL OUTPUT FORMAT

```json
{"seed":N,"context":"<specific domain context>","noncompliant":"<escaped code>","compliant":"<escaped code>"}
```

**Escaping Rules:**
- Newlines: `\\n`
- Backslashes: `\\\\`
- Quotes: `\\"`
- One JSON object per line (JSONL format)

**Example:**
```json
{"seed":1,"context":"Financial risk-bucket encoder (hex flags)","noncompliant":"// Seed 001 — NC: lowercase hex A–F\\n#include <cstdint>\\n#include <iostream>\\nint main(){\\n    std::uint8_t credit=0xa5, liquid=0x1f, market=0xbe; // NC\\n    std::uint8_t code = static_cast<std::uint8_t>(credit ^ market ^ liquid);\\n    std::cout << \\"risk=0x\\" << std::hex << static_cast<unsigned>(code) << \\"\\\\n\\";\\n    return 0;\\n}","compliant":"// Seed 001 — C: uppercase hex A–F\\n#include <cstdint>\\n#include <iostream>\\nint main(){\\n    std::uint8_t credit=0xA5, liquid=0x1F, market=0xBE; // C\\n    std::uint8_t code = static_cast<std::uint8_t>(credit ^ market ^ liquid);\\n    std::cout << \\"risk=0x\\" << std::hex << static_cast<unsigned>(code) << \\"\\\\n\\";\\n    return 0;\\n}"}
```

---
## VALIDATION CHECKLIST

Before outputting each seed, verify:
- ✅ Seed number is sequential ({{RANGE_START}}–{{RANGE_END}})
- ✅ **Domain + program/functionality combination is unique** (never seen before in this batch)
- ✅ Context string is specific and technically precise (4-10 words)
- ✅ Code compiles: `g++ -std=c++17 -fsyntax-only`
- ✅ Only one violation in non-compliant version
- ✅ Compliant version fixes only that violation
- ✅ Variable names and logic match domain context
- ✅ Code is minimal (no unnecessary complexity)
- ✅ JSON is properly escaped and valid
- ✅ Difference between NC/C is clear and isolated

---
## GENERATION WORKFLOW

1. **Select unique domain + program/functionality** combination (check against all previous seeds)
2. **Create specific technical context** string (4-10 words)
3. **Design minimal code** (5–15 lines) showing violation with domain-appropriate variables
4. **Create compliant version** with minimal change (only fix the violation)
5. **Verify compilation** and rule adherence
6. **Format as JSONL** with proper escaping
7. **Validate** against checklist (especially uniqueness)
8. **Output** single-line JSON object

**Uniqueness Check**: Before finalizing each seed, ensure the domain + program/functionality combination has not been used in any previous seed in this batch.

---
## QUALITY STANDARDS

- **Accuracy**: Code must correctly demonstrate rule violation/compliance
- **Clarity**: Violation should be immediately obvious when comparing versions
- **Realism**: Use domain-appropriate terminology and operations
- **Simplicity**: Avoid unrelated language features or complexity
- **Consistency**: Maintain uniform style across all seeds
- **Completeness**: Every seed must be self-contained and compilable

---
## OUTPUT

Generate {{RANGE_END - RANGE_START + 1}} seeds in JSONL format.
Each line contains one complete seed JSON object.
Ensure all seeds are unique, diverse, and follow all requirements above.