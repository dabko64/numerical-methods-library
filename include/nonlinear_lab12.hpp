#ifndef NONLINEAR_LAB12_HPP
#define NONLINEAR_LAB12_HPP
#include <fstream>

using namespace std;


const int max_roots_lab12 = 32;
const int max_iter_lab12 = 100;


enum status_lab12
{
    converged_lab12,
    max_iter_lab12_status,
    zero_derivative_lab12,
    oscillation_lab12
};

struct result_lab12
{
    double root;
    int iterations;
    status_lab12 status;
    double empirical_order;
    double empirical_constant;
};

struct steps_history_lab12
{
    double x[max_iter_lab12];
    double fx[max_iter_lab12];
    double error[max_iter_lab12];
    int n;
};

double function_1_lab12(double x);
double derivative_1_lab12(double x);
double function_2_lab12(double x);
double derivative_2_lab12(double x);
double function_3_lab12(double x);
double derivative_3_lab12(double x);
double numeric_derivative_lab12(double (*f)(double), double x);
void analyze_convergence_lab12(double e0, double e1, double e2, double &p, double &c);
result_lab12 newton_method_lab12(double (*f)(double), double (*df)(double), double x0, bool use_numeric_derivative, steps_history_lab12 &history);
result_lab12 secant_method_lab12(double (*f)(double), double x0, double x1, steps_history_lab12 &history);
bool root_already_exists_lab12(double x);
const char* decode_status_lab12(status_lab12 status);
void save_method_to_csv_lab12(ofstream &file, const char* function_name, const char* method_name, double root_id, const steps_history_lab12 &history);
void search_and_compare_lab12(ofstream &file, double (*f)(double), double (*df)(double), const char* function_name, double start, double end);

void run_example_lab12();

#endif