# Code Review Checklist

## Overview

This checklist ensures code quality and consistency across CLearning projects. Use before completing any feature or committing code.

## Pre-Review Quick Checks

### Build and Test
```bash
make clean
make
make test
```

All three commands must succeed before review.

## Code Quality Checklist

### ✅ Compilation

- [ ] Code compiles without errors
- [ ] Code compiles without warnings (`-Wall -Wextra`)
- [ ] No unused variables
- [ ] No unused functions
- [ ] All includes are necessary

### ✅ Testing

- [ ] All tests pass (`make test`)
- [ ] New functions have tests
- [ ] Tests cover happy path
- [ ] Tests cover error cases
- [ ] Tests cover edge cases
- [ ] Test names are descriptive

### ✅ Documentation

- [ ] File has file-level docstring
- [ ] All functions have docstrings
- [ ] Parameters documented with `@param`
- [ ] Return values documented with `@return`
- [ ] Complex logic has explanatory notes
- [ ] Formulas are documented
- [ ] No commented-out code

### ✅ Naming Conventions

- [ ] Variables use `snake_case`
- [ ] Functions use `snake_case`
- [ ] Constants use `UPPER_CASE`
- [ ] Names are descriptive
- [ ] No single-letter names (except `i`, `j`, `k`, `c`)
- [ ] File names follow conventions

### ✅ Code Style

- [ ] Consistent indentation (2 or 4 spaces)
- [ ] No trailing whitespace
- [ ] Braces on same line (K&R style) or next line (Allman) consistently
- [ ] One statement per line
- [ ] Reasonable line length (< 100 chars preferred)
- [ ] Blank lines separate logical sections

### ✅ Input Validation

- [ ] All user input is validated
- [ ] scanf return values checked
- [ ] Input buffer cleared after scanf
- [ ] Error messages are user-friendly
- [ ] Invalid input handled gracefully
- [ ] No buffer overflows possible

### ✅ Error Handling

- [ ] Functions return error status
- [ ] Errors are handled, not ignored
- [ ] Error messages are specific
- [ ] Resources cleaned up on error
- [ ] No silent failures

### ✅ Memory Safety

- [ ] No uninitialized variables
- [ ] Pointers checked before dereferencing
- [ ] Array bounds respected
- [ ] No memory leaks
- [ ] Proper use of const
- [ ] Correct format specifiers (`%d`, `%f`, `%lf`)

### ✅ Logic Correctness

- [ ] Algorithm is correct
- [ ] Edge cases handled
- [ ] No off-by-one errors
- [ ] Division by zero prevented
- [ ] Integer overflow considered
- [ ] Floating-point precision appropriate

### ✅ Code Organization

- [ ] Functions have single responsibility
- [ ] Functions are reasonably sized (< 50 lines)
- [ ] Code is DRY (Don't Repeat Yourself)
- [ ] Related code is grouped together
- [ ] Logical flow is clear

### ✅ Best Practices

- [ ] No magic numbers (use named constants)
- [ ] No global variables (unless justified)
- [ ] Appropriate use of headers
- [ ] Includes are minimal
- [ ] No platform-specific code (unless necessary)

## Detailed Review Sections

### Input Validation Review

**Check each user input function:**

```c
// ✅ GOOD Example
int read_int(const char *prompt, int *value) {
  int c;
  printf("%s", prompt);                    // ✓ Shows prompt
  if (scanf("%d", value) != 1) {           // ✓ Checks return value
    while ((c = getchar()) != '\n' && c != EOF)  // ✓ Clears buffer
      ;
    printf("Invalid input. Please enter a valid integer.\n");  // ✓ Error message
    return 0;                              // ✓ Returns error status
  }
  while ((c = getchar()) != '\n' && c != EOF)    // ✓ Clears trailing newline
    ;
  return 1;                                // ✓ Returns success
}
```

**Common Issues:**
- ❌ Not checking scanf return value
- ❌ Not clearing input buffer
- ❌ Using uninitialized variable if scanf fails
- ❌ No error message to user

### Documentation Review

**Check file-level documentation:**

```c
/**
 * @file function_file.c
 * @brief Implementation of input validation and calculation utilities
 *
 * Contains validated input functions for integers, floats, and doubles,
 * plus various calculation utilities including arithmetic sequences,
 * salary calculations, and time conversions.
 */
```

**Required elements:**
- [ ] `@file` tag with filename
- [ ] `@brief` with one-line description
- [ ] Longer description paragraph
- [ ] Lists key contents/responsibilities

**Check function documentation:**

```c
/**
 * Calculate and print net salary based on wage, hours, and tax rate.
 *
 * Prompts the user for hourly wage, hours worked, and tax rate percentage.
 * Computes the gross salary, tax amount, and net salary, then prints results.
 *
 * Formulas used:
 *   gross_salary = hourly_wage * hours_worked
 *   tax_amount = gross_salary * tax_rate_percentage / 100
 *   net_salary = gross_salary - tax_amount
 *
 * @note Prints results to stdout
 */
void salary_calculator(void);
```

**Required for non-void returns:**
- [ ] `@param` for each parameter
- [ ] `@return` describing return value
- [ ] Specific return values explained

### Memory Safety Review

**Check variable initialization:**

```c
// ✅ GOOD - initialized before use
int value;
if (read_int("Enter value: ", &value)) {
  printf("Value: %d\n", value);  // Safe - initialized by read_int
}

// ❌ BAD - may be uninitialized
int value;
printf("Value: %d\n", value);  // Undefined behavior!
```

**Check format specifiers:**

```c
// ✅ GOOD
int i;
scanf("%d", &i);      // int with %d

float f;
scanf("%f", &f);      // float with %f

double d;
scanf("%lf", &d);     // double with %lf

// ❌ BAD
double d;
scanf("%f", &d);      // WRONG: should be %lf
```

**Check division:**

```c
// ✅ GOOD - float division
double avg = (grade1 + grade2) / 2.0;  // Uses 2.0

// ❌ BAD - integer division
double avg = (grade1 + grade2) / 2;    // Uses 2, loses precision
```

### Testing Review

**Check test coverage:**

For function `calculate_average(int a, int b)`:

```c
// ✓ Happy path
void test_calculate_average_typical(void) {
  TEST_ASSERT_EQUAL_DOUBLE(75.0, calculate_average(70, 80));
}

// ✓ Edge case - zeros
void test_calculate_average_zeros(void) {
  TEST_ASSERT_EQUAL_DOUBLE(0.0, calculate_average(0, 0));
}

// ✓ Edge case - negative
void test_calculate_average_negative(void) {
  TEST_ASSERT_EQUAL_DOUBLE(-5.0, calculate_average(-10, 0));
}

// ✓ Rounding
void test_calculate_average_rounding(void) {
  TEST_ASSERT_EQUAL_DOUBLE(1.5, calculate_average(1, 2));
}
```

**Required:**
- [ ] At least one happy path test
- [ ] At least one error/edge case test
- [ ] Output format verified (for I/O functions)
- [ ] Return values checked

## Project-Specific Checks

### Makefile

- [ ] Compiles all source files
- [ ] Includes test targets
- [ ] Uses standard variable names (`CC`, `CFLAGS`, `LDFLAGS`)
- [ ] Has `clean` target
- [ ] PHONY targets declared

### File Organization

- [ ] Follows standard structure
- [ ] main.c is entry point only
- [ ] Implementation in function_file.c
- [ ] Declarations in helper.h
- [ ] Tests in tests/ directory

### Header Files

- [ ] Has header guard
- [ ] Contains declarations only
- [ ] No implementations in header
- [ ] Includes are minimal

## Common Anti-Patterns

### ❌ Magic Numbers

```c
// BAD
double area = radius * radius * 3.14159;

// GOOD
#define PI 3.14159
double area = radius * radius * PI;
```

### ❌ Ignored Return Values

```c
// BAD
scanf("%d", &value);
printf("Value: %d\n", value);  // May be uninitialized

// GOOD
if (scanf("%d", &value) == 1) {
  printf("Value: %d\n", value);
}
```

### ❌ Not Clearing Buffer

```c
// BAD
scanf("%d", &value);  // Leaves newline in buffer
scanf("%d", &next);   // May immediately fail

// GOOD
scanf("%d", &value);
while ((c = getchar()) != '\n' && c != EOF)
  ;
```

### ❌ Generic Error Messages

```c
// BAD
printf("Error\n");

// GOOD
printf("Invalid input. Please enter a valid integer.\n");
```

### ❌ Too Many Responsibilities

```c
// BAD - does too much
void do_everything(void) {
  // Read input
  // Validate
  // Calculate
  // Convert
  // Print
  // Log
}

// GOOD - single responsibility
void read_input(int *value);
void calculate_result(int input);
void print_result(int result);
```

## Review Process

### Self-Review (Before Requesting Review)

1. Run checklist yourself
2. Fix any issues found
3. Re-run `make test`
4. Commit only if all checks pass

### Peer Review (If Applicable)

1. Reviewer runs checklist
2. Provides specific feedback
3. Author fixes issues
4. Re-review if needed

### Automated Checks (If Available)

```bash
# Compilation check
make clean && make

# Test check
make test

# Static analysis (future)
# cppcheck function_file.c
```

## Priority Levels

### 🔴 Critical (Must Fix)

- Compilation errors
- Test failures
- Memory safety issues
- Buffer overflows
- Uninitialized variables

### 🟡 Important (Should Fix)

- Missing documentation
- Poor naming
- No error handling
- Magic numbers
- Code duplication

### 🔵 Nice to Have (Consider Fixing)

- Code style inconsistencies
- Long functions
- Minor optimizations
- Additional tests

## Final Checks Before Commit

```bash
# 1. Clean build
make clean

# 2. Compile
make
# Must succeed with no warnings

# 3. Test
make test
# All tests must pass

# 4. Self-review
# Run through checklist

# 5. Only then commit
git add .
git commit -m "Descriptive message"
```

## Review Completion

**Sign-off checklist:**

- [ ] All critical issues fixed
- [ ] All tests pass
- [ ] Documentation complete
- [ ] Code follows conventions
- [ ] No warnings or errors
- [ ] Ready for commit/deployment

## See Also

- **testing-workflow.md** - Testing procedures
- **git-workflow.md** - Git and commit standards
- **c-programming/docstring-standards.md** - Documentation requirements
- **project-specific/naming-conventions.md** - Naming standards
