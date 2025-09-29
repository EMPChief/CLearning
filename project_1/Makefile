# Simple single-binary Makefile (no .o artifacts)

CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -O2
LDFLAGS :=

TARGET := main
SRC := main.c calculations.c

.PHONY: all clean run debug test

all: $(TARGET)

$(TARGET): $(SRC)
\t$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)

run: $(TARGET)
\t@if [ -n "$$INPUT" ]; then printf "%s" "$$INPUT" | ./$(TARGET); else ./$(TARGET); fi

clean:
\t$(RM) $(TARGET) ProjectOne project_one *.o tests/test_calculations_unit

# Build with debug symbols (still single-binary)
debug:
\t$(MAKE) clean
\t$(MAKE) CFLAGS="-std=c11 -Wall -Wextra -g" all

test: tests/test_calculations_unit
\t./tests/test_calculations_unit

tests/test_calculations_unit: tests/test_calculations_unit.c tests/test_io_capture.h tests/test_asserts.h test_calculations.c
\t$(CC) $(CFLAGS) -o $@ tests/test_calculations_unit.c
