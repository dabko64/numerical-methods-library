#ifndef ODE_LAB10_HPP
#define ODE_LAB10_HPP

double derivative_lab10(double temperature, double alpha, double beta);
double exact_solution_lab10(double time, double initial_temperature, double alpha);
double euler_step_lab10(double temperature, double step, double alpha, double beta);
double heun_step_lab10(double temperature, double step, double alpha, double beta);
double midpoint_step_lab10(double temperature, double step, double alpha, double beta);
double runge_kutta_4_step_lab10(double temperature, double step, double alpha, double beta);
double absolute_error_lab10(double exact_value, double approximate_value);
void save_row_lab10(double time, double euler_temperature, double heun_temperature, double midpoint_temperature, double rk4_temperature, double exact_temperature, double euler_error, double heun_error, double midpoint_error, double rk4_error);
void print_row_lab10(double time, double euler_temperature, double heun_temperature, double midpoint_temperature, double rk4_temperature, double exact_temperature);
void run_temperature_change_lab10(double initial_temperature, double alpha, double beta, double cooling_time);
void run_convergence_analysis_lab10(double initial_temperature, double alpha, double beta, double cooling_time);
void run_example_lab10();

#endif