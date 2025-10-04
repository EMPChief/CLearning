# Knowledge Base

This directory contains the project knowledge base maintained by the Knowledge Holder Agent.

## Structure

- `c-programming/` - C programming patterns, best practices, and common solutions
- `project-specific/` - Project-specific conventions, decisions, and patterns
- `development-workflow/` - Development processes, git workflow, and procedures

## Usage

The Knowledge Holder Agent (@subagents/knowledge) maintains and updates this knowledge base to provide quick reference and guidance for C development tasks.

---

## Agent Delegation Workflow

### Main Delegator Agent Responsibilities

The main delegator agent should **ONLY**:
- ✅ Create implementation plans
- ✅ Get user approval for plans
- ✅ Delegate implementation work to specialized subagents
- ✅ Monitor progress and coordinate between subagents
- ✅ Handle critical fixes when absolutely necessary

The main delegator should **NEVER**:
- ❌ Write code directly
- ❌ Edit files directly (except critical fixes)
- ❌ Implement features themselves
- ❌ Do work that should be delegated to specialized subagents

### Proper Delegation Examples

#### ✅ CORRECT Workflow
```
Phase 1: Planning (Main Delegator)
1. Analyze requirements
2. Create detailed implementation plan
3. Get user approval

Phase 2: Implementation (Delegate to Specialists)
1. Delegate to @subagents/documentation: "Add file-level docstrings to all project_2 files"
2. Delegate to @subagents/coder-agent: "Set up Unity testing infrastructure"
3. Delegate to @subagents/coder-agent: "Create test_calculations.c with 8 tests"
4. Delegate to @subagents/coder-agent: "Update Makefile with test targets"

Phase 3: Verification (Delegate to General Agent)
1. Delegate to general agent: "Run tests and analyze results"
2. Delegate to general agent: "Perform code review"
3. Delegate to general agent: "Polish documentation"
```

#### ❌ INCORRECT Workflow
```
Phase 1: Planning (Main Delegator)
1. Analyze requirements ✅
2. Create implementation plan ✅

Phase 2: Implementation (Main Delegator - WRONG!)
1. Main delegator adds docstrings ❌
2. Main delegator sets up test infrastructure ❌
3. Main delegator creates test files ❌
4. Main delegator updates Makefile ❌
```

### Delegation Decision Matrix

| Task Type | Delegate To | Example |
|-----------|-------------|---------|
| Code implementation | @subagents/coder-agent | "Implement calculator functions" |
| Test creation | @subagents/coder-agent | "Create unit tests for validation" |
| Documentation writing | @subagents/documentation | "Add docstrings to all files" |
| Build system updates | @subagents/coder-agent | "Update Makefile with test targets" |
| Test execution | general agent | "Run tests and report results" |
| Code review | general agent | "Review code for quality issues" |
| Git operations | general agent | "Commit changes with message" |
| Planning | main delegator | "Create implementation plan" |

### Key Principle

**Separation of Concerns**: The main delegator orchestrates, specialized agents execute. This ensures:
- Clear responsibility boundaries
- Specialized expertise applied to each task
- Better tracking and accountability
- Proper workflow enforcement