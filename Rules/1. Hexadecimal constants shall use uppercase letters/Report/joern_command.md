import java.nio.file.{Files, Paths, StandardOpenOption}
import java.nio.charset.StandardCharsets

// Detect file type pattern
val allFiles = cpg.file.name.l
val fileType = if (allFiles.exists(_.contains("mainNC.cpp"))) "main" else "test"
val ncPattern = s"${fileType}NC.cpp"
val cPattern = s"${fileType}C.cpp"

println("=" * 70)
println("MISRA C++ Hexadecimal Constants Rule Analysis")
println("=" * 70)
println(s"Detected file type: $ncPattern and $cPattern")
println("=" * 70)

// Find all hex literals
val hexLiterals = cpg.literal.where(_.code("(?i)0x[0-9a-f]+")).l

// Function to check if hex has lowercase letters
def hasLowercaseHex(code: String): Boolean = {
  val hexPart = code.toLowerCase.stripPrefix("0x")
  hexPart.exists(c => c >= 'a' && c <= 'f') && code.exists(c => c >= 'a' && c <= 'f')
}

// Categorize violations
val violations = hexLiterals.filter(lit => hasLowercaseHex(lit.code))

val ncViolations = violations.filter(_.file.name.headOption.getOrElse("").contains(ncPattern))
val cViolations = violations.filter(_.file.name.headOption.getOrElse("").contains(cPattern))

// Statistics
val totalHexLiterals = hexLiterals.size
val totalViolations = violations.size
val ncCount = ncViolations.size

// Generate detailed reports
val ncReport = ncViolations.groupBy(_.file.name.headOption.getOrElse("")).map { case (file, lits) =>
  val fileName = file.split("/").last
  val violations = lits.map(lit => 
    s"    Line ${lit.lineNumber.getOrElse("?")} | ${lit.code}"
  ).mkString("\n")
  s"  File: $fileName\n  Found ${lits.size} violation(s):\n$violations"
}.mkString("\n\n")

val cReport = if (cViolations.isEmpty) {
  "  ✓ No violations found - all compliant files are correct"
} else {
  cViolations.groupBy(_.file.name.headOption.getOrElse("")).map { case (file, lits) =>
    val fileName = file.split("/").last
    val violations = lits.map(lit => 
      s"    Line ${lit.lineNumber.getOrElse("?")} | ${lit.code}"
    ).mkString("\n")
    s"  ✗ File: $fileName\n  Found ${lits.size} violation(s):\n$violations"
  }.mkString("\n\n")
}

// Generate full report
val fullReport = s"""
======================================================================
MISRA C++ HEXADECIMAL CONSTANTS RULE CHECKER
======================================================================
Rule: Hexadecimal constants shall use uppercase letters (A-F)
File Type: $fileType (${ncPattern}, ${cPattern})
Generated: ${java.time.LocalDateTime.now()}

===================================================================

RULE DESCRIPTION:
-----------------
Hexadecimal constants should use uppercase letters (A-F), not lowercase (a-f).

Examples:
  ✓ Compliant:     0xFF, 0xABCD, 0x1234
  ✗ Non-compliant: 0xff, 0xabcd, 0x1a2b, 0xDeAdBeEf (mixed case)

===================================================================

STATISTICS:
-----------
Total hexadecimal literals found: $totalHexLiterals
Total violations found: $totalViolations
Violations in ${fileType}NC.cpp files: $ncCount
Violations in ${fileType}C.cpp files: ${cViolations.size}

===================================================================

NON-COMPLIANT FILES (${fileType}NC.cpp):
Expected violations - these files should contain lowercase hex
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
val outputPath = "/Users/sumandey/Desktop/IITH/Classes/Sem 5/mds-llm-code_compliance/Rules/1. Hexadecimal constants shall use uppercase letters/Pairs/hex_uppercase_violations_report.txt"

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
println(s"  Total hex literals: $totalHexLiterals")
println(s"  Total violations: $totalViolations")
println(s"  ${fileType}NC.cpp violations: $ncCount")
println(s"  ${fileType}C.cpp violations: ${cViolations.size}")
println("\nFile patterns used:")
println(s"  Non-compliant: $ncPattern")
println(s"  Compliant: $cPattern")