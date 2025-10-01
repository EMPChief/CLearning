#include "helper.h"
#include <stdio.h>

int main(void) {
  int user_choice;
  int valid_choice = 0;

  do {
    printf("=== Calculation Menu ===\n");
    printf("1 - Calculate sum of arithmetic sequence\n");
    printf("2 - Salary calculator\n");
    printf("========================\n");
    printf("Enter your choice (1): ");

    if (!read_int("Enter your choice (1-8): ", &user_choice)) {
      continue;
    }

    switch (user_choice) {
    case 1:
      sum_of_arithemetic_sequence();
      valid_choice = 1;
      break;
    case 2:
      salary_calculator();
      valid_choice = 1;
      break;
    default:
      printf("Invalid choice! Please choose 1-9.\n");
      printf("1 - Calculate sum of arithmetic sequence\n");
    }
  } while (!valid_choice);

  return 0;
}
