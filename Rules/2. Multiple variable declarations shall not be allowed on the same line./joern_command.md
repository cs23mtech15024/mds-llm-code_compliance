import java.nio.file.{Files, Paths, StandardOpenOption}
import java.nio.charset.StandardCharsets

// Detect file type pattern
val allFiles = cpg.file.name.l
val fileType = if (allFiles.exists(_.contains("mainNC.cpp"))) "main" else "test"
val ncPattern = s"${fileType}NC.cpp"
val cPattern = s"${fileType}C.cpp"

println("=" * 70)
println("MISRA C++ Multiple Variable Declarations Rule Analysis")
println("=" * 70)
println(s"Detected file type: $ncPattern and $cPattern")
println("=" * 70)

// Find all local variable declarations
val allLocals = cpg.local.l

// Group by file, line number, AND variable name to remove duplicates
val uniqueLocals = allLocals
  .groupBy(local => (
    local.file.name.headOption.getOrElse(""),
    local.lineNumber.getOrElse(-1),
    local.name
  ))
  .map { case (key, locals) => locals.head } // Take only one instance of each unique variable
  .toList

// Now group by file and line number to find multiple declarations on same line
val multipleDeclarations = uniqueLocals
  .groupBy(local => (local.file.name.headOption.getOrElse(""), local.lineNumber.getOrElse(-1)))
  .filter { case ((file, line), locals) => 
    line != -1 && locals.size > 1  // More than one UNIQUE declaration on the same line
  }
  .toList

// Categorize violations by file type
val ncViolations = multipleDeclarations.filter { case ((file, line), locals) =>
  file.contains(ncPattern)
}

val cViolations = multipleDeclarations.filter { case ((file, line), locals) =>
  file.contains(cPattern)
}

// Statistics
val totalDeclarations = uniqueLocals.size
val totalViolations = multipleDeclarations.size
val ncCount = ncViolations.size
val cCount = cViolations.size

// Generate detailed reports for NC files
val ncReport = if (ncViolations.isEmpty) {
  "  No violations found"
} else {
  ncViolations
    .groupBy { case ((file, line), locals) => file }
    .map { case (file, violations) =>
      val fileName = file.split("/").last
      val violationDetails = violations.map { case ((_, line), locals) =>
        // Get unique variable names only
        val uniqueVarNames = locals.map(_.name).distinct
        val uniqueVarTypes = locals.map(_.typeFullName).distinct
        s"    Line $line | Variables: ${uniqueVarNames.mkString(", ")} | Type(s): ${uniqueVarTypes.mkString(", ")} | Count: ${uniqueVarNames.size}"
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
    .groupBy { case ((file, line), locals) => file }
    .map { case (file, violations) =>
      val fileName = file.split("/").last
      val violationDetails = violations.map { case ((_, line), locals) =>
        // Get unique variable names only
        val uniqueVarNames = locals.map(_.name).distinct
        val uniqueVarTypes = locals.map(_.typeFullName).distinct
        s"    Line $line | Variables: ${uniqueVarNames.mkString(", ")} | Type(s): ${uniqueVarTypes.mkString(", ")} | Count: ${uniqueVarNames.size}"
      }.mkString("\n")
      s"  ✗ File: $fileName\n  Found ${violations.size} violation(s):\n$violationDetails"
    }
    .mkString("\n\n")
}

// Generate full report
val fullReport = s"""
======================================================================
MISRA C++ MULTIPLE VARIABLE DECLARATIONS RULE CHECKER
======================================================================
Rule: Multiple variable declarations shall not be allowed on the same line
File Type: $fileType (${ncPattern}, ${cPattern})
Generated: ${java.time.LocalDateTime.now()}

===================================================================

RULE DESCRIPTION:
-----------------
Each variable declaration should be on its own line for clarity and maintainability.

Examples:
  ✓ Compliant:
    int x;
    int y;
    int z;

  ✗ Non-compliant:
    int x, y, z;        // Multiple declarations on one line
    int a, b; int c;    // Multiple declarations (even if separated)

===================================================================

STATISTICS:
-----------
Total unique variable declarations found: $totalDeclarations
Total violations (lines with multiple declarations): $totalViolations
Violations in ${fileType}NC.cpp files: $ncCount
Violations in ${fileType}C.cpp files: $cCount

===================================================================

NON-COMPLIANT FILES (${fileType}NC.cpp):
Expected violations - these files should contain multiple declarations per line
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
val outputPath = "/Users/sumandey/Desktop/IITH/Classes/Sem 5/mds-llm-code_compliance/Rules/2. Multiple variable declarations shall not be allowed on the same line./Pairs/multiple_declarations_report.txt"

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
println(s"  Total unique variable declarations: $totalDeclarations")
println(s"  Total violations: $totalViolations")
println(s"  ${fileType}NC.cpp violations: $ncCount")
println(s"  ${fileType}C.cpp violations: $cCount")
println("\nFile patterns used:")
println(s"  Non-compliant: $ncPattern")
println(s"  Compliant: $cPattern")