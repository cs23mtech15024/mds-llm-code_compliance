# Three-Dimensional Uniqueness Requirement for MISRA C++ Seeds

## Overview

Each seed must be unique across **THREE dimensions** to ensure maximum dataset diversity:

```
SEED = Domain + Program/Functionality + Technical Context
```

---

## Dimension 1: Domain (High-Level Area)

The broad application category or industry sector.

**Examples:**
- Financial
- Genomics  
- Automotive
- Aerospace
- Blockchain
- Medical
- Robotics
- IoT
- Graphics
- Security

**Constraint:** Same domain CAN appear multiple times, BUT must have different program/functionality.

---

## Dimension 2: Program/Functionality (Specific System)

The particular system, component, or feature within the domain.

**Examples within Automotive domain:**
- fuel injection controller
- brake system monitor
- ADAS lane detector
- powertrain control unit
- tire pressure sensor

**Examples within Financial domain:**
- risk-bucket encoder
- credit scoring engine
- trading order matcher
- portfolio optimizer
- fraud detection filter

**Constraint:** Each domain + program/functionality pair must be **globally unique** across all seeds.

---

## Dimension 3: Technical Context (Implementation Detail)

The precise technical aspect or implementation being demonstrated.

**Examples:**
- "hex flags"
- "quality mask"
- "checksum calculator"
- "bitmap encoder"
- "tag validator"

**Constraint:** The full context string should precisely describe what the code does.

---

## Real Examples from Your Dataset

### ✅ Valid Unique Seeds

```
Seed 1: Financial + risk-bucket encoder + (hex flags)
  → "Financial risk-bucket encoder (hex flags)"

Seed 2: Genomics + base-call quality + mask
  → "Genomics base-call quality mask"

Seed 3: Cryptography + hash salt constant + sharding
  → "Hash salt constant for consistent sharding"

Seed 4: Robotics + warehouse bin-label + checksum
  → "Robotic warehouse bin-label checksum"

Seed 27: Automotive + CAN diagnostic + PID filter
  → "CAN diagnostic PID filter"

Seed 64: Blockchain + transaction validation + nonce
  → "Blockchain transaction validation nonce"
```

### ❌ Invalid - Violates Uniqueness

```
Seed 1: Financial + risk-bucket encoder + (hex flags)
Seed 50: Financial + risk-bucket encoder + (decimal tags)  ← INVALID!
  → Same domain + program/functionality, only context differs
  → This violates dimension 2 uniqueness

Seed 2: Genomics + base-call quality + mask
Seed 75: Genomics + base-call quality + filter  ← INVALID!
  → Same domain + program/functionality
```

### ✅ Valid - Same Domain, Different Program

```
Seed 5: Aerospace + telemetry ID composer + satellite bus
Seed 19: Aerospace + drone geofence + tile code
  → Same domain (Aerospace)
  → Different program/functionality (telemetry vs geofence)
  → VALID!

Seed 27: Automotive + CAN diagnostic + PID filter
Seed 30: Automotive + vehicle samplerate + literal tag
  → Same domain (Automotive)
  → Different program/functionality (CAN diagnostic vs samplerate)
  → VALID!
```

---

## Context String Format

**Pattern:** `<Domain> <program/functionality> <technical detail>`

**Good Examples:**
- "Financial risk-bucket encoder (hex flags)" ← 5 words, specific
- "Genomics base-call quality mask" ← 4 words, technical
- "Robotic warehouse bin-label checksum" ← 4 words, precise
- "Camera Bayer pattern ratio helper" ← 5 words, clear
- "Blockchain transaction validation nonce" ← 4 words, exact

**Bad Examples:**
- "Financial system" ← Too vague, missing program/functionality
- "Hash function" ← Missing domain context
- "Encoder" ← Way too generic
- "Automotive control system for managing brake pressure in real-time" ← Too long (11 words)

---

## Uniqueness Validation Algorithm

```python
# Pseudo-code for checking uniqueness

seen_combinations = set()

for each new seed:
    # Extract domain and program/functionality
    domain = extract_domain(context)
    program_functionality = extract_program_functionality(context)
    
    # Create unique key
    key = (domain, program_functionality)
    
    # Check if combination already exists
    if key in seen_combinations:
        REJECT_SEED("Duplicate domain + program/functionality")
    else:
        seen_combinations.add(key)
        ACCEPT_SEED()
```

---

## Practical Generation Strategy

### Step 1: Choose Domain
Pick from broad categories: Financial, Automotive, Medical, IoT, etc.

### Step 2: Choose Specific Program/Functionality
Within that domain, pick a specific system or feature that hasn't been used.

### Step 3: Add Technical Detail
Describe the precise implementation aspect.

### Step 4: Verify Uniqueness
Check that this domain + program/functionality combination is new.

---

## Example Generation Process

**Target: Generate 5 seeds in Automotive domain**

```
Seed N: Automotive + fuel injection controller + duty cycle register
  → "Automotive fuel injection controller duty cycle register"
  ✅ Unique combination

Seed N+1: Automotive + brake system monitor + pressure sensor calibration
  → "Automotive brake system monitor pressure sensor calibration"
  ✅ Unique combination (different program/functionality)

Seed N+2: Automotive + ADAS lane detector + confidence threshold
  → "Automotive ADAS lane detector confidence threshold"
  ✅ Unique combination (different program/functionality)

Seed N+3: Automotive + tire pressure sensor + alert bitmap
  → "Automotive tire pressure sensor alert bitmap"
  ✅ Unique combination (different program/functionality)

Seed N+4: Automotive + fuel injection controller + timing offset  ← INVALID!
  → Same domain + same program/functionality as Seed N
  ❌ Violates uniqueness
```

---

## Summary Checklist

For each seed context, verify:
- ✅ Domain is clearly identifiable
- ✅ Program/functionality is specific and technical
- ✅ Technical detail is precise
- ✅ Full context is 4-10 words
- ✅ Domain + program/functionality combination is globally unique
- ✅ Context string is professionally written and realistic
- ✅ Variable names in code match the context

---

## Why This Matters

**Dataset Quality:**
- Prevents duplicate scenarios in training/testing
- Ensures comprehensive coverage of different systems
- Creates realistic, diverse examples from real-world domains

**Model Performance:**
- Better generalization from varied examples
- Avoids overfitting to repeated patterns
- Tests rule understanding across different contexts

**Professional Standards:**
- Mirrors real-world safety-critical software diversity
- Reflects actual MISRA C++ usage across industries
- Provides educational value for developers