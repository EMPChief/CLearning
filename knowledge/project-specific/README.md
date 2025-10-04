# Project-Specific Knowledge Base

This directory contains CLearning project conventions, standards, and patterns specific to this codebase.

## Contents

- **naming-conventions.md** - Naming standards for variables, functions, files, and projects
- **file-organization.md** - Standard file structure and organization patterns
- **boilerplate-usage.md** - Using the boilerplate template for new projects
- **makefile-patterns.md** - Makefile structure, targets, and build patterns
- **project-structure.md** - Overall project organization and directory layout

## Quick Reference

### Naming Conventions

**Variables:** `snake_case`
```c
int grade_average;
double hourly_wage;
```

**Functions:** `snake_case`
```c
void calculate_average(void);
int read_int(const char *prompt, int *value);
```

**Constants/Macros:** `UPPER_CASE`
```c
#define PI 3.141592653589793
#define MAX_BUFFER 256
```

**Files:** `kebab-case` for projects, `snake_case` for source files
```
project-name/
├── main.c
├── function_file.c
└── helper.h
```

### Standard File Structure

```
project_name/
├── main.c              # Entry point with menu
├── function_file.c     # Function implementations
├── helper.h            # Function declarations
├── Makefile            # Build configuration
├── tests/              # Unit tests (Unity framework)
│   ├── test_*.c
│   └── test_utils.h
└── unity/              # Unity testing framework
    ├── unity.c
    └── unity.h
```

### Creating New Projects

```bash
# Using the boilerplate
./newproject.sh project_3

# Sets up:
# - project_3/main.c
# - project_3/function_file.c
# - project_3/helper.h
# - project_3/Makefile
```

### Common Make Targets

```bash
make            # Build project
make run        # Run executable
make test       # Run all tests
make clean      # Remove build artifacts
make debug      # Build with debug symbols
```

See individual documents for detailed information.
