#ifndef ODE_LAB9_HPP
#define ODE_LAB9_HPP

double derivative_lab9(double temperature, double alpha, double beta);
double exact_solution_lab9(double time, double initial_temperature, double alpha);
double euler_step_lab9(double temperature, double step, double alpha, double beta);
double absolute_error_lab9(double exact_value, double approximate_value);
double percentage_error_lab9(double exact_value, double approximate_value);
void save_row_lab9(double time, double temperature, double exact_temperature, double error, double percentage_error);
void print_row_lab9(double time, double temperature, double exact_temperature, double error, double percentage_error);
void run_cooling_simulation_lab9(double initial_temperature, double alpha, double beta,double cooling_time);
void run_example_lab9();

#endif