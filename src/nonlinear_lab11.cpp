#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include "../include/nonlinear_lab11.hpp"

using namespace std;


static const double eps_x_lab11 = 1e-10;
static const double eps_f_lab11 = 1e-10;
static const double step_lab11 = 0.1;
static double found_roots_lab11[max_roots_lab11];
static int found_roots_count_lab11 = 0;


// this is the first test function
double function_1_lab11(double x) {return pow(x, 6) - 9.0 * pow(x, 5) + 29.0 * pow(x, 4) - 39.0 * pow(x, 3) + 23.0 * pow(x, 2) - 6.0 * x - 3.0;}

// this is the derivative of the first test function
double derivative_1_lab11(double x){ return 6.0 * pow(x, 5) - 45.0 * pow(x, 4) + 116.0 * pow(x, 3) - 117.0 * pow(x, 2) + 46.0 * x - 6.0;}


// this is the second test function
double function_2_lab11(double x)
{
    if (fabs(x) < 1e-12)
    {
        cout << "error: x is too close to zero" << endl;
        return 1e18;
    }

    return pow(x, 3) + cos(x) - 1.0 / x;
}



// this is the derivative of the second test function
double derivative_2_lab11(double x)
{
    if (fabs(x) < 1e-12)
    {
        cout << "error: x is too close to zero" << endl;
        return 1e18;
    }

    return 3.0 * pow(x, 2) - sin(x) + 1.0 / (x * x);
}


// this is the third test function
double function_3_lab11(double x){return 2.0 * sin(x) + cos(x) * cos(x);}



// this is the derivative of the third test function
double derivative_3_lab11(double x){return 2.0 * cos(x) - 2.0 * sin(x) * cos(x);}



// this function calculates numeric derivative
double numeric_derivative_lab11(double (*f)(double), double x)
{
    double h;

    if (fabs(x) > 1.0) { h = 1e-6 * fabs(x); }
    else { h = 1e-6; }

    return (f(x + h) - f(x - h)) / (2.0 * h);
}




// this function calculates empirical convergence order
void analyze_convergence_lab11(double e0, double e1, double e2, double &p, double &c)
{
    if (e0 > 1e-14 && e1 > 1e-14 && e2 > 1e-14)
    {
        double r1 = log(e2 / e1);
        double r2 = log(e1 / e0);

        if (fabs(r2) > 1e-10)
        {
            p = r1 / r2;
            c = e2 / pow(e1, p);

            if (p > 0.1 && p < 5.0)
            { return; }
        }
    }
    p = 0.0;
    c = 0.0;
}




// this function solves equation using newton method
result_lab11 newton_method_lab11(double (*f)(double), double (*df)(double), double x0, bool use_numeric_derivative, steps_history_lab11 &history){


    result_lab11 result;
    result.root = 0.0;
    result.iterations = 0;
    result.status = max_iter_lab11_status;
    result.empirical_order = 0.0;
    result.empirical_constant = 0.0;
    history.n = 0;
    double x_current = x0;


    for (int i = 0; i < max_iter_lab11; i++)
    {
        double fx = f(x_current);
        double dfx;

        if (use_numeric_derivative) { dfx = numeric_derivative_lab11(f, x_current); }
        else{ dfx = df(x_current);}

        if (fabs(dfx) < 1e-14)
        {
            cout << "error: derivative is close to zero" << endl;
            result.status = zero_derivative_lab11;
            return result;
        }

        double x_next = x_current - fx / dfx;
        double error = fabs(x_next - x_current);

        if (history.n < max_iter_lab11)
        {
            history.x[history.n] = x_next;
            history.fx[history.n] = f(x_next);
            history.error[history.n] = error;
            history.n++;
        }

        if (error < eps_x_lab11 && fabs(f(x_next)) < eps_f_lab11)
        {
            result.status = converged_lab11;
            result.root = x_next;
            result.iterations = i + 1;

            if (history.n >= 3)
            {
                analyze_convergence_lab11(history.error[history.n - 3], history.error[history.n - 2], history.error[history.n - 1], result.empirical_order, result.empirical_constant);
            }
            return result;
        }

        if (fabs(x_next) > 1e10)
        {
            cout << "error: method is divergent" << endl;
            result.status = oscillation_lab11;
            return result;
        }

        if (i > 5 && history.n >= 2)
        {
            if (error > history.error[history.n - 2] * 10.0)
            {
                cout << "error: method is probably oscillating" << endl;
                result.status = oscillation_lab11;
                return result;
            }
        }
        x_current = x_next;
    }
    result.iterations = max_iter_lab11;
    return result;
}



// this function solves equation using secant method
result_lab11 secant_method_lab11(double (*f)(double), double x0, double x1, steps_history_lab11 &history) {

    result_lab11 result;
    result.root = 0.0;
    result.iterations = 0;
    result.status = max_iter_lab11_status;
    result.empirical_order = 0.0;
    result.empirical_constant = 0.0;
    history.n = 0;
    double x_before = x0;
    double x_actual = x1;


    for (int i = 0; i < max_iter_lab11; i++)
    {
        double f_before = f(x_before);
        double f_actual = f(x_actual);

        if (fabs(f_actual - f_before) < 1e-14)
        {
            cout << "error: denominator is close to zero" << endl;
            result.status = zero_derivative_lab11;
            return result;
        }

        double x_next = x_actual - f_actual * (x_actual - x_before) / (f_actual - f_before);
        double error = fabs(x_next - x_actual);
        if (history.n < max_iter_lab11)
        {
            history.x[history.n] = x_next;
            history.fx[history.n] = f(x_next);
            history.error[history.n] = error;
            history.n++;
        }

        if (error < eps_x_lab11 && fabs(f(x_next)) < eps_f_lab11)
        {
            result.status = converged_lab11;
            result.root = x_next;
            result.iterations = i + 1;

            if (history.n >= 3)
            {
                analyze_convergence_lab11(history.error[history.n - 3], history.error[history.n - 2], history.error[history.n - 1], result.empirical_order, result.empirical_constant);
            }
            return result;
        }

        if (fabs(x_next) > 1e10)
        {
            cout << "error: method is divergent" << endl;
            result.status = oscillation_lab11;
            return result;
        }

        x_before = x_actual;
        x_actual = x_next;
    }

    result.iterations = max_iter_lab11;
    return result;
}




// this function checks if root was already found
bool root_already_exists_lab11(double x)
{
    for (int i = 0; i < found_roots_count_lab11; i++)
    {
        if (fabs(found_roots_lab11[i] - x) < 1e-3)
        {
            return true;
        }
    }
    return false;
}




// this function changes status to text
const char* decode_status_lab11(result_status_lab11 status)
{
    if (status == converged_lab11) { return "converged"; }
    if (status == zero_derivative_lab11){return "zero_derivative";}
    if (status == oscillation_lab11){return "oscillation";}


    return "max_iter";
}



// this function saves method history to csv file
void save_method_to_csv_lab11(ofstream &file, const char* function_name, const char* method_name, double root_id, const steps_history_lab11 &history) {

    for (int i = 0; i < history.n; i++)
    {
        file << function_name << ";"
             << root_id << ";"
             << method_name << ";"
             << (i + 1) << ";"
             << setprecision(12) << history.x[i] << ";"
             << history.fx[i] << ";"
             << history.error[i] << "\n";
    }
}



// this function scans interval and compares methods
void search_and_compare_lab11(ofstream &file,double (*f)(double), double (*df)(double), const char* function_name, double start, double end)
{
    cout << endl;
    cout << "scanning function " << function_name
         << " on interval [" << start << ", " << end << "]" << endl;


    found_roots_count_lab11 = 0;
    for (double x = start; x < end; x = x + step_lab11)
    {
        double x_left = x;
        double x_right = x + step_lab11;

        if (x_right > end) { x_right = end; }


        double f_left = f(x_left);
        double f_right = f(x_right);
        if (f_left * f_right <= 0.0 || fabs(f_left) < 1e-4)
        {
            double x_start = (x_left + x_right) / 2.0;

            steps_history_lab11 history_newton_analytic;
            steps_history_lab11 history_newton_numeric;
            steps_history_lab11 history_secant;

            result_lab11 result_newton_analytic = newton_method_lab11(f, df, x_start, false, history_newton_analytic);
            result_lab11 result_newton_numeric = newton_method_lab11(f, df, x_start, true, history_newton_numeric);
            result_lab11 result_secant = secant_method_lab11(f, x_left, x_right, history_secant);


            double root = 0.0;

            if (result_newton_analytic.status == converged_lab11) { root = result_newton_analytic.root; }
            else if (result_secant.status == converged_lab11) {root = result_secant.root; }
            else { continue; }

            if (root_already_exists_lab11(root)) { continue; }

            if (found_roots_count_lab11 < max_roots_lab11)
            {
                found_roots_lab11[found_roots_count_lab11] = root;
                found_roots_count_lab11++;
            }

            save_method_to_csv_lab11(file, function_name, "newton_analytic", root, history_newton_analytic);
            save_method_to_csv_lab11(file, function_name, "newton_numeric", root, history_newton_numeric);
            save_method_to_csv_lab11(file, function_name,"secant",root,history_secant);
            printf("root found x = %13.10f, newton iterations = %d, secant iterations = %d\n", root, result_newton_analytic.iterations, result_secant.iterations);
        }
    }
}




// this function runs example from lab 11
void run_example_lab11()
{
    cout << fixed << setprecision(10);

    double start;
    double end;

    cout << "lab 11 - nonlinear equations" << endl;
    cout << "enter start of interval: ";
    cin >> start;

    cout << "enter end of interval: ";
    cin >> end;

    if (start >= end)
    {
        cout << "error: start must be smaller than end" << endl;
        return;
    }

    ofstream file("results_lab11.csv");

    if (!file.is_open())
    {
        cout << "error: cannot open results_lab11.csv" << endl;
        return;
    }

    file << "function;root_id;method;iteration;x_n;f_x_n;error_dx\n";


    cout << endl;
    cout << "running calculations on interval [" << start << ", " << end << "]" << endl;
    double f2_start = start;


    if (f2_start <= 0.0)
    {
        f2_start = 0.1;
        cout << "for function 2 start was changed to 0.1 because of x = 0" << endl;
    }

    search_and_compare_lab11(file, function_1_lab11, derivative_1_lab11, "f1", start, end);
    search_and_compare_lab11(file, function_2_lab11, derivative_2_lab11, "f2", f2_start, end);
    search_and_compare_lab11(file, function_3_lab11, derivative_3_lab11, "f3", start, end);

    file.close();

    cout << endl;
    cout << "all iterations saved to results_lab11.csv" << endl;
}