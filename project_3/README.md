# Fun Math Functions

A modular C program demonstrating various mathematical algorithms and functions with interactive menu-driven interface. Includes comprehensive unit testing with Unity framework.

## Features

- **Modular Programming Explanation** - Displays information about modular programming concepts
- **Prime Number Checker** - Determines if a number is prime
- **Fibonacci Calculator** - Calculates nth Fibonacci number
- **Factorial Calculator** - Computes factorial with error handling for negative inputs
- **Pyramid Printer** - Draws ASCII pyramid patterns
- **Number Reversal** - Reverses digits of a number (handles negative numbers)
- **Palindrome Checker** - Verifies if a number reads the same forwards and backwards
- **Sum of Digits** - Calculates the sum of all digits in a number
- **Multiplication Table** - Prints multiplication table for any number (1-10)
- **GCD Calculator** - Computes Greatest Common Divisor using Euclidean algorithm

## Building

```bash
make          # Build the program
make run      # Build and run
make clean    # Remove executables
```

## Usage

Run the program and select options from the interactive menu:

```
=== Fun Math Functions Menu ===
1  - Explain modular programming
2  - Check if number is prime
3  - Calculate Fibonacci number
4  - Calculate factorial
5  - Print pyramid
6  - Reverse number
7  - Check if palindrome
8  - Sum of digits
9  - Multiplication table
10 - Greatest Common Divisor (GCD)
0  - Exit
================================
```

### Example Output

```
Enter your choice (0-10): 2
Enter a number: 17
17 is prime!

Enter your choice (0-10): 3
Enter position (n): 7
Fibonacci(7) = 13

Enter your choice (0-10): 10
Enter first number: 48
Enter second number: 60
GCD(48, 60) = 12
```

## Testing

Comprehensive unit tests using Unity testing framework:

```bash
make test_runner    # Build test suite
./test_runner       # Run all tests
```

Test coverage includes:
- Edge cases (zero, negative numbers, boundary values)
- Normal operation (typical inputs)
- Large values and special conditions

## File Structure

```
project_3/
├── main.c              # Entry point with menu system
├── function_file.c     # Implementation of all math functions
├── helper.h            # Function declarations and headers
├── tests/              # Unity test suite
│   └── test_math_functions.c
└── unity/              # Unity testing framework
    ├── unity.c
    └── unity.h
```

## Implementation Details

- **Input Validation**: Robust error handling with `read_int()` helper
- **Prime Detection**: Optimized algorithm checking odd divisors up to √n
- **Fibonacci**: Iterative approach for efficiency
- **GCD**: Euclidean algorithm with absolute value handling
- **Modular Design**: Separation of concerns across files
