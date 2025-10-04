# Memory Safety Guidelines

## Overview

Memory safety is critical in C programming. This document covers memory safety patterns and common pitfalls observed in CLearning projects.

## Stack vs Heap

### Stack Allocation (Preferred for Small, Fixed-Size Data)

**Pattern:**
```c
void calculate_average(void) {
  int grade_one;      // Stack allocated
  int grade_two;      // Stack allocated
  double average;     // Stack allocated
  
  // Use variables
  if (!read_int("Enter grade 1: ", &grade_one)) {
    return;  // Stack variables automatically cleaned up
  }
  // ...
}
```

**Benefits:**
- Automatic cleanup (no manual free needed)
- Fast allocation
- No memory leaks possible

**Used throughout:** All calculation functions in project_1 and project_2

### Heap Allocation (When Needed)

**Note:** Current projects use stack allocation exclusively. Use heap when:
- Size not known at compile time
- Large data structures
- Data must outlive function scope

**Pattern (for future reference):**
```c
int *allocate_array(size_t size) {
  int *arr = malloc(size * sizeof(int));
  if (arr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }
  return arr;
}

// Caller must free
int *data = allocate_array(100);
if (data != NULL) {
  // Use data
  free(data);  // Always free
}
```

## Pointer Safety

### Passing Pointers for Output Parameters

**Pattern:**
```c
// Function modifies value through pointer
int read_int(const char *prompt, int *value) {
  // Check pointer validity (defensive programming)
  if (value == NULL) {
    return 0;
  }
  
  // Modify through pointer
  if (scanf("%d", value) != 1) {
    return 0;
  }
  return 1;
}

// Caller
int age;
read_int("Age: ", &age);  // Pass address of age
```

**Examples:**
- `project_1/calculations.c:18` - read_int
- `project_2/function_file.c:102` - read_three_ints

### Const Correctness

**Pattern:**
```c
// const indicates prompt won't be modified
int read_int(const char *prompt, int *value) {
  printf("%s", prompt);  // OK: printf doesn't modify
  // prompt[0] = 'X';    // ERROR: can't modify const
  
  *value = 42;  // OK: value is not const
  return 1;
}
```

**Benefits:**
- Compiler enforces immutability
- Documents intent
- Prevents accidental modifications

**Used throughout:** All read_* functions use `const char *prompt`

## Buffer Safety

### scanf Buffer Management

**Critical Pattern:**
```c
int read_int(const char *prompt, int *value) {
  int c;
  printf("%s", prompt);
  
  if (scanf("%d", value) != 1) {
    // CRITICAL: Clear buffer to prevent overflow
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    return 0;
  }
  
  // CRITICAL: Clear trailing newline
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  return 1;
}
```

**Why this matters:**
- Prevents buffer overflow attacks
- Handles arbitrarily long bad input safely
- Checks EOF to prevent infinite loops

### String Buffer Safety (Future Reference)

**When working with strings:**
```c
// BAD: No bounds checking
char name[32];
scanf("%s", name);  // Dangerous: can overflow

// GOOD: Limit input size
char name[32];
scanf("%31s", name);  // Leaves room for '\0'

// BETTER: Use fgets
char name[32];
if (fgets(name, sizeof(name), stdin) != NULL) {
  // Safe: fgets respects buffer size
}
```

## Type Safety

### Proper Format Specifiers

**Pattern:**
```c
// Match scanf format to variable type
int i;
scanf("%d", &i);     // int: %d

float f;
scanf("%f", &f);     // float: %f

double d;
scanf("%lf", &d);    // double: %lf (note: 'l' prefix)

// Printf is different!
printf("%f", f);     // float: %f
printf("%lf", d);    // double: %lf or %f (both work)
```

**Examples:**
- `project_1/calculations.c:21` - scanf("%d", ...) for int
- `project_1/calculations.c:46` - scanf("%f", ...) for float  
- `project_1/calculations.c:71` - scanf("%lf", ...) for double

### Integer Division vs Float Division

**Pattern:**
```c
int grade_one = 70;
int grade_two = 80;

// Integer division (WRONG for average)
double avg_wrong = (grade_one + grade_two) / 2;  // = 75.0

// Float division (CORRECT)
double avg_right = (grade_one + grade_two) / 2.0;  // = 75.0

// Explicit cast (also correct)
double avg_cast = (double)(grade_one + grade_two) / 2;
```

**Examples:**
- `project_1/calculations.c:128` - Uses 2.0 for float division
- `project_2/function_file.c:195` - Cast to double

## Uninitialized Variables

### Always Check Before Use

**Pattern:**
```c
void calculate_average(void) {
  int grade;
  
  // BAD: Using uninitialized variable
  // printf("Grade: %d\n", grade);  // Undefined behavior
  
  // GOOD: Initialize before use
  if (!read_int("Enter grade: ", &grade)) {
    return;  // Don't use grade if read failed
  }
  
  // Now grade is initialized and safe to use
  printf("Grade: %d\n", grade);
}
```

**Rule:** Variables are only initialized after successful scanf/assignment

## Memory Safety Checklist

- [ ] Use stack allocation for fixed-size data
- [ ] Clear scanf buffer after every read
- [ ] Check scanf return value before using variable
- [ ] Use const for parameters that shouldn't change
- [ ] Match scanf format specifiers to types
- [ ] Use 2.0 (not 2) for float division
- [ ] Handle EOF in buffer clearing loops
- [ ] Don't use variables before initialization

## Common Pitfalls

### ❌ Using Uninitialized Variable
```c
int value;
printf("%d\n", value);  // Undefined behavior
```

### ✅ Initialize Before Use
```c
int value;
if (scanf("%d", &value) == 1) {
  printf("%d\n", value);  // Safe
}
```

### ❌ Wrong Format Specifier
```c
double d;
scanf("%f", &d);  // WRONG: Should be %lf
```

### ✅ Correct Format Specifier
```c
double d;
scanf("%lf", &d);  // CORRECT
```

### ❌ Integer Division Bug
```c
int a = 1, b = 2;
double avg = (a + b) / 2;  // = 1.0 (WRONG)
```

### ✅ Float Division
```c
int a = 1, b = 2;
double avg = (a + b) / 2.0;  // = 1.5 (CORRECT)
```

## See Also

- **error-handling.md** - Error handling patterns
- **input-validation.md** - Safe input validation
- **testing-patterns.md** - Testing for memory safety
