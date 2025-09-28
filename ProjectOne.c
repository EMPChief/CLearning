#include <stdio.h>
#define PI 3.141592653589793
// Function declarations
void calculate_two_grade_average(void);
void calculate_birth_year(void);
void calculate_rectangle_area(void);
void calculate_rectangle_circle_area(void);
void calculate_rectangle_perimeter(void);
void calculate_three_grade_average(void);
void temperature_converter(void);
void swap_two_floating_numbers(void);

int main(void) {
  int user_choice;
  int valid_choice = 0;

  do {
    // Show user a menu of available calculations
    printf("=== Calculation Menu ===\n");
    printf("1 - Average of two grades (learning about scanf)\n");
    printf("2 - Birth year calculator (learn a bit more about scanf)\n");
    printf("3 - Rectangle area (learning about rectangle)\n");
    printf("4 - Rectangle and circle area\n");
    printf("5 - Rectangle perimeter (learning about double)\n");
    printf("6 - Average of iithree grades (learning about casting)\n");
    printf("7 - Convert Celsius Degree to Fahrenheit Degrees\n");
    printf("8 - Swaping 2 floating numbers\n");
    printf("========================\n");
    printf("Enter your choice (1-8): ");
    scanf("%d", &user_choice);

    // Decide which calculation to run based on user choice
    switch (user_choice) {
    case 1:
      calculate_two_grade_average();
      valid_choice = 1;
      break;
    case 2:
      calculate_birth_year();
      valid_choice = 1;
      break;
    case 3:
      calculate_rectangle_area();
      valid_choice = 1;
      break;
    case 4:
      calculate_rectangle_circle_area();
      valid_choice = 1;
      break;
    case 5:
      calculate_rectangle_perimeter();
      valid_choice = 1;
      break;
    case 6:
      calculate_three_grade_average();
      valid_choice = 1;
      break;
    case 7:
      temperature_converter();
      valid_choice = 1;
      break;
    case 8:
      swap_two_floating_numbers();
      valid_choice = 1;
      break;
    default:
      printf("Invalid choice! Please choose 1-8.\n");
    }
  } while (!valid_choice);

  return 0;
}

// ---- Function definitions ----

void calculate_two_grade_average(void) {
  // Calculate the average of two grades
  int grade_one, grade_two;
  double average;

  printf("Input first grade: ");
  scanf("%d", &grade_one);
  printf("Input second grade: ");
  scanf("%d", &grade_two);

  // Cast to double by dividing by 2.0
  average = (grade_one + grade_two) / 2.0;
  printf("The average grade is: %.2f\n", average);
}

void calculate_birth_year(void) {
  // Calculate year of birth from current year and age
  int current_year, age, birth_year;

  printf("Input current year: ");
  scanf("%d", &current_year);
  printf("Input your age: ");
  scanf("%d", &age);

  birth_year = current_year - age;
  printf("You were born in: %d\n", birth_year);
}

void calculate_rectangle_area(void) {
  // Calculate the area of a rectangle
  int length, height, area;

  printf("Input rectangle length: ");
  scanf("%d", &length);
  printf("Input rectangle height: ");
  scanf("%d", &height);

  area = length * height;
  printf("The area of the rectangle is: %d\n", area);
}

void calculate_rectangle_circle_area(void) {
  // Calculate areas of both a rectangle and a circle
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
  // Calculate the perimeter of a rectangle
  double length, width, perimeter;

  printf("Input rectangle length: ");
  scanf("%lf", &length);
  printf("Input rectangle width: ");
  scanf("%lf", &width);

  perimeter = 2 * (length + width);
  printf("Rectangle perimeter: %.2lf\n", perimeter);
}

void calculate_three_grade_average(void) {
  // Calculate average of three grades, demonstrating casting
  int grade_one, grade_two, grade_three;
  double average;

  printf("Input three grades separated by spaces: ");
  scanf("%d %d %d", &grade_one, &grade_two, &grade_three);

  // Casting one operand ensures a double result
  average = (grade_one + grade_two + grade_three) / 3.0;
  printf("The average grade is: %.2f\n", average);
}

void temperature_converter(void) {
  double celsius, fahrenheit, user_choice, result;
  printf("Enter 1 to convert Celcius to Fahrenheit or 2 to convert Fahrenheit "
         "to Celcius: ");
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
