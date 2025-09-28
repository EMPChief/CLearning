# Top-level Makefile to build/run all project_* subprojects
SHELL := /bin/bash

# Discover subprojects automatically, version-sorted (handles 2 < 10)
SUBDIRS := $(shell ls -1d project_* 2>/dev/null | sort -V)

.DEFAULT_GOAL := all

.PHONY: all run clean list new

# Build all subprojects
all:
	@set -e; for d in $(SUBDIRS); do \
		$(MAKE) -C $$d all; \
	done

# Run all subprojects sequentially (interactive unless INPUT_<dir> provided)
# Example: make run INPUT_project_one=$'1\n10\n20\n' INPUT_project_two=$'1\n'
run:
	@set -e; for d in $(SUBDIRS); do \
		echo "-- Running $$d --"; \
		var="INPUT_$$d"; \
		input="${!var}"; \
		if [ -n "$$input" ]; then \
			$(MAKE) -C $$d run INPUT="$$input"; \
		else \
			$(MAKE) -C $$d run; \
		fi; \
	done

# Clean all subprojects
clean:
	@set -e; for d in $(SUBDIRS); do \
		$(MAKE) -C $$d clean; \
	done

# Utility: list discovered projects
list:
	@echo "Projects:" $(SUBDIRS)

# Create a new project from the boilerplate directory
# Usage: make new NAME=project_3
new:
	@test -n "$(NAME)" || { echo "usage: make new NAME=project_3"; exit 1; }
	@cp -R boilerplate "$(NAME)"
	@$(MAKE) -C "$(NAME)" clean >/dev/null
	@echo "Created $(NAME). You can build with: make -C $(NAME)"
