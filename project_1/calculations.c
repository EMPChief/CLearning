#include <stdio.h>
#include "calculations.h"

#define PI 3.141592653589793

void calculate_two_grade_average(void) {
  int grade_one, grade_two;
  double average;

  printf("Input first grade: ");
  scanf("%d", &grade_one);
  printf("Input second grade: ");
  scanf("%d", &grade_two);

  average = (grade_one + grade_two) / 2.0;
  printf("The average grade is: %.2f\n", average);
}

void calculate_birth_year(void) {
  int current_year, age, birth_year;

  printf("Input current year: ");
  scanf("%d", &current_year);
  printf("Input your age: ");
  scanf("%d", &age);

  birth_year = current_year - age;
  printf("You were born in: %d\n", birth_year);
}

void calculate_rectangle_area(void) {
  int length, height, area;

  printf("Input rectangle length: ");
  scanf("%d", &length);
  printf("Input rectangle height: ");
  scanf("%d", &height);

  area = length * height;
  printf("The area of the rectangle is: %d\n", area);
}

void calculate_rectangle_circle_area(void) {
  float rectangle_length, rectangle_width, rectangle_area;
  float circle_radius, circle_area;

  printf("Input rectangle length: ");
  scanf("%f", &rectangle_length);
  printf("Input rectangle width: ");
  scanf("%f", &rectangle_width);
  printf("Input circle radius: ");
  scanf("%f", &circle_radius);

  rectangle_area = rectangle_length * rectangle_width;
  circle_area = PI * circle_radius * circle_radius;

  printf("Rectangle area: %.2f\n", rectangle_area);
  printf("Circle area: %.2f\n", circle_area);
}

void calculate_rectangle_perimeter(void) {
  double length, width, perimeter;

  printf("Input rectangle length: ");
  scanf("%lf", &length);
  printf("Input rectangle width: ");
  scanf("%lf", &width);

  perimeter = 2 * (length + width);
  printf("Rectangle perimeter: %.2lf\n", perimeter);
}

void calculate_three_grade_average(void) {
  int grade_one, grade_two, grade_three;
  double average;

  printf("Input three grades separated by spaces: ");
  scanf("%d %d %d", &grade_one, &grade_two, &grade_three);

  average = (grade_one + grade_two + grade_three) / 3.0;
  printf("The average grade is: %.2f\n", average);
}

void temperature_converter(void) {
  double celsius, fahrenheit, user_choice, result;
  printf("Enter 1 to convert Celcius to Fahrenheit or 2 to convert Fahrenheit to Celcius: ");
  scanf("%lf", &user_choice);

  if (user_choice == 1) {
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    result = (celsius * 9.0 / 5.0) + 32.0;
    printf("%.2lf Celsius is %.2lf Fahrenheit\n", celsius, result);
  } else if (user_choice == 2) {
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    result = (fahrenheit - 32.0) * 5.0 / 9.0;
    printf("%.2lf Fahrenheit is %.2lf Celsius\n", fahrenheit, result);
  } else {
    printf("Invalid choice! Please run the program again and choose 1 or 2.\n");
  }
}

void swap_two_floating_numbers(void) {
  float a, b, temp;
  printf("Enter first number: ");
  scanf("%f", &a);
  printf("Enter second number: ");
  scanf("%f", &b);
  printf("a before swap: %f\n", a);
  printf("b before swap: %f\n", b);
  temp = a;
  a = b;
  b = temp;
  printf("a after swap: %f\n", a);
  printf("b after swap: %f\n", b);
}
