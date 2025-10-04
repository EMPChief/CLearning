/**
 * @file test_calculations.c
 * @brief Unit tests for calculation functions
 */

#include "../unity/unity.h"
#include <math.h>

#define TEST_ASSERT_EQUAL_INT(expected, actual) \
  TEST_ASSERT((expected) == (actual))

#define TEST_ASSERT_DOUBLE_WITHIN(tolerance, expected, actual) \
  TEST_ASSERT(fabs((expected) - (actual)) < (tolerance))

#define UNITY_BEGIN() UnityBegin(__FILE__)
#define UNITY_END() (UnityEnd(), Unity_tests_failed)

void setUp(void) {}

void tearDown(void) {}

void test_arithmetic_sequence_formula(void) {
  int number_of_terms = 9;
  int first_term = 1;
  int last_term = 17;
  double expected_sum = ((double)first_term + last_term) * number_of_terms / 2;
  
  TEST_ASSERT_DOUBLE_WITHIN(0.01, 81.0, expected_sum);
}

void test_salary_calculation_formula(void) {
  double hourly_wage = 20.0;
  double hours_worked = 160.0;
  int tax_rate = 15;
  
  double gross_salary = hourly_wage * hours_worked;
  double tax_amount = gross_salary * tax_rate / 100.0;
  double net_salary = gross_salary - tax_amount;
  
  TEST_ASSERT_DOUBLE_WITHIN(0.01, 3200.0, gross_salary);
  TEST_ASSERT_DOUBLE_WITHIN(0.01, 480.0, tax_amount);
  TEST_ASSERT_DOUBLE_WITHIN(0.01, 2720.0, net_salary);
}

void test_driving_time_calculation(void) {
  int distance_km = 120;
  int speed_kmh = 60;
  
  double travel_time_hours = (double)distance_km / speed_kmh;
  int hours = (int)travel_time_hours;
  int minutes = (int)((travel_time_hours - hours) * 60);
  
  TEST_ASSERT_EQUAL_INT(2, hours);
  TEST_ASSERT_EQUAL_INT(0, minutes);
}

void test_driving_time_with_minutes(void) {
  int distance_km = 150;
  int speed_kmh = 60;
  
  double travel_time_hours = (double)distance_km / speed_kmh;
  int hours = (int)travel_time_hours;
  int minutes = (int)((travel_time_hours - hours) * 60);
  
  TEST_ASSERT_EQUAL_INT(2, hours);
  TEST_ASSERT_EQUAL_INT(30, minutes);
}

void test_seconds_to_hms_conversion(void) {
  int total_seconds = 3661;
  
  int hours = total_seconds / 3600;
  int minutes = (total_seconds % 3600) / 60;
  int seconds = total_seconds % 60;
  
  TEST_ASSERT_EQUAL_INT(1, hours);
  TEST_ASSERT_EQUAL_INT(1, minutes);
  TEST_ASSERT_EQUAL_INT(1, seconds);
}

void test_seconds_to_hms_edge_case_zero(void) {
  int total_seconds = 0;
  
  int hours = total_seconds / 3600;
  int minutes = (total_seconds % 3600) / 60;
  int seconds = total_seconds % 60;
  
  TEST_ASSERT_EQUAL_INT(0, hours);
  TEST_ASSERT_EQUAL_INT(0, minutes);
  TEST_ASSERT_EQUAL_INT(0, seconds);
}

void test_seconds_to_hms_edge_case_large(void) {
  int total_seconds = 86400;
  
  int hours = total_seconds / 3600;
  int minutes = (total_seconds % 3600) / 60;
  int seconds = total_seconds % 60;
  
  TEST_ASSERT_EQUAL_INT(24, hours);
  TEST_ASSERT_EQUAL_INT(0, minutes);
  TEST_ASSERT_EQUAL_INT(0, seconds);
}

void test_seconds_to_hms_only_minutes(void) {
  int total_seconds = 300;
  
  int hours = total_seconds / 3600;
  int minutes = (total_seconds % 3600) / 60;
  int seconds = total_seconds % 60;
  
  TEST_ASSERT_EQUAL_INT(0, hours);
  TEST_ASSERT_EQUAL_INT(5, minutes);
  TEST_ASSERT_EQUAL_INT(0, seconds);
}

int main(void) {
  UNITY_BEGIN();
  
  RUN_TEST(test_arithmetic_sequence_formula);
  RUN_TEST(test_salary_calculation_formula);
  RUN_TEST(test_driving_time_calculation);
  RUN_TEST(test_driving_time_with_minutes);
  RUN_TEST(test_seconds_to_hms_conversion);
  RUN_TEST(test_seconds_to_hms_edge_case_zero);
  RUN_TEST(test_seconds_to_hms_edge_case_large);
  RUN_TEST(test_seconds_to_hms_only_minutes);
  
  return UNITY_END();
}
