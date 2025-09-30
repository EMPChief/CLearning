#include "calculations.h"
#include <stdio.h>

/**
 * Main program for C learning exercises with interactive menu system.
 *
 * Displays a menu of calculation exercises and executes the selected function.
 * Continues prompting until the user enters a valid choice (1-8), then runs
 * the corresponding calculation function and exits.
 *
 * @return 0 on successful completion
 */
int main(void) {
  int user_choice;
  int valid_choice = 0;

  do {
    printf("=== Calculation Menu ===\n");
    printf("1 - Average of two grades\n");
    printf("2 - Birth year calculator\n");
    printf("3 - Rectangle area\n");
    printf("4 - Rectangle and circle area\n");
    printf("5 - Rectangle perimeter\n");
    printf("6 - Average of three grades\n");
    printf("7 - Temperature converter\n");
    printf("8 - Swap two floating numbers\n");
    printf("9 - Math operation learn\n");
    printf("========================\n");

    if (!read_int("Enter your choice (1-8): ", &user_choice)) {
      continue;
    }

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
    case 9:
      math_operation_learn();
      valid_choice = 1;
      break;
    default:
      printf("Invalid choice! Please choose 1-8.\n");
    }
  } while (!valid_choice);

  return 0;
}
