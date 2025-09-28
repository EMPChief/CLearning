# C Learning Projects

A collection of C programming projects with a standardized boilerplate for quick project setup.

## Project Structure

```
CLearning/
├── boilerplate/          # Template files for new projects
│   ├── Makefile         # Standard Makefile configuration
│   ├── main.c           # Main program file
│   ├── function_file.c  # Implementation file
│   └── helper.h         # Header file
├── project_1/           # Sample project 1
├── project_2/           # Sample project 2
├── newproject.sh        # Script to create new projects
└── README.md           # This file
```

## Quick Start

### Creating a New Project

To create a new C project with the boilerplate files:

```bash
./newproject.sh project_name
```

This will create a new directory with all the necessary files copied from the boilerplate.

### Building and Running

Each project includes a Makefile with the following targets:

```bash
make          # Build the project
make run      # Build and run the program
make clean    # Remove built files
make debug    # Build with debug symbols
```

### Running with Input

To pass input to your program:

```bash
INPUT="your input here" make run
```

## Makefile Features

- **No object files**: Compiles directly to executable without intermediate .o files
- **Automatic naming**: Executable name matches the directory name
- **Standard flags**: Uses `-std=c11 -Wall -Wextra -O2` for compilation
- **Clean builds**: `make clean` removes only the necessary files

## Project Organization

- `main.c` - Entry point of your program
- `function_file.c` - Implementation of your functions
- `helper.h` - Function declarations and includes
- `Makefile` - Build configuration