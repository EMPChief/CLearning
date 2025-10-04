#include "helper.h"
#include <stdio.h>

int read_int(const char *prompt, int *value) {
  int c;
  printf("%s", prompt);
  if (scanf("%d", value) != 1) {
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Invalid input. Please enter a valid integer.\n");
    return 0;
  }
  while ((c = getchar()) != '\n' && c != EOF);
  return 1;
}

int read_float(const char *prompt, float *value) {
  int c;
  printf("%s", prompt);
  if (scanf("%f", value) != 1) {
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Invalid input. Please enter a valid number.\n");
    return 0;
  }
  while ((c = getchar()) != '\n' && c != EOF);
  return 1;
}

int read_double(const char *prompt, double *value) {
  int c;
  printf("%s", prompt);
  if (scanf("%lf", value) != 1) {
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Invalid input. Please enter a valid number.\n");
    return 0;
  }
  while ((c = getchar()) != '\n' && c != EOF);
  return 1;
}

int read_three_ints(const char *prompt, int *val1, int *val2, int *val3) {
  int c;
  printf("%s", prompt);
  if (scanf("%d %d %d", val1, val2, val3) != 3) {
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Invalid input. Please enter three valid integers separated by spaces.\n");
    return 0;
  }
  while ((c = getchar()) != '\n' && c != EOF);
  return 1;
}

void explain_modular_programming(void) {
  printf("This program demonstrates modular programming in C.\n");
  printf("It consists of multiple files, each handling specific tasks.\n");
  printf("The main file coordinates the execution flow.\n");
  printf("Header files declare functions and macros for reuse.\n");
  printf("Source files implement the declared functions.\n");
  printf("This structure enhances code organization and maintainability.\n");
}

int is_prime(int n) {
  if (n <= 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int fibonacci(int n) {
  if (n <= 0) return 0;
  if (n == 1) return 1;
  int a = 0, b = 1, temp;
  for (int i = 2; i <= n; i++) {
    temp = a + b;
    a = b;
    b = temp;
  }
  return b;
}

int factorial(int n) {
  if (n < 0) return -1;
  if (n == 0 || n == 1) return 1;
  int result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

void print_pyramid(int height) {
  for (int i = 1; i <= height; i++) {
    for (int j = 0; j < height - i; j++) {
      printf(" ");
    }
    for (int k = 0; k < 2 * i - 1; k++) {
      printf("*");
    }
    printf("\n");
  }
}

int reverse_number(int num) {
  int reversed = 0;
  int sign = (num < 0) ? -1 : 1;
  num *= sign;
  while (num > 0) {
    reversed = reversed * 10 + num % 10;
    num /= 10;
  }
  return reversed * sign;
}

int is_palindrome(int num) {
  if (num < 0) return 0;
  return num == reverse_number(num);
}

int sum_of_digits(int num) {
  int sum = 0;
  if (num < 0) num = -num;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

void print_multiplication_table(int num) {
  printf("\nMultiplication Table for %d:\n", num);
  for (int i = 1; i <= 10; i++) {
    printf("%d x %d = %d\n", num, i, num * i);
  }
}

int gcd(int a, int b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
