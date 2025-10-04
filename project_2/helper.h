/**
 * @file helper.h
 * @brief Function declarations for input validation and calculations
 *
 * Provides validated input functions and various calculation utilities
 * for use in interactive programs.
 */

#ifndef HELPER_H
#define HELPER_H

int read_int(const char *prompt, int *value);
int read_float(const char *prompt, float *value);
int read_double(const char *prompt, double *value);
int read_three_ints(const char *prompt, int *first_value, int *second_value,
                    int *third_value);

void sum_of_arithmetic_sequence(void);
void salary_calculator(void);
void driving_time_calculator(void);
void seconds_to_hms(void);

#endif
