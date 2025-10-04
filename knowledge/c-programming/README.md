# C Programming Knowledge Base

This directory contains C programming patterns, best practices, and common solutions used across CLearning projects.

## Contents

- **input-validation.md** - Robust input validation patterns for user input
- **error-handling.md** - Error handling best practices and patterns
- **memory-safety.md** - Memory safety guidelines and common pitfalls
- **testing-patterns.md** - Testing patterns using Unity framework
- **calculation-utilities.md** - Common calculation and conversion utilities
- **docstring-standards.md** - Documentation standards and examples

## Quick Reference

### Input Validation
Use the standard `read_*` functions for validated user input:
- `read_int()` - Integer input with validation
- `read_float()` - Float input with validation
- `read_double()` - Double input with validation
- `read_three_ints()` - Multiple integer input

See: `input-validation.md`

### Testing
Use Unity framework for unit testing. See test examples in:
- `project_1/tests/test_calculations_io.c`
- `project_2/tests/test_calculations.c`

See: `testing-patterns.md`

### Documentation
Follow Doxygen-style documentation format with:
- File-level docstrings (`@file`, `@brief`)
- Function docstrings (`@param`, `@return`, `@note`)

See: `docstring-standards.md`
