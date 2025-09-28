# Simple single-binary Makefile (no .o artifacts)

CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -O2
LDFLAGS :=

TARGET := main
SRC := main.c calculations.c

.PHONY: all clean run debug

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)

run: $(TARGET)
	@if [ -n "$$INPUT" ]; then printf "%s" "$$INPUT" | ./$(TARGET); else ./$(TARGET); fi

clean:
	$(RM) $(TARGET) ProjectOne project_one *.o

# Build with debug symbols (still single-binary)
debug:
	$(MAKE) clean
	$(MAKE) CFLAGS="-std=c11 -Wall -Wextra -g" all
