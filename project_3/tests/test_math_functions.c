#include "../unity/unity.h"
#include "../helper.h"

void test_is_prime_should_return_false_for_negative_numbers(void) {
  TEST_ASSERT(!is_prime(-5));
  TEST_ASSERT(!is_prime(-1));
}

void test_is_prime_should_return_false_for_zero_and_one(void) {
  TEST_ASSERT(!is_prime(0));
  TEST_ASSERT(!is_prime(1));
}

void test_is_prime_should_return_true_for_two(void) {
  TEST_ASSERT(is_prime(2));
}

void test_is_prime_should_return_false_for_even_numbers(void) {
  TEST_ASSERT(!is_prime(4));
  TEST_ASSERT(!is_prime(100));
  TEST_ASSERT(!is_prime(1000));
}

void test_is_prime_should_return_true_for_small_primes(void) {
  TEST_ASSERT(is_prime(3));
  TEST_ASSERT(is_prime(5));
  TEST_ASSERT(is_prime(7));
  TEST_ASSERT(is_prime(11));
  TEST_ASSERT(is_prime(13));
}

void test_is_prime_should_return_false_for_composite_numbers(void) {
  TEST_ASSERT(!is_prime(9));
  TEST_ASSERT(!is_prime(15));
  TEST_ASSERT(!is_prime(25));
  TEST_ASSERT(!is_prime(49));
}

void test_is_prime_should_return_true_for_large_primes(void) {
  TEST_ASSERT(is_prime(97));
  TEST_ASSERT(is_prime(101));
  TEST_ASSERT(is_prime(233));
}

void test_fibonacci_should_return_zero_for_negative_and_zero(void) {
  TEST_ASSERT(fibonacci(-5) == 0);
  TEST_ASSERT(fibonacci(-1) == 0);
  TEST_ASSERT(fibonacci(0) == 0);
}

void test_fibonacci_should_return_one_for_first_position(void) {
  TEST_ASSERT(fibonacci(1) == 1);
}

void test_fibonacci_should_return_correct_sequence(void) {
  TEST_ASSERT(fibonacci(2) == 1);
  TEST_ASSERT(fibonacci(3) == 2);
  TEST_ASSERT(fibonacci(4) == 3);
  TEST_ASSERT(fibonacci(5) == 5);
  TEST_ASSERT(fibonacci(6) == 8);
  TEST_ASSERT(fibonacci(7) == 13);
  TEST_ASSERT(fibonacci(8) == 21);
}

void test_fibonacci_should_handle_larger_values(void) {
  TEST_ASSERT(fibonacci(10) == 55);
  TEST_ASSERT(fibonacci(20) == 6765);
}

void test_factorial_should_return_error_for_negative(void) {
  TEST_ASSERT(factorial(-1) == -1);
  TEST_ASSERT(factorial(-5) == -1);
  TEST_ASSERT(factorial(-100) == -1);
}

void test_factorial_should_return_one_for_zero_and_one(void) {
  TEST_ASSERT(factorial(0) == 1);
  TEST_ASSERT(factorial(1) == 1);
}

void test_factorial_should_calculate_small_factorials(void) {
  TEST_ASSERT(factorial(2) == 2);
  TEST_ASSERT(factorial(3) == 6);
  TEST_ASSERT(factorial(4) == 24);
  TEST_ASSERT(factorial(5) == 120);
}

void test_factorial_should_calculate_larger_factorials(void) {
  TEST_ASSERT(factorial(6) == 720);
  TEST_ASSERT(factorial(7) == 5040);
  TEST_ASSERT(factorial(8) == 40320);
  TEST_ASSERT(factorial(9) == 362880);
  TEST_ASSERT(factorial(10) == 3628800);
}

void test_reverse_number_should_handle_zero(void) {
  TEST_ASSERT(reverse_number(0) == 0);
}

void test_reverse_number_should_reverse_single_digit(void) {
  TEST_ASSERT(reverse_number(5) == 5);
  TEST_ASSERT(reverse_number(9) == 9);
}

void test_reverse_number_should_reverse_multiple_digits(void) {
  TEST_ASSERT(reverse_number(123) == 321);
  TEST_ASSERT(reverse_number(6789) == 9876);
  TEST_ASSERT(reverse_number(12345) == 54321);
}

void test_reverse_number_should_handle_negative_numbers(void) {
  TEST_ASSERT(reverse_number(-123) == -321);
  TEST_ASSERT(reverse_number(-6789) == -9876);
}

void test_reverse_number_should_handle_trailing_zeros(void) {
  TEST_ASSERT(reverse_number(100) == 1);
  TEST_ASSERT(reverse_number(120) == 21);
  TEST_ASSERT(reverse_number(1000) == 1);
}

void test_is_palindrome_should_return_false_for_negative(void) {
  TEST_ASSERT(!is_palindrome(-121));
  TEST_ASSERT(!is_palindrome(-1));
}

void test_is_palindrome_should_return_true_for_single_digit(void) {
  TEST_ASSERT(is_palindrome(0));
  TEST_ASSERT(is_palindrome(5));
  TEST_ASSERT(is_palindrome(9));
}

void test_is_palindrome_should_identify_palindromes(void) {
  TEST_ASSERT(is_palindrome(11));
  TEST_ASSERT(is_palindrome(121));
  TEST_ASSERT(is_palindrome(1221));
  TEST_ASSERT(is_palindrome(12321));
  TEST_ASSERT(is_palindrome(123321));
}

void test_is_palindrome_should_identify_non_palindromes(void) {
  TEST_ASSERT(!is_palindrome(10));
  TEST_ASSERT(!is_palindrome(123));
  TEST_ASSERT(!is_palindrome(1234));
  TEST_ASSERT(!is_palindrome(12345));
}

void test_sum_of_digits_should_handle_zero(void) {
  TEST_ASSERT(sum_of_digits(0) == 0);
}

void test_sum_of_digits_should_sum_single_digit(void) {
  TEST_ASSERT(sum_of_digits(5) == 5);
  TEST_ASSERT(sum_of_digits(9) == 9);
}

void test_sum_of_digits_should_sum_multiple_digits(void) {
  TEST_ASSERT(sum_of_digits(123) == 6);
  TEST_ASSERT(sum_of_digits(12345) == 15);
  TEST_ASSERT(sum_of_digits(123456789) == 45);
}

void test_sum_of_digits_should_handle_negative_numbers(void) {
  TEST_ASSERT(sum_of_digits(-123) == 6);
  TEST_ASSERT(sum_of_digits(-12345) == 15);
}

void test_sum_of_digits_should_handle_large_numbers(void) {
  TEST_ASSERT(sum_of_digits(1000000) == 1);
  TEST_ASSERT(sum_of_digits(1234) == 10);
}

void test_gcd_should_handle_zero(void) {
  TEST_ASSERT(gcd(0, 5) == 5);
  TEST_ASSERT(gcd(10, 0) == 10);
  TEST_ASSERT(gcd(0, 0) == 0);
}

void test_gcd_should_calculate_gcd_of_equal_numbers(void) {
  TEST_ASSERT(gcd(5, 5) == 5);
  TEST_ASSERT(gcd(100, 100) == 100);
}

void test_gcd_should_calculate_gcd_of_coprime_numbers(void) {
  TEST_ASSERT(gcd(7, 13) == 1);
  TEST_ASSERT(gcd(15, 28) == 1);
}

void test_gcd_should_calculate_gcd_of_common_multiples(void) {
  TEST_ASSERT(gcd(12, 18) == 6);
  TEST_ASSERT(gcd(25, 15) == 5);
  TEST_ASSERT(gcd(48, 60) == 12);
}

void test_gcd_should_handle_negative_numbers(void) {
  TEST_ASSERT(gcd(-12, 18) == 6);
  TEST_ASSERT(gcd(12, -18) == 6);
  TEST_ASSERT(gcd(-12, -18) == 6);
}

void test_gcd_should_handle_large_numbers(void) {
  TEST_ASSERT(gcd(100, 75) == 25);
  TEST_ASSERT(gcd(101, 103) == 1);
  TEST_ASSERT(gcd(252, 105) == 21);
}

int main(void) {
  UnityBegin(__FILE__);
  
  RUN_TEST(test_is_prime_should_return_false_for_negative_numbers);
  RUN_TEST(test_is_prime_should_return_false_for_zero_and_one);
  RUN_TEST(test_is_prime_should_return_true_for_two);
  RUN_TEST(test_is_prime_should_return_false_for_even_numbers);
  RUN_TEST(test_is_prime_should_return_true_for_small_primes);
  RUN_TEST(test_is_prime_should_return_false_for_composite_numbers);
  RUN_TEST(test_is_prime_should_return_true_for_large_primes);
  
  RUN_TEST(test_fibonacci_should_return_zero_for_negative_and_zero);
  RUN_TEST(test_fibonacci_should_return_one_for_first_position);
  RUN_TEST(test_fibonacci_should_return_correct_sequence);
  RUN_TEST(test_fibonacci_should_handle_larger_values);
  
  RUN_TEST(test_factorial_should_return_error_for_negative);
  RUN_TEST(test_factorial_should_return_one_for_zero_and_one);
  RUN_TEST(test_factorial_should_calculate_small_factorials);
  RUN_TEST(test_factorial_should_calculate_larger_factorials);
  
  RUN_TEST(test_reverse_number_should_handle_zero);
  RUN_TEST(test_reverse_number_should_reverse_single_digit);
  RUN_TEST(test_reverse_number_should_reverse_multiple_digits);
  RUN_TEST(test_reverse_number_should_handle_negative_numbers);
  RUN_TEST(test_reverse_number_should_handle_trailing_zeros);
  
  RUN_TEST(test_is_palindrome_should_return_false_for_negative);
  RUN_TEST(test_is_palindrome_should_return_true_for_single_digit);
  RUN_TEST(test_is_palindrome_should_identify_palindromes);
  RUN_TEST(test_is_palindrome_should_identify_non_palindromes);
  
  RUN_TEST(test_sum_of_digits_should_handle_zero);
  RUN_TEST(test_sum_of_digits_should_sum_single_digit);
  RUN_TEST(test_sum_of_digits_should_sum_multiple_digits);
  RUN_TEST(test_sum_of_digits_should_handle_negative_numbers);
  RUN_TEST(test_sum_of_digits_should_handle_large_numbers);
  
  RUN_TEST(test_gcd_should_handle_zero);
  RUN_TEST(test_gcd_should_calculate_gcd_of_equal_numbers);
  RUN_TEST(test_gcd_should_calculate_gcd_of_coprime_numbers);
  RUN_TEST(test_gcd_should_calculate_gcd_of_common_multiples);
  RUN_TEST(test_gcd_should_handle_negative_numbers);
  RUN_TEST(test_gcd_should_handle_large_numbers);
  
  UnityEnd();
  return Unity_tests_failed ? 1 : 0;
}
