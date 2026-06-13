#ifndef INTEGRATION_LAB7_HPP
#define INTEGRATION_LAB7_HPP

double function_lab7(double x);
double trapezoidal_lab7(double (*f)(double), double a, double b, int n);
double simpson_lab7(double (*f)(double), double a, double b, int n);
double gauss_quadrature_lab7(double (*f)(double), double a, double b, int nodes);
double composite_gauss_lab7(double (*f)(double), double a, double b, int intervals, int nodes);
double absolute_error_lab7(double exact_value, double approximate_value);
double percentage_error_lab7(double exact_value, double approximate_value);
void run_example_lab7();

#endif