#!/bin/bash

# Script to create a new C project using the boilerplate

# Check if a project name was provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <project_name>"
    exit 1
fi

PROJECT_NAME="$1"
BOILERPLATE_DIR="/mnt/data/Project/CLearning/boilerplate"
PROJECT_DIR="/mnt/data/Project/CLearning/$PROJECT_NAME"

# Check if the project already exists
if [ -d "$PROJECT_DIR" ]; then
    echo "Error: Project '$PROJECT_NAME' already exists."
    exit 1
fi

# Create project directory
mkdir -p "$PROJECT_DIR"

# Copy files from boilerplate (excluding .o files and binary)
cp "$BOILERPLATE_DIR/Makefile" "$PROJECT_DIR/"
cp "$BOILERPLATE_DIR"/*.c "$PROJECT_DIR/" 2>/dev/null || true
cp "$BOILERPLATE_DIR"/*.h "$PROJECT_DIR/" 2>/dev/null || true

echo "Created new project '$PROJECT_NAME' with boilerplate files."
echo "Project location: $PROJECT_DIR"