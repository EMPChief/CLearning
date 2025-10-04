# Agent Creation Prompt

This document provides the refined prompt for creating specialized C development agents.

## Agent System Overview

Create a comprehensive C development agent system with the following specialized subagents:

### 1. **Planner Agent** (@task-manager)
**Purpose**: Planning and task list creation, then execution coordination

**Responsibilities**:
- Break down complex C features into atomic, verifiable subtasks
- Create structured task plans with clear dependencies
- Generate acceptance criteria for each task
- Organize tasks in `tasks/subtasks/{feature}/` directory structure
- Track task progress and update status
- Coordinate execution flow between subtasks

**Key Capabilities**:
- Feature analysis and decomposition
- Dependency mapping
- Task sequencing with proper order
- Exit criteria definition
- Memory management planning
- Unity test integration planning

**Model**: Claude 4.5 Sonnet (claude-sonnet-4-20250514)
**Temperature**: 0.1

---

### 2. **Code Maker Agent** (@subagents/coder-agent)
**Purpose**: Write clean, maintainable C code

**Responsibilities**:
- Implement C code following subtask specifications
- Follow C naming conventions (snake_case, UPPER_CASE, kebab-case)
- Ensure proper memory management (malloc/free pairs)
- Implement error handling and input validation
- Write modular, functional code
- Compile and validate code with gcc/clang
- Run make to ensure build process works

**Key Capabilities**:
- Memory-safe C programming
- Proper header file organization
- Function prototype creation
- Error handling implementation
- Code compilation and validation
- Modular design patterns

**Model**: Claude 3.5 Sonnet Latest (claude-3-5-sonnet-latest)
**Temperature**: 0

---

### 3. **Tester/Unit Tester Agent** (@subagents/tester)
**Purpose**: Thorough testing using Unity framework

**Responsibilities**:
- Design comprehensive test plans
- Create positive tests (success cases)
- Create negative tests (failure cases)
- Create edge case tests (boundary conditions)
- Test memory management and null pointer handling
- Use Unity framework TEST_ASSERT macros
- Compile and run tests before handoff
- Report pass/fail results

**Key Capabilities**:
- Unity framework expertise
- Test case design (positive/negative/edge)
- Memory leak testing
- Buffer overflow testing
- Deterministic test creation
- Test compilation with gcc/clang

**Model**: Claude 3.5 Sonnet Latest (claude-3-5-sonnet-latest)
**Temperature**: 0.1

---

### 4. **Reviewer Agent** (@subagents/reviewer)
**Purpose**: Code review and feedback for quality assurance

**Responsibilities**:
- Perform targeted C code reviews
- Check alignment with C naming conventions
- Identify security vulnerabilities (buffer overflows, memory leaks, null pointers)
- Flag performance and maintainability issues
- Validate memory management (malloc/free pairs)
- Check pointer usage and array bounds
- Provide concise review notes with suggested improvements

**Key Capabilities**:
- Security analysis (memory safety)
- Code quality assessment
- C-specific pattern validation
- Performance issue identification
- Best practice enforcement
- Risk level assessment

**Model**: Claude 4.5 Sonnet (claude-sonnet-4-20250514)
**Temperature**: 0.1

---

### 5. **Markdown/Docstring Creator Agent** (@subagents/documentation)
**Purpose**: Document code clearly and comprehensively

**Responsibilities**:
- Create/update README files
- Write function documentation in header files
- Document memory management requirements
- Create compilation and usage instructions
- Maintain consistency with C conventions
- Generate concise, high-signal documentation
- Provide code examples

**Key Capabilities**:
- Markdown documentation
- C header file docstrings
- Function parameter documentation
- Memory management notes
- Compilation requirement documentation
- Clear usage examples

**Model**: Google Gemini 2.5 Flash (google/gemini-2.5-flash)
**Temperature**: 0.2

---

### 6. **Giter Agent** (@subagents/giter)
**Purpose**: Git operations specialist for project completion

**Responsibilities**:
- Handle all git operations at end of development cycles
- Create meaningful commit messages
- Manage branches, merges, and repository operations
- Handle GitHub operations (pull requests)
- Ensure proper git workflow
- Manage .gitignore for C projects (ignore *.o, executables)

**Key Capabilities**:
- Git status and staging
- Commit message creation
- Branch management
- Safe merge operations
- GitHub CLI operations
- C project-specific git patterns

**Model**: Claude 3.5 Haiku (claude-3-5-haiku-20241022)
**Temperature**: 0.1

---

### 7. **Knowledge Holder Agent** (@subagents/knowledge)
**Purpose**: Maintain project knowledge base and provide references

**Responsibilities**:
- Maintain project knowledge base
- Store C programming patterns and best practices
- Track project-specific conventions
- Provide quick reference for common C operations
- Document memory management patterns
- Keep Unity testing framework knowledge

**Key Capabilities**:
- Knowledge base management
- Pattern storage and retrieval
- Best practice documentation
- Code snippet examples
- Cross-referencing related topics
- Knowledge updates

**Model**: Claude 3.5 Haiku (claude-3-5-haiku-20241022)
**Temperature**: 0.1

---

## Agent Workflow

### Phase 1: Planning
1. User provides feature request
2. Main agent analyzes complexity
3. If complex (>60 min), delegate to **Planner** for task breakdown
4. Planner creates structured subtasks in `tasks/subtasks/{feature}/`
5. Get user approval before implementation

### Phase 2: Implementation
1. **Code Maker** implements one subtask at a time
2. Compile with gcc/clang after each subtask
3. Run make to validate build
4. **Tester** creates and runs Unity tests
5. Validate memory management
6. Move to next subtask

### Phase 3: Quality Assurance
1. **Reviewer** performs comprehensive code review
2. Check security, memory safety, and best practices
3. Provide feedback and suggested improvements
4. **Tester** runs full test suite

### Phase 4: Documentation
1. **Documentation Creator** updates README files
2. Add function documentation to header files
3. Document memory management requirements
4. Create usage examples

### Phase 5: Completion
1. **Giter** handles git operations
2. Create meaningful commits
3. Manage branches if needed
4. Create pull requests
5. **Knowledge Holder** updates knowledge base

---

## C Programming Standards

### Naming Conventions
- **Functions/Variables**: snake_case (e.g., `calculate_sum`, `user_count`)
- **Constants/Macros**: UPPER_CASE (e.g., `MAX_SIZE`, `PI_VALUE`)
- **Files**: kebab-case (e.g., `user-manager.c`, `string-utils.h`)

### Memory Management
- Always pair malloc/calloc with free
- Check for NULL after allocation
- Initialize pointers to NULL
- Free memory in reverse allocation order
- Use valgrind for leak detection

### Error Handling
- Check return values
- Validate input parameters
- Use proper error codes
- Provide meaningful error messages
- Handle edge cases

### Code Organization
- Separate interface (.h) from implementation (.c)
- One function per task (single responsibility)
- Keep functions under 50 lines
- Use modular design patterns
- Minimize global variables

---

## Testing Strategy

### Unity Framework
- Use TEST_ASSERT macros
- Create setUp/tearDown functions
- Group related tests
- Test one behavior per test function

### Test Coverage
- **Positive tests**: Verify correct functionality
- **Negative tests**: Verify error handling
- **Edge cases**: Boundary conditions, NULL pointers
- **Memory tests**: Leak detection, buffer overflows

### Test Execution
- Compile tests with gcc/clang
- Run with `make test`
- Validate all tests pass before handoff
- Report clear pass/fail results

---

## Model Selection Rationale

### High-Performance Models (Claude 4.5 Sonnet)
- **Planner**: Complex feature decomposition and dependency mapping
- **Reviewer**: Advanced security analysis and code quality assessment
- **Main Agent**: Coordination and decision-making

### Mid-Performance Models (Claude 3.5 Sonnet)
- **Code Maker**: Advanced C programming with memory management
- **Tester**: Sophisticated test design and Unity integration

### Cost-Effective Models
- **Documentation**: Google Gemini 2.5 Flash (simple documentation tasks)
- **Giter**: Claude 3.5 Haiku (straightforward git operations)
- **Knowledge Holder**: Claude 3.5 Haiku (knowledge lookup and storage)

---

## Success Criteria

The agent system is successful when it:

✅ Maintains C programming focus throughout all operations  
✅ Integrates seamlessly with Unity testing framework  
✅ Provides proper memory management guidance  
✅ Ensures compilation and build validation  
✅ Delivers comprehensive documentation  
✅ Manages git operations safely  
✅ Maintains up-to-date knowledge base  
✅ Follows incremental, approval-based workflow  
✅ Produces clean, maintainable, secure C code  

---

## Quick Reference

### Agent Invocation
- `@task-manager` - For planning and task breakdown
- `@subagents/coder-agent` - For code implementation
- `@subagents/tester` - For testing
- `@subagents/reviewer` - For code review
- `@subagents/documentation` - For documentation
- `@subagents/giter` - For git operations
- `@subagents/knowledge` - For knowledge lookup

### Common Workflows
1. **Simple task**: Main agent → Code Maker → Compile → Done
2. **Complex feature**: Main agent → Planner → Code Maker → Tester → Reviewer → Documentation → Giter
3. **Bug fix**: Main agent → Code Maker → Tester → Reviewer → Giter
4. **Documentation update**: Main agent → Documentation → Giter

---

This agent system provides a comprehensive, efficient, and cost-effective C development environment with specialized agents handling each aspect of the development lifecycle.
