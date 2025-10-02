#ifndef HELPER_H
#define HELPER_H

int read_int(const char *prompt, int *value);
int read_float(const char *prompt, float *value);
int read_double(const char *prompt, double *value);
int read_three_ints(const char *prompt, int *first_value, int *second_value, int *third_value);

void sum_of_arithmetic_sequence(void);
void salary_calculator(void);
void driving_time_calculator(void);

#endif