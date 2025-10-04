/**
 * @file helper.h
 * @brief Template header file for function declarations
 *
 * This is a boilerplate template for quick project setup.
 * Add your function declarations below the input validation functions.
 * Includes common input validation utilities for integers, floats, and doubles.
 */

#ifndef HELPER_H
#define HELPER_H

int read_int(const char *prompt, int *value);
int read_float(const char *prompt, float *value);
int read_double(const char *prompt, double *value);
int read_three_ints(const char *prompt, int *val1, int *val2, int *val3);

void explain_modular_programming(void);

#endif // HELPER_H
