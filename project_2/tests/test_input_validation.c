/**
 * @file test_input_validation.c
 * @brief Unit tests for input validation functions
 */

#include "../unity/unity.h"
#include <stdio.h>
#include <string.h>

#define UNITY_BEGIN() UnityBegin(__FILE__)
#define UNITY_END() (UnityEnd(), Unity_tests_failed)

int read_int(const char *prompt, int *value);
int read_float(const char *prompt, float *value);
int read_double(const char *prompt, double *value);
int read_three_ints(const char *prompt, int *first_value, int *second_value, int *third_value);

void setUp(void) {}

void tearDown(void) {}

void test_read_int_valid_input(void) {
  int value;
  FILE *fp = fopen("/tmp/test_input.txt", "w");
  fprintf(fp, "42\n");
  fclose(fp);
  
  freopen("/tmp/test_input.txt", "r", stdin);
  int result = read_int("Enter number: ", &value);
  freopen("/dev/tty", "r", stdin);
  
  TEST_ASSERT(result == 1);
  TEST_ASSERT(value == 42);
}

void test_read_float_valid_input(void) {
  float value;
  FILE *fp = fopen("/tmp/test_input.txt", "w");
  fprintf(fp, "3.14\n");
  fclose(fp);
  
  freopen("/tmp/test_input.txt", "r", stdin);
  int result = read_float("Enter number: ", &value);
  freopen("/dev/tty", "r", stdin);
  
  TEST_ASSERT(result == 1);
  TEST_ASSERT(value > 3.13 && value < 3.15);
}

void test_read_double_valid_input(void) {
  double value;
  FILE *fp = fopen("/tmp/test_input.txt", "w");
  fprintf(fp, "2.71828\n");
  fclose(fp);
  
  freopen("/tmp/test_input.txt", "r", stdin);
  int result = read_double("Enter number: ", &value);
  freopen("/dev/tty", "r", stdin);
  
  TEST_ASSERT(result == 1);
  TEST_ASSERT(value > 2.71 && value < 2.72);
}

void test_read_three_ints_valid_input(void) {
  int val1, val2, val3;
  FILE *fp = fopen("/tmp/test_input.txt", "w");
  fprintf(fp, "10 20 30\n");
  fclose(fp);
  
  freopen("/tmp/test_input.txt", "r", stdin);
  int result = read_three_ints("Enter three numbers: ", &val1, &val2, &val3);
  freopen("/dev/tty", "r", stdin);
  
  TEST_ASSERT(result == 1);
  TEST_ASSERT(val1 == 10);
  TEST_ASSERT(val2 == 20);
  TEST_ASSERT(val3 == 30);
}

void test_read_int_negative_number(void) {
  int value;
  FILE *fp = fopen("/tmp/test_input.txt", "w");
  fprintf(fp, "-100\n");
  fclose(fp);
  
  freopen("/tmp/test_input.txt", "r", stdin);
  int result = read_int("Enter number: ", &value);
  freopen("/dev/tty", "r", stdin);
  
  TEST_ASSERT(result == 1);
  TEST_ASSERT(value == -100);
}

void test_read_int_zero(void) {
  int value;
  FILE *fp = fopen("/tmp/test_input.txt", "w");
  fprintf(fp, "0\n");
  fclose(fp);
  
  freopen("/tmp/test_input.txt", "r", stdin);
  int result = read_int("Enter number: ", &value);
  freopen("/dev/tty", "r", stdin);
  
  TEST_ASSERT(result == 1);
  TEST_ASSERT(value == 0);
}

int main(void) {
  UNITY_BEGIN();
  
  RUN_TEST(test_read_int_valid_input);
  RUN_TEST(test_read_float_valid_input);
  RUN_TEST(test_read_double_valid_input);
  RUN_TEST(test_read_three_ints_valid_input);
  RUN_TEST(test_read_int_negative_number);
  RUN_TEST(test_read_int_zero);
  
  return UNITY_END();
}
