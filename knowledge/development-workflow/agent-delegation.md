# Agent Delegation Workflow

## Overview

CLearning uses an agent-based workflow where a main delegator coordinates specialized agents to complete tasks efficiently.

## Agent Roles

### Main Delegator Agent

**Responsibilities:**
- ✅ Create implementation plans
- ✅ Get user approval for plans
- ✅ Delegate work to specialized agents
- ✅ Monitor progress and coordinate
- ✅ Handle critical fixes when necessary

**Should NEVER:**
- ❌ Write code directly
- ❌ Edit files directly (except critical fixes)
- ❌ Implement features themselves
- ❌ Do work that should be delegated

**Key Principle:** Orchestrates, does not execute

### Specialized Agents

#### @subagents/coder-agent

**Purpose:** Code implementation specialist

**Responsibilities:**
- Implement functions
- Create test files
- Update Makefiles
- Write calculation/utility code
- Set up project infrastructure

**Examples:**
- "Implement calculator functions"
- "Create unit tests for validation"
- "Update Makefile with test targets"
- "Set up Unity testing infrastructure"

#### @subagents/documentation

**Purpose:** Documentation specialist

**Responsibilities:**
- Add file-level docstrings
- Write function docstrings
- Create README files
- Update documentation
- Maintain knowledge base

**Examples:**
- "Add docstrings to all project_2 files"
- "Create README for new feature"
- "Document API changes"

### General Agent

**Purpose:** Execution and verification

**Responsibilities:**
- Run tests and report results
- Perform code reviews
- Verify builds
- Polish documentation

**Examples:**
- "Run tests and analyze results"
- "Perform code review"
- "Verify build compiles without warnings"

#### @subagents/giter (Git Agent)

**Purpose:** Version control operations specialist

**Responsibilities:**
- Stage relevant changes
- Create meaningful commit messages
- Commit changes
- **Push to remote repository** (default behavior)
- Verify push success
- Report results to user

**Examples:**
- "Stage and commit the calculator feature"
- "Commit test additions and push to remote"
- "Create commit for bug fix and sync with remote"

**Push behavior:**
- ✅ **Default:** Always push after committing
- ❌ **Skip only when:** User explicitly says "don't push" or "commit locally only"

## Delegation Decision Matrix

| Task Type | Delegate To | Example |
|-----------|-------------|---------|
| Code implementation | @subagents/coder-agent | "Implement calculator functions" |
| Test creation | @subagents/coder-agent | "Create unit tests for input validation" |
| Documentation | @subagents/documentation | "Add docstrings to all functions" |
| Makefile updates | @subagents/coder-agent | "Add test targets to Makefile" |
| Test execution | general agent | "Run make test and report results" |
| Code review | general agent | "Review code for quality issues" |
| Git operations | @subagents/giter | "Stage, commit, and push changes" |
| Planning | main delegator | "Create implementation plan" |
| Coordination | main delegator | "Monitor task progress" |

## Workflow Examples

### ✅ CORRECT Workflow

**Task:** Add temperature converter feature with tests

```
Phase 1: Planning (Main Delegator)
────────────────────────────────────
1. Analyze requirements
2. Break down:
   - Implement temperature_converter()
   - Create tests for converter
   - Add to main menu
   - Document function
3. Create detailed plan
4. Get user approval

Phase 2: Implementation (Delegate)
────────────────────────────────────
1. Delegate to @subagents/coder-agent:
   "Implement temperature_converter() function in function_file.c"

2. Delegate to @subagents/coder-agent:
   "Create test_temperature_converter.c with test cases"

3. Delegate to @subagents/documentation:
   "Add docstring to temperature_converter function"

4. Delegate to @subagents/coder-agent:
   "Update Makefile with temperature converter test target"

Phase 3: Verification (General Agent)
────────────────────────────────────
1. Delegate to general agent:
   "Run make test and report results"

2. Delegate to general agent:
   "Perform code review for quality issues"

Phase 4: Version Control (@subagents/giter)
────────────────────────────────────
1. Delegate to @subagents/giter:
   "Stage changes, commit with message 'feat: add temperature 
   converter with tests', and push to remote"

2. Git agent will:
   - Stage relevant files
   - Create meaningful commit
   - Push to remote (default)
   - Verify push success
   - Report results
```

### ❌ INCORRECT Workflow

**What NOT to do:**

```
Phase 1: Planning (Main Delegator)
────────────────────────────────────
1. Analyze requirements ✅
2. Create plan ✅

Phase 2: Implementation (Main Delegator - WRONG!)
────────────────────────────────────
1. Main delegator implements temperature_converter() ❌
2. Main delegator creates test file ❌
3. Main delegator adds docstrings ❌
4. Main delegator updates Makefile ❌
```

**Problem:** Main delegator doing work instead of delegating

## Delegation Best Practices

### 1. Be Specific in Delegation

**Good:**
```
Delegate to @subagents/coder-agent:
"Implement read_int() function in function_file.c with:
- Parameter: const char *prompt, int *value
- Return: 1 on success, 0 on failure
- Behavior: Validate scanf input, clear buffer, show error message"
```

**Bad:**
```
Delegate to @subagents/coder-agent:
"Add input function"
```

### 2. One Task Per Delegation

**Good:**
```
Delegate to @subagents/coder-agent:
"Implement calculate_average() function"

Then separately:
Delegate to @subagents/coder-agent:
"Create tests for calculate_average()"
```

**Bad:**
```
Delegate to @subagents/coder-agent:
"Implement all calculator functions and tests and docs and Makefile"
```

### 3. Verify Before Moving On

**Pattern:**
```
1. Delegate implementation
2. Wait for completion
3. Delegate verification
4. Check results
5. Proceed to next task
```

### 4. Use Appropriate Agent

**Match task to expertise:**
- Code → @subagents/coder-agent
- Docs → @subagents/documentation
- Tests → @subagents/coder-agent
- Review → general agent
- Execute → general agent
- Git operations → @subagents/giter

## Communication Patterns

### Delegating to Coder Agent

**Template:**
```
@subagents/coder-agent: [Specific task]

Requirements:
- [Requirement 1]
- [Requirement 2]
- [Requirement 3]

Files to modify:
- [file 1]
- [file 2]

Expected outcome:
- [What should result]
```

### Delegating to Documentation Agent

**Template:**
```
@subagents/documentation: [Documentation task]

Files to document:
- [file 1]
- [file 2]

Standards:
- Follow Doxygen style
- Include @param and @return
- Add usage examples
```

### Delegating to General Agent

**Template:**
```
@general: [Execution task]

Command: make test

Expected: All tests pass

Report: Test results and any failures
```

### Delegating to Git Agent

**Template:**
```
@subagents/giter: [Git operation]

Action: Stage, commit, and push changes

Files to include:
- [file 1]
- [file 2]

Commit message: [type]: [subject]

Push: Yes (default) / No (only if user requested)

Expected: Changes committed and pushed to remote successfully
```

## Escalation Handling

### When to Intervene

**Main Delegator should intervene when:**
- Agent reports blocker
- Task dependencies conflict
- User changes requirements
- Critical bug discovered

**How to intervene:**
1. Pause current delegations
2. Assess situation
3. Create new plan
4. Resume with adjusted tasks

### Critical Fixes

**Main Delegator CAN directly fix when:**
- Typo blocking all work
- Missing semicolon preventing compilation
- Trivial syntax error

**Pattern:**
```
1. Identify critical blocker
2. Make minimal fix
3. Document what was fixed
4. Resume normal delegation
```

## Progress Tracking

### Task Status

**Track each delegated task:**
- [ ] Delegated
- [ ] In Progress
- [ ] Completed
- [ ] Verified

**Use TodoWrite tool to maintain task list**

### Reporting

**At each phase completion:**
```
Phase: Implementation
Status: Complete

Completed tasks:
✅ Implemented temperature_converter()
✅ Created test file
✅ Added docstrings
✅ Updated Makefile

Next phase: Verification
```

## Common Pitfalls

### ❌ Doing Work Instead of Delegating

**Wrong:**
```
Main Delegator: *edits code directly*
```

**Right:**
```
Main Delegator: @subagents/coder-agent, please implement...
```

### ❌ Vague Delegation

**Wrong:**
```
@subagents/coder-agent: Fix the code
```

**Right:**
```
@subagents/coder-agent: Implement input validation in read_int() 
function at line 25 of function_file.c
```

### ❌ Not Waiting for Completion

**Wrong:**
```
1. Delegate task A
2. Immediately delegate task B (depends on A)
3. Task B fails because A not done
```

**Right:**
```
1. Delegate task A
2. Wait for completion
3. Verify task A
4. Then delegate task B
```

### ❌ Wrong Agent for Task

**Wrong:**
```
@subagents/documentation: Implement function
```

**Right:**
```
@subagents/coder-agent: Implement function
@subagents/documentation: Document function
```

## Workflow Checklist

Before delegating:
- [ ] Task is clearly defined
- [ ] Right agent selected
- [ ] Dependencies identified
- [ ] Success criteria established

After delegation:
- [ ] Wait for completion
- [ ] Verify work done
- [ ] Check quality
- [ ] Proceed to next task

## See Also

- **testing-workflow.md** - Testing procedures
- **code-review-checklist.md** - Code review standards
- **git-workflow.md** - Git operations workflow
