# Simple single-binary Makefile (no .o artifacts)

CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -O2
LDFLAGS := -lm

TARGET := main
SRC := main.c function_file.c

UNITY_SRC := unity/unity.c
TEST_CALCULATIONS := tests/test_calculations
TEST_INPUT := tests/test_input_validation

.PHONY: all clean run debug test test-calculations test-input

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)

run: $(TARGET)
	@if [ -n "$$INPUT" ]; then printf "%s" "$$INPUT" | ./$(TARGET); else ./$(TARGET); fi

$(TEST_CALCULATIONS): tests/test_calculations.c function_file.c $(UNITY_SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(TEST_INPUT): tests/test_input_validation.c function_file.c $(UNITY_SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

test-calculations: $(TEST_CALCULATIONS)
	@echo "Running calculation tests..."
	@./$(TEST_CALCULATIONS)

test-input: $(TEST_INPUT)
	@echo "Running input validation tests..."
	@./$(TEST_INPUT)

test: test-calculations test-input
	@echo "All tests completed!"

clean:
	$(RM) $(TARGET) project_two ProjectOne *.o $(TEST_CALCULATIONS) $(TEST_INPUT)

# Build with debug symbols (still single-binary)
debug:
	$(MAKE) clean
	$(MAKE) CFLAGS="-std=c11 -Wall -Wextra -g" all
