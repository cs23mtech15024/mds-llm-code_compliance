import java.nio.file.{Files, Paths, StandardOpenOption}
import java.nio.charset.StandardCharsets

// Detect file type pattern
val allFiles = cpg.file.name.l
val fileType = if (allFiles.exists(_.contains("mainNC.cpp"))) "main" else "test"
val ncPattern = s"${fileType}NC.cpp"
val cPattern = s"${fileType}C.cpp"

println("=" * 70)
println("MISRA C++ Underscore Identifier Rule Analysis")
println("=" * 70)
println(s"Detected file type: $ncPattern and $cPattern")
println("=" * 70)

// Find all identifiers (variables, functions, parameters, members, etc.)
val allLocals = cpg.local.l
val allParameters = cpg.parameter.l
val allMembers = cpg.member.l
val allMethods = cpg.method.isExternal(false).l

// Combine all identifiers with their metadata
case class Identifier(name: String, kind: String, file: String, line: Int)

val localIdentifiers = allLocals.map(l => 
  Identifier(l.name, "variable", l.file.name.headOption.getOrElse(""), l.lineNumber.getOrElse(-1))
)

val paramIdentifiers = allParameters.map(p => 
  Identifier(p.name, "parameter", p.file.name.headOption.getOrElse(""), p.lineNumber.getOrElse(-1))
)

val memberIdentifiers = allMembers.map(m => 
  Identifier(m.name, "member", m.file.name.headOption.getOrElse(""), m.lineNumber.getOrElse(-1))
)

val methodIdentifiers = allMethods.map(m => 
  Identifier(m.name, "function", m.file.name.headOption.getOrElse(""), m.lineNumber.getOrElse(-1))
)

// Combine all identifiers
val allIdentifiers = (localIdentifiers ++ paramIdentifiers ++ memberIdentifiers ++ methodIdentifiers).toList

// Filter identifiers that start with underscore
val underscoreViolations = allIdentifiers
  .filter(id => id.name.startsWith("_") && id.line != -1 && id.file.nonEmpty)
  .groupBy(id => (id.file, id.line, id.name, id.kind))
  .map { case (key, ids) => ids.head } // Remove duplicates
  .toList
  .sortBy(id => (id.file, id.line))

// Categorize violations by file type
val ncViolations = underscoreViolations.filter(id => id.file.contains(ncPattern))
val cViolations = underscoreViolations.filter(id => id.file.contains(cPattern))

// Statistics
val totalIdentifiers = allIdentifiers.size
val totalViolations = underscoreViolations.size
val ncCount = ncViolations.size
val cCount = cViolations.size

// Generate detailed reports for NC files
val ncReport = if (ncViolations.isEmpty) {
  "  No violations found"
} else {
  ncViolations
    .groupBy(_.file)
    .map { case (file, violations) =>
      val fileName = file.split("/").last
      val violationDetails = violations.map { id =>
        s"    Line ${id.line} | ${id.kind}: ${id.name}"
      }.mkString("\n")
      s"  File: $fileName\n  Found ${violations.size} violation(s):\n$violationDetails"
    }
    .mkString("\n\n")
}

// Generate detailed reports for C files
val cReport = if (cViolations.isEmpty) {
  "  ✓ No violations found - all compliant files are correct"
} else {
  cViolations
    .groupBy(_.file)
    .map { case (file, violations) =>
      val fileName = file.split("/").last
      val violationDetails = violations.map { id =>
        s"    Line ${id.line} | ${id.kind}: ${id.name}"
      }.mkString("\n")
      s"  ✗ File: $fileName\n  Found ${violations.size} violation(s):\n$violationDetails"
    }
    .mkString("\n\n")
}

// Generate full report
val fullReport = s"""
======================================================================
MISRA C++ UNDERSCORE IDENTIFIER RULE CHECKER
======================================================================
Rule: Identifiers will not begin with the underscore character '_'
File Type: $fileType (${ncPattern}, ${cPattern})
Generated: ${java.time.LocalDateTime.now()}

===================================================================

RULE DESCRIPTION:
-----------------
Identifiers (variables, functions, parameters, members) should not begin
with an underscore character as these are typically reserved for system
and compiler implementations.

Examples:
  ✓ Compliant:
    int counter;
    void processData();
    int myVariable;

  ✗ Non-compliant:
    int _counter;       // Variable starts with underscore
    void _process();    // Function starts with underscore
    int _value;         // Parameter starts with underscore

===================================================================

STATISTICS:
-----------
Total identifiers found: $totalIdentifiers
Total violations (identifiers starting with '_'): $totalViolations
Violations in ${fileType}NC.cpp files: $ncCount
Violations in ${fileType}C.cpp files: $cCount

===================================================================

NON-COMPLIANT FILES (${fileType}NC.cpp):
Expected violations - these files should contain identifiers starting with '_'
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
val outputPath = "/Users/sumandey/Desktop/IITH/Classes/Sem 5/mds-llm-code_compliance/Rules/4. Identifiers will not begin with the underscore character '_'/Pairs/underscore_identifier_report.txt"

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
println(s"  Total identifiers: $totalIdentifiers")
println(s"  Total violations: $totalViolations")
println(s"  ${fileType}NC.cpp violations: $ncCount")
println(s"  ${fileType}C.cpp violations: $cCount")
println("\nFile patterns used:")
println(s"  Non-compliant: $ncPattern")
println(s"  Compliant: $cPattern")