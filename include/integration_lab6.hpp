#ifndef INTEGRATION_LAB6_HPP
#define INTEGRATION_LAB6_HPP

double function_lab6(double x);

double left_rectangle_lab6(double a, double b, int n);
double midpoint_rectangle_lab6(double a, double b, int n);
double trapezoidal_lab6(double a, double b, int n);
double simpson_lab6(double a, double b, int n);

double absolute_error_lab6(double exact_value, double approximate_value);
double convergence_order_lab6(double error_n, double error_2n);

double measure_time_lab6(double (*method)(double, double, int), double a, double b, int n, double &result);

void run_example_lab6();

#endif