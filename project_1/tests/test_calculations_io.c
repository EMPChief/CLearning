// Testing framework: Unity (embedded minimal)
// These are IO-capturing tests that exercise the interactive functions
// implemented in project_1/calculations.c.

#include "../unity/unity.h"
#include "../calculations.h"
#include "test_utils.h"

#include <string.h>
#include <stdio.h>

#define ASSERT_CONTAINS(hay, needle) TEST_ASSERT(strstr((hay), (needle)) \!= NULL)

static char out[4096];
static char expect[256];

void test_two_grade_average_typical(void) {
    capture_io_run(calculate_two_grade_average, "70\n80\n", out, sizeof(out));
    snprintf(expect, sizeof(expect), "The average grade is: %.2f\n", (70 + 80) / 2.0);
    ASSERT_CONTAINS(out, expect);
}

void test_two_grade_average_rounding(void) {
    // 1 and 2 -> 1.50
    capture_io_run(calculate_two_grade_average, "1\n2\n", out, sizeof(out));
    snprintf(expect, sizeof(expect), "The average grade is: %.2f\n", (1 + 2) / 2.0);
    ASSERT_CONTAINS(out, expect);
}

void test_birth_year_typical(void) {
    capture_io_run(calculate_birth_year, "2025\n25\n", out, sizeof(out));
    snprintf(expect, sizeof(expect), "You were born in: %d\n", 2025 - 25);
    ASSERT_CONTAINS(out, expect);
}

void test_rectangle_area_int(void) {
    capture_io_run(calculate_rectangle_area, "4\n5\n", out, sizeof(out));
    snprintf(expect, sizeof(expect), "The area of the rectangle is: %d\n", 4 * 5);
    ASSERT_CONTAINS(out, expect);
}

void test_rectangle_circle_area_floats(void) {
    // length=3.5, width=2.0, radius=1.5
    capture_io_run(calculate_rectangle_circle_area, "3.5\n2.0\n1.5\n", out, sizeof(out));
    snprintf(expect, sizeof(expect), "Rectangle area: %.2f\n", 3.5f * 2.0f);
    ASSERT_CONTAINS(out, expect);
    // Circle area uses PI from implementation; recompute here for expected string
    float circle = 3.141592653589793f * 1.5f * 1.5f;
    snprintf(expect, sizeof(expect), "Circle area: %.2f\n", circle);
    ASSERT_CONTAINS(out, expect);
}

void test_rectangle_perimeter_double(void) {
    capture_io_run(calculate_rectangle_perimeter, "2.5\n5.0\n", out, sizeof(out));
    snprintf(expect, sizeof(expect), "Rectangle perimeter: %.2f\n", 2 * (2.5 + 5.0));
    ASSERT_CONTAINS(out, expect);
}

void test_three_grade_average_space_separated(void) {
    capture_io_run(calculate_three_grade_average, "70 80 90\n", out, sizeof(out));
    snprintf(expect, sizeof(expect), "The average grade is: %.2f\n", (70 + 80 + 90) / 3.0);
    ASSERT_CONTAINS(out, expect);
}

void test_temperature_converter_c_to_f(void) {
    capture_io_run(temperature_converter, "1\n37\n", out, sizeof(out));
    snprintf(expect, sizeof(expect), "%.2f Celsius is %.2f Fahrenheit\n", 37.0, (37.0 * 9.0 / 5.0) + 32.0);
    ASSERT_CONTAINS(out, expect);
}

void test_temperature_converter_f_to_c(void) {
    capture_io_run(temperature_converter, "2\n212\n", out, sizeof(out));
    snprintf(expect, sizeof(expect), "%.2f Fahrenheit is %.2f Celsius\n", 212.0, (212.0 - 32.0) * 5.0 / 9.0);
    ASSERT_CONTAINS(out, expect);
}

void test_temperature_converter_invalid_choice(void) {
    capture_io_run(temperature_converter, "3\n", out, sizeof(out));
    ASSERT_CONTAINS(out, "Invalid choice\! Please run the program again and choose 1 or 2.\n");
}

void test_swap_two_floating_numbers(void) {
    capture_io_run(swap_two_floating_numbers, "1.23\n4.56\n", out, sizeof(out));
    ASSERT_CONTAINS(out, "First number before swap: 1.230000\n");
    ASSERT_CONTAINS(out, "Second number before swap: 4.560000\n");
    ASSERT_CONTAINS(out, "First number after swap: 4.560000\n");
    ASSERT_CONTAINS(out, "Second number after swap: 1.230000\n");
}

void test_math_operation_learn_defaults(void) {
    capture_io_run(math_operation_learn, "", out, sizeof(out));
    // Default example: first=1, d=2, n=9 -> nth=17
    ASSERT_CONTAINS(out, "Therefore, the 9.00-th term of the arithmetic sequence is: 17.00\n");
}

// -----------------------------------------------------------------------------

int main(void) {
    UnityBegin(__FILE__);

    RUN_TEST(test_two_grade_average_typical);
    RUN_TEST(test_two_grade_average_rounding);

    RUN_TEST(test_birth_year_typical);

    RUN_TEST(test_rectangle_area_int);
    RUN_TEST(test_rectangle_circle_area_floats);
    RUN_TEST(test_rectangle_perimeter_double);

    RUN_TEST(test_three_grade_average_space_separated);

    RUN_TEST(test_temperature_converter_c_to_f);
    RUN_TEST(test_temperature_converter_f_to_c);
    RUN_TEST(test_temperature_converter_invalid_choice);

    RUN_TEST(test_swap_two_floating_numbers);
    RUN_TEST(test_math_operation_learn_defaults);

    UnityEnd();
    return Unity_tests_failed ? 1 : 0;
}