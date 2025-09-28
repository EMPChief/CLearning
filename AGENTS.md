# AGENTS.md - C Learning Projects

## Build Commands
- `make` - Build current project
- `make -C project_name` - Build specific project  
- `make all` - Build all projects from root
- `make run` - Build and run (use `INPUT="data" make run` for input)
- `make debug` - Build with debug symbols (-g flag)
- `make clean` - Remove executables and artifacts
- `make new NAME=project_x` - Create new project from boilerplate

## Code Style Guidelines
- **Standard**: C11 with `-Wall -Wextra -O2` compiler flags
- **Naming**: `snake_case` for functions/variables, `UPPER_CASE` for constants/macros
- **Headers**: Use include guards (`#ifndef HEADER_H`, `#define HEADER_H`, `#endif`)
- **Functions**: Declare `void` parameter explicitly: `int main(void)`
- **Spacing**: 2-space indentation, space after keywords (`if (condition)`)
- **Organization**: `main.c` (entry), `function_file.c` (implementation), `helper.h` (declarations)
- **Constants**: Define at top of file (`#define PI 3.141592653589793`)
- **Variables**: Declare at function start, use descriptive names
- **Error handling**: Check scanf return values, validate user input
- **Output**: Use descriptive prompts and formatted output (%.2f for floats)