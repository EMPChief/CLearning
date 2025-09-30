#ifndef CALCULATIONS_H
#define CALCULATIONS_H

int read_int(const char *prompt, int *value);
int read_float(const char *prompt, float *value);
int read_double(const char *prompt, double *value);
int read_three_ints(const char *prompt, int *val1, int *val2, int *val3);

void calculate_two_grade_average(void);
void calculate_birth_year(void);
void calculate_rectangle_area(void);
void calculate_rectangle_circle_area(void);
void calculate_rectangle_perimeter(void);
void calculate_three_grade_average(void);
void temperature_converter(void);
void swap_two_floating_numbers(void);
void math_operation_learn(void);

#endif
