#pragma once

const int max_degree_lab8 = 10;
const int simpson_n_lab8 = 10000;

double function_lab8(double x);
double power_integral_lab8(int power);
double function_times_power_integral_lab8(int power);
double polynomial_value_lab8(double coeff[], int degree, double x);
void create_system_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1], double rhs[max_degree_lab8 + 1], int degree);
void print_matrix_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1], int degree);
void print_vector_lab8(double rhs[max_degree_lab8 + 1], int degree);
void print_augmented_matrix_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 2], int size);
void save_system_to_file_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1], double rhs[max_degree_lab8 + 1], int degree);
bool gaussian_elimination_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1], double rhs[max_degree_lab8 + 1], double result[max_degree_lab8 + 1], int degree);
bool gaussian_elimination_silent_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1], double rhs[max_degree_lab8 + 1], double result[max_degree_lab8 + 1], int degree);
double mean_square_error_lab8(double coeff[max_degree_lab8 + 1], int degree);
void save_plot_data_lab8(double coeff[max_degree_lab8 + 1], int degree);
void save_degree_analysis_lab8(int max_degree);
void run_example_lab8();