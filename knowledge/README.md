# CLearning Knowledge Base

Comprehensive documentation for C programming patterns, project conventions, and development workflows.

## 📚 Knowledge Base Structure

### 1. C Programming (`c-programming/`)

Fundamental C programming patterns and best practices:

- **input-validation.md** - Robust input validation with `read_int()`, `read_float()`, `read_double()`
- **error-handling.md** - Error handling patterns and best practices
- **memory-safety.md** - Memory safety, type safety, and common pitfalls
- **testing-patterns.md** - Unity framework testing patterns and examples
- **calculation-utilities.md** - Common calculation, conversion, and math utilities
- **docstring-standards.md** - Doxygen-style documentation standards

### 2. Project-Specific (`project-specific/`)

CLearning project conventions and standards:

- **naming-conventions.md** - Variable, function, file naming standards (snake_case, etc.)
- **file-organization.md** - Standard three-file structure (main.c, function_file.c, helper.h)
- **boilerplate-usage.md** - Using the project template with newproject.sh
- **makefile-patterns.md** - Makefile structure, targets, and build patterns
- **project-structure.md** - Overall repository organization and directory layout

### 3. Development Workflow (`development-workflow/`)

Development processes and procedures:

- **agent-delegation.md** - Agent roles, responsibilities, and delegation workflow
- **testing-workflow.md** - Test-driven development (TDD) and testing procedures
- **code-review-checklist.md** - Comprehensive code quality checklist
- **git-workflow.md** - Git workflow, commit standards, and version control

## 🚀 Quick Start

### For New C Programmers

1. Start with **c-programming/input-validation.md** - Learn the standard input patterns
2. Read **c-programming/error-handling.md** - Understand error handling
3. Review **c-programming/docstring-standards.md** - Learn documentation format
4. Check **project-specific/naming-conventions.md** - Naming standards

### For Creating New Projects

1. Read **project-specific/boilerplate-usage.md** - Create project with `./newproject.sh`
2. Check **project-specific/file-organization.md** - Understand file structure
3. Review **project-specific/makefile-patterns.md** - Learn build commands

### For Testing

1. Read **c-programming/testing-patterns.md** - Unity framework basics
2. Check **development-workflow/testing-workflow.md** - TDD workflow
3. Run `make test` frequently during development

### For Code Review

1. Use **development-workflow/code-review-checklist.md** before committing
2. Check **development-workflow/git-workflow.md** for commit standards

## 📖 Common References

### Input Validation Functions

All projects include these standard validated input functions:

```c
int read_int(const char *prompt, int *value);      // Integer input
int read_float(const char *prompt, float *value);  // Float input
int read_double(const char *prompt, double *value); // Double input
int read_three_ints(const char *prompt, int *val1, int *val2, int *val3);
```

**Returns:** 1 on success, 0 on failure  
**Details:** See `c-programming/input-validation.md`

### Standard Project Structure

```
project_name/
├── main.c              # Entry point
├── function_file.c     # Implementations
├── helper.h            # Declarations
├── Makefile            # Build config
├── tests/              # Unit tests
└── unity/              # Test framework
```

**Details:** See `project-specific/file-organization.md`

### Common Make Targets

```bash
make          # Build project
make run      # Execute program
make test     # Run all tests
make clean    # Remove build artifacts
make debug    # Build with debug symbols
```

**Details:** See `project-specific/makefile-patterns.md`

## 🔍 Finding Information

### By Topic

| Topic | Location |
|-------|----------|
| Input validation | `c-programming/input-validation.md` |
| Naming conventions | `project-specific/naming-conventions.md` |
| Testing | `c-programming/testing-patterns.md` or `development-workflow/testing-workflow.md` |
| Makefile | `project-specific/makefile-patterns.md` |
| Documentation | `c-programming/docstring-standards.md` |
| Error handling | `c-programming/error-handling.md` |
| Code review | `development-workflow/code-review-checklist.md` |
| Git workflow | `development-workflow/git-workflow.md` |

### By Question

| Question | Answer Location |
|----------|-----------------|
| How do I create a new project? | `project-specific/boilerplate-usage.md` |
| How do I validate user input? | `c-programming/input-validation.md` |
| How do I write tests? | `c-programming/testing-patterns.md` |
| What naming conventions should I use? | `project-specific/naming-conventions.md` |
| How do I document my code? | `c-programming/docstring-standards.md` |
| What should I check before committing? | `development-workflow/code-review-checklist.md` |

## 📝 Documentation Standards

All documentation in this knowledge base follows these principles:

- **Actionable** - Provides clear examples and instructions
- **Cross-referenced** - Links to related documentation
- **Example-driven** - Shows real code from CLearning projects
- **Comprehensive** - Covers both basics and advanced topics
- **Maintained** - Updated as project evolves

## 🎯 Quick Checklists

### Before Starting Development

- [ ] Read relevant C programming patterns
- [ ] Understand naming conventions
- [ ] Know how to validate input
- [ ] Understand testing requirements

### Before Committing

- [ ] Code compiles without warnings (`make`)
- [ ] All tests pass (`make test`)
- [ ] Functions documented
- [ ] Code reviewed against checklist
- [ ] Meaningful commit message

### Before Completing Feature

- [ ] Implementation complete
- [ ] Tests written and passing
- [ ] Documentation added
- [ ] Code reviewed
- [ ] All files properly organized

## 🔗 External Resources

- Unity Testing Framework: https://github.com/ThrowTheSwitch/Unity
- C11 Standard Reference: https://en.cppreference.com/w/c
- Git Documentation: https://git-scm.com/doc
- GNU Make Manual: https://www.gnu.org/software/make/manual/

## 📞 Knowledge Base Maintenance

This knowledge base is maintained to provide quick reference for C development tasks. It is:

- Updated as new patterns emerge
- Expanded with new topics as needed
- Kept synchronized with actual project code
- Cross-referenced for easy navigation

For questions or suggestions about the knowledge base, refer to specific documentation files or review code examples in existing projects.