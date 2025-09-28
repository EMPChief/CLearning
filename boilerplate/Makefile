# Makefile for project_two

CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -O2
LDFLAGS :=

TARGET := $(notdir $(CURDIR))
SRC := main.c function_file.c
OBJ := $(SRC:.c=.o)
DEPS := helper.h

.PHONY: all clean run debug

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	@if [ -n "$$INPUT" ]; then printf "%s" "$$INPUT" | ./$(TARGET); else ./$(TARGET); fi

clean:
	$(RM) $(OBJ) $(TARGET) *.o ProjectOne

# Build with debug symbols
debug: CFLAGS := -std=c11 -Wall -Wextra -g
debug: clean $(TARGET)
