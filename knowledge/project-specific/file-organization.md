# File Organization

## Overview

CLearning projects follow a standard three-file structure for modularity and clarity. This document describes the standard file organization pattern.

## Standard File Structure

### Core Files

Every project contains three core source files:

```
project_name/
├── main.c              # Entry point, menu system
├── function_file.c     # Function implementations
└── helper.h            # Function declarations
```

### With Testing

Projects with tests include additional directories:

```
project_name/
├── main.c              # Entry point
├── function_file.c     # Implementations
├── helper.h            # Declarations
├── Makefile            # Build configuration
├── tests/              # Test directory
│   ├── test_calculations.c
│   ├── test_input_validation.c
│   └── test_utils.h
└── unity/              # Unity framework
    ├── unity.c
    └── unity.h
```

## File Purposes

### `main.c` - Entry Point

**Purpose:** Program entry point and user interface

**Responsibilities:**
- Define `main()` function
- Display menu/options to user
- Call functions from `function_file.c`
- Handle program flow

**Pattern:**
```c
#include <stdio.h>
#include "helper.h"

int main(void) {
  // Display menu
  printf("Choose an option:\n");
  printf("1. Calculate average\n");
  printf("2. Convert temperature\n");
  
  // Get user choice
  int choice;
  scanf("%d", &choice);
  
  // Call appropriate function
  switch (choice) {
    case 1:
      calculate_average();
      break;
    case 2:
      temperature_converter();
      break;
    default:
      printf("Invalid choice\n");
  }
  
  return 0;
}
```

**Key Points:**
- Include `helper.h` for function declarations
- Keep logic minimal (delegate to functions)
- Handle user interaction
- Return 0 on success

### `function_file.c` - Implementations

**Purpose:** Contains all function implementations

**Responsibilities:**
- Implement all declared functions
- Include file-level docstring
- Include `helper.h`
- Provide input validation utilities
- Implement calculation/conversion functions

**Structure:**
```c
/**
 * @file function_file.c
 * @brief Implementation of [project purpose]
 *
 * Detailed description of what this file contains.
 */

#include "helper.h"
#include <stdio.h>

// Input validation functions
int read_int(const char *prompt, int *value) {
  // Implementation
}

int read_float(const char *prompt, float *value) {
  // Implementation
}

// ... more input functions

// Calculation functions
void calculate_average(void) {
  // Implementation
}

// ... more functions
```

**Organization within file:**
1. File-level docstring
2. Includes
3. Input validation functions (read_*)
4. Calculation/utility functions
5. Main application functions

**Example:** `project_2/function_file.c`

### `helper.h` - Declarations

**Purpose:** Header file with function declarations

**Responsibilities:**
- Declare all functions from `function_file.c`
- Include header guards
- Include file-level docstring
- NO implementations (declarations only)

**Structure:**
```c
/**
 * @file helper.h
 * @brief Function declarations for [project]
 *
 * Description of header contents.
 */

#ifndef HELPER_H
#define HELPER_H

// Input validation functions
int read_int(const char *prompt, int *value);
int read_float(const char *prompt, float *value);
int read_double(const char *prompt, double *value);
int read_three_ints(const char *prompt, int *val1, int *val2, int *val3);

// Application functions
void calculate_average(void);
void temperature_converter(void);

#endif // HELPER_H
```

**Key Components:**
1. File docstring
2. Header guard (`#ifndef` / `#define` / `#endif`)
3. Function declarations (no implementations)
4. Organized by function type

**Example:** `boilerplate/helper.h`

## Alternative Naming

### Project-Specific Names

Some projects use descriptive names instead of generic `function_file`:

```
project_1/
├── main.c
├── calculations.c      # Instead of function_file.c
└── calculations.h      # Instead of helper.h
```

**When to use:**
- When project has a clear theme (e.g., calculations)
- For better code organization
- For improved clarity

**Rule:** Header and implementation must match:
- `calculations.c` ↔ `calculations.h`
- `utilities.c` ↔ `utilities.h`
- `converters.c` ↔ `converters.h`

## Testing Files

### Test Directory Structure

```
tests/
├── test_calculations.c         # Test for calculation functions
├── test_input_validation.c     # Test for input functions
└── test_utils.h                # Test utilities (IO capture)
```

### Test File Organization

**Pattern:**
```c
// tests/test_calculations.c

#include "../unity/unity.h"
#include "../function_file.h"  // or "../calculations.h"

// Test functions
void test_calculate_average_typical(void) {
  // Test implementation
}

void test_calculate_average_rounding(void) {
  // Test implementation
}

// Test runner
int main(void) {
  UnityBegin(__FILE__);
  
  RUN_TEST(test_calculate_average_typical);
  RUN_TEST(test_calculate_average_rounding);
  
  UnityEnd();
  return Unity_tests_failed ? 1 : 0;
}
```

**Organization:**
1. Includes (Unity + module under test)
2. Test functions
3. Test runner main()

**See:** `project_2/tests/test_calculations.c`

## Build Files

### `Makefile`

**Purpose:** Build configuration and automation

**Location:** Project root directory

**See:** `makefile-patterns.md` for detailed Makefile documentation

## File Dependencies

### Include Chain

```
main.c
  └─ includes helper.h
       └─ declares functions from function_file.c

function_file.c
  └─ includes helper.h
       └─ declares its own functions

test_*.c
  └─ includes function_file.h (or helper.h)
       └─ declares functions to test
  └─ includes unity/unity.h
       └─ testing framework
```

### Compilation Flow

```
1. Compile function_file.c → function_file.o
2. Compile main.c → main.o
3. Link main.o + function_file.o → executable

For tests:
1. Compile test_*.c + function_file.c + unity.c → test_executable
2. Run test_executable
```

**Note:** Current projects use single-step compilation (no .o files)

## File Size Guidelines

| File | Typical Size | Max Recommended |
|------|--------------|-----------------|
| `main.c` | 30-100 lines | 200 lines |
| `function_file.c` | 200-400 lines | 600 lines |
| `helper.h` | 20-40 lines | 100 lines |
| Test files | 100-200 lines | 400 lines |

**When file gets too large:**
- Split into multiple modules (e.g., `input.c`, `calculations.c`, `converters.c`)
- Update Makefile accordingly
- Keep related functions together

## Checklist for New Files

### Creating `main.c`
- [ ] Include `helper.h`
- [ ] Implement `main()` function
- [ ] Display menu/interface
- [ ] Call functions from `function_file.c`
- [ ] Return 0 on success

### Creating `function_file.c`
- [ ] Add file-level docstring
- [ ] Include `helper.h`
- [ ] Include `<stdio.h>` and other needed headers
- [ ] Implement all declared functions
- [ ] Document each function with docstring
- [ ] Organize functions logically

### Creating `helper.h`
- [ ] Add file-level docstring
- [ ] Add header guard (`#ifndef HELPER_H`)
- [ ] Declare all functions from `function_file.c`
- [ ] Close header guard (`#endif`)
- [ ] NO implementations in header

### Creating Test File
- [ ] Include Unity framework
- [ ] Include module under test
- [ ] Write test functions (`test_*`)
- [ ] Create test runner `main()`
- [ ] Update Makefile with test target

## Common Mistakes

### ❌ Implementing Functions in Header

```c
// helper.h (WRONG)
int add(int a, int b) {
  return a + b;  // DON'T implement in header!
}
```

### ✅ Declare in Header, Implement in Source

```c
// helper.h (CORRECT)
int add(int a, int b);

// function_file.c (CORRECT)
int add(int a, int b) {
  return a + b;
}
```

### ❌ Missing Header Guard

```c
// helper.h (WRONG - no header guard)
int read_int(const char *prompt, int *value);
```

### ✅ Always Use Header Guard

```c
// helper.h (CORRECT)
#ifndef HELPER_H
#define HELPER_H

int read_int(const char *prompt, int *value);

#endif // HELPER_H
```

## See Also

- **naming-conventions.md** - File naming standards
- **boilerplate-usage.md** - Using templates for new files
- **makefile-patterns.md** - Build configuration
- **project-structure.md** - Overall project organization
