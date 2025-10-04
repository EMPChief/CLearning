

This repository defines task-focused agents to streamline C programming development, including planning, implementation, review, documentation, and testing.

Main Agent:
- `codebase-agent`: C Development Main Delegator Agent - coordinates all C development tasks

Specialized Subagents:

- `@task-manager`: C project planner - breaks down complex features into manageable tasks
- `@subagents/coder-agent`: C code maker - executes C coding subtasks with proper memory management
- `@subagents/tester`: C unit tester - Unity framework testing specialist for thorough testing
- `@subagents/reviewer`: C code reviewer - security and quality assurance with feedback
- `@subagents/documentation`: C documentation creator - markdown and docstring specialist for clear documentation
- `@subagents/giter`: Git operations specialist - handles all git operations at project completion
- `@subagents/knowledge`: Knowledge holder - maintains project knowledge base and references

Legacy Agents (for reference):
- `general`: General-purpose agent for researching complex questions
- `subagents/build-agent`: Build validation agent

Usage:

```bash
# Main C development workflow
# The main agent delegates to appropriate subagents automatically

# Direct subagent usage examples:
task --description "Plan C feature" --prompt "Break down calculator implementation" --subagent_type task-manager

task --description "Write C code" --prompt "Implement add function in calculator.c" --subagent_type subagents/coder-agent

task --description "Test C code" --prompt "Create Unity tests for calculator functions" --subagent_type subagents/tester

task --description "Review C code" --prompt "Review calculator.c for memory safety" --subagent_type subagents/reviewer

task --description "Document C code" --prompt "Create documentation for calculator module" --subagent_type subagents/documentation

task --description "Git operations" --prompt "Commit and push calculator implementation" --subagent_type subagents/giter

task --description "Knowledge lookup" --prompt "Find C memory management best practices" --subagent_type subagents/knowledge
```

C Development Focus:

- All agents are specialized for C programming with Unity testing framework
- Memory safety and proper error handling are prioritized
- Compilation and build validation using gcc/clang and make
- Integration with existing project structure (boilerplate/, project_1/, project_2/)

Safety:

- Repo-level `permissions.json` sets baseline rules; per-agent `permissions` apply tighter, task-specific restrictions
- Special focus on memory safety and buffer overflow prevention
- Git operations require approval for destructive commands

Approval-first workflow:

- Each agent begins by proposing a short plan and asks for approval before proceeding
- Per-agent `permissions` enforce tighter rules than repo defaults
- Main delegator agent coordinates the workflow and ensures proper handoffs between subagents


