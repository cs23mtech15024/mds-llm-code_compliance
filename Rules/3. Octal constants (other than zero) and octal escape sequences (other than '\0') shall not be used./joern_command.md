import java.nio.file.{Files, Paths, StandardOpenOption}
import java.nio.charset.StandardCharsets

// Detect file type pattern
val allFiles = cpg.file.name.l
val fileType = if (allFiles.exists(_.contains("mainNC.cpp"))) "main" else "test"
val ncPattern = s"${fileType}NC.cpp"
val cPattern = s"${fileType}C.cpp"

println("=" * 70)
println("MISRA C++ Octal Constants Rule Analysis")
println("=" * 70)
println(s"Detected file type: $ncPattern and $cPattern")
println("=" * 70)

// Find all literals
val allLiterals = cpg.literal.l

// Function to check if a literal is an invalid octal constant
def isInvalidOctal(code: String): Boolean = {
  // Match octal numbers: starts with 0, followed by digits 0-7
  // But exclude: plain "0", "0L", "0U", "0UL", etc. (just zero with suffixes)
  val octalPattern = """^0[0-7]+[ULul]*$""".r
  val justZeroPattern = """^0[ULul]*$""".r
  
  octalPattern.matches(code) && !justZeroPattern.matches(code)
}

// Function to check if a string literal contains invalid octal escape sequences
def hasInvalidOctalEscape(code: String): Boolean = {
  // Look for octal escape sequences in string literals
  // Valid: \0 (null terminator)
  // Invalid: \1, \12, \123, \777, etc.
  val octalEscapePattern = """\\[0-7]{1,3}""".r
  val nullTerminatorPattern = """\\0(?![0-7])""".r
  
  if (code.contains("\"") || code.contains("'")) {
    val octalEscapes = octalEscapePattern.findAllIn(code).toList
    val validNullTerminators = nullTerminatorPattern.findAllIn(code).toList
    
    // Check if there are octal escapes that are not just \0
    octalEscapes.exists(escape => escape != "\\0" && !escape.matches("""\\0[ULul]*"""))
  } else {
    false
  }
}

// Find violations
val octalConstantViolations = allLiterals.filter(lit => isInvalidOctal(lit.code))
val octalEscapeViolations = allLiterals.filter(lit => hasInvalidOctalEscape(lit.code))

// Combine all violations (remove duplicates by creating a set based on file, line, and code)
val allViolationsMap = (octalConstantViolations ++ octalEscapeViolations)
  .groupBy(lit => (lit.file.name.headOption.getOrElse(""), lit.lineNumber.getOrElse(-1), lit.code))
  .map { case (key, lits) => lits.head }
  .toList

// Categorize by file type
val ncViolations = allViolationsMap.filter(lit => 
  lit.file.name.headOption.getOrElse("").contains(ncPattern)
)

val cViolations = allViolationsMap.filter(lit => 
  lit.file.name.headOption.getOrElse("").contains(cPattern)
)

// Statistics
val totalLiterals = allLiterals.size
val totalViolations = allViolationsMap.size
val ncCount = ncViolations.size
val cCount = cViolations.size
val octalConstCount = octalConstantViolations.size
val octalEscapeCount = octalEscapeViolations.size

// Helper function to determine violation type
def getViolationType(code: String): String = {
  if (isInvalidOctal(code)) "Octal Constant"
  else if (hasInvalidOctalEscape(code)) "Octal Escape Sequence"
  else "Unknown"
}

// Generate detailed reports for NC files
val ncReport = if (ncViolations.isEmpty) {
  "  No violations found"
} else {
  ncViolations
    .groupBy(lit => lit.file.name.headOption.getOrElse(""))
    .map { case (file, lits) =>
      val fileName = file.split("/").last
      val violationDetails = lits.map { lit =>
        val violationType = getViolationType(lit.code)
        s"    Line ${lit.lineNumber.getOrElse("?")} | Type: $violationType | Code: ${lit.code}"
      }.mkString("\n")
      s"  File: $fileName\n  Found ${lits.size} violation(s):\n$violationDetails"
    }
    .mkString("\n\n")
}

// Generate detailed reports for C files
val cReport = if (cViolations.isEmpty) {
  "  ✓ No violations found - all compliant files are correct"
} else {
  cViolations
    .groupBy(lit => lit.file.name.headOption.getOrElse(""))
    .map { case (file, lits) =>
      val fileName = file.split("/").last
      val violationDetails = lits.map { lit =>
        val violationType = getViolationType(lit.code)
        s"    Line ${lit.lineNumber.getOrElse("?")} | Type: $violationType | Code: ${lit.code}"
      }.mkString("\n")
      s"  ✗ File: $fileName\n  Found ${lits.size} violation(s):\n$violationDetails"
    }
    .mkString("\n\n")
}

// Generate full report
val fullReport = s"""
======================================================================
MISRA C++ OCTAL CONSTANTS RULE CHECKER
======================================================================
Rule: Octal constants (other than zero) and octal escape sequences 
      (other than '\\0') shall not be used
File Type: $fileType (${ncPattern}, ${cPattern})
Generated: ${java.time.LocalDateTime.now()}

===================================================================

RULE DESCRIPTION:
-----------------
Octal literals and escape sequences can be confusing and error-prone.
Only zero (0) and null terminator (\\0) are allowed.

Examples:
  ✓ Compliant:
    int x = 0;          // Plain zero is OK
    int y = 10;         // Decimal
    int z = 0x10;       // Hexadecimal
    char c = '\\0';      // Null terminator is OK
    
  ✗ Non-compliant:
    int a = 077;        // Octal constant (other than 0)
    int b = 0123;       // Octal constant
    char d = '\\033';    // Octal escape sequence (other than \\0)
    char e = '\\177';    // Octal escape sequence

===================================================================

STATISTICS:
-----------
Total literals found: $totalLiterals
Total violations found: $totalViolations
  - Octal constants: $octalConstCount
  - Octal escape sequences: $octalEscapeCount
Violations in ${fileType}NC.cpp files: $ncCount
Violations in ${fileType}C.cpp files: $cCount

===================================================================

NON-COMPLIANT FILES (${fileType}NC.cpp):
Expected violations - these files should contain octal constants/escapes
$ncReport

===================================================================

COMPLIANT FILES CHECK (${fileType}C.cpp):
Should have 0 violations
-------------------------------------------------------------------
$cReport

===================================================================

SUMMARY:
--------
${if (cViolations.isEmpty) s"✓ PASS: All ${fileType}C.cpp files are compliant" else s"✗ FAIL: Found ${cViolations.size} violations in ${fileType}C.cpp files"}
${if (ncCount > 0) s"✓ ${fileType}NC.cpp files contain $ncCount violations (expected)" else s"⚠ WARNING: No violations found in ${fileType}NC.cpp files"}

===================================================================
"""

// HARDCODED OUTPUT PATH
val outputPath = "/Users/sumandey/Desktop/IITH/Classes/Sem 5/mds-llm-code_compliance/Rules/3. Octal constants (other than zero) and octal escape sequences (other than '\\0') shall not be used./Pairs/octal_constants_report.txt"

// CREATE THE PARENT DIRECTORY IF IT DOESN'T EXIST
val outputFile = Paths.get(outputPath).toAbsolutePath
val parentDir = outputFile.getParent
if (parentDir != null && !Files.exists(parentDir)) {
  Files.createDirectories(parentDir)
}

Files.write(
  outputFile,
  fullReport.getBytes(StandardCharsets.UTF_8)
)

println(s"✓ Report saved to: ${outputFile.toString}")
println(s"\nQuick Summary:")
println(s"  Total literals: $totalLiterals")
println(s"  Total violations: $totalViolations")
println(s"    - Octal constants: $octalConstCount")
println(s"    - Octal escape sequences: $octalEscapeCount")
println(s"  ${fileType}NC.cpp violations: $ncCount")
println(s"  ${fileType}C.cpp violations: $cCount")
println("\nFile patterns used:")
println(s"  Non-compliant: $ncPattern")
println(s"  Compliant: $cPattern")