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
 * @param first_value Pointer to store the first validated integer
 * @param second_value Pointer to store the second validated integer
 * @param third_value Pointer to store the third validated integer
 * @return 1 on successful input, 0 on invalid input
 */
int read_three_ints(const char *prompt, int *first_value, int *second_value,
                    int *third_value) {
  int c;
  printf("%s", prompt);
  if (scanf("%d %d %d", first_value, second_value, third_value) != 3) {
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
 * Computes the sum of an arithmetic sequence using the formula:
 *   sum = (first_term + last_term) * number_of_terms / 2
 *
 * The function uses the following fixed values:
 *   - number_of_terms = 9
 *   - first_term = 1
 *   - last_term = 17
 *
 * Prints the calculated sum with two decimal places.
 */
void sum_of_arithmetic_sequence(void) {
  double sequence_sum;
  int number_of_terms = 9;
  int first_term = 1;
  int last_term = 17;
  sequence_sum = ((double)first_term + last_term) * number_of_terms / 2;
  printf("Sum of the arithmetic sequence: %.2lf\n", sequence_sum);
}

/**
 * Calculate and print net salary based on hourly wage, hours worked, and tax
 * rate.
 *
 * Prompts the user for hourly wage, hours worked, and tax rate percentage.
 * Computes the gross salary, tax amount, and net salary, then prints the
 * results.
 *
 * Formulas used:
 *   gross_salary = hourly_wage * hours_worked
 *   tax_amount = gross_salary * tax_rate_percentage / 100
 *   net_salary = gross_salary - tax_amount
 */
void salary_calculator(void) {
  double hourly_wage, hours_worked, gross_salary, net_salary, tax_amount;
  int tax_rate_percentage;
  while (!read_double("Enter hourly wage: ", &hourly_wage))
    ;
  while (!read_double("Enter hours worked this month: ", &hours_worked))
    ;
  while (!read_int("Enter tax rate (0-100): ", &tax_rate_percentage))
    ;
  gross_salary = hourly_wage * hours_worked;
  tax_amount = gross_salary * tax_rate_percentage / 100.0;
  net_salary = gross_salary - tax_amount;
  printf("Gross Salary: $%.2lf\n", gross_salary);
  printf("Tax Amount: $%.2lf\n", tax_amount);
  printf("Net Salary: $%.2lf\n", net_salary);
}

/**
 * Calculate and print estimated driving time based on distance and speed.
 *
 * Prompts the user for driving distance (in km) and speed (in km/h).
 * Computes travel time in hours, minutes, seconds, and milliseconds.
 * Prints the formatted travel time.
 *
 * Formulas used:
 *   travel_time_hours = distance_km / speed_kmh
 *   hours   = integer part of travel_time_hours
 *   minutes = integer part of ((travel_time_hours - hours) * 60)
 *   seconds = integer part of (((travel_time_hours - hours) * 60 - minutes) *
 * 60) milliseconds = ((((travel_time_hours - hours) * 60 - minutes) * 60 -
 * seconds) * 1000)
 */
void driving_time_calculator(void) {
  int distance_km, speed_kmh;
  double travel_time_hours;
  int hours, minutes, seconds, milliseconds;

  while (!read_int("Enter the driving distance (in km): ", &distance_km))
    ;
  while (!read_int("Enter the driving speed (in km/h): ", &speed_kmh))
    ;

  travel_time_hours = (double)distance_km / speed_kmh;
  hours = (int)travel_time_hours;
  minutes = (int)((travel_time_hours - hours) * 60);
  seconds = (int)((((travel_time_hours - hours) * 60) - minutes) * 60);
  milliseconds =
      (int)((((((travel_time_hours - hours) * 60) - minutes) * 60) - seconds) *
            1000);
  printf("Estimated travel time: %d %s, %d %s, %d %s, %d %s\n", hours,
         (hours == 1 ? "hour" : "hours"), minutes,
         (minutes == 1 ? "minute" : "minutes"), seconds,
         (seconds == 1 ? "second" : "seconds"), milliseconds,
         (milliseconds == 1 ? "millisecond" : "milliseconds"));
}

/**
 * Convert and print total seconds into hours, minutes, and seconds.
 *
 * Prompts the user for a total number of seconds, then calculates the
 * equivalent hours, minutes, and remaining seconds. Prints the result
 * in a human-readable format.
 *
 * Formulas used:
 *   hours   = total_seconds / 3600
 *   minutes = (total_seconds % 3600) / 60
 *   seconds = total_seconds % 60
 */
void seconds_to_hms(void) {
  int total_seconds;
  int hours, minutes, seconds;

  while (
      !read_int("Enter total seconds you want to convert: ", &total_seconds) ||
      total_seconds < 0) {
    if (total_seconds < 0) {
      printf("Please enter a non-negative value.\n");
    }
  }

  hours = total_seconds / 3600;
  minutes = (total_seconds % 3600) / 60;
  seconds = total_seconds % 60;

  printf("%d seconds is equivalent to %d hours, %d minutes, and %d seconds.\n",
         total_seconds, hours, minutes, seconds);
}
