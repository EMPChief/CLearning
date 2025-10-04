# Error Handling Best Practices

## Overview

Error handling ensures programs behave predictably when things go wrong. This document covers error handling patterns used in CLearning projects.

## Error Handling Patterns

### 1. Return Value Pattern

**Use when:** Functions can succeed or fail

**Pattern:**
```c
// Return 1 for success, 0 for failure
int read_int(const char *prompt, int *value) {
  if (scanf("%d", value) != 1) {
    // Clear buffer and report error
    return 0;  // Failure
  }
  return 1;  // Success
}
```

**Caller Handling:**
```c
// Early return on error
if (!read_int("Enter value: ", &value)) {
  return;
}

// Retry loop on error
while (!read_int("Enter value: ", &value))
  ;
```

**Examples:**
- `project_1/calculations.c:18` - read_int
- `project_2/function_file.c:25` - read_int

### 2. Error Message Pattern

**Use when:** User needs feedback on what went wrong

**Pattern:**
```c
int read_int(const char *prompt, int *value) {
  printf("%s", prompt);
  if (scanf("%d", value) != 1) {
    // Clear buffer
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    // Specific error message
    printf("Invalid input. Please enter a valid integer.\n");
    return 0;
  }
  return 1;
}
```

**Best Practices:**
- Be specific about what went wrong
- Suggest how to fix it
- Keep messages user-friendly

**Examples:**
- `project_1/calculations.c:24` - "Please enter a valid integer"
- `project_2/function_file.c:109` - "Please enter three valid integers separated by spaces"

### 3. Validation with Early Return

**Use when:** Multiple validation steps required

**Pattern:**
```c
void calculate_two_grade_average(void) {
  int grade_one, grade_two;
  
  // First validation
  if (!read_int("Input first grade: ", &grade_one)) {
    return;  // Exit on error
  }
  
  // Second validation
  if (!read_int("Input second grade: ", &grade_two)) {
    return;  // Exit on error
  }
  
  // Both inputs valid - proceed with calculation
  double average = (grade_one + grade_two) / 2.0;
  printf("The average grade is: %.2f\n", average);
}
```

**Benefits:**
- Clean, readable code
- No nested error handling
- Clear flow: validate → process

**Examples:**
- `project_1/calculations.c:116` - calculate_two_grade_average
- `project_1/calculations.c:160` - calculate_rectangle_area

### 4. Range Validation Pattern

**Use when:** Valid input must be within a specific range

**Pattern:**
```c
void seconds_to_hms(void) {
  int total_seconds;
  
  // Combine input validation with range check
  while (!read_int("Enter total seconds: ", &total_seconds) ||
         total_seconds < 0) {
    if (total_seconds < 0) {
      printf("Please enter a non-negative value.\n");
    }
  }
  
  // Guaranteed: total_seconds >= 0
  int hours = total_seconds / 3600;
  // ... rest of calculation
}
```

**Benefits:**
- Ensures logical validity
- Provides specific feedback
- Retries until valid

**Examples:**
- `project_2/function_file.c:228` - seconds_to_hms

### 5. Choice Validation Pattern

**Use when:** User must select from limited options

**Pattern:**
```c
void temperature_converter(void) {
  double user_choice;
  
  if (!read_double("Enter 1 for C→F or 2 for F→C: ", &user_choice)) {
    return;
  }
  
  if (user_choice == 1) {
    // Handle option 1
  } else if (user_choice == 2) {
    // Handle option 2
  } else {
    // Invalid choice
    printf("Invalid choice! Please choose 1 or 2.\n");
  }
}
```

**Examples:**
- `project_1/calculations.c:267` - temperature_converter

## Buffer Management

### Critical: Always Clear Input Buffer

**Why:** Leftover characters cause cascading failures

**Pattern:**
```c
int read_int(const char *prompt, int *value) {
  int c;
  printf("%s", prompt);
  
  if (scanf("%d", value) != 1) {
    // Clear buffer on error
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    printf("Invalid input.\n");
    return 0;
  }
  
  // Clear buffer on success (removes '\n')
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  return 1;
}
```

**What it does:**
- Removes all characters up to newline
- Handles EOF gracefully
- Prevents input from "bleeding" into next scanf

## Error Handling Checklist

When implementing functions with user input:

- [ ] Check scanf return value
- [ ] Clear input buffer after every scanf
- [ ] Provide user-friendly error messages
- [ ] Return error status to caller
- [ ] Handle EOF condition
- [ ] Validate ranges/choices after input
- [ ] Document error behavior

## Common Pitfalls

### ❌ Not Handling scanf Failure
```c
// BAD
scanf("%d", &value);
printf("Value: %d\n", value);  // Uninitialized if scanf failed
```

### ✅ Proper Error Handling
```c
// GOOD
if (scanf("%d", &value) != 1) {
  printf("Invalid input\n");
  return 0;
}
printf("Value: %d\n", value);
```

### ❌ Not Clearing Buffer
```c
// BAD
if (scanf("%d", &value) != 1) {
  return 0;  // Buffer still has bad input
}
// Next scanf will immediately fail
```

### ✅ Clearing Buffer
```c
// GOOD
if (scanf("%d", &value) != 1) {
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  return 0;
}
```

### ❌ Generic Error Messages
```c
// BAD
printf("Error\n");
```

### ✅ Specific Error Messages
```c
// GOOD
printf("Invalid input. Please enter a valid integer.\n");
```

## See Also

- **input-validation.md** - Input validation patterns
- **testing-patterns.md** - Testing error handling
- **memory-safety.md** - Memory-related error handling
