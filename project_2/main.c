/**
 * @file main.c
 * @brief Interactive calculation menu for various utility functions
 *
 * Provides a menu-driven interface for arithmetic sequences, salary
 * calculations, driving time estimates, and time conversions.
 */

#include "helper.h"
#include <stdio.h>

int main(void) {
  int user_choice;
  int valid_choice = 0;

  do {
    printf("=== Calculation Menu ===\n");
    printf("1 - Calculate sum of arithmetic sequence\n");
    printf("2 - Salary calculator\n");
    printf("3 - Driving time calculator\n");
    printf("4 - Convert seconds to hours, minutes, and seconds\n");
    printf("========================\n");
    printf("Enter your choice (1-3): ");

    if (!read_int("Enter your choice (1-3): ", &user_choice)) {
      continue;
    }

    switch (user_choice) {
    case 1:
      sum_of_arithmetic_sequence();
      valid_choice = 1;
      break;
    case 2:
      salary_calculator();
      valid_choice = 1;
      break;
    case 3:
      driving_time_calculator();
      valid_choice = 1;
      break;
    case 4:
      seconds_to_hms();
      valid_choice = 1;
      break;
    default:
      printf("Invalid choice! Please choose 1-3.\n");
    }
  } while (!valid_choice);

  return 0;
}
