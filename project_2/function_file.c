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
  int an = 17;
  // while (!read_int("Enter the number of terms (n): ", &n))
  //   ;
  // while (!read_int("Enter the first term (a1): ", &a1))
  //   ;
  // while (!read_int("Enter the last term (an): ", &an))
  //   ;
  sum_of_sequence = ((double)a1 + an) * n / 2;
  printf("Sum of the arithmetic sequence: %.2lf\n", sum_of_sequence);
}

/**
 * Calculate and print gross salary, tax amount, and net salary.
 *
 * Prompts the user to input:
 *   - Hourly wage (double)
 *   - Hours worked (double)
 *   - Tax rate in percentage (integer 0–100)
 *
 * Computes:
 *   gross_salary = hourly_wage * hours_worked
 *   tax_amount   = gross_salary * (tax_rate / 100.0)
 *   net_salary   = gross_salary - tax_amount
 *
 * Prints the gross salary, tax amount, and net salary formatted
 * to two decimal places.
 *
 * @note Input is validated using read_double and read_int.
 *       The loop ensures valid entries before proceeding.
 */
void salary_calculator(void) {
  double hourly_wage, hours_worked, gross_salary, net_salary, tax_amount;
  int tax_rate;
  while (!read_double("Enter hourly wage: ", &hourly_wage))
    ;
  while (!read_double("Enter hours worked this month: ", &hours_worked))
    ;
  while (!read_int("Enter tax rate (0-100): ", &tax_rate))
    ;
  gross_salary = hourly_wage * hours_worked;
  tax_amount = gross_salary * tax_rate / 100.0;
  net_salary = gross_salary - tax_amount;
  printf("Gross Salary: $%.2lf\n", gross_salary);
  printf("Tax Amount: $%.2lf\n", tax_amount);
  printf("Net Salary: $%.2lf\n", net_salary);
}

/**
 * Calculate and print the estimated driving time based on distance and speed.
 *
 * Prompts the user to input:
 *   - Driving distance in kilometers (integer)
 *   - Driving speed in kilometers per hour (integer)
 *
 * Computes:
 *   travel_time (in hours) = (double)driving_distance / driving_speed
 *   hours   = integer part of travel_time
 *   minutes = integer part of (fractional hours * 60)
 *   seconds = integer part of (remaining fractional minutes * 60)
 *   milliseconds = integer part of (remaining fractional seconds * 1000)
 *
 * Prints the estimated travel time in hours, minutes, and seconds, and
 * milliseconds.
 *
 * @note Input is validated using read_int to ensure integer values.
 *       Floating-point arithmetic is used to preserve fractional accuracy.
 */

void driving_time_calculator(void) {
  int driving_distance, driving_speed;
  double travel_time;
  int hours, minutes, seconds, miliseconds;

  while (!read_int("Enter the driving distance (in km): ", &driving_distance))
    ;
  while (!read_int("Enter the driving speed (in km/h): ", &driving_speed))
    ;

  travel_time = (double)driving_distance / driving_speed;
  hours = (int)travel_time;
  minutes = (int)((travel_time - hours) * 60);
  seconds = (int)((((travel_time - hours) * 60) - minutes) * 60);
  miliseconds =
      (int)((((((travel_time - hours) * 60) - minutes) * 60) - seconds) * 1000);
  printf("Estimated travel time: %d %s, %d %s, %d %s, %d %s\n", hours,
         (hours == 1 ? "hour" : "hours"), minutes,
         (minutes == 1 ? "minute" : "minutes"), seconds,
         (seconds == 1 ? "second" : "seconds"), miliseconds,
         (miliseconds == 1 ? "millisecond" : "milliseconds"));
}
