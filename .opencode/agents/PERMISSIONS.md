# Agent Permissions & Models Summary

This document outlines the specific permissions and model assignments for each agent to ensure secure, efficient, and cost-effective operations.

## Model Assignments

### Claude Sonnet 4.5
- **main**: Complex orchestration and decision-making
- **plan**: Strategic planning and design decisions

### Claude Sonnet 3.5
- **execute**: Code implementation and pattern matching
- **review**: Code analysis and standards checking
- **testing**: Test writing and edge case identification

### Claude Haiku 3.5
- **docs**: Documentation and markdown writing
- **manage**: File operations and simple organization
- **git**: Git commands and commit messages

## Permission Levels

### Main Agent (Sonnet 4.5)
- **Read**: All files, full repository access
- **Write**: Delegation only (no direct writes)
- **Execute**: Minimal bash for analysis
- **Purpose**: Coordination and delegation
- **Why Sonnet 4.5**: Complex multi-step coordination and strategic decisions

### Plan Agent (Sonnet 4.5)
- **Read**: Files, directories, code search (glob/grep)
- **Write**: Todo lists only (TodoWrite/TodoRead)
- **Execute**: None
- **Purpose**: Research and planning without modification
- **Why Sonnet 4.5**: Strategic planning and architectural decisions

### Execute Agent (Sonnet 3.5)
- **Read**: All files, directories, code search
- **Write**: Code files (.c, .h), test files
- **Execute**: Bash (make, compilation - no git, no rm)
- **Purpose**: Implementation and compilation
- **Why Sonnet 3.5**: Good at pattern matching and following conventions

### Review Agent (Sonnet 3.5)
- **Read**: All files, directories, code search
- **Write**: None (read-only)
- **Execute**: Bash (make, test execution - validation only)
- **Purpose**: Quality assurance without modification
- **Why Sonnet 3.5**: Thorough code analysis and standards checking

### Testing Agent (Sonnet 3.5)
- **Read**: All files, directories, code search
- **Write**: Test files only (tests/*.c, tests/*.h)
- **Execute**: Bash (gcc, make test, test execution)
- **Purpose**: Test creation and execution
- **Why Sonnet 3.5**: Good at edge case identification and test design

### Documentation Agent (Haiku 3.5)
- **Read**: All files, directories, code search
- **Write**: Markdown files (.md) and code docstrings only
- **Execute**: None
- **Purpose**: Documentation without affecting logic
- **Why Haiku 3.5**: Fast and cost-effective for simple documentation tasks

### Manage Agent (Haiku 3.5)
- **Read**: All files, directories
- **Write**: Project structure (Makefiles, boilerplate)
- **Execute**: Bash (mkdir, mv, cp, rm, make new/clean)
- **Purpose**: File system organization
- **Why Haiku 3.5**: Simple file operations don't need advanced reasoning

### Git Agent (Haiku 3.5)
- **Read**: All files, git status/log/diff
- **Write**: None (only git operations)
- **Execute**: Bash (git commands only - no file modification)
- **Purpose**: Version control without code changes
- **Why Haiku 3.5**: Git operations are straightforward and well-defined

## Security Rules

1. **Separation of Concerns**: Each agent only accesses what it needs
2. **No Privilege Escalation**: Agents cannot exceed their permissions
3. **Read-Only When Possible**: Review agent cannot modify code
4. **Limited Execution**: Only necessary bash commands per agent
5. **Git Safety**: Only git agent can commit; only when user requests
6. **Documentation Isolation**: Docs agent cannot affect code logic
7. **Test Isolation**: Testing agent only writes to tests/ directory

## Enforcement

The main agent is responsible for:
- Routing requests to appropriate agents
- Ensuring agents stay within permission boundaries
- Preventing unauthorized operations
- Coordinating multi-agent workflows safely
