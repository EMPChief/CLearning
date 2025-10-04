# OpenCode Agents for C Learning Projects

This directory contains specialized AI agents for managing C learning projects efficiently.

## Agent Structure

### Main Agent (`../main.md`)
Orchestrator that coordinates between all sub-agents. Routes user requests to appropriate specialists.

### Sub-Agents

1. **Plan Agent** (`plan.md`)
   - Creates structured task plans
   - Breaks down complex features
   - Identifies dependencies and risks

2. **Execute Agent** (`execute.md`)
   - Implements code changes
   - Follows C11 standards and project conventions
   - Ensures compilation and correctness

3. **Review Agent** (`review.md`)
   - Reviews code quality and standards
   - Checks compilation and testing
   - Validates against project checklist

4. **Testing Agent** (`testing.md`)
   - Creates unit tests using Unity framework
   - Runs tests and validates results
   - Ensures code coverage

5. **Documentation Agent** (`docs.md`)
   - Maintains markdown documentation
   - Creates code docstrings (when requested)
   - Keeps docs synchronized with code

6. **Manage Agent** (`manage.md`)
   - Handles project structure
   - Creates new projects from boilerplate
   - Manages files and Makefiles

7. **Git Agent** (`git.md`)
   - Manages version control
   - Creates meaningful commits
   - Handles branches and PRs

## Usage

Agents automatically coordinate based on user requests. The main agent delegates to specialists as needed.

## Project Standards Reference

All agents follow standards defined in `/project/AGENTS.md`:
- C11 standard with strict warnings
- snake_case naming for functions/variables
- UPPER_CASE for constants
- 2-space indentation
- Unity framework for tests
- Makefile-based builds
