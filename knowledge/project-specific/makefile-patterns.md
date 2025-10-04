# Makefile Patterns

## Overview

CLearning projects use Make for build automation. This document covers standard Makefile patterns and targets used across projects.

## Basic Makefile Structure

### Template Makefile

From `boilerplate/Makefile`:

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

## Variable Definitions

### Compiler Settings

```makefile
CC := gcc                          # C compiler
CFLAGS := -std=c11 -Wall -Wextra -O2  # Compiler flags
LDFLAGS :=                         # Linker flags (empty by default)
```

**Compiler Flags Explained:**
- `-std=c11` - Use C11 standard
- `-Wall` - Enable all warnings
- `-Wextra` - Enable extra warnings
- `-O2` - Optimization level 2

**Adding Math Library:**
```makefile
LDFLAGS := -lm  # Link math library
```

### Project Files

```makefile
TARGET := main                     # Executable name
SRC := main.c function_file.c     # Source files
DEPS := helper.h                   # Header dependencies
```

**Multiple Source Files:**
```makefile
SRC := main.c function_file.c input_utils.c converters.c
DEPS := helper.h input_utils.h converters.h
```

## Standard Targets

### `all` - Default Build Target

```makefile
.PHONY: all

all: $(TARGET)
```

**Usage:**
```bash
make        # Runs 'all' target by default
make all    # Explicit
```

### `$(TARGET)` - Build Executable

```makefile
$(TARGET): $(SRC) $(DEPS)
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)
```

**Explanation:**
- `$(TARGET)` depends on source files and headers
- `$(CC)` compiles with `$(CFLAGS)`
- `$@` represents the target name (`main`)
- `-o $@` sets output filename

**Rebuilds when:**
- Any source file changes
- Any header file changes

### `run` - Execute Program

```makefile
.PHONY: run

run: $(TARGET)
	@if [ -n "$$INPUT" ]; then printf "%s" "$$INPUT" | ./$(TARGET); else ./$(TARGET); fi
```

**Usage:**
```bash
# Normal run
make run

# With input
INPUT="1\n2\n" make run
```

**Explanation:**
- `@` suppresses command echo
- Checks if `INPUT` environment variable is set
- If set, pipes input to program
- Otherwise runs program normally

### `clean` - Remove Build Artifacts

```makefile
.PHONY: clean

clean:
	$(RM) $(TARGET)
```

**Usage:**
```bash
make clean
```

**Removes:**
- Executable (main)
- Any listed object files
- Test binaries (if in clean target)

**Expanded clean:**
```makefile
clean:
	$(RM) $(TARGET) *.o $(TEST_BINARIES)
```

### `debug` - Debug Build

```makefile
.PHONY: debug

debug: CFLAGS := -std=c11 -Wall -Wextra -g
debug: clean $(TARGET)
```

**Usage:**
```bash
make debug
```

**Explanation:**
- Overrides `CFLAGS` with debug flags
- `-g` includes debug symbols
- Removes `-O2` optimization
- Cleans before building

## Testing Targets

### With Unity Framework

From `project_2/Makefile`:

```makefile
UNITY_SRC := unity/unity.c
TEST_CALCULATIONS := tests/test_calculations
TEST_INPUT := tests/test_input_validation

# Build test binaries
$(TEST_CALCULATIONS): tests/test_calculations.c function_file.c $(UNITY_SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(TEST_INPUT): tests/test_input_validation.c function_file.c $(UNITY_SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Run individual test suite
.PHONY: test-calculations test-input

test-calculations: $(TEST_CALCULATIONS)
	@echo "Running calculation tests..."
	@./$(TEST_CALCULATIONS)

test-input: $(TEST_INPUT)
	@echo "Running input validation tests..."
	@./$(TEST_INPUT)

# Run all tests
.PHONY: test

test: test-calculations test-input
	@echo "All tests completed!"
```

**Usage:**
```bash
make test                # Run all tests
make test-calculations   # Run specific suite
make test-input          # Run specific suite
```

**Pattern Explanation:**
- Define test binary variables
- Create build rule for each test
  - Compiles test file + module + Unity
- Create run target for each test
  - Echoes message
  - Runs test binary
- Create master `test` target
  - Depends on all test targets

### Expanded Clean with Tests

```makefile
clean:
	$(RM) $(TARGET) *.o $(TEST_CALCULATIONS) $(TEST_INPUT)
```

## Advanced Patterns

### Separate Compilation (with .o files)

```makefile
OBJ := $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJ)
```

**Benefits:**
- Only recompile changed files
- Faster builds for large projects

**Note:** Current CLearning projects use direct compilation (simpler for small projects)

### Multiple Executables

```makefile
PROGRAMS := calculator converter timer

.PHONY: all
all: $(PROGRAMS)

calculator: calculator.c utils.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

converter: converter.c utils.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

timer: timer.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	$(RM) $(PROGRAMS)
```

### Automatic Dependency Generation

```makefile
DEPS := $(SRC:.c=.d)

-include $(DEPS)

%.d: %.c
	@$(CC) -MM $(CFLAGS) $< > $@

clean:
	$(RM) $(TARGET) $(OBJ) $(DEPS)
```

**Note:** Advanced feature, not needed for current projects

## Common Makefile Variables

| Variable | Purpose | Example |
|----------|---------|---------|
| `CC` | C compiler | `gcc`, `clang` |
| `CFLAGS` | Compiler flags | `-Wall -Wextra -O2` |
| `LDFLAGS` | Linker flags | `-lm -lpthread` |
| `TARGET` | Executable name | `main`, `calculator` |
| `SRC` | Source files | `main.c utils.c` |
| `OBJ` | Object files | `main.o utils.o` |
| `DEPS` | Header files | `utils.h config.h` |

## Automatic Variables

| Variable | Meaning | Example |
|----------|---------|---------|
| `$@` | Target name | `main` |
| `$<` | First prerequisite | `main.c` |
| `$^` | All prerequisites | `main.c utils.c` |
| `$?` | Changed prerequisites | `utils.c` |

**Example:**
```makefile
main: main.c utils.c helper.h
	$(CC) $(CFLAGS) $^ -o $@
# Expands to:
# gcc -Wall -Wextra main.c utils.c -o main
```

## PHONY Targets

```makefile
.PHONY: all clean run debug test
```

**Purpose:**
- Declares targets that don't create files
- Prevents conflicts with files named 'clean', 'test', etc.
- Always executes, never "up to date"

**Always PHONY:**
- `all`
- `clean`
- `run`
- `debug`
- `test`
- Any target that runs a command

## Makefile Best Practices

### 1. Use Tabs for Indentation

```makefile
# CORRECT
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@

# WRONG (spaces instead of tab)
$(TARGET): $(SRC)
    $(CC) $(CFLAGS) $(SRC) -o $@
```

**Note:** Make requires TAB character, not spaces

### 2. Use := for Variables

```makefile
# GOOD (immediate assignment)
CC := gcc
CFLAGS := -Wall -Wextra

# AVOID (recursive assignment)
CC = gcc
CFLAGS = -Wall -Wextra
```

### 3. Suppress Echo with @

```makefile
# Shows command before running
test:
	echo "Running tests..."
	./run_tests

# Cleaner output
test:
	@echo "Running tests..."
	@./run_tests
```

### 4. Use $(RM) for Portability

```makefile
# GOOD
clean:
	$(RM) $(TARGET)

# AVOID
clean:
	rm -f $(TARGET)
```

### 5. Declare PHONY Targets

```makefile
.PHONY: clean test run

clean:
	$(RM) $(TARGET)
```

## Common Makefile Patterns

### Help Target

```makefile
.PHONY: help

help:
	@echo "Available targets:"
	@echo "  make        - Build project"
	@echo "  make run    - Run executable"
	@echo "  make test   - Run tests"
	@echo "  make clean  - Remove build artifacts"
	@echo "  make debug  - Build with debug symbols"
```

### Install Target

```makefile
PREFIX := /usr/local
BINDIR := $(PREFIX)/bin

.PHONY: install

install: $(TARGET)
	install -d $(BINDIR)
	install -m 755 $(TARGET) $(BINDIR)
```

### Verbose Output Toggle

```makefile
ifeq ($(VERBOSE),1)
  Q :=
else
  Q := @
endif

$(TARGET): $(SRC)
	$(Q)$(CC) $(CFLAGS) $(SRC) -o $@
```

**Usage:**
```bash
make              # Quiet
make VERBOSE=1    # Shows commands
```

## Troubleshooting

### Missing Separator Error

```
Makefile:10: *** missing separator. Stop.
```

**Cause:** Spaces instead of TAB

**Fix:** Replace spaces with TAB character

### Target Up to Date

```bash
make
# make: 'main' is up to date.
```

**Cause:** No source files changed

**Fix:**
```bash
make clean && make  # Force rebuild
touch main.c && make  # Touch file to trigger rebuild
```

### Command Not Found

```
make: gcc: command not found
```

**Fix:** Install gcc or change `CC` variable

## See Also

- **file-organization.md** - Project file structure
- **boilerplate-usage.md** - Template Makefile
- **project-structure.md** - Overall organization
- **testing-patterns.md** - Test target patterns
