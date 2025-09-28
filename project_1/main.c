#include <stdio.h>
#include "calculations.h"

int main(void) {
  int user_choice;
  int valid_choice = 0;

  do {
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
