// Main program for C learning exercises - interactive menu system
#include "calculations.h"
#include <stdio.h>

int main(void) {
  int user_choice;        // Store user's menu selection
  int valid_choice = 0;   // Flag to control menu loop (0 = invalid, 1 = valid)

  // Main menu loop - continues until user makes a valid selection
  do {
    // Display menu options to user
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
    scanf("%d", &user_choice);  // Read user's menu choice

    // Execute the selected function based on user choice
    switch (user_choice) {
    case 1:
      calculate_two_grade_average();    // Basic average calculation
      valid_choice = 1;                 // Mark as valid to exit loop
      break;
    case 2:
      calculate_birth_year();           // Year calculation from age
      valid_choice = 1;
      break;
    case 3:
      calculate_rectangle_area();       // Simple area calculation
      valid_choice = 1;
      break;
    case 4:
      calculate_rectangle_circle_area(); // Multiple shape areas
      valid_choice = 1;
      break;
    case 5:
      calculate_rectangle_perimeter();  // Perimeter using doubles
      valid_choice = 1;
      break;
    case 6:
      calculate_three_grade_average();  // Three grade average with casting
      valid_choice = 1;
      break;
    case 7:
      temperature_converter();          // Celsius/Fahrenheit conversion
      valid_choice = 1;
      break;
    case 8:
      swap_two_floating_numbers();      // Variable swapping demonstration
      valid_choice = 1;
      break;
    case 9:
      math_operation_learn();           // Arithmetic sequence calculation
      valid_choice = 1;
      break;
    default:
      printf("Invalid choice! Please choose 1-8.\n");  // Error message for invalid input
    }
  } while (!valid_choice);  // Continue loop until valid choice is made

  return 0;  // Program completed successfully
}
