// Implementation file for calculation functions - C learning exercises
#include "calculations.h"
#include <stdio.h>

// Mathematical constant for circle calculations
#define PI 3.141592653589793

// Function to calculate average of two grades (demonstrates basic scanf and
// arithmetic)
void calculate_two_grade_average(void) {
  int grade_one;        // First grade input
  int grade_two;        // Second grade input
  double grade_average; // Result stored as double for precision

  // Get user input for both grades
  printf("Input first grade: ");
  scanf("%d", &grade_one);
  printf("Input second grade: ");
  scanf("%d", &grade_two);

  // Calculate average using 2.0 to ensure floating-point division
  grade_average = (grade_one + grade_two) / 2.0;
  printf("The average grade is: %.2f\n", grade_average);
}

// Function to calculate birth year from current year and age
void calculate_birth_year(void) {
  int current_year; // Current calendar year
  int current_age;  // User's current age
  int birth_year;   // Calculated birth year

  // Get input from user
  printf("Input current year: ");
  scanf("%d", &current_year);
  printf("Input your age: ");
  scanf("%d", &current_age);

  // Simple subtraction to find approximate birth year
  birth_year = current_year - current_age;
  printf("You were born in: %d\n", birth_year);
}

// Function to calculate rectangle area using integer values
void calculate_rectangle_area(void) {
  int rectangle_length; // Length of rectangle
  int rectangle_height; // Height of rectangle
  int rectangle_area;   // Calculated area (length × height)

  // Get rectangle dimensions from user
  printf("Input rectangle length: ");
  scanf("%d", &rectangle_length);
  printf("Input rectangle height: ");
  scanf("%d", &rectangle_height);

  // Calculate area using basic multiplication
  rectangle_area = rectangle_length * rectangle_height;
  printf("The area of the rectangle is: %d\n", rectangle_area);
}

// Function to calculate both rectangle and circle areas using float values
void calculate_rectangle_circle_area(void) {
  float rectangle_length; // Length of rectangle
  float rectangle_width;  // Width of rectangle
  float rectangle_area;   // Calculated rectangle area
  float circle_radius;    // Radius of circle
  float circle_area;      // Calculated circle area

  // Get dimensions for both shapes from user
  printf("Input rectangle length: ");
  scanf("%f", &rectangle_length);
  printf("Input rectangle width: ");
  scanf("%f", &rectangle_width);
  printf("Input circle radius: ");
  scanf("%f", &circle_radius);

  // Calculate areas using appropriate formulas
  rectangle_area = rectangle_length * rectangle_width; // Area = length × width
  circle_area = PI * circle_radius * circle_radius;    // Area = π × r²

  // Display both results with 2 decimal places
  printf("Rectangle area: %.2f\n", rectangle_area);
  printf("Circle area: %.2f\n", circle_area);
}

// Function to calculate rectangle perimeter using double precision values
void calculate_rectangle_perimeter(void) {
  double rectangle_length;    // Length of rectangle (double precision)
  double rectangle_width;     // Width of rectangle (double precision)
  double rectangle_perimeter; // Calculated perimeter

  // Get rectangle dimensions with double precision
  printf("Input rectangle length: ");
  scanf("%lf", &rectangle_length); // %lf for double input
  printf("Input rectangle width: ");
  scanf("%lf", &rectangle_width);

  // Calculate perimeter: 2 × (length + width)
  rectangle_perimeter = 2 * (rectangle_length + rectangle_width);
  printf("Rectangle perimeter: %.2lf\n",
         rectangle_perimeter); // %lf for double output
}

// Function to calculate average of three grades (demonstrates casting and
// multiple input)
void calculate_three_grade_average(void) {
  int grade_one;   // First grade
  int grade_two;   // Second grade
  int grade_three; // Third grade
  double
      grade_average; // Average result (demonstrates casting from int to double)

  // Read three grades in a single scanf call
  printf("Input three grades separated by spaces: ");
  scanf("%d %d %d", &grade_one, &grade_two, &grade_three);

  // Calculate average - division by 3.0 ensures floating-point result
  grade_average = (grade_one + grade_two + grade_three) / 3.0;
  printf("The average grade is: %.2f\n", grade_average);
}

// Function to convert between Celsius and Fahrenheit temperatures
void temperature_converter(void) {
  double celsius_temperature;    // Temperature in Celsius
  double fahrenheit_temperature; // Temperature in Fahrenheit
  double user_choice;            // User's conversion choice (1 or 2)
  double conversion_result;      // Final converted temperature

  // Get conversion direction from user
  printf("Enter 1 to convert Celsius to Fahrenheit or 2 to convert Fahrenheit "
         "to Celsius: ");
  scanf("%lf", &user_choice);

  // Perform conversion based on user choice
  if (user_choice == 1) {
    // Celsius to Fahrenheit conversion
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius_temperature);
    conversion_result =
        (celsius_temperature * 9.0 / 5.0) + 32.0; // Formula: (C × 9/5) + 32
    printf("%.2lf Celsius is %.2lf Fahrenheit\n", celsius_temperature,
           conversion_result);
  } else if (user_choice == 2) {
    // Fahrenheit to Celsius conversion
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit_temperature);
    conversion_result =
        (fahrenheit_temperature - 32.0) * 5.0 / 9.0; // Formula: (F - 32) × 5/9
    printf("%.2lf Fahrenheit is %.2lf Celsius\n", fahrenheit_temperature,
           conversion_result);
  } else {
    // Invalid choice handling
    printf("Invalid choice! Please run the program again and choose 1 or 2.\n");
  }
}

// Function to demonstrate variable swapping using a temporary variable
void swap_two_floating_numbers(void) {
  float first_number;       // First number to swap
  float second_number;      // Second number to swap
  float temporary_variable; // Temporary storage for swapping process

  // Get two numbers from user
  printf("Enter first number: ");
  scanf("%f", &first_number);
  printf("Enter second number: ");
  scanf("%f", &second_number);

  // Display original values
  printf("First number before swap: %f\n", first_number);
  printf("Second number before swap: f\n", second_number);

  // Perform the swap using three-step process
  temporary_variable = first_number;  // Step 1: Save first number
  first_number = second_number;       // Step 2: Move second to first
  second_number = temporary_variable; // Step 3: Move saved value to second

  // Display swapped values
  printf("First number after swap: %f\n", first_number);
  printf("Second number after swap: %f\n", second_number);
}

// Function to calculate nth term of an arithmetic sequence (demonstrates math
// operations)
void math_operation_learn(void) {
  double common_difference; // Difference between consecutive terms
  int first_term;           // Starting value of the sequence
  double term_position;     // Which term we want to calculate (nth term)
  double nth_term;          // Result of the calculation

  // Example values in comments for reference:
  common_difference = 2; // Difference between consecutive terms
  first_term = 1;        // Starting value of the sequence
  term_position = 9;     // Which term we want to calculate

  // Get sequence parameters from user
  printf("Enter the term position, first term, and common difference separated "
         "by spaces: ");
  // scanf("%lf", &term_position);     // Which term to find
  // scanf("%d", &first_term);         // Starting term
  // scanf("%lf", &common_difference); // Difference between terms

  // Apply arithmetic sequence formula: nth_term = a + (n-1) × d
  nth_term = first_term + (term_position - 1) * common_difference;

  // Display detailed explanation of the calculation
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
