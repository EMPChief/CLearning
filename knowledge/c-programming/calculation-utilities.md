# Calculation Utilities

## Overview

Common calculation patterns and utilities used across CLearning projects for mathematical operations, conversions, and transformations.

## Arithmetic Calculations

### Grade Average Calculations

**Two Grade Average**

Location: `project_1/calculations.c:116`

```c
void calculate_two_grade_average(void) {
  int grade_one, grade_two;
  double grade_average;

  if (!read_int("Input first grade: ", &grade_one)) return;
  if (!read_int("Input second grade: ", &grade_two)) return;

  grade_average = (grade_one + grade_two) / 2.0;  // Note: 2.0 for float division
  printf("The average grade is: %.2f\n", grade_average);
}
```

**Key Points:**
- Use `2.0` (not `2`) to force floating-point division
- Format average to 2 decimal places with `%.2f`
- Validate each input before calculation

**Three Grade Average (Space-Separated Input)**

Location: `project_1/calculations.c:234`

```c
void calculate_three_grade_average(void) {
  int grade_one, grade_two, grade_three;
  double grade_average;

  if (!read_three_ints("Input three grades separated by spaces: ", 
                       &grade_one, &grade_two, &grade_three)) {
    return;
  }

  grade_average = (grade_one + grade_two + grade_three) / 3.0;
  printf("The average grade is: %.2f\n", grade_average);
}
```

### Geometric Calculations

**Rectangle Area (Integer)**

Location: `project_1/calculations.c:160`

```c
void calculate_rectangle_area(void) {
  int rectangle_length, rectangle_height, rectangle_area;

  if (!read_int("Input rectangle length: ", &rectangle_length)) return;
  if (!read_int("Input rectangle height: ", &rectangle_height)) return;

  rectangle_area = rectangle_length * rectangle_height;
  printf("The area of the rectangle is: %d\n", rectangle_area);
}
```

**Rectangle and Circle Areas (Float)**

Location: `project_1/calculations.c:182`

```c
#define PI 3.141592653589793

void calculate_rectangle_circle_area(void) {
  float rectangle_length, rectangle_width, rectangle_area;
  float circle_radius, circle_area;

  if (!read_float("Input rectangle length: ", &rectangle_length)) return;
  if (!read_float("Input rectangle width: ", &rectangle_width)) return;
  if (!read_float("Input circle radius: ", &circle_radius)) return;

  rectangle_area = rectangle_length * rectangle_width;
  circle_area = PI * circle_radius * circle_radius;

  printf("Rectangle area: %.2f\n", rectangle_area);
  printf("Circle area: %.2f\n", circle_area);
}
```

**Rectangle Perimeter (Double)**

Location: `project_1/calculations.c:212`

```c
void calculate_rectangle_perimeter(void) {
  double rectangle_length, rectangle_width, rectangle_perimeter;

  if (!read_double("Input rectangle length: ", &rectangle_length)) return;
  if (!read_double("Input rectangle width: ", &rectangle_width)) return;

  rectangle_perimeter = 2 * (rectangle_length + rectangle_width);
  printf("Rectangle perimeter: %.2lf\n", rectangle_perimeter);
}
```

**Note:** Use `%.2lf` for double, `%.2f` for float

## Conversion Utilities

### Temperature Conversion

Location: `project_1/calculations.c:255`

```c
void temperature_converter(void) {
  double celsius_temperature, fahrenheit_temperature;
  double user_choice, conversion_result;

  if (!read_double("Enter 1 for C→F or 2 for F→C: ", &user_choice)) {
    return;
  }

  if (user_choice == 1) {
    if (!read_double("Enter temperature in Celsius: ", &celsius_temperature)) {
      return;
    }
    conversion_result = (celsius_temperature * 9.0 / 5.0) + 32.0;
    printf("%.2lf Celsius is %.2lf Fahrenheit\n", 
           celsius_temperature, conversion_result);
  } else if (user_choice == 2) {
    if (!read_double("Enter temperature in Fahrenheit: ", 
                     &fahrenheit_temperature)) {
      return;
    }
    conversion_result = (fahrenheit_temperature - 32.0) * 5.0 / 9.0;
    printf("%.2lf Fahrenheit is %.2lf Celsius\n", 
           fahrenheit_temperature, conversion_result);
  } else {
    printf("Invalid choice! Please choose 1 or 2.\n");
  }
}
```

**Formulas:**
- Celsius → Fahrenheit: `(C × 9/5) + 32`
- Fahrenheit → Celsius: `(F - 32) × 5/9`

### Time Conversions

**Seconds to Hours:Minutes:Seconds**

Location: `project_2/function_file.c:224`

```c
void seconds_to_hms(void) {
  int total_seconds, hours, minutes, seconds;

  while (!read_int("Enter total seconds: ", &total_seconds) ||
         total_seconds < 0) {
    if (total_seconds < 0) {
      printf("Please enter a non-negative value.\n");
    }
  }

  hours = total_seconds / 3600;
  minutes = (total_seconds % 3600) / 60;
  seconds = total_seconds % 60;

  printf("%d seconds is equivalent to %d hours, %d minutes, and %d seconds.\n",
         total_seconds, hours, minutes, seconds);
}
```

**Formulas:**
- Hours: `total_seconds / 3600`
- Minutes: `(total_seconds % 3600) / 60`
- Seconds: `total_seconds % 60`

**Driving Time Calculator**

Location: `project_2/function_file.c:185`

```c
void driving_time_calculator(void) {
  int distance_km, speed_kmh;
  double travel_time_hours;
  int hours, minutes, seconds, milliseconds;

  while (!read_int("Enter distance (km): ", &distance_km));
  while (!read_int("Enter speed (km/h): ", &speed_kmh));

  travel_time_hours = (double)distance_km / speed_kmh;
  
  hours = (int)travel_time_hours;
  minutes = (int)((travel_time_hours - hours) * 60);
  seconds = (int)((((travel_time_hours - hours) * 60) - minutes) * 60);
  milliseconds = (int)((((((travel_time_hours - hours) * 60) - minutes) * 60) 
                       - seconds) * 1000);

  printf("Estimated travel time: %d hours, %d minutes, %d seconds, %d ms\n",
         hours, minutes, seconds, milliseconds);
}
```

### Birth Year Calculation

Location: `project_1/calculations.c:138`

```c
void calculate_birth_year(void) {
  int current_year, current_age, birth_year;

  if (!read_int("Input current year: ", &current_year)) return;
  if (!read_int("Input your age: ", &current_age)) return;

  birth_year = current_year - current_age;
  printf("You were born in: %d\n", birth_year);
}
```

## Mathematical Operations

### Variable Swapping

Location: `project_1/calculations.c:293`

```c
void swap_two_floating_numbers(void) {
  float first_number, second_number, temporary_variable;

  if (!read_float("Enter first number: ", &first_number)) return;
  if (!read_float("Enter second number: ", &second_number)) return;

  printf("First number before swap: %.2f\n", first_number);
  printf("Second number before swap: %.2f\n", second_number);

  temporary_variable = first_number;
  first_number = second_number;
  second_number = temporary_variable;

  printf("First number after swap: %.2f\n", first_number);
  printf("Second number after swap: %.2f\n", second_number);
}
```

**Pattern:** Use temporary variable to swap values

### Arithmetic Sequence

**Sum of Arithmetic Sequence**

Location: `project_2/function_file.c:127`

```c
void sum_of_arithmetic_sequence(void) {
  double sequence_sum;
  int number_of_terms = 9;
  int first_term = 1;
  int last_term = 17;
  
  sequence_sum = ((double)first_term + last_term) * number_of_terms / 2;
  printf("Sum of the arithmetic sequence: %.2lf\n", sequence_sum);
}
```

**Formula:** `sum = (first_term + last_term) × n / 2`

**N-th Term of Arithmetic Sequence**

Location: `project_1/calculations.c:323`

```c
void math_operation_learn(void) {
  double common_difference = 2;
  int first_term = 1;
  double term_position = 9;
  double nth_term;

  nth_term = first_term + (term_position - 1) * common_difference;
  
  printf("The %.2lf-th term is: %.2lf\n", term_position, nth_term);
}
```

**Formula:** `nth_term = first_term + (n - 1) × d`

## Financial Calculations

### Salary Calculator

Location: `project_2/function_file.c:151`

```c
void salary_calculator(void) {
  double hourly_wage, hours_worked, gross_salary, net_salary, tax_amount;
  int tax_rate_percentage;
  
  while (!read_double("Enter hourly wage: ", &hourly_wage));
  while (!read_double("Enter hours worked: ", &hours_worked));
  while (!read_int("Enter tax rate (0-100): ", &tax_rate_percentage));
  
  gross_salary = hourly_wage * hours_worked;
  tax_amount = gross_salary * tax_rate_percentage / 100.0;
  net_salary = gross_salary - tax_amount;
  
  printf("Gross Salary: $%.2lf\n", gross_salary);
  printf("Tax Amount: $%.2lf\n", tax_amount);
  printf("Net Salary: $%.2lf\n", net_salary);
}
```

**Formulas:**
- Gross salary: `hourly_wage × hours_worked`
- Tax amount: `gross_salary × tax_rate / 100`
- Net salary: `gross_salary - tax_amount`

## Best Practices

### Numeric Type Selection

| Calculation Type | Recommended Type | Reason |
|-----------------|------------------|---------|
| Whole numbers only | `int` | Exact representation |
| May have decimals | `float` | Sufficient precision |
| High precision needed | `double` | Maximum precision |
| Currency | `double` or `int` cents | Avoid float rounding |

### Division Operations

```c
// Integer division (loses fractional part)
int result = 7 / 2;  // = 3

// Float division (preserves fractional part)
double result = 7 / 2.0;  // = 3.5
double result = (double)7 / 2;  // = 3.5
```

**Rule:** At least one operand must be floating-point for float division

### Output Formatting

```c
// Integer
printf("%d\n", value);

// Float (2 decimal places)
printf("%.2f\n", value);

// Double (2 decimal places)
printf("%.2lf\n", value);

// Scientific notation
printf("%.2e\n", value);  // e.g., 1.23e+02
```

## See Also

- **input-validation.md** - Input functions used in calculations
- **error-handling.md** - Error handling patterns
- **memory-safety.md** - Type safety and division operations
- **testing-patterns.md** - Testing calculation functions
