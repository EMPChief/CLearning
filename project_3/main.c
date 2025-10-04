#include "helper.h"
#include <stdio.h>

int main(void) {
  int user_choice;
  int num, num2, result;

  do {
    printf("\n=== Fun Math Functions Menu ===\n");
    printf("1  - Explain modular programming\n");
    printf("2  - Check if number is prime\n");
    printf("3  - Calculate Fibonacci number\n");
    printf("4  - Calculate factorial\n");
    printf("5  - Print pyramid\n");
    printf("6  - Reverse number\n");
    printf("7  - Check if palindrome\n");
    printf("8  - Sum of digits\n");
    printf("9  - Multiplication table\n");
    printf("10 - Greatest Common Divisor (GCD)\n");
    printf("0  - Exit\n");
    printf("================================\n");

    if (!read_int("Enter your choice (0-10): ", &user_choice)) {
      continue;
    }

    switch (user_choice) {
    case 0:
      printf("Goodbye!\n");
      break;
    case 1:
      explain_modular_programming();
      break;
    case 2:
      if (read_int("Enter a number: ", &num)) {
        if (is_prime(num)) {
          printf("%d is prime!\n", num);
        } else {
          printf("%d is not prime.\n", num);
        }
      }
      break;
    case 3:
      if (read_int("Enter position (n): ", &num)) {
        result = fibonacci(num);
        printf("Fibonacci(%d) = %d\n", num, result);
      }
      break;
    case 4:
      if (read_int("Enter a number: ", &num)) {
        result = factorial(num);
        if (result == -1) {
          printf("Error: Factorial not defined for negative numbers.\n");
        } else {
          printf("%d! = %d\n", num, result);
        }
      }
      break;
    case 5:
      if (read_int("Enter pyramid height: ", &num)) {
        print_pyramid(num);
      }
      break;
    case 6:
      if (read_int("Enter a number: ", &num)) {
        result = reverse_number(num);
        printf("Reversed: %d\n", result);
      }
      break;
    case 7:
      if (read_int("Enter a number: ", &num)) {
        if (is_palindrome(num)) {
          printf("%d is a palindrome!\n", num);
        } else {
          printf("%d is not a palindrome.\n", num);
        }
      }
      break;
    case 8:
      if (read_int("Enter a number: ", &num)) {
        result = sum_of_digits(num);
        printf("Sum of digits: %d\n", result);
      }
      break;
    case 9:
      if (read_int("Enter a number: ", &num)) {
        print_multiplication_table(num);
      }
      break;
    case 10:
      if (read_int("Enter first number: ", &num) && read_int("Enter second number: ", &num2)) {
        result = gcd(num, num2);
        printf("GCD(%d, %d) = %d\n", num, num2, result);
      }
      break;
    default:
      printf("Invalid choice! Please choose 0-10.\n");
    }
  } while (user_choice != 0);

  return 0;
}
