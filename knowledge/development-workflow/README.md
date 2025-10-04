# Development Workflow Knowledge Base

This directory contains documentation about development processes, workflows, and procedures for CLearning projects.

## Contents

- **agent-delegation.md** - Agent delegation workflow and responsibilities
- **testing-workflow.md** - Testing procedures and test-driven development
- **code-review-checklist.md** - Code review standards and quality checks
- **git-workflow.md** - Git workflow, branching, and commit standards

## Quick Reference

### Agent Delegation

**Main Delegator:** Plans and coordinates, does NOT implement  
**Specialized Agents:** Implement features, write code, create tests  
**General Agent:** Executes tests, reviews code, handles git operations

See: `agent-delegation.md`

### Testing Workflow

1. Write test first (TDD approach)
2. Implement function to pass test
3. Run `make test` to verify
4. Refactor if needed

See: `testing-workflow.md`

### Code Review

Before completing a feature:
- [ ] Code compiles without warnings
- [ ] All tests pass
- [ ] Functions documented
- [ ] Naming conventions followed
- [ ] Input validation present
- [ ] No magic numbers

See: `code-review-checklist.md`

### Git Workflow

**Commit Standards:**
- Use descriptive messages
- One logical change per commit
- Reference issue/feature if applicable

See: `git-workflow.md`

## Development Process Overview

### 1. Planning Phase (Main Delegator)

- Analyze requirements
- Break down into tasks
- Create implementation plan
- Get user approval

### 2. Implementation Phase (Specialized Agents)

- @subagents/coder-agent: Write code
- @subagents/documentation: Add docstrings
- @subagents/coder-agent: Create tests

### 3. Verification Phase (General Agent)

- Run all tests
- Perform code review
- Check documentation
- Verify build

### 4. Completion Phase

- Final review
- Commit changes (if requested)
- Update documentation

See individual documents for detailed workflows.
