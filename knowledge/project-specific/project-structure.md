# Project Structure Standards

## Overview

This document describes the overall directory structure and organization of the CLearning repository.

## Repository Structure

```
/mnt/data/Project/CLearning/
├── boilerplate/              # Project template
│   ├── main.c
│   ├── function_file.c
│   ├── helper.h
│   └── Makefile
├── knowledge/                # Knowledge base (this documentation)
│   ├── c-programming/
│   ├── project-specific/
│   ├── development-workflow/
│   └── README.md
├── project_1/                # Individual projects
│   ├── main.c
│   ├── calculations.c
│   ├── calculations.h
│   ├── Makefile
│   ├── tests/
│   └── unity/
├── project_2/                # Individual projects
│   ├── main.c
│   ├── function_file.c
│   ├── helper.h
│   ├── Makefile
│   ├── tests/
│   └── unity/
├── Makefile                  # Root-level Makefile (optional)
├── newproject.sh             # Project creation script
└── README.md                 # Repository README
```

## Directory Purposes

### `/boilerplate/`

**Purpose:** Template for new projects

**Contents:**
- Standard three-file structure
- Pre-configured Makefile
- Input validation utilities
- Ready to copy and customize

**Usage:** See `boilerplate-usage.md`

### `/knowledge/`

**Purpose:** Centralized documentation and knowledge base

**Structure:**
```
knowledge/
├── c-programming/            # C programming patterns
│   ├── README.md
│   ├── input-validation.md
│   ├── error-handling.md
│   ├── memory-safety.md
│   ├── testing-patterns.md
│   ├── calculation-utilities.md
│   └── docstring-standards.md
├── project-specific/         # CLearning-specific conventions
│   ├── README.md
│   ├── naming-conventions.md
│   ├── file-organization.md
│   ├── boilerplate-usage.md
│   ├── makefile-patterns.md
│   └── project-structure.md  # (this file)
├── development-workflow/     # Development processes
│   ├── README.md
│   ├── agent-delegation.md
│   ├── testing-workflow.md
│   ├── code-review-checklist.md
│   └── git-workflow.md
└── README.md                 # Knowledge base index
```

### `/project_N/` - Individual Projects

**Purpose:** Self-contained learning projects

**Standard Structure:**
```
project_N/
├── main.c              # Entry point
├── function_file.c     # Implementations (or custom name)
├── helper.h            # Declarations (or custom name)
├── Makefile            # Build configuration
├── tests/              # Unit tests (optional)
│   ├── test_*.c
│   └── test_utils.h
└── unity/              # Unity framework (optional)
    ├── unity.c
    └── unity.h
```

**Naming:**
- `project_1`, `project_2`, etc. for numbered projects
- Descriptive names also acceptable (`calculator`, `converter`)

### Root-Level Files

**`newproject.sh`**
- Script to create new projects from boilerplate
- See `boilerplate-usage.md`

**`README.md`**
- Repository overview
- Getting started guide
- Project list

**`Makefile`** (optional)
- Root-level build commands
- Aggregate targets (build all projects)

## Project Directory Standards

### Minimal Project

**Suitable for:** Simple learning exercises

```
simple_project/
├── main.c
├── function_file.c
├── helper.h
└── Makefile
```

**Build:**
```bash
cd simple_project
make
./main
```

### Standard Project

**Suitable for:** Most projects

```
standard_project/
├── main.c
├── function_file.c
├── helper.h
├── Makefile
├── tests/
│   ├── test_functions.c
│   └── test_utils.h
└── unity/
    ├── unity.c
    └── unity.h
```

**Build and Test:**
```bash
cd standard_project
make
make test
```

### Advanced Project

**Suitable for:** Larger projects with multiple modules

```
advanced_project/
├── main.c
├── input/
│   ├── input_utils.c
│   └── input_utils.h
├── calculations/
│   ├── calc_basic.c
│   ├── calc_advanced.c
│   └── calculations.h
├── converters/
│   ├── temperature.c
│   ├── time.c
│   └── converters.h
├── Makefile
├── tests/
│   ├── test_input.c
│   ├── test_calculations.c
│   ├── test_converters.c
│   └── test_utils.h
└── unity/
    ├── unity.c
    └── unity.h
```

**Note:** Not currently used, but supported pattern for future

## Naming Conventions

### Project Directories

**Pattern:** `snake_case` or `project_N`

**Examples:**
- `project_1` - Numbered projects
- `project_2`
- `calculator` - Descriptive names
- `temperature_converter`

**Avoid:**
- `Project1` - Mixed case
- `my-project` - Kebab case for directories
- `myProject` - Camel case

### Source Files

**Pattern:** `snake_case.c` / `snake_case.h`

**Standard:**
- `main.c` - Entry point
- `function_file.c` - Generic implementation
- `helper.h` - Generic header

**Project-Specific:**
- `calculations.c` / `calculations.h`
- `input_utils.c` / `input_utils.h`
- `converters.c` / `converters.h`

## File Organization Within Projects

### By Function Type

**Recommended for small/medium projects:**

```c
// function_file.c organization:

// 1. File docstring
// 2. Includes
// 3. Constants/Macros
// 4. Input validation functions
// 5. Utility functions
// 6. Calculation functions
// 7. Conversion functions
// 8. Main application functions
```

**Example:** `project_2/function_file.c`

### By Module

**Recommended for larger projects:**

```
project/
├── input.c / input.h       # All input functions
├── calc.c / calc.h         # All calculations
├── convert.c / convert.h   # All conversions
└── main.c                  # Coordination
```

## Testing Structure

### Co-located Tests

**Pattern:** Tests in `tests/` subdirectory

```
project/
├── function_file.c
├── helper.h
└── tests/
    ├── test_input.c
    ├── test_calculations.c
    └── test_utils.h
```

**Benefits:**
- Clear separation
- Easy to find
- Can be excluded from builds

### Test Naming

**Pattern:** `test_<module>_<aspect>.c`

**Examples:**
- `test_calculations.c` - Tests for calculation functions
- `test_input_validation.c` - Tests for input functions
- `test_converters.c` - Tests for conversion functions

## Build Artifacts

### Generated Files

```
project/
├── main               # Executable (from main.c)
├── tests/test_input   # Test binary
├── *.o                # Object files (if using separate compilation)
└── *.d                # Dependency files (if using auto-dependencies)
```

### Gitignore Pattern

```gitignore
# Executables
main
project_*/main
*/main

# Test binaries
tests/test_*
!tests/test_*.c

# Object files
*.o

# Dependencies
*.d
```

## Cross-Project Consistency

### What Should Be Consistent

- [ ] File naming (snake_case)
- [ ] Directory structure (main.c, function_file.c, helper.h)
- [ ] Build system (Makefile with standard targets)
- [ ] Documentation style (Doxygen-style docstrings)
- [ ] Code style (naming, formatting)
- [ ] Input validation (read_* functions)

### What Can Vary

- Project directory names
- Specific function implementations
- Additional modules/files
- Custom function names
- Project-specific utilities

## Navigation Tips

### Finding Code

```bash
# Find all projects
ls -d project_*/

# Find all main files
find . -name "main.c"

# Find all Makefiles
find . -name "Makefile"

# Find test files
find . -path "*/tests/test_*.c"
```

### Building All Projects

```bash
# Using loop
for dir in project_*/; do
  cd "$dir"
  make
  cd ..
done

# Or with find
find . -name "Makefile" -execdir make \;
```

## Best Practices

### 1. Keep Projects Self-Contained

Each project should:
- Build independently
- Have its own Makefile
- Not depend on other projects
- Include all needed files

### 2. Follow Standard Structure

Unless there's a good reason:
- Use standard three-file structure
- Put tests in `tests/`
- Use Unity for testing
- Follow naming conventions

### 3. Document Deviations

If project structure differs:
- Document in project README
- Explain why it's different
- Provide build instructions

### 4. Maintain Consistency

Across projects:
- Same Makefile structure
- Same test patterns
- Same input validation
- Same documentation style

## See Also

- **file-organization.md** - Individual file structure
- **naming-conventions.md** - Naming standards
- **boilerplate-usage.md** - Creating new projects
- **makefile-patterns.md** - Build system standards
