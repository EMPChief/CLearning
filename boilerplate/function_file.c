/**
 * @file function_file.c
 * @brief Template implementation file for utility functions
 *
 * This is a boilerplate template containing common input validation functions.
 * Add your own functions below the input validation utilities.
 * The read_* functions provide validated user input handling.
 */

#include "helper.h"
#include <stdio.h>

/**
 * Read an integer from user input with validation.
 *
 * Prints the prompt, reads an integer using scanf, and validates the input.
 * If scanf fails to read exactly one integer, clears the input buffer and
 * returns 0. Otherwise returns 1 for success.
 *
 * @param prompt The prompt string to display to the user
 * @param value Pointer to store the validated integer value
 * @return 1 on successful input, 0 on invalid input
 */
int read_int(const char *prompt, int *value) {
  int c;
  printf("%s", prompt);
  if (scanf("%d", value) != 1) {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    printf("Invalid input. Please enter a valid integer.\n");
    return 0;
  }
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  return 1;
}

/**
 * Read a float from user input with validation.
 *
 * Prints the prompt, reads a float using scanf, and validates the input.
 * If scanf fails to read exactly one float, clears the input buffer and
 * returns 0. Otherwise returns 1 for success.
 *
 * @param prompt The prompt string to display to the user
 * @param value Pointer to store the validated float value
 * @return 1 on successful input, 0 on invalid input
 */
int read_float(const char *prompt, float *value) {
  int c;
  printf("%s", prompt);
  if (scanf("%f", value) != 1) {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    printf("Invalid input. Please enter a valid number.\n");
    return 0;
  }
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  return 1;
}

/**
 * Read a double from user input with validation.
 *
 * Prints the prompt, reads a double using scanf, and validates the input.
 * If scanf fails to read exactly one double, clears the input buffer and
 * returns 0. Otherwise returns 1 for success.
 *
 * @param prompt The prompt string to display to the user
 * @param value Pointer to store the validated double value
 * @return 1 on successful input, 0 on invalid input
 */
int read_double(const char *prompt, double *value) {
  int c;
  printf("%s", prompt);
  if (scanf("%lf", value) != 1) {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    printf("Invalid input. Please enter a valid number.\n");
    return 0;
  }
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  return 1;
}

/**
 * Read three integers from user input with validation.
 *
 * Prints the prompt, reads three space-separated integers using scanf, and
 * validates the input. If scanf fails to read exactly three integers, clears
 * the input buffer and returns 0. Otherwise returns 1 for success.
 *
 * @param prompt The prompt string to display to the user
 * @param val1 Pointer to store the first validated integer
 * @param val2 Pointer to store the second validated integer
 * @param val3 Pointer to store the third validated integer
 * @return 1 on successful input, 0 on invalid input
 */
int read_three_ints(const char *prompt, int *val1, int *val2, int *val3) {
  int c;
  printf("%s", prompt);
  if (scanf("%d %d %d", val1, val2, val3) != 3) {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    printf("Invalid input. Please enter three valid integers separated by "
           "spaces.\n");
    return 0;
  }
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  return 1;
}
/**
 * Print explanation of modular programming concepts.
 *
 * Displays a description of modular programming principles and structure
 * in C, covering file organization and benefits.
 *
 * @note Prints explanation to stdout
 */
void explain_modular_programming(void) {
  printf("This program demonstrates modular programming in C.\n");
  printf("It consists of multiple files, each handling specific tasks.\n");
  printf("The main file coordinates the execution flow.\n");
  printf("Header files declare functions and macros for reuse.\n");
  printf("Source files implement the declared functions.\n");
  printf("This structure enhances code organization and maintainability.\n");
}
