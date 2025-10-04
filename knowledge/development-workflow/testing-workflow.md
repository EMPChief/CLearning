# Testing Workflow

## Overview

CLearning projects use test-driven development (TDD) with the Unity testing framework. This document describes testing procedures and workflows.

## Testing Philosophy

**Key Principles:**
1. Write tests before or alongside implementation
2. Every function should have tests
3. Tests document expected behavior
4. Run tests frequently during development
5. Never commit failing tests

## Test-Driven Development (TDD) Workflow

### Basic TDD Cycle

```
1. Write failing test
   ↓
2. Run test (should fail)
   ↓
3. Write minimal code to pass
   ↓
4. Run test (should pass)
   ↓
5. Refactor if needed
   ↓
6. Run test again (should still pass)
   ↓
7. Repeat for next feature
```

### Example: Adding Calculator Function

**Step 1: Write Test First**

```c
// tests/test_calculator.c

void test_add_two_numbers(void) {
    // Arrange
    int a = 5, b = 3;
    int expected = 8;
    
    // Act
    int actual = add(a, b);
    
    // Assert
    TEST_ASSERT_EQUAL_INT(expected, actual);
}
```

**Step 2: Run Test (Fails)**

```bash
make test-calculator
# Result: Compilation error - add() doesn't exist
```

**Step 3: Implement Function**

```c
// function_file.c

int add(int a, int b) {
    return a + b;
}
```

**Step 4: Run Test (Passes)**

```bash
make test-calculator
# Result: 1 Tests 0 Failures 0 Ignored - OK
```

**Step 5: Refactor if Needed**

```c
// Already simple, no refactoring needed
```

**Step 6: Retest**

```bash
make test-calculator
# Result: Still passes - OK
```

## Testing Commands

### Build Tests

```bash
# Build specific test
make tests/test_calculations

# Build all tests (if targets exist)
make test-build
```

### Run Tests

```bash
# Run all tests
make test

# Run specific test suite
make test-calculations
make test-input

# Run test binary directly
./tests/test_calculations
```

### Test During Development

```bash
# Continuous testing pattern
make clean && make && make test

# Watch for changes (manual)
while true; do
    make test
    sleep 2
done
```

## Test File Organization

### Creating Test File

**1. Create test file:**

```bash
touch tests/test_myfeature.c
```

**2. Add boilerplate:**

```c
#include "../unity/unity.h"
#include "../helper.h"

// Test functions here

int main(void) {
    UnityBegin(__FILE__);
    
    // RUN_TEST calls here
    
    UnityEnd();
    return Unity_tests_failed ? 1 : 0;
}
```

**3. Add to Makefile:**

```makefile
TEST_MYFEATURE := tests/test_myfeature

$(TEST_MYFEATURE): tests/test_myfeature.c function_file.c $(UNITY_SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

test-myfeature: $(TEST_MYFEATURE)
	@echo "Running myfeature tests..."
	@./$(TEST_MYFEATURE)

test: test-calculations test-input test-myfeature
	@echo "All tests completed!"
```

## Test Patterns

### Testing Pure Functions

**Pattern: Arrange-Act-Assert (AAA)**

```c
void test_calculate_average(void) {
    // Arrange: Set up test data
    int grade1 = 80;
    int grade2 = 90;
    double expected = 85.0;
    
    // Act: Call function
    double actual = calculate_average(grade1, grade2);
    
    // Assert: Verify result
    TEST_ASSERT_EQUAL_DOUBLE(expected, actual);
}
```

### Testing I/O Functions

**Pattern: Capture and Verify**

```c
void test_calculate_two_grade_average(void) {
    char output[4096];
    char expected[256];
    
    // Simulate input "70\n80\n"
    capture_io_run(calculate_two_grade_average, "70\n80\n", 
                   output, sizeof(output));
    
    // Verify output contains expected result
    snprintf(expected, sizeof(expected), 
             "The average grade is: %.2f\n", 75.0);
    ASSERT_CONTAINS(output, expected);
}
```

**See:** `c-programming/testing-patterns.md` for `capture_io_run` details

### Testing Multiple Scenarios

**Pattern: One test per scenario**

```c
// Normal case
void test_read_int_valid_input(void) {
    // Test valid input
}

// Error case
void test_read_int_invalid_input(void) {
    // Test invalid input
}

// Edge case
void test_read_int_boundary_values(void) {
    // Test INT_MAX, INT_MIN, etc.
}

// Main runner
int main(void) {
    UnityBegin(__FILE__);
    
    RUN_TEST(test_read_int_valid_input);
    RUN_TEST(test_read_int_invalid_input);
    RUN_TEST(test_read_int_boundary_values);
    
    UnityEnd();
    return Unity_tests_failed ? 1 : 0;
}
```

## Test Coverage Goals

### What to Test

**Input Validation Functions:**
- ✅ Valid input
- ✅ Invalid input (letters, symbols)
- ✅ Boundary values
- ✅ Empty input
- ✅ Multiple values

**Calculation Functions:**
- ✅ Typical values
- ✅ Edge cases (0, negative)
- ✅ Rounding behavior
- ✅ Division by zero (if applicable)

**Conversion Functions:**
- ✅ Forward conversion
- ✅ Reverse conversion
- ✅ Invalid choice handling
- ✅ Boundary values

### Coverage Checklist

For each function:
- [ ] At least one happy path test
- [ ] At least one error case test
- [ ] Edge cases covered
- [ ] Output format verified
- [ ] Return values checked

## Test Naming

### Convention: `test_<function>_<scenario>`

**Examples:**

```c
// Function being tested: calculate_average

void test_calculate_average_typical(void);
void test_calculate_average_rounding(void);
void test_calculate_average_zero_values(void);
void test_calculate_average_negative_values(void);
```

**Scenarios:**
- `typical` - Normal/expected case
- `invalid` - Invalid input
- `empty` - Empty/null input
- `boundary` - Edge values
- `error` - Error conditions
- `rounding` - Rounding behavior

## Running Tests

### Development Workflow

```bash
# 1. Write/modify code
vim function_file.c

# 2. Write/modify tests
vim tests/test_myfeature.c

# 3. Build and test
make clean
make
make test

# 4. Fix any failures
# 5. Repeat until all pass
```

### Continuous Testing

```bash
# After every change
make test

# Before committing
make clean
make test

# Expected output:
# Running calculation tests...
# 12 Tests 0 Failures 0 Ignored 
# OK
```

## Interpreting Test Results

### Successful Test Output

```
Running calculation tests...
tests/test_calculations.c:45:test_sum:PASS
tests/test_calculations.c:52:test_average:PASS
tests/test_calculations.c:59:test_multiply:PASS

-----------------------
3 Tests 0 Failures 0 Ignored 
OK
```

### Failed Test Output

```
Running calculation tests...
tests/test_calculations.c:45:test_sum:PASS
tests/test_calculations.c:52:test_average:FAIL: Expected 85.0 Was 84.5
tests/test_calculations.c:59:test_multiply:PASS

-----------------------
3 Tests 1 Failures 0 Ignored 
FAIL
```

**Action:** Fix the failing test or implementation

### Compilation Error

```
gcc -std=c11 -Wall -Wextra -O2 tests/test_calculations.c function_file.c unity/unity.c -o tests/test_calculations -lm
function_file.c:25:5: error: expected ';' before 'return'
```

**Action:** Fix compilation error first, then run tests

## Testing Best Practices

### 1. Test One Thing Per Test

**Good:**
```c
void test_read_int_valid_input(void) {
    // Only tests valid input case
}

void test_read_int_invalid_input(void) {
    // Only tests invalid input case
}
```

**Bad:**
```c
void test_read_int(void) {
    // Tests valid input
    // Tests invalid input  
    // Tests edge cases
    // Too much in one test
}
```

### 2. Use Descriptive Names

**Good:**
```c
void test_temperature_converter_celsius_to_fahrenheit(void);
void test_temperature_converter_invalid_choice(void);
```

**Bad:**
```c
void test1(void);
void test_converter(void);
```

### 3. Test Edge Cases

```c
void test_divide_by_zero(void);
void test_negative_values(void);
void test_maximum_int_value(void);
void test_empty_string_input(void);
```

### 4. Keep Tests Independent

```c
// GOOD - Each test is independent
void test_feature_a(void) {
    int value = 10;  // Own data
    // Test feature A
}

void test_feature_b(void) {
    int value = 20;  // Own data
    // Test feature B
}
```

**Avoid:** Tests that depend on each other's state

### 5. Run Tests Before Committing

```bash
# Always run before commit
make clean
make
make test

# Only commit if all tests pass
```

## Common Testing Issues

### Issue: Tests Pass Locally, Fail in CI

**Cause:** Environment differences

**Solution:**
- Use consistent compiler flags
- Avoid platform-specific code
- Test on multiple machines

### Issue: Flaky Tests

**Cause:** Tests sometimes pass, sometimes fail

**Solutions:**
- Remove timing dependencies
- Ensure test independence
- Use fixed test data
- Clear state between tests

### Issue: Tests Take Too Long

**Solutions:**
- Split into multiple test files
- Run specific suites during development
- Run full suite before commit

### Issue: Can't Test Interactive Functions

**Solution:** Use I/O capture pattern

```c
// See project_1/tests/test_utils.h
capture_io_run(function, input, output, size);
```

## Test Maintenance

### When to Update Tests

- Function signature changes
- Function behavior changes
- New edge cases discovered
- Bugs fixed (add regression test)

### Refactoring Tests

**When tests get too complex:**
1. Extract common setup into helper functions
2. Use test fixtures (setUp/tearDown)
3. Split into multiple test files

## Advanced Testing (Future)

### Coverage Analysis

```bash
# With gcov (future enhancement)
gcc --coverage -o test_file test.c
./test_file
gcov test.c
```

### Mocking (Future)

```c
// Mock external dependencies
// Not currently used but possible
```

### Performance Testing (Future)

```c
// Measure execution time
// Compare performance
```

## See Also

- **c-programming/testing-patterns.md** - Detailed Unity patterns
- **code-review-checklist.md** - Test quality checks
- **makefile-patterns.md** - Test build configuration
- **agent-delegation.md** - Who writes tests
