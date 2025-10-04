# Git Workflow and Commit Standards

## Overview

This document covers Git workflow, commit standards, and version control best practices for CLearning projects.

## Commit Message Standards

### Format

```
<type>: <subject>

<optional body>

<optional footer>
```

### Types

| Type | Usage | Example |
|------|-------|---------|
| `feat` | New feature | `feat: add temperature converter function` |
| `fix` | Bug fix | `fix: correct input buffer clearing in read_int` |
| `docs` | Documentation | `docs: add docstrings to calculation functions` |
| `test` | Tests | `test: add unit tests for input validation` |
| `refactor` | Code refactoring | `refactor: simplify temperature conversion logic` |
| `style` | Formatting | `style: fix indentation in function_file.c` |
| `chore` | Maintenance | `chore: update Makefile test targets` |

### Subject Line

**Rules:**
- Start with lowercase (after type)
- No period at end
- Imperative mood ("add" not "added")
- Max 50 characters
- Be specific

**Good Examples:**
```
feat: add salary calculator with tax calculation
fix: prevent division by zero in average calculation
test: add edge cases for temperature converter
docs: document input validation pattern
```

**Bad Examples:**
```
Update stuff                    // Too vague
Added new features.            // Past tense, period
feat: Added a really long description that exceeds the limit  // Too long
Fixed bug                      // Not specific
```

### Body (Optional)

**When to include:**
- Complex changes need explanation
- Multiple related changes
- Breaking changes
- Design decisions

**Format:**
- Separate from subject with blank line
- Wrap at 72 characters
- Explain WHY, not WHAT
- Reference issues if applicable

**Example:**
```
feat: add temperature converter function

Implements bidirectional temperature conversion between Celsius
and Fahrenheit. Uses standard formulas:
- C→F: (C × 9/5) + 32
- F→C: (F - 32) × 5/9

Includes input validation and error handling for invalid choices.

Closes #42
```

## Commit Best Practices

### 1. Commit Often

```bash
# Small, focused commits
git commit -m "feat: add read_int function"
git commit -m "test: add tests for read_int"
git commit -m "docs: document read_int function"
```

**Not:**
```bash
# One huge commit
git commit -m "Add everything"
```

### 2. One Logical Change Per Commit

**Good - Single purpose:**
```bash
git add function_file.c helper.h
git commit -m "feat: add temperature converter function"
```

**Bad - Multiple unrelated changes:**
```bash
git add .
git commit -m "Add converter, fix bug, update docs"
```

### 3. Test Before Committing

```bash
# Always run before commit
make clean
make test

# Only commit if tests pass
git commit -m "feat: add new function"
```

### 4. Write Clear Messages

**Template:**
```
What: Add temperature converter
Why: Allow users to convert between C and F
How: Implement conversion formulas with validation
```

**In commit:**
```
feat: add temperature converter

Allows bidirectional conversion between Celsius and Fahrenheit.
Includes input validation and handles invalid choices gracefully.
```

## Git Commands Reference

### Daily Workflow

```bash
# Check status
git status

# Stage specific files
git add function_file.c helper.h

# Stage all changes
git add .

# Commit with message
git commit -m "feat: add calculator function"

# View commit history
git log
git log --oneline

# View changes
git diff
git diff --staged
```

### Undoing Changes

```bash
# Unstage file
git reset HEAD file.c

# Discard local changes
git checkout -- file.c

# Amend last commit
git commit --amend

# Undo last commit (keep changes)
git reset --soft HEAD~1

# Undo last commit (discard changes) 
git reset --hard HEAD~1
```

### Branching (If Used)

```bash
# Create branch
git branch feature-name

# Switch to branch
git checkout feature-name

# Create and switch
git checkout -b feature-name

# Merge branch
git checkout main
git merge feature-name

# Delete branch
git branch -d feature-name
```

## Workflow Patterns

### Feature Development

```bash
# 1. Start clean
git status  # Ensure working directory clean

# 2. Develop feature
vim function_file.c
vim tests/test_feature.c

# 3. Test
make test

# 4. Stage changes
git add function_file.c helper.h tests/test_feature.c Makefile

# 5. Commit
git commit -m "feat: add feature X with tests"

# 6. Push (if working with remote)
git push origin main
```

### Bug Fix

```bash
# 1. Reproduce bug
make test  # Shows failing test

# 2. Fix bug
vim function_file.c

# 3. Verify fix
make test  # Should pass

# 4. Commit
git add function_file.c
git commit -m "fix: correct buffer overflow in read_int"

# 5. Consider adding test
vim tests/test_input.c  # Add regression test
git add tests/test_input.c
git commit -m "test: add regression test for buffer overflow"
```

### Documentation Update

```bash
# 1. Update docs
vim function_file.c  # Add/update docstrings

# 2. Stage
git add function_file.c

# 3. Commit
git commit -m "docs: add docstrings to input validation functions"
```

## Commit Hygiene

### Before Committing

**Checklist:**
- [ ] Code compiles without warnings
- [ ] All tests pass
- [ ] Only related files staged
- [ ] No debug code
- [ ] No commented-out code
- [ ] Commit message is clear

### What NOT to Commit

```bash
# Build artifacts
*.o
main
tests/test_*

# Editor files
*.swp
.vscode/
.idea/

# OS files
.DS_Store
Thumbs.db
```

**Use `.gitignore`:**
```gitignore
# Executables
main
*/main

# Object files
*.o

# Test binaries
tests/test_*
!tests/*.c

# Editor
*.swp
.vscode/
```

### Staging Selectively

```bash
# Stage specific files only
git add function_file.c helper.h

# Stage parts of a file (interactive)
git add -p function_file.c

# Review what's staged
git diff --staged
```

## Working with Remotes

### Cloning

```bash
git clone https://github.com/user/CLearning.git
cd CLearning
```

### Pushing

```bash
# Push to remote
git push origin main

# Push new branch
git push -u origin feature-name
```

### Pulling

```bash
# Update from remote
git pull origin main

# Fetch without merging
git fetch origin
git merge origin/main
```

### Resolving Conflicts

```bash
# After pull shows conflicts
vim conflicted_file.c  # Resolve conflicts
git add conflicted_file.c
git commit -m "merge: resolve conflicts in feature X"
```

## Branching Strategy (If Used)

### Simple Strategy

```
main ─────┬─────────────┬─────────
          │             │
          └─ feature-1 ─┘
```

**Usage:**
- `main` - Always stable, tested code
- `feature-X` - Development branches
- Merge to main when done and tested

### Creating Feature Branch

```bash
# Start from main
git checkout main
git pull

# Create feature branch
git checkout -b add-calculator

# Work on feature
vim function_file.c
git add function_file.c
git commit -m "feat: implement calculator"

# When done, merge to main
git checkout main
git merge add-calculator

# Delete feature branch
git branch -d add-calculator
```

## History Management

### Viewing History

```bash
# Recent commits
git log --oneline -10

# Graphical view
git log --graph --oneline

# Specific file history
git log function_file.c

# Search commits
git log --grep="calculator"

# Show changes in commit
git show <commit-hash>
```

### Finding Changes

```bash
# When did this line change?
git blame function_file.c

# Find when bug was introduced
git bisect start
git bisect bad
git bisect good <commit-hash>
# Git will guide you through testing
```

## Tags and Releases

### Creating Tags

```bash
# Lightweight tag
git tag v1.0

# Annotated tag (recommended)
git tag -a v1.0 -m "Release version 1.0"

# Tag specific commit
git tag -a v1.0 <commit-hash> -m "Version 1.0"

# List tags
git tag

# Push tags
git push origin v1.0
git push origin --tags
```

### Semantic Versioning

```
v<MAJOR>.<MINOR>.<PATCH>

v1.0.0  - Initial release
v1.0.1  - Bug fix
v1.1.0  - New feature (backward compatible)
v2.0.0  - Breaking change
```

## Commit Templates

### Setting Up Template

```bash
# Create template file
cat > ~/.gitmessage << EOF
<type>: <subject>

<body>

<footer>
EOF

# Configure git to use it
git config --global commit.template ~/.gitmessage
```

### Using Template

```bash
# Opens editor with template
git commit
```

## Best Practices Summary

### Do

- ✅ Commit often
- ✅ Write clear messages
- ✅ Test before committing
- ✅ Stage selectively
- ✅ Use meaningful commit messages
- ✅ Reference issues
- ✅ Keep commits focused

### Don't

- ❌ Commit broken code
- ❌ Commit untested code
- ❌ Use vague messages ("fix", "update")
- ❌ Commit debug code
- ❌ Commit generated files
- ❌ Mix unrelated changes
- ❌ Commit sensitive data

## Emergency Procedures

### Committed Sensitive Data

```bash
# Remove file from all history (DANGEROUS)
git filter-branch --force --index-filter \
  "git rm --cached --ignore-unmatch sensitive_file" \
  --prune-empty --tag-name-filter cat -- --all

# Force push
git push origin --force --all
```

### Broke Main Branch

```bash
# Revert to last known good commit
git reset --hard <good-commit-hash>

# Or revert specific commit
git revert <bad-commit-hash>
```

### Lost Commits

```bash
# Find lost commits
git reflog

# Recover commit
git checkout <lost-commit-hash>
git checkout -b recovery-branch
```

## Integration with Development Workflow

### With Agent Delegation

**Pattern:**
```
1. Main Delegator: Plan work
2. Specialized Agent: Implement
3. General Agent: Test
4. General Agent: Commit (if requested by user)
```

**Commit from General Agent:**
```bash
# After user requests commit
git add <relevant files>
git commit -m "feat: add feature X

Implementation by coder-agent, tested and verified.
All tests pass."
```

### With Testing

```bash
# Before committing
make clean
make
make test

# Only commit if all pass
if [ $? -eq 0 ]; then
    git commit -m "feat: tested feature"
else
    echo "Tests failed - fix before committing"
fi
```

## See Also

- **code-review-checklist.md** - Pre-commit checks
- **testing-workflow.md** - Testing before commit
- **agent-delegation.md** - Who commits what
- Git documentation: https://git-scm.com/doc
