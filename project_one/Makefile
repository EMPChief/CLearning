# Simple Makefile for ProjectOne

CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -O2
LDFLAGS :=

TARGET := ProjectOne
SRC := main.c calculations.c
OBJ := $(SRC:.c=.o)
DEPS := calculations.h

.PHONY: all clean run debug

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(OBJ) $(TARGET)

# Build with debug symbols
debug: CFLAGS := -std=c11 -Wall -Wextra -g
debug: clean $(TARGET)
