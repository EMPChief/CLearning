// Implementation file for calculation functions - C learning exercises
#include "calculations.h"
#include <stdio.h>

#define PI 3.141592653589793

static int read_int(const char *prompt, int *value) {
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

static int read_float(const char *prompt, float *value) {
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

static int read_double(const char *prompt, double *value) {
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

static int read_three_ints(const char *prompt, int *val1, int *val2, int *val3) {
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

void calculate_two_grade_average(void) {
  /**
   * Read two grades from input, calculate their average, and print the result.
   *
   * Prompts the user for two integer grades, computes their average as a double
   * to ensure precision, and displays the result formatted with two decimals.
   */
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

void calculate_birth_year(void) {
  /**
   * Compute birth year from current year and age.
   *
   * Prompts the user for the current year and their age, then calculates and
   * prints the year they were born.
   */
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

void calculate_rectangle_area(void) {
  /**
   * Compute and print the area of a rectangle with integer dimensions.
   *
   * Reads the length and height as integers, multiplies them, and prints
   * the resulting area.
   */
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

void calculate_rectangle_circle_area(void) {
  /**
   * Compute and print the areas of a rectangle and a circle.
   *
   * Prompts the user for rectangle length, width, and circle radius. Calculates
   * the rectangle area as length × width, the circle area as π × r², and prints
   * both results with two decimal places.
   */
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

void calculate_rectangle_perimeter(void) {
  /**
   * Compute and print the perimeter of a rectangle.
   *
   * Reads rectangle length and width as doubles, computes perimeter using
   * 2 × (length + width), and prints the result with two decimals.
   */
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

void calculate_three_grade_average(void) {
  /**
   * Compute and print the average of three grades.
   *
   * Reads three integer grades from input, calculates their average as a double
   * to ensure floating-point precision, and displays the result.
   */
  int grade_one;
  int grade_two;
  int grade_three;
  double grade_average;

  if (!read_three_ints("Input three grades separated by spaces: ", &grade_one, &grade_two, &grade_three)) {
    return;
  }

  grade_average = (grade_one + grade_two + grade_three) / 3.0;
  printf("The average grade is: %.2f\n", grade_average);
}

void temperature_converter(void) {
  /**
   * Convert between Celsius and Fahrenheit temperatures.
   *
   * Prompts the user to choose conversion direction:
   *   1 → Celsius to Fahrenheit
   *   2 → Fahrenheit to Celsius
   * Based on the choice, asks for the temperature value, performs the
   * conversion, and prints the result with two decimal places.
   */
  double celsius_temperature;
  double fahrenheit_temperature;
  double user_choice;
  double conversion_result;

  if (!read_double("Enter 1 to convert Celsius to Fahrenheit or 2 to convert Fahrenheit to Celsius: ", &user_choice)) {
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
    if (!read_double("Enter temperature in Fahrenheit: ", &fahrenheit_temperature)) {
      return;
    }
    conversion_result = (fahrenheit_temperature - 32.0) * 5.0 / 9.0;
    printf("%.2lf Fahrenheit is %.2lf Celsius\n", fahrenheit_temperature,
           conversion_result);
  } else {
    printf("Invalid choice! Please run the program again and choose 1 or 2.\n");
  }
}

void swap_two_floating_numbers(void) {
  /**
   * Read two floating-point numbers, swap them, and print before/after values.
   *
   * Prompts the user to enter two floats, exchanges their values using a
   * temporary variable, and displays the values before and after the swap.
   */
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

void math_operation_learn(void) {
  /**
   * Demonstrates how to compute the nth term of an arithmetic sequence.
   *
   * An arithmetic sequence is a sequence of numbers where each term
   * after the first is obtained by adding a fixed value (the common
   * difference) to the previous term.
   *
   * Formula:
   *     nth_term = first_term + (term_position - 1) * common_difference
   *
   * Where:
   *     - first_term: the first number in the sequence (a₁)
   *     - common_difference: the fixed difference added each step (d)
   *     - term_position: the position of the term you want to calculate (n)
   *     - nth_term: the resulting value at position n
   *
   * Example:
   *     If first_term = 1, common_difference = 2, and term_position = 9,
   *     the 9th term is:
   *         nth_term = 1 + (9 - 1) * 2 = 17
   *
   * Notes:
   * - This function comes with default values so it can run without input.
   * - Uncomment the scanf lines to allow interactive input from the user.
   */

  double common_difference;
  int first_term;
  double term_position;
  double nth_term;

  // Default example values
  common_difference = 2;
  first_term = 1;
  term_position = 9;

  // Uncomment to enable interactive input
  // printf("Enter the term position, first term, and common difference
  // separated by spaces: "); scanf("%lf", &term_position); scanf("%d",
  // &first_term); scanf("%lf", &common_difference);

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
