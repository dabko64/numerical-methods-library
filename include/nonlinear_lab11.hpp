#ifndef NONLINEAR_LAB11_HPP
#define NONLINEAR_LAB11_HPP

#include <fstream>

using namespace std;

const int max_roots_lab11 = 32;
const int max_iter_lab11 = 100;
enum result_status_lab11
{
    converged_lab11,
    max_iter_lab11_status,
    zero_derivative_lab11,
    oscillation_lab11
};

struct result_lab11
{
    double root;
    int iterations;
    result_status_lab11 status;
    double empirical_order;
    double empirical_constant;
};

struct steps_history_lab11
{
    double x[max_iter_lab11];
    double fx[max_iter_lab11];
    double error[max_iter_lab11];
    int n;
};
double function_1_lab11(double x);
double derivative_1_lab11(double x);
double function_2_lab11(double x);
double derivative_2_lab11(double x);
double function_3_lab11(double x);
double derivative_3_lab11(double x);
double numeric_derivative_lab11(double (*f)(double), double x);
void analyze_convergence_lab11(double e0, double e1, double e2, double &p, double &c);
result_lab11 newton_method_lab11(double (*f)(double), double (*df)(double), double x0, bool use_numeric_derivative, steps_history_lab11 &history);
result_lab11 secant_method_lab11(double (*f)(double), double x0, double x1, steps_history_lab11 &history);
bool root_already_exists_lab11(double x);
const char* decode_status_lab11(result_status_lab11 status);
void save_method_to_csv_lab11(ofstream &file, const char* function_name, const char* method_name, double root_id, const steps_history_lab11 &history);
void search_and_compare_lab11(ofstream &file, double (*f)(double), double (*df)(double), const char* function_name, double start, double end);
void run_example_lab11();

#endif