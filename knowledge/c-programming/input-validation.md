# Input Validation Patterns

## Overview

Robust input validation is critical for interactive C programs. This document covers standard patterns used across CLearning projects.

## Standard Input Functions

### `read_int()` - Integer Input Validation

**Location:** `project_1/calculations.c:18`, `project_2/function_file.c:25`, `boilerplate/function_file.c:24`

```c
int read_int(const char *prompt, int *value) {
  int c;
  printf("%s", prompt);
  if (scanf("%d", value) != 1) {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    printf("Invalid input. Please enter a valid integer.\n");
    return 0;
  }
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  return 1;
}
```

**Key Features:**
- Returns 1 on success, 0 on failure
- Clears input buffer after reading
- Provides user feedback on invalid input
- Handles EOF safely

**Usage Example:**
```c
int age;
if (!read_int("Enter your age: ", &age)) {
  return;  // Handle error - exit or retry
}
// Use age value safely
```

### `read_float()` - Float Input Validation

**Location:** `project_1/calculations.c:43`, `project_2/function_file.c:50`, `boilerplate/function_file.c:49`

```c
int read_float(const char *prompt, float *value) {
  int c;
  printf("%s", prompt);
  if (scanf("%f", value) != 1) {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    printf("Invalid input. Please enter a valid number.\n");
    return 0;
  }
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  return 1;
}
```

**Usage Example:**
```c
float radius;
if (!read_float("Enter circle radius: ", &radius)) {
  return;
}
float area = 3.14159 * radius * radius;
```

### `read_double()` - Double Input Validation

**Location:** `project_1/calculations.c:68`, `project_2/function_file.c:75`, `boilerplate/function_file.c:74`

```c
int read_double(const char *prompt, double *value) {
  int c;
  printf("%s", prompt);
  if (scanf("%lf", value) != 1) {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    printf("Invalid input. Please enter a valid number.\n");
    return 0;
  }
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  return 1;
}
```

**Usage Example:**
```c
double temperature;
if (!read_double("Enter temperature in Celsius: ", &temperature)) {
  return;
}
```

### `read_three_ints()` - Multiple Integer Input

**Location:** `project_1/calculations.c:95`, `project_2/function_file.c:102`, `boilerplate/function_file.c:101`

```c
int read_three_ints(const char *prompt, int *val1, int *val2, int *val3) {
  int c;
  printf("%s", prompt);
  if (scanf("%d %d %d", val1, val2, val3) != 3) {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    printf("Invalid input. Please enter three valid integers separated by "
           "spaces.\n");
    return 0;
  }
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  return 1;
}
```

**Usage Example:**
```c
int grade1, grade2, grade3;
if (!read_three_ints("Enter three grades separated by spaces: ", 
                     &grade1, &grade2, &grade3)) {
  return;
}
double average = (grade1 + grade2 + grade3) / 3.0;
```

## Validation Patterns

### Early Return on Invalid Input

**Pattern:**
```c
void some_calculation(void) {
  int value;
  if (!read_int("Enter value: ", &value)) {
    return;  // Exit early on invalid input
  }
  // Continue with valid value
  printf("Result: %d\n", value * 2);
}
```

**Example:** `project_1/calculations.c:116` (calculate_two_grade_average)

### Retry Loop Until Valid Input

**Pattern:**
```c
void salary_calculator(void) {
  double hourly_wage;
  // Keep retrying until valid input
  while (!read_double("Enter hourly wage: ", &hourly_wage))
    ;
  // Continue with guaranteed valid input
}
```

**Example:** `project_2/function_file.c:154` (salary_calculator)

### Validation with Range Check

**Pattern:**
```c
void seconds_to_hms(void) {
  int total_seconds;
  while (!read_int("Enter total seconds: ", &total_seconds) ||
         total_seconds < 0) {
    if (total_seconds < 0) {
      printf("Please enter a non-negative value.\n");
    }
  }
  // Use validated, range-checked value
}
```

**Example:** `project_2/function_file.c:228` (seconds_to_hms)

## Best Practices

1. **Always clear the input buffer** - Prevents cascading input errors
2. **Provide specific error messages** - Help users understand what went wrong
3. **Return success/failure status** - Allow callers to handle errors appropriately
4. **Use const for prompts** - Indicates prompt strings won't be modified
5. **Handle EOF gracefully** - Prevents infinite loops on stream errors
6. **Validate ranges after input** - Combine scanf validation with logical validation

## Common Pitfalls

### ❌ Not Clearing Input Buffer
```c
// BAD: Doesn't clear buffer
scanf("%d", &value);
// Next scanf may immediately fail on leftover input
```

### ✅ Proper Buffer Clearing
```c
// GOOD: Clears buffer after scanf
if (scanf("%d", &value) != 1) {
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}
while ((c = getchar()) != '\n' && c != EOF)
  ;
```

### ❌ Ignoring scanf Return Value
```c
// BAD: Doesn't check for failure
scanf("%d", &value);
printf("Value: %d\n", value);  // May use uninitialized value
```

### ✅ Checking Return Value
```c
// GOOD: Checks return value
if (scanf("%d", &value) != 1) {
  printf("Invalid input\n");
  return 0;
}
printf("Value: %d\n", value);
```

## See Also

- **error-handling.md** - General error handling patterns
- **testing-patterns.md** - Testing input validation with Unity
- **calculation-utilities.md** - Functions that use input validation
