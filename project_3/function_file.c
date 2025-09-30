#include "helper.h"
#include <stdio.h>

int read_int(const char *prompt, int *value) {
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

int read_float(const char *prompt, float *value) {
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

int read_double(const char *prompt, double *value) {
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

int read_three_ints(const char *prompt, int *val1, int *val2, int *val3) {
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

void how_this_work(void) {
  printf("This program demonstrates modular programming in C.\n");
  printf("It consists of multiple files, each handling specific tasks.\n");
  printf("The main file coordinates the execution flow.\n");
  printf("Header files declare functions and macros for reuse.\n");
  printf("Source files implement the declared functions.\n");
  printf("This structure enhances code organization and maintainability.\n");
}
