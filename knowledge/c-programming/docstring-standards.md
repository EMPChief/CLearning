# Documentation Standards

## Overview

CLearning projects use Doxygen-style documentation for C files. This document covers documentation standards and provides examples.

## File-Level Documentation

### Standard File Header

**Location:** Every `.c` and `.h` file should start with file-level documentation

**Template:**
```c
/**
 * @file filename.c
 * @brief Short description of file purpose
 *
 * Longer description explaining:
 * - What this file contains
 * - Key responsibilities
 * - Notable implementation details
 * - Dependencies or relationships
 */
```

**Example (Implementation File):**

From `project_2/function_file.c:1`:
```c
/**
 * @file function_file.c
 * @brief Implementation of input validation and calculation utilities
 *
 * Contains validated input functions for integers, floats, and doubles,
 * plus various calculation utilities including arithmetic sequences,
 * salary calculations, driving time estimates, and time conversions.
 */
```

**Example (Header File):**

From `boilerplate/helper.h:1`:
```c
/**
 * @file helper.h
 * @brief Template header file for function declarations
 *
 * This is a boilerplate template for quick project setup.
 * Add your function declarations below the input validation functions.
 * Includes common input validation utilities for integers, floats, and doubles.
 */
```

## Function Documentation

### Standard Function Docstring

**Template:**
```c
/**
 * Brief one-line description of what function does.
 *
 * Longer description explaining:
 * - How the function works
 * - Important implementation details
 * - Formulas used (if applicable)
 * - Side effects or state changes
 *
 * @param param_name Description of parameter
 * @param another_param Description of another parameter
 * @return Description of return value and possible values
 * @note Additional notes, warnings, or usage examples
 */
return_type function_name(param_type param_name) {
    // Implementation
}
```

### Input Validation Functions

**Example:** `project_1/calculations.c:18`

```c
/**
 * Read an integer from user input with validation.
 *
 * Prints the prompt, reads an integer using scanf, and validates the input.
 * If scanf fails to read exactly one integer, clears the input buffer and
 * returns 0. Otherwise returns 1 for success.
 *
 * @param prompt The prompt string to display to the user
 * @param value Pointer to store the validated integer value
 * @return 1 on successful input, 0 on invalid input
 */
int read_int(const char *prompt, int *value) {
  // Implementation
}
```

**Key Elements:**
- Brief description first line
- Detailed behavior in paragraph
- Each parameter documented with `@param`
- Return value documented with `@return`
- Specific return values explained (0 vs 1)

### Calculation Functions

**Example:** `project_1/calculations.c:116`

```c
/**
 * Calculate and print the average of two grades entered by the user.
 *
 * Prompts the user for two integer grades, validates input,
 * and prints the average formatted to two decimal places.
 */
void calculate_two_grade_average(void) {
  // Implementation
}
```

**For void functions with no parameters:**
- Focus on what the function does
- Mention user interaction
- Note output format if applicable

### Functions with Formulas

**Example:** `project_2/function_file.c:127`

```c
/**
 * Calculate and print the sum of an arithmetic sequence.
 *
 * Computes the sum of an arithmetic sequence using the formula:
 *   sum = (first_term + last_term) * number_of_terms / 2
 *
 * @note Uses hardcoded values: number_of_terms=9, first_term=1, last_term=17
 * @note Prints result to stdout with two decimal places
 */
void sum_of_arithmetic_sequence(void) {
  // Implementation
}
```

**Key Elements:**
- State the formula clearly
- Use `@note` for important details
- Mention hardcoded values if any

### Complex Functions

**Example:** `project_2/function_file.c:151`

```c
/**
 * Calculate and print net salary based on hourly wage, hours worked, and tax rate.
 *
 * Prompts the user for hourly wage, hours worked, and tax rate percentage.
 * Computes the gross salary, tax amount, and net salary, then prints the results.
 *
 * Formulas used:
 *   gross_salary = hourly_wage * hours_worked
 *   tax_amount = gross_salary * tax_rate_percentage / 100
 *   net_salary = gross_salary - tax_amount
 *
 * @note Prints results to stdout
 */
void salary_calculator(void) {
  // Implementation
}
```

**For multi-step calculations:**
- List all formulas used
- Explain the calculation flow
- Note any assumptions

### Functions with Validation

**Example:** `project_2/function_file.c:224`

```c
/**
 * Convert and print total seconds into hours, minutes, and seconds.
 *
 * Prompts the user for a total number of seconds, then calculates the
 * equivalent hours, minutes, and remaining seconds. Prints the result
 * in a human-readable format.
 *
 * Formulas used:
 *   hours   = total_seconds / 3600
 *   minutes = (total_seconds % 3600) / 60
 *   seconds = total_seconds % 60
 *
 * @note Validates that input is non-negative
 * @note Prints result to stdout
 */
void seconds_to_hms(void) {
  // Implementation
}
```

## Header File Documentation

### Function Declarations

**Header files should contain brief documentation:**

From `boilerplate/helper.h:13`:
```c
#ifndef HELPER_H
#define HELPER_H

int read_int(const char *prompt, int *value);
int read_float(const char *prompt, float *value);
int read_double(const char *prompt, double *value);
int read_three_ints(const char *prompt, int *val1, int *val2, int *val3);

void explain_modular_programming(void);

#endif // HELPER_H
```

**Note:** Full documentation in `.c` file; headers contain declarations only

## Documentation Tags

### Essential Tags

| Tag | Usage | Example |
|-----|-------|---------|
| `@file` | File-level doc | `@file main.c` |
| `@brief` | Short description | `@brief Main entry point` |
| `@param` | Parameter doc | `@param value Input value` |
| `@return` | Return value doc | `@return 1 on success, 0 on failure` |
| `@note` | Important notes | `@note Not thread-safe` |

### Optional Tags (for future use)

| Tag | Usage | Example |
|-----|-------|---------|
| `@see` | Cross-reference | `@see calculate_average` |
| `@warning` | Important warning | `@warning May modify global state` |
| `@example` | Usage example | `@example read_int("Age: ", &age)` |
| `@deprecated` | Deprecated code | `@deprecated Use read_int_v2 instead` |

## Style Guidelines

### 1. Brief Description

- First sentence should be < 80 characters
- Start with verb (Calculate, Read, Convert, Print)
- Be specific about what function does

```c
// GOOD
/**
 * Calculate and print the average of two grades.
 */

// BAD
/**
 * This function takes input and does stuff.
 */
```

### 2. Detailed Description

- Explain HOW, not just WHAT
- Mention validation behavior
- Note output format
- Include formulas if applicable

```c
// GOOD
/**
 * Read an integer from user input with validation.
 *
 * Prints the prompt, reads using scanf, and validates the input.
 * Clears the input buffer on both success and failure.
 *
 * @param prompt The prompt string
 * @param value Pointer to store validated integer
 * @return 1 on success, 0 on invalid input
 */

// BAD
/**
 * Reads an integer.
 *
 * @param prompt Prompt
 * @param value Value
 * @return Status
 */
```

### 3. Parameter Documentation

- Use "The" prefix for clarity
- Explain what the parameter represents
- Mention constraints if any

```c
// GOOD
@param prompt The prompt string to display to the user
@param value Pointer to store the validated integer value

// BAD
@param prompt prompt
@param value an integer
```

### 4. Return Value Documentation

- Be specific about return values
- Explain what each value means
- Mention special cases

```c
// GOOD
@return 1 on successful input, 0 on invalid input

// BAD
@return Status
```

## Documentation Checklist

When documenting a file:
- [ ] File-level `@file` and `@brief` present
- [ ] Longer file description explains purpose
- [ ] Each function has docstring
- [ ] Brief description is clear and concise
- [ ] Parameters documented with `@param`
- [ ] Return value documented with `@return`
- [ ] Formulas included where applicable
- [ ] Special behaviors noted with `@note`
- [ ] Validation behavior explained
- [ ] Output format mentioned

## Examples by Function Type

### Input Function
```c
/**
 * Read a float from user input with validation.
 *
 * Prints the prompt, reads using scanf, and validates.
 * Clears buffer and provides error message on failure.
 *
 * @param prompt The prompt string to display
 * @param value Pointer to store the validated float
 * @return 1 on success, 0 on invalid input
 */
int read_float(const char *prompt, float *value);
```

### Calculation Function
```c
/**
 * Calculate and print rectangle area.
 *
 * Prompts for length and height, validates input,
 * and prints area as integer.
 */
void calculate_rectangle_area(void);
```

### Conversion Function
```c
/**
 * Convert temperature between Celsius and Fahrenheit.
 *
 * Prompts user to choose conversion direction,
 * reads temperature, and prints converted value.
 *
 * Formulas:
 *   C→F: (C × 9/5) + 32
 *   F→C: (F - 32) × 5/9
 */
void temperature_converter(void);
```

## See Also

- **input-validation.md** - Functions to document
- **calculation-utilities.md** - Calculation function examples
- **project-specific/file-organization.md** - Project structure
