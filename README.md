# C Learning Projects

A collection of C programming projects with robust input validation, clean code style, and a standardized boilerplate for quick project setup. All projects follow C11 standards with comprehensive error handling.

## Project Structure

```
CLearning/
├── boilerplate/          # Template files for new projects
│   ├── Makefile         # Standard Makefile configuration
│   ├── main.c           # Main program file with menu system
│   ├── function_file.c  # Implementation with input validation helpers
│   └── helper.h         # Header file with function declarations
├── project_1/           # Mathematical calculations with robust I/O
│   ├── tests/           # Unit tests using Unity framework
│   └── unity/           # Unity testing framework
├── project_2/           # Menu-driven calculator (arithmetic, salary, time)
├── project_3/           # Modular programming demonstration
├── newproject.sh        # Script to create new projects from boilerplate
├── Makefile            # Root Makefile for building all projects
├── AGENTS.md           # Code style guidelines and build commands
└── README.md           # This file
```

## Quick Start

### Creating a New Project

To create a new C project with the boilerplate files:

```bash
./newproject.sh project_name
# or use the root Makefile:
make new NAME=project_name
```

This creates a new directory with all necessary files copied from the boilerplate, including robust input validation helpers.

### Building and Running

Each project includes a Makefile with the following targets:

```bash
make          # Build the project
make run      # Build and run the program
make clean    # Remove built files
make debug    # Build with debug symbols (-g flag)
make all      # Build all projects (from root directory)
```

### Running with Input

To pass input to your program:

```bash
INPUT="your input here" make run
```

## Code Style Guidelines

All projects follow consistent C11 coding standards:

### Naming Conventions
- **Functions/Variables**: `snake_case` (e.g., `calculate_sum`, `user_input`)
- **Constants/Macros**: `UPPER_CASE` (e.g., `#define PI 3.141592653589793`)
- **Files**: `snake_case.c/.h` (e.g., `function_file.c`, `helper.h`)

### Code Organization
- **Headers**: Use include guards (`#ifndef HEADER_H`, `#define HEADER_H`, `#endif`)
- **Functions**: Declare `void` parameter explicitly: `int main(void)`
- **Spacing**: 2-space indentation, space after keywords (`if (condition)`)
- **Variables**: Declare at function start, use descriptive names
- **Documentation**: Essential docstrings for helper functions, minimal inline comments

### Input Validation
All projects include robust input validation helpers:

```c
int read_int(const char *prompt, int *value);        // Read validated integer
int read_float(const char *prompt, float *value);    // Read validated float  
int read_double(const char *prompt, double *value);  // Read validated double
int read_three_ints(const char *prompt, int *a, int *b, int *c); // Read three integers
```

These functions:
- ✅ Validate scanf return values
- ✅ Clear input buffer on errors
- ✅ Provide clear error messages
- ✅ Prevent undefined behavior from malformed input

## Project Details

### Project 1: Mathematical Calculations
- **Features**: Circle area, cylinder volume, distance calculations, temperature conversion
- **Testing**: Includes Unity framework for unit testing
- **Run tests**: `make -C project_1/tests`

### Project 2: Menu-Driven Calculator  
- **Features**: Arithmetic sequence sum, salary calculator, driving time calculator
- **Validation**: All user inputs validated with descriptive error messages

### Project 3: Modular Programming Demo
- **Features**: Demonstrates clean modular programming structure
- **Purpose**: Educational example of proper C project organization

## Makefile Features

- **No object files**: Compiles directly to executable without intermediate .o files
- **Automatic naming**: Executable name matches the directory name  
- **Standard flags**: Uses `-std=c11 -Wall -Wextra -O2` for compilation
- **Clean builds**: `make clean` removes only the necessary files
- **Parallel builds**: `make all` builds all projects efficiently

## Best Practices Implemented

- ✅ **Input Validation**: All scanf calls properly validated
- ✅ **Error Handling**: Clear error messages and graceful failure handling  
- ✅ **Memory Safety**: No buffer overflows or undefined behavior
- ✅ **Code Style**: Consistent naming, spacing, and organization
- ✅ **Documentation**: Essential function documentation without noise
- ✅ **Modularity**: Clean separation of concerns across files
- ✅ **Standards Compliance**: Full C11 compatibility with strict compiler flags

## File Organization

- `main.c` - Entry point with menu system and user interaction
- `function_file.c` - Implementation of functions with input validation helpers  
- `helper.h` - Function declarations and includes with proper guards
- `Makefile` - Build configuration with standard targets