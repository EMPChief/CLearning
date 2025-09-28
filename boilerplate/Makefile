# Makefile for C projects

CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -O2
LDFLAGS :=

TARGET := $(notdir $(CURDIR))
SRC := main.c function_file.c
DEPS := helper.h

.PHONY: all clean run debug

all: $(TARGET)

$(TARGET): $(SRC) $(DEPS)
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)

run: $(TARGET)
	@if [ -n "$$INPUT" ]; then printf "%s" "$$INPUT" | ./$(TARGET); else ./$(TARGET); fi

clean:
	$(RM) $(TARGET)

# Build with debug symbols
debug: CFLAGS := -std=c11 -Wall -Wextra -g
debug: clean $(TARGET)
