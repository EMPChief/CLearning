#include "helper.h"
#include <stdio.h>

int main(void) {
  int user_choice;
  int valid_choice = 0;

  do {
    printf("=== Modular Programming Demo ===\n");
    printf("1 - Explain modular programming\n");
    printf("=================================\n");
    printf("Enter your choice (1): ");

    if (!read_int("Enter your choice (1): ", &user_choice)) {
      continue;
    }

    switch (user_choice) {
    case 1:
      explain_modular_programming();
      valid_choice = 1;
      break;
    default:
      printf("Invalid choice! Please choose 1.\n");
    }
  } while (!valid_choice);

  return 0;
}
