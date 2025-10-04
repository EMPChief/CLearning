# C Learning Projects - System Instructions

## Project Overview
Multi-project C learning repository with Unity test framework integration.

## Build Commands
- `make` - Build current project
- `make -C project_name` - Build specific project
- `make all` - Build all projects from root
- `make run` - Build and run (use `INPUT="data" make run` for input)
- `make clean` - Remove executables

## Test Commands
- `make -C project_1 test` - Run all tests in project_1
- `./project_1/tests/test_calculations_io` - Run single test executable
- Tests use Unity framework (unity/ directory)

## Code Style
- **Standard**: C11 with `-Wall -Wextra -O2`
- **Naming**: `snake_case` functions/vars, `UPPER_CASE` constants
- **Headers**: Include guards required
- **Structure**: main.c (entry), function_file.c (impl), helper.h (decl)
- **No comments** unless requested
- **Error handling**: Always check scanf return values

## File Organization
Each project follows boilerplate/ template structure. Use `make new NAME=project_x` to create new projects.
