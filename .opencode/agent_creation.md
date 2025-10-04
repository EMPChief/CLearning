# Agent Creation Guide

### Core Requirements

1. **Main Agent** - Central delegator that coordinates all tasks
2. **Planner** - Planning and task list creation specialist
3. **Code Maker** - C code writing specialist
4. **Tester/Unit Tester** - Thorough testing using Unity framework
5. **Reviewer** - Code review and feedback specialist
6. **Markdown/Docstring Creator** - Documentation specialist
7. **Giter** - Git operations specialist for project completion
8. **Knowledge Holder** - Knowledge management and reference specialist

## Refined Agent Architecture

### Model Selection Strategy

**High-Performance Agents** (Claude 4.5 Sonnet Latest):

- Main Delegator Agent - Complex coordination and decision making
- Task Manager/Planner - Complex feature breakdown and planning
- Code Maker - Advanced C programming with memory management
- Reviewer - Complex code analysis and security review
- Tester - Sophisticated test design and Unity framework integration

**Cost-Effective Agents** (Claude 3.5 Haiku):

- Giter - Simple git operations and commands
- Knowledge Holder - Knowledge lookup and reference tasks

### Agent Specialization

Each agent is specifically tailored for C programming with:

1. **Memory Safety Focus** - All agents prioritize proper memory management
2. **Unity Testing Integration** - Testing framework already used in the project
3. **Compilation Awareness** - Understanding of gcc/clang and make processes
4. **Security Emphasis** - Buffer overflow prevention and secure coding practices

### Workflow Design

**Delegation Pattern**: The main agent acts as a coordinator, delegating specific tasks to specialized subagents rather than doing the work itself.

**Approval-First**: All agents propose plans before implementation to ensure user control.

**Incremental Implementation**: Tasks are broken down and completed one step at a time.

## Implementation Principles

### C Programming Standards

- snake_case for functions and variables
- UPPER_CASE for constants and macros
- kebab-case for file names
- Proper header file organization
- Memory management best practices

### Testing Strategy

- Unity framework integration
- Positive, negative, and edge case testing
- Memory leak detection
- Compilation validation

### Documentation Approach

- Clear function documentation in headers
- Markdown documentation for modules
- Usage examples and compilation instructions
- Memory management notes

### Git Workflow

- Meaningful commit messages
- Proper .gitignore for C projects
- Safe operations with approval for destructive commands
- Integration with existing project structure

## Agent Interaction Flow

1. **User Request** → Main Delegator Agent
2. **Complex Features** → Task Manager for breakdown
3. **Implementation** → Code Maker for C coding
4. **Testing** → Tester for Unity framework tests
5. **Review** → Reviewer for security and quality
6. **Documentation** → Documentation Creator for markdown/docstrings
7. **Completion** → Giter for git operations
8. **Reference** → Knowledge Holder for patterns and best practices

## Success Criteria

The agent system successfully:

- Maintains C programming focus throughout all operations
- Integrates with existing Unity testing framework
- Provides proper memory management guidance
- Ensures compilation and build validation
- Delivers comprehensive documentation
- Manages git operations safely
- Maintains knowledge base for future reference

This architecture provides a comprehensive C development environment with specialized agents handling each aspect of the development lifecycle while maintaining cost efficiency through appropriate model selection.
