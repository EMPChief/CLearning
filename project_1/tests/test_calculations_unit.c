// Unit tests for project_1/test_calculations.c
// Testing library/framework: None detected in repo -> custom assert-based harness.
//
// Approach:
//   * Redirect stdin/stdout via POSIX facilities to drive interactive functions.
//   * Validate both prompts and computed results to cover core behaviors and edge paths.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_io_capture.h"
#include "test_asserts.h"

#include "../test_calculations.c"

static void normalize_newlines(char *s) {
  for (; *s; ++s) {
    if (*s == '\r') {
      *s = '\n';
    }
  }
}

static int test_calculate_two_grade_average_basic(void) {
  io_begin("80\n90\n");
  calculate_two_grade_average();
  char *out = io_end_and_read();
  normalize_newlines(out);
  ASSERT_CONTAINS(out, "Input first grade:");
  ASSERT_CONTAINS(out, "Input second grade:");
  ASSERT_CONTAINS(out, "The average grade is: 85.00");
  free(out);
  return 0;
}

static int test_calculate_two_grade_average_handles_zero(void) {
  io_begin("0\n100\n");
  calculate_two_grade_average();
  char *out = io_end_and_read();
  normalize_newlines(out);
  ASSERT_CONTAINS(out, "The average grade is: 50.00");
  free(out);
  return 0;
}

static int test_calculate_birth_year_basic(void) {
  io_begin("2025\n30\n");
  calculate_birth_year();
  char *out = io_end_and_read();
  normalize_newlines(out);
  ASSERT_CONTAINS(out, "You were born in: 1995");
  free(out);
  return 0;
}

static int test_calculate_rectangle_area_basic(void) {
  io_begin("7\n5\n");
  calculate_rectangle_area();
  char *out = io_end_and_read();
  normalize_newlines(out);
  ASSERT_CONTAINS(out, "The area of the rectangle is: 35");
  free(out);
  return 0;
}

static int test_calculate_rectangle_area_zero_dimension(void) {
  io_begin("0\n12\n");
  calculate_rectangle_area();
  char *out = io_end_and_read();
  normalize_newlines(out);
  ASSERT_CONTAINS(out, "The area of the rectangle is: 0");
  free(out);
  return 0;
}

static int test_calculate_rectangle_circle_area_basic(void) {
  io_begin("3.5\n2\n2\n");
  calculate_rectangle_circle_area();
  char *out = io_end_and_read();
  normalize_newlines(out);
  ASSERT_CONTAINS(out, "Rectangle area: 7.00");
  ASSERT_CONTAINS(out, "Circle area: 12.57");
  free(out);
  return 0;
}

static int test_calculate_rectangle_perimeter_basic(void) {
  io_begin("3.5\n2.0\n");
  calculate_rectangle_perimeter();
  char *out = io_end_and_read();
  normalize_newlines(out);
  ASSERT_CONTAINS(out, "Rectangle perimeter: 11.00");
  free(out);
  return 0;
}

static int test_calculate_three_grade_average_basic(void) {
  io_begin("70 80 90\n");
  calculate_three_grade_average();
  char *out = io_end_and_read();
  normalize_newlines(out);
  ASSERT_CONTAINS(out, "The average grade is: 80.00");
  free(out);
  return 0;
}

static int test_temperature_converter_c_to_f(void) {
  io_begin("1\n100\n");
  temperature_converter();
  char *out = io_end_and_read();
  normalize_newlines(out);
  ASSERT_CONTAINS(out, "100.00 Celsius is 212.00 Fahrenheit");
  free(out);
  return 0;
}

static int test_temperature_converter_f_to_c(void) {
  io_begin("2\n32\n");
  temperature_converter();
  char *out = io_end_and_read();
  normalize_newlines(out);
  ASSERT_CONTAINS(out, "32.00 Fahrenheit is 0.00 Celsius");
  free(out);
  return 0;
}

static int test_temperature_converter_invalid_choice(void) {
  io_begin("3\n");
  temperature_converter();
  char *out = io_end_and_read();
  normalize_newlines(out);
  ASSERT_CONTAINS(out, "Invalid choice\! Please run the program again and choose 1 or 2.");
  free(out);
  return 0;
}

static int test_swap_two_floating_numbers(void) {
  io_begin("1.5\n-2.25\n");
  swap_two_floating_numbers();
  char *out = io_end_and_read();
  normalize_newlines(out);
  ASSERT_CONTAINS(out, "First number before swap: 1.500000");
  ASSERT_CONTAINS(out, "Second number before swap: -2.250000");
  ASSERT_CONTAINS(out, "First number after swap: -2.250000");
  ASSERT_CONTAINS(out, "Second number after swap: 1.500000");
  free(out);
  return 0;
}

static int test_math_operation_learn_outputs(void) {
  io_begin("");
  math_operation_learn();
  char *out = io_end_and_read();
  normalize_newlines(out);
  ASSERT_CONTAINS(out, "The first term is: 1");
  ASSERT_CONTAINS(out, "The common difference is: 2.00");
  ASSERT_CONTAINS(out, "nth_term = 1 + (9.00 - 1) * 2.00 = 17.00");
  ASSERT_CONTAINS(out, "Therefore, the 9.00-th term of the arithmetic sequence is: 17.00");
  free(out);
  return 0;
}

int main(void) {
  RUN_TEST(test_calculate_two_grade_average_basic);
  RUN_TEST(test_calculate_two_grade_average_handles_zero);
  RUN_TEST(test_calculate_birth_year_basic);
  RUN_TEST(test_calculate_rectangle_area_basic);
  RUN_TEST(test_calculate_rectangle_area_zero_dimension);
  RUN_TEST(test_calculate_rectangle_circle_area_basic);
  RUN_TEST(test_calculate_rectangle_perimeter_basic);
  RUN_TEST(test_calculate_three_grade_average_basic);
  RUN_TEST(test_temperature_converter_c_to_f);
  RUN_TEST(test_temperature_converter_f_to_c);
  RUN_TEST(test_temperature_converter_invalid_choice);
  RUN_TEST(test_swap_two_floating_numbers);
  RUN_TEST(test_math_operation_learn_outputs);

  TEST_SUMMARY();
}