# Boilerplate Template Usage

## Overview

CLearning includes a boilerplate template for quickly setting up new projects with standard structure and input validation utilities.

## Boilerplate Location

```
/mnt/data/Project/CLearning/boilerplate/
├── main.c              # Template main file
├── function_file.c     # Template with input utilities
├── helper.h            # Template header
└── Makefile            # Template build configuration
```

## Using the Boilerplate

### Automated Script (Recommended)

**Script:** `/mnt/data/Project/CLearning/newproject.sh`

**Usage:**
```bash
./newproject.sh project_name
```

**What it does:**
1. Creates `/mnt/data/Project/CLearning/project_name/`
2. Copies all boilerplate files to new directory
3. Ready to start coding immediately

**Example:**
```bash
./newproject.sh project_3

# Output:
# Created new project 'project_3' with boilerplate files.
# Project location: /mnt/data/Project/CLearning/project_3
```

**Script Contents:** `newproject.sh:1-30`

```bash
#!/bin/bash

# Check if a project name was provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <project_name>"
    exit 1
fi

PROJECT_NAME="$1"
BOILERPLATE_DIR="/mnt/data/Project/CLearning/boilerplate"
PROJECT_DIR="/mnt/data/Project/CLearning/$PROJECT_NAME"

# Check if project already exists
if [ -d "$PROJECT_DIR" ]; then
    echo "Error: Project '$PROJECT_NAME' already exists."
    exit 1
fi

# Create project directory
mkdir -p "$PROJECT_DIR"

# Copy files from boilerplate
cp "$BOILERPLATE_DIR/Makefile" "$PROJECT_DIR/"
cp "$BOILERPLATE_DIR"/*.c "$PROJECT_DIR/" 2>/dev/null || true
cp "$BOILERPLATE_DIR"/*.h "$PROJECT_DIR/" 2>/dev/null || true

echo "Created new project '$PROJECT_NAME' with boilerplate files."
echo "Project location: $PROJECT_DIR"
```

### Manual Copy

If script is unavailable:

```bash
# Create project directory
mkdir project_name

# Copy boilerplate files
cp boilerplate/main.c project_name/
cp boilerplate/function_file.c project_name/
cp boilerplate/helper.h project_name/
cp boilerplate/Makefile project_name/

cd project_name
```

## Boilerplate Contents

### `main.c` Template

**Purpose:** Minimal main file to get started

**Contents:**
```c
#include <stdio.h>
#include "helper.h"

int main(void) {
  explain_modular_programming();
  return 0;
}
```

**Customization:**
- Add menu system
- Call your new functions
- Handle user input/output

### `function_file.c` Template

**Purpose:** Pre-loaded with input validation utilities

**Contents:** `boilerplate/function_file.c:1-131`

**Includes:**
- File-level docstring template
- `read_int()` - Integer input with validation
- `read_float()` - Float input with validation
- `read_double()` - Double input with validation
- `read_three_ints()` - Multiple integer input
- `explain_modular_programming()` - Example function

**Customization:**
- Keep input validation functions
- Add your own functions below
- Update file-level docstring

### `helper.h` Template

**Purpose:** Function declarations template

**Contents:** `boilerplate/helper.h:1-21`

```c
/**
 * @file helper.h
 * @brief Template header file for function declarations
 *
 * Add your function declarations below the input validation functions.
 * Includes common input validation utilities for integers, floats, and doubles.
 */

#ifndef HELPER_H
#define HELPER_H

int read_int(const char *prompt, int *value);
int read_float(const char *prompt, float *value);
int read_double(const char *prompt, double *value);
int read_three_ints(const char *prompt, int *val1, int *val2, int *val3);

void explain_modular_programming(void);

#endif // HELPER_H
```

**Customization:**
- Add declarations for your new functions
- Keep input validation declarations
- Update file docstring

### `Makefile` Template

**Purpose:** Build configuration

**Contents:** `boilerplate/Makefile:1-27`

```makefile
CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -O2
LDFLAGS :=

TARGET := main
SRC := main.c function_file.c
DEPS := helper.h

.PHONY: all clean run debug

all: $(TARGET)

$(TARGET): $(SRC) $(DEPS)
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)

run: $(TARGET)
	@if [ -n "$$INPUT" ]; then printf "%s" "$$INPUT" | ./$(TARGET); else ./$(TARGET); fi

clean:
	$(RM) $(TARGET)

debug: CFLAGS := -std=c11 -Wall -Wextra -g
debug: clean $(TARGET)
```

**Customization:**
- Add source files to `SRC` variable
- Add test targets (see `makefile-patterns.md`)
- Adjust compiler flags if needed

## After Creating Project

### 1. Navigate to Project

```bash
cd project_name
```

### 2. Verify Structure

```bash
ls -la

# Should show:
# main.c
# function_file.c
# helper.h
# Makefile
```

### 3. Test Build

```bash
make

# Should compile successfully
# Creates 'main' executable
```

### 4. Test Run

```bash
make run

# Should run and display:
# "This program demonstrates modular programming in C..."
```

### 5. Start Development

1. **Edit `function_file.c`:**
   - Update file docstring
   - Add your functions after input validation utilities
   - Keep `read_*` functions for input validation

2. **Edit `helper.h`:**
   - Update file docstring
   - Add declarations for your new functions
   - Keep `read_*` declarations

3. **Edit `main.c`:**
   - Replace placeholder code
   - Add menu/interface
   - Call your functions

4. **Build and test:**
   ```bash
   make clean
   make
   make run
   ```

## Workflow Example

**Goal:** Create a calculator project

### Step 1: Create Project

```bash
./newproject.sh calculator
cd calculator
```

### Step 2: Add Function to `function_file.c`

```c
// Add after existing functions

/**
 * Calculate sum of two integers.
 *
 * Prompts for two integers, validates input, and prints sum.
 */
void add_two_numbers(void) {
  int num1, num2;
  
  if (!read_int("Enter first number: ", &num1)) return;
  if (!read_int("Enter second number: ", &num2)) return;
  
  printf("Sum: %d\n", num1 + num2);
}
```

### Step 3: Declare in `helper.h`

```c
// Add before #endif

void add_two_numbers(void);
```

### Step 4: Call from `main.c`

```c
#include <stdio.h>
#include "helper.h"

int main(void) {
  printf("Simple Calculator\n");
  printf("1. Add two numbers\n");
  printf("Enter choice: ");
  
  int choice;
  scanf("%d", &choice);
  
  if (choice == 1) {
    add_two_numbers();
  }
  
  return 0;
}
```

### Step 5: Build and Run

```bash
make clean && make && make run
```

## Included Utilities

### Input Validation Functions

**Always available in boilerplate:**

| Function | Type | Returns | Usage |
|----------|------|---------|-------|
| `read_int()` | int | 1/0 | Validated integer input |
| `read_float()` | float | 1/0 | Validated float input |
| `read_double()` | double | 1/0 | Validated double input |
| `read_three_ints()` | int×3 | 1/0 | Three space-separated integers |

**Pattern:**
```c
int value;
if (!read_int("Enter value: ", &value)) {
  return;  // Handle error
}
// Use value safely
```

See `c-programming/input-validation.md` for detailed documentation

## Adding Testing

Boilerplate doesn't include testing setup. To add:

### 1. Copy Unity Framework

```bash
mkdir unity
cp /path/to/unity/unity.c unity/
cp /path/to/unity/unity.h unity/
```

### 2. Create Test Directory

```bash
mkdir tests
```

### 3. Add Test Targets to Makefile

See `makefile-patterns.md` for test target examples

## Best Practices

1. **Don't Modify Boilerplate Directly**
   - Boilerplate is a template
   - Modifications won't affect new projects
   - Update boilerplate only to improve template

2. **Keep Input Validation Functions**
   - They're tested and reliable
   - Consistent across all projects
   - Delete only if truly not needed

3. **Update Documentation**
   - Change file docstrings immediately
   - Document new functions as you add them
   - Keep README updated if project has one

4. **Follow Conventions**
   - Use existing naming patterns
   - Maintain file organization
   - Follow coding style

## Common Modifications

### Adding More Source Files

If project grows, split into multiple files:

```bash
# Create new module
touch input_utils.c input_utils.h
```

**Update Makefile:**
```makefile
SRC := main.c function_file.c input_utils.c
DEPS := helper.h input_utils.h
```

### Adding Constants

```c
// In function_file.c or new constants.h
#define PI 3.141592653589793
#define MAX_BUFFER_SIZE 256
```

### Changing Executable Name

**In Makefile:**
```makefile
TARGET := calculator  # Instead of 'main'
```

## Troubleshooting

### Project Already Exists

```bash
./newproject.sh my_project
# Error: Project 'my_project' already exists.
```

**Solution:** Choose different name or remove existing project

### Script Not Executable

```bash
bash: ./newproject.sh: Permission denied
```

**Solution:**
```bash
chmod +x newproject.sh
./newproject.sh my_project
```

### Missing Files After Creation

**Solution:**
```bash
# Verify boilerplate exists
ls boilerplate/

# Try manual copy
cp boilerplate/* my_project/
```

## See Also

- **file-organization.md** - File structure standards
- **makefile-patterns.md** - Makefile configuration
- **naming-conventions.md** - Naming standards
- **c-programming/input-validation.md** - Input function documentation
