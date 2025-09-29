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

# ---------------------
# Unit tests (Unity)
# ---------------------
UNITY_DIR := unity
TEST_DIR  := tests
TEST_BIN  := test_calculations_io
TEST_SRCS := $(TEST_DIR)/test_calculations_io.c $(TEST_DIR)/test_utils.c $(UNITY_DIR)/unity.c calculations.c

.PHONY: test tests tests-clean

$(TEST_BIN): $(TEST_SRCS)
	$(CC) $(CFLAGS) -I$(UNITY_DIR) -I. $(TEST_SRCS) -o $(TEST_BIN) -lm

test: $(TEST_BIN)
	./$(TEST_BIN)

tests: test

tests-clean:
	$(RM) $(TEST_BIN)
