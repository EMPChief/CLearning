#include "helper.h"
#include <stdio.h>
#include <sys/types.h>

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
 * Calculate and print the sum of an arithmetic sequence.
 *
 * Uses the arithmetic series formula:
 *   S = (a1 + an) * n / 2
 * where:
 *   - a1 is the first term,
 *   - an is the last term,
 *   - n is the number of terms.
 *
 * Currently uses hardcoded values:
 *   n = 9, a1 = 1, an = 17
 *
 * Prints the sum formatted to 2 decimal places.
 *
 * @note Input reading via read_three_ints is commented out,
 *       but can be enabled for user input.
 */
void sum_of_arithemetic_sequence(void) {
  double sum_of_sequence;
  int n = 9;
  int a1 = 1;
  // int d = 2;
  int an = 17;
  // while (!read_three_ints("Enter n, a1, d: ", &n, &a1, &d))
  //   ;
  sum_of_sequence = ((double)a1 + an) * n / 2;
  printf("Sum of the arithmetic sequence: %.2lf\n", sum_of_sequence);
}
