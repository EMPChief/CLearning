# Testing Patterns with Unity Framework

## Overview

CLearning projects use the Unity testing framework for unit tests. This document covers testing patterns and best practices.

## Unity Framework Setup

### Directory Structure

```
project_2/
├── tests/
│   ├── test_calculations.c       # Test file
│   ├── test_input_validation.c   # Test file
│   └── test_utils.h              # Test utilities
├── unity/
│   ├── unity.c                   # Unity framework
│   └── unity.h                   # Unity header
├── function_file.c               # Code under test
└── Makefile                      # Build with test targets
```

**Example:** project_2/ and project_1/ follow this structure

### Makefile Integration

**Pattern:** `project_2/Makefile:11-39`

```makefile
UNITY_SRC := unity/unity.c
TEST_CALCULATIONS := tests/test_calculations
TEST_INPUT := tests/test_input_validation

# Compile test binary
$(TEST_CALCULATIONS): tests/test_calculations.c function_file.c $(UNITY_SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Run specific test suite
test-calculations: $(TEST_CALCULATIONS)
	@echo "Running calculation tests..."
	@./$(TEST_CALCULATIONS)

# Run all tests
test: test-calculations test-input
	@echo "All tests completed!"
```

**Usage:**
```bash
make test                  # Run all tests
make test-calculations     # Run specific test suite
make test-input           # Run input validation tests
```

## Test File Structure

### Basic Template

```c
#include "../unity/unity.h"
#include "../function_file.h"

// Test function
void test_something(void) {
    // Arrange
    int expected = 42;
    int actual;
    
    // Act
    actual = some_function();
    
    // Assert
    TEST_ASSERT_EQUAL_INT(expected, actual);
}

// Main test runner
int main(void) {
    UnityBegin(__FILE__);
    
    RUN_TEST(test_something);
    
    UnityEnd();
    return Unity_tests_failed ? 1 : 0;
}
```

## Testing Patterns

### 1. Unit Testing Pure Functions

**Pattern:** Test functions without I/O

```c
// Function under test
int calculate_sum(int a, int b) {
    return a + b;
}

// Test
void test_calculate_sum(void) {
    TEST_ASSERT_EQUAL_INT(5, calculate_sum(2, 3));
    TEST_ASSERT_EQUAL_INT(0, calculate_sum(-1, 1));
    TEST_ASSERT_EQUAL_INT(-5, calculate_sum(-2, -3));
}
```

**Example:** `project_2/tests/test_calculations.c`

### 2. Testing I/O Functions with Capture

**Pattern:** Redirect stdin/stdout for testing interactive functions

**Test Utility:** `project_1/tests/test_utils.h`

```c
// Captures stdout and provides stdin for testing
void capture_io_run(void (*fn)(void), const char *input_data, 
                    char *out_buf, size_t out_size);
```

**Usage Example:** `project_1/tests/test_calculations_io.c:17`

```c
void test_two_grade_average_typical(void) {
    char out[4096];
    char expect[256];
    
    // Run function with simulated input "70\n80\n"
    capture_io_run(calculate_two_grade_average, "70\n80\n", 
                   out, sizeof(out));
    
    // Check output contains expected result
    snprintf(expect, sizeof(expect), 
             "The average grade is: %.2f\n", (70 + 80) / 2.0);
    ASSERT_CONTAINS(out, expect);
}
```

**Pattern explained:**
1. Prepare input string (e.g., "70\n80\n")
2. Call `capture_io_run` with function and input
3. Verify captured output contains expected text

### 3. Testing Input Validation

**Pattern:** Test both valid and invalid inputs

```c
void test_read_int_valid(void) {
    int value;
    // Simulate valid input
    capture_and_test("42\n", &value);
    TEST_ASSERT_EQUAL_INT(1, result);  // Success
    TEST_ASSERT_EQUAL_INT(42, value);
}

void test_read_int_invalid(void) {
    int value;
    // Simulate invalid input
    capture_and_test("abc\n", &value);
    TEST_ASSERT_EQUAL_INT(0, result);  // Failure
    // Output should contain error message
    ASSERT_CONTAINS(output, "Invalid input");
}
```

**Example:** `project_2/tests/test_input_validation.c`

### 4. Testing Edge Cases

**Pattern:** Test boundary conditions and special cases

```c
void test_temperature_converter_c_to_f(void) {
    // Normal case
    capture_io_run(temperature_converter, "1\n37\n", out, sizeof(out));
    snprintf(expect, sizeof(expect), "37.00 Celsius is 98.60 Fahrenheit\n");
    ASSERT_CONTAINS(out, expect);
}

void test_temperature_converter_invalid_choice(void) {
    // Error case: invalid choice
    capture_io_run(temperature_converter, "3\n", out, sizeof(out));
    ASSERT_CONTAINS(out, "Invalid choice");
}
```

**Example:** `project_1/tests/test_calculations_io.c:67-79`

### 5. Testing Multiple Scenarios

**Pattern:** One test function per scenario

```c
// Test typical case
void test_two_grade_average_typical(void) {
    capture_io_run(calculate_two_grade_average, "70\n80\n", out, sizeof(out));
    ASSERT_CONTAINS(out, "The average grade is: 75.00\n");
}

// Test rounding behavior
void test_two_grade_average_rounding(void) {
    capture_io_run(calculate_two_grade_average, "1\n2\n", out, sizeof(out));
    ASSERT_CONTAINS(out, "The average grade is: 1.50\n");
}

int main(void) {
    UnityBegin(__FILE__);
    RUN_TEST(test_two_grade_average_typical);
    RUN_TEST(test_two_grade_average_rounding);
    UnityEnd();
    return Unity_tests_failed ? 1 : 0;
}
```

**Example:** `project_1/tests/test_calculations_io.c:17-28`

## Unity Assertions

### Common Assertions

```c
// Integer equality
TEST_ASSERT_EQUAL_INT(expected, actual);

// Float/Double equality (with tolerance)
TEST_ASSERT_EQUAL_FLOAT(expected, actual);
TEST_ASSERT_EQUAL_DOUBLE(expected, actual);

// String equality
TEST_ASSERT_EQUAL_STRING(expected, actual);

// Boolean/Null checks
TEST_ASSERT_TRUE(condition);
TEST_ASSERT_FALSE(condition);
TEST_ASSERT_NULL(pointer);
TEST_ASSERT_NOT_NULL(pointer);

// Custom: String contains
#define ASSERT_CONTAINS(haystack, needle) \
    TEST_ASSERT(strstr((haystack), (needle)) != NULL)
```

**Used in:** `project_1/tests/test_calculations_io.c:12`

## Test Organization

### Naming Conventions

```c
// test_<function_name>_<scenario>
void test_read_int_valid_input(void) { }
void test_read_int_invalid_input(void) { }
void test_calculate_average_typical(void) { }
void test_calculate_average_rounding(void) { }
```

### Test File Naming

```
tests/test_<module>.c       # Test file for <module>
tests/test_calculations.c   # Tests for calculations
tests/test_input_validation.c  # Tests for input functions
```

## Running Tests

### Make Targets

```bash
# Run all tests
make test

# Run specific test suite
make test-calculations
make test-input

# Clean and rebuild tests
make clean
make test
```

### Test Output

```
Running calculation tests...
test_calculations.c:45:test_sum_of_arithmetic_sequence:PASS
test_calculations.c:52:test_salary_calculator:PASS
...
-----------------------
12 Tests 0 Failures 0 Ignored 
OK
```

## Testing Checklist

- [ ] Create `tests/` directory in project
- [ ] Add Unity framework (`unity/unity.c`, `unity/unity.h`)
- [ ] Create test files (`test_*.c`)
- [ ] Include module under test
- [ ] Write test functions (test_<name>)
- [ ] Add test targets to Makefile
- [ ] Run tests with `make test`
- [ ] Test both success and failure cases
- [ ] Test edge cases and boundaries
- [ ] Use descriptive test names

## Common Patterns

### Test with Expected Output

```c
void test_function_output(void) {
    char out[4096];
    capture_io_run(some_function, "input\n", out, sizeof(out));
    ASSERT_CONTAINS(out, "expected output");
}
```

### Test with Multiple Inputs

```c
void test_three_grades(void) {
    char out[4096];
    capture_io_run(calculate_three_grade_average, 
                   "70 80 90\n", out, sizeof(out));
    ASSERT_CONTAINS(out, "The average grade is: 80.00\n");
}
```

### Test Error Messages

```c
void test_invalid_input_message(void) {
    char out[4096];
    capture_io_run(some_function, "invalid\n", out, sizeof(out));
    ASSERT_CONTAINS(out, "Invalid input");
}
```

## See Also

- **error-handling.md** - Error handling to test
- **input-validation.md** - Input functions to test
- **calculation-utilities.md** - Calculation functions to test
- Unity documentation: https://github.com/ThrowTheSwitch/Unity
