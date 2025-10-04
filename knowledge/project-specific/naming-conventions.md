# Naming Conventions

## Overview

CLearning projects follow consistent naming conventions across all code. This document defines standards for variables, functions, files, and other identifiers.

## Variable Names

### Standard: `snake_case`

**Pattern:** All lowercase with underscores separating words

**Examples:**
```c
// Descriptive variable names
int grade_average;
double hourly_wage;
float circle_radius;
int total_seconds;

// Temporary/loop variables
int i, j, k;  // Loop counters
int c;        // Character buffer operations

// From project_1/calculations.c:
int grade_one;
int grade_two;
double grade_average;
int rectangle_length;
int rectangle_height;
```

**Guidelines:**
- Use full words, not abbreviations (except standard ones)
- Be descriptive but concise
- Use context-appropriate names

**Good Examples:**
```c
int current_year;      // Clear and specific
double celsius_temperature;
float rectangle_area;
```

**Bad Examples:**
```c
int cy;               // Too abbreviated
double temp;          // Ambiguous
float a;              // Not descriptive
```

## Function Names

### Standard: `snake_case`

**Pattern:** All lowercase with underscores, verb-first naming

**Examples from codebase:**
```c
// Input validation functions
int read_int(const char *prompt, int *value);
int read_float(const char *prompt, float *value);
int read_double(const char *prompt, double *value);
int read_three_ints(const char *prompt, int *val1, int *val2, int *val3);

// Calculation functions
void calculate_two_grade_average(void);
void calculate_birth_year(void);
void calculate_rectangle_area(void);
void calculate_rectangle_perimeter(void);

// Conversion functions
void temperature_converter(void);
void seconds_to_hms(void);

// Other functions
void sum_of_arithmetic_sequence(void);
void salary_calculator(void);
void driving_time_calculator(void);
void swap_two_floating_numbers(void);
```

**Naming Patterns:**

| Function Type | Pattern | Examples |
|--------------|---------|----------|
| Input | `read_<type>` | `read_int`, `read_float` |
| Calculation | `calculate_<what>` | `calculate_average`, `calculate_area` |
| Conversion | `<what>_converter` or `<from>_to_<to>` | `temperature_converter`, `seconds_to_hms` |
| Utility | `<verb>_<noun>` | `swap_numbers`, `print_menu` |

## Constants and Macros

### Standard: `UPPER_CASE`

**Pattern:** All uppercase with underscores

**Examples:**
```c
#define PI 3.141592653589793
#define MAX_BUFFER_SIZE 256
#define DEFAULT_TAX_RATE 15
```

**Guidelines:**
- Use for mathematical constants
- Use for buffer sizes
- Use for configuration values

## File Names

### Source Files: `snake_case.c` or `snake_case.h`

**Standard files:**
```
main.c              # Program entry point
function_file.c     # Function implementations
helper.h            # Function declarations
calculations.c      # Calculation functions
calculations.h      # Calculation headers
```

**Test files:**
```
test_calculations.c
test_input_validation.c
test_utils.c
test_utils.h
```

### Project Directories: `snake_case` or `project_N`

**Patterns:**
```
project_1/          # Numbered projects
project_2/
boilerplate/        # Descriptive names
knowledge/
```

## Type Definitions (Future Reference)

### Standard: `snake_case_t`

**Pattern:** snake_case with `_t` suffix

```c
typedef struct {
  int hours;
  int minutes;
  int seconds;
} time_t;

typedef enum {
  STATUS_SUCCESS,
  STATUS_ERROR,
  STATUS_INVALID_INPUT
} status_t;
```

**Note:** Not currently used in projects, but recommended for future code

## Header Guards

### Standard: `FILENAME_H`

**Pattern:** Uppercase filename with underscores

**Examples:**
```c
// helper.h
#ifndef HELPER_H
#define HELPER_H

// Function declarations

#endif // HELPER_H
```

```c
// calculations.h
#ifndef CALCULATIONS_H
#define CALCULATIONS_H

// Function declarations

#endif // CALCULATIONS_H
```

## Test Function Names

### Standard: `test_<function>_<scenario>`

**Pattern:** Prefix with `test_`, describe function and scenario

**Examples from project_1/tests/test_calculations_io.c:**
```c
void test_two_grade_average_typical(void);
void test_two_grade_average_rounding(void);
void test_birth_year_typical(void);
void test_rectangle_area_int(void);
void test_temperature_converter_c_to_f(void);
void test_temperature_converter_f_to_c(void);
void test_temperature_converter_invalid_choice(void);
```

**Pattern breakdown:**
- `test_` prefix (required)
- Function name being tested
- Underscore separator
- Scenario description (typical, error, edge_case, etc.)

## Naming Guidelines Summary

| Item | Convention | Example |
|------|-----------|---------|
| Variables | `snake_case` | `grade_average` |
| Functions | `snake_case` | `calculate_average` |
| Constants | `UPPER_CASE` | `PI`, `MAX_SIZE` |
| Macros | `UPPER_CASE` | `BUFFER_SIZE` |
| Source files | `snake_case.c` | `function_file.c` |
| Header files | `snake_case.h` | `helper.h` |
| Projects | `snake_case` or `project_N` | `project_1` |
| Header guards | `FILENAME_H` | `HELPER_H` |
| Test functions | `test_<name>_<case>` | `test_read_int_valid` |

## Common Naming Patterns

### Input Variables
```c
// Pattern: <type>_<purpose>
int user_input;
double input_value;
char user_choice;
```

### Calculation Variables
```c
// Pattern: <what>_<property>
double rectangle_area;
double circle_perimeter;
int total_sum;
double grade_average;
```

### Temporary Variables
```c
// Pattern: descriptive_purpose or single_letter
int c;                    // Character for buffer operations
int i, j, k;             // Loop counters
double temporary_variable;  // For swapping
```

### Loop Variables
```c
// Pattern: i, j, k for simple loops; descriptive for complex
for (int i = 0; i < n; i++) {
  // Use 'i' for simple iteration
}

for (int test_index = 0; test_index < num_tests; test_index++) {
  // Use descriptive name for complex logic
}
```

## Abbreviations

### Acceptable Abbreviations

```c
// These are acceptable:
int num_items;      // 'num' for number
int max_value;      // 'max' for maximum
int min_value;      // 'min' for minimum
int calc_result;    // 'calc' for calculation (context-dependent)
char c;             // Single char for getchar() operations
int i, j, k;        // Loop counters
```

### Avoid These

```c
// Avoid unclear abbreviations:
int tmp;            // Use 'temporary_value' or specific name
int val;            // Use 'value' or be more specific
int cnt;            // Use 'count'
int avg;            // Use 'average'
```

## Best Practices

1. **Be Consistent** - Follow the same pattern throughout the project
2. **Be Descriptive** - Names should clearly indicate purpose
3. **Be Concise** - Don't make names unnecessarily long
4. **Use Context** - Variable name clarity depends on scope
5. **Follow Patterns** - Use established patterns for similar items

### Examples

**Good:**
```c
double calculate_circle_area(double radius) {
  double area = PI * radius * radius;
  return area;
}
```

**Bad:**
```c
double calcCircleA(double r) {  // Mixed case, abbreviated
  double a = PI * r * r;         // Unclear variable name
  return a;
}
```

## See Also

- **file-organization.md** - File structure standards
- **project-structure.md** - Project organization
- **docstring-standards.md** - Documentation naming
