// Implementation file for calculation functions - C learning exercises
#include "calculations.h"
#include <stdio.h>

#define PI 3.141592653589793

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
 * Calculate and print the average of two grades entered by the user.
 *
 * Prompts the user for two integer grades, validates input,
 * and prints the average formatted to two decimal places.
 */
void calculate_two_grade_average(void) {
  int grade_one;
  int grade_two;
  double grade_average;

  if (!read_int("Input first grade: ", &grade_one)) {
    return;
  }
  if (!read_int("Input second grade: ", &grade_two)) {
    return;
  }

  grade_average = (grade_one + grade_two) / 2.0;
  printf("The average grade is: %.2f\n", grade_average);
}

/**
 * Calculate and print the birth year based on the user's current age.
 *
 * Prompts the user for the current year and their age, validates input,
 * and computes the birth year as (current year - age).
 */
void calculate_birth_year(void) {
  int current_year;
  int current_age;
  int birth_year;

  if (!read_int("Input current year: ", &current_year)) {
    return;
  }
  if (!read_int("Input your age: ", &current_age)) {
    return;
  }

  birth_year = current_year - current_age;
  printf("You were born in: %d\n", birth_year);
}

/**
 * Calculate and print the area of a rectangle.
 *
 * Prompts the user for the length and height of a rectangle, validates input,
 * and prints the area as an integer.
 */
void calculate_rectangle_area(void) {
  int rectangle_length;
  int rectangle_height;
  int rectangle_area;

  if (!read_int("Input rectangle length: ", &rectangle_length)) {
    return;
  }
  if (!read_int("Input rectangle height: ", &rectangle_height)) {
    return;
  }

  rectangle_area = rectangle_length * rectangle_height;
  printf("The area of the rectangle is: %d\n", rectangle_area);
}

/**
 * Calculate and print the areas of a rectangle and a circle.
 *
 * Prompts the user for rectangle length, rectangle width, and circle radius,
 * validates input, and prints the calculated areas of both shapes.
 */
void calculate_rectangle_circle_area(void) {
  float rectangle_length;
  float rectangle_width;
  float rectangle_area;
  float circle_radius;
  float circle_area;

  if (!read_float("Input rectangle length: ", &rectangle_length)) {
    return;
  }
  if (!read_float("Input rectangle width: ", &rectangle_width)) {
    return;
  }
  if (!read_float("Input circle radius: ", &circle_radius)) {
    return;
  }

  rectangle_area = rectangle_length * rectangle_width;
  circle_area = PI * circle_radius * circle_radius;

  printf("Rectangle area: %.2f\n", rectangle_area);
  printf("Circle area: %.2f\n", circle_area);
}

/**
 * Calculate and print the perimeter of a rectangle.
 *
 * Prompts the user for rectangle length and width, validates input,
 * and prints the perimeter formatted to two decimal places.
 */
void calculate_rectangle_perimeter(void) {
  double rectangle_length;
  double rectangle_width;
  double rectangle_perimeter;

  if (!read_double("Input rectangle length: ", &rectangle_length)) {
    return;
  }
  if (!read_double("Input rectangle width: ", &rectangle_width)) {
    return;
  }

  rectangle_perimeter = 2 * (rectangle_length + rectangle_width);
  printf("Rectangle perimeter: %.2lf\n", rectangle_perimeter);
}

/**
 * Calculate and print the average of three grades entered by the user.
 *
 * Prompts the user for three integer grades separated by spaces,
 * validates input, and prints the average formatted to two decimal places.
 */
void calculate_three_grade_average(void) {
  int grade_one;
  int grade_two;
  int grade_three;
  double grade_average;

  if (!read_three_ints("Input three grades separated by spaces: ", &grade_one,
                       &grade_two, &grade_three)) {
    return;
  }

  grade_average = (grade_one + grade_two + grade_three) / 3.0;
  printf("The average grade is: %.2f\n", grade_average);
}

/**
 * Convert temperatures between Celsius and Fahrenheit.
 *
 * Prompts the user to choose between converting Celsius → Fahrenheit or
 * Fahrenheit → Celsius, validates input, and prints the converted value.
 */
void temperature_converter(void) {
  double celsius_temperature;
  double fahrenheit_temperature;
  double user_choice;
  double conversion_result;

  if (!read_double("Enter 1 to convert Celsius to Fahrenheit or 2 to convert "
                   "Fahrenheit to Celsius: ",
                   &user_choice)) {
    return;
  }

  if (user_choice == 1) {
    if (!read_double("Enter temperature in Celsius: ", &celsius_temperature)) {
      return;
    }
    conversion_result = (celsius_temperature * 9.0 / 5.0) + 32.0;
    printf("%.2lf Celsius is %.2lf Fahrenheit\n", celsius_temperature,
           conversion_result);
  } else if (user_choice == 2) {
    if (!read_double("Enter temperature in Fahrenheit: ",
                     &fahrenheit_temperature)) {
      return;
    }
    conversion_result = (fahrenheit_temperature - 32.0) * 5.0 / 9.0;
    printf("%.2lf Fahrenheit is %.2lf Celsius\n", fahrenheit_temperature,
           conversion_result);
  } else {
    printf("Invalid choice! Please run the program again and choose 1 or 2.\n");
  }
}

/**
 * Swap and print two floating-point numbers.
 *
 * Prompts the user for two floating-point numbers, validates input,
 * swaps their values, and prints the numbers before and after swapping.
 */
void swap_two_floating_numbers(void) {
  float first_number;
  float second_number;
  float temporary_variable;

  if (!read_float("Enter first number: ", &first_number)) {
    return;
  }
  if (!read_float("Enter second number: ", &second_number)) {
    return;
  }

  printf("First number before swap: %f\n", first_number);
  printf("Second number before swap: %f\n", second_number);

  temporary_variable = first_number;
  first_number = second_number;
  second_number = temporary_variable;

  printf("First number after swap: %f\n", first_number);
  printf("Second number after swap: %f\n", second_number);
}

/**
 * Demonstrate arithmetic sequence calculations.
 *
 * Calculates the n-th term of an arithmetic sequence given a first term,
 * common difference, and term position (currently hardcoded).
 * Prints the sequence details and step-by-step formula derivation.
 */
void math_operation_learn(void) {
  double common_difference;
  int first_term;
  double term_position;
  double nth_term;

  common_difference = 2;
  first_term = 1;
  term_position = 9;
  // Uncomment to enable interactive input
  // printf("Enter the term position, first term, and c...");
  // scanf("%lf", &term_positi, &first_term);
  // scanf("%lf", &common_difference);

  nth_term = first_term + (term_position - 1) * common_difference;

  printf("We are working with an arithmetic sequence.\n");
  printf("The first term is: %d\n", first_term);
  printf("The common difference is: %.2lf\n", common_difference);
  printf("We want to find the %.2lf-th term.\n", term_position);
  printf("Using the formula nth_term = first_term + (term_position - 1) * "
         "common_difference:\n");
  printf("nth_term = %d + (%.2lf - 1) * %.2lf = %.2lf\n", first_term,
         term_position, common_difference, nth_term);
  printf("Therefore, the %.2lf-th term of the arithmetic sequence is: %.2lf\n",
         term_position, nth_term);
}
