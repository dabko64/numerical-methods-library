#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <fstream>
#include <string>
#include <stdexcept>

#include "../include/integration_lab6.hpp"

using namespace std;

// this function comes from lab 6
// f(x) = cos(12x + 1) / (1 + x^2)

double function_lab6(double x)  {return cos(12.0 * x + 1.0) / (1.0 + x * x);}

// this function calculates the integral using the left rectangle method
double left_rectangle_lab6(double a, double b, int n)
{
    if (n <= 0)
    {
        throw invalid_argument("number of intervals must be positive");
    }

    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        double x = a + i * h;
        sum += function_lab6(x);
    }

    return h * sum;
}

// this function calculates the integral using the midpoint rectangle method

double midpoint_rectangle_lab6(double a, double b, int n)
{
    if (n <= 0)
    {
        throw invalid_argument("number of intervals must be positive");
    }

    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        double x = a + (i + 0.5) * h;
        sum += function_lab6(x);
    }

    return h * sum;
}

// this function calculates the integral using the trapezoidal method
double trapezoidal_lab6(double a, double b, int n)
{
    if (n <= 0)
    {
        throw invalid_argument("number of intervals must be positive");
    }

    double h = (b - a) / n;
    double sum = 0.5 * function_lab6(a) + 0.5 * function_lab6(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        sum += function_lab6(x);
    }

    return h * sum;
}

// this function calculates the integral using simpson method
double simpson_lab6(double a, double b, int n)
{
    if (n <= 0)
    {
        throw invalid_argument("number of intervals must be positive");
    }

    if (n % 2 != 0)
    {
        n++;
    }

    double h = (b - a) / n;
    double sum = function_lab6(a) + function_lab6(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;

        if (i % 2 == 0)
        {
            sum += 2.0 * function_lab6(x);
        }
        else
        {
            sum += 4.0 * function_lab6(x);
        }
    }

    return (h / 3.0) * sum;
}

// this function calculates absolute error
double absolute_error_lab6(double exact_value, double approximate_value){return fabs(exact_value - approximate_value);}

// this function calculates experimental convergence order
double convergence_order_lab6(double error_n, double error_2n)
{
    if (error_n <= 0.0 || error_2n <= 0.0)
    {
        throw invalid_argument("errors must be positive");
    }

    return log(error_n / error_2n) / log(2.0);
}

// this function measures method execution time in microseconds
double measure_time_lab6(double (*method)(double, double, int), double a, double b, int n, double &result)
{
    auto start = chrono::high_resolution_clock::now();

    result = method(a, b, n);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, micro> time = end - start;
    return time.count();
}

// this function runs the full lab 6 example and saves results to csv

void run_example_lab6()
{
    double a = 0.0;
    double b = 3.0;

    double exact_value = -0.07686081533310683;

    ofstream file("results_lab6.csv");

    if (!file)
    {
        cout << "error: cannot create results_lab6.csv" << endl;
        return;
    }

    file << fixed << setprecision(15);

    file << "n;"
         << "left_rectangle;left_rectangle_error;left_rectangle_time;"
         << "midpoint_rectangle;midpoint_rectangle_error;midpoint_rectangle_time;"
         << "trapezoidal;trapezoidal_error;trapezoidal_time;"
         << "simpson;simpson_error;simpson_time\n";

    cout << fixed << setprecision(15);

    cout << "lab 6 - numerical integration 1" << endl;
    cout << "function: f(x) = cos(12x + 1) / (1 + x^2)" << endl;
    cout << "interval: [" << a << ", " << b << "]" << endl;
    cout << "exact value: " << exact_value << endl;

    cout << endl;
    cout << "results" << endl;

    cout << setw(8) << "n"
         << setw(22) << "left"
         << setw(18) << "error"
         << setw(22) << "midpoint"
         << setw(18) << "error"
         << setw(22) << "trapezoidal"
         << setw(18) << "error"
         << setw(22) << "simpson"
         << setw(18) << "error"
         << endl;

    cout << string(150, '-') << endl;

    for (int n = 10; n <= 10000; n *= 2)
    {
        double result_left;
        double result_midpoint;
        double result_trapezoidal;
        double result_simpson;

        double time_left = measure_time_lab6(left_rectangle_lab6, a, b, n, result_left);
        double time_midpoint = measure_time_lab6(midpoint_rectangle_lab6, a, b, n, result_midpoint);
        double time_trapezoidal = measure_time_lab6(trapezoidal_lab6, a, b, n, result_trapezoidal);
        double time_simpson = measure_time_lab6(simpson_lab6, a, b, n, result_simpson);

        double error_left = absolute_error_lab6(exact_value, result_left);
        double error_midpoint = absolute_error_lab6(exact_value, result_midpoint);
        double error_trapezoidal = absolute_error_lab6(exact_value, result_trapezoidal);
        double error_simpson = absolute_error_lab6(exact_value, result_simpson);

        cout << setw(8) << n
             << setw(22) << result_left
             << setw(18) << error_left
             << setw(22) << result_midpoint
             << setw(18) << error_midpoint
             << setw(22) << result_trapezoidal
             << setw(18) << error_trapezoidal
             << setw(22) << result_simpson
             << setw(18) << error_simpson
             << endl;

        file << n << ";"
             << result_left << ";" << error_left << ";" << time_left << ";"
             << result_midpoint << ";" << error_midpoint << ";" << time_midpoint << ";"
             << result_trapezoidal << ";" << error_trapezoidal << ";" << time_trapezoidal << ";"
             << result_simpson << ";" << error_simpson << ";" << time_simpson << "\n";
    }

    file.close();

    cout << endl;
    cout << "convergence order" << endl;

    int n1 = 1000;
    int n2 = 2000;

    double left_1 = left_rectangle_lab6(a, b, n1);
    double left_2 = left_rectangle_lab6(a, b, n2);

    double midpoint_1 = midpoint_rectangle_lab6(a, b, n1);
    double midpoint_2 = midpoint_rectangle_lab6(a, b, n2);

    double trapezoidal_1 = trapezoidal_lab6(a, b, n1);
    double trapezoidal_2 = trapezoidal_lab6(a, b, n2);

    double simpson_1 = simpson_lab6(a, b, n1);
    double simpson_2 = simpson_lab6(a, b, n2);

    double error_left_1 = absolute_error_lab6(exact_value, left_1);
    double error_left_2 = absolute_error_lab6(exact_value, left_2);

    double error_midpoint_1 = absolute_error_lab6(exact_value, midpoint_1);
    double error_midpoint_2 = absolute_error_lab6(exact_value, midpoint_2);

    double error_trapezoidal_1 = absolute_error_lab6(exact_value, trapezoidal_1);
    double error_trapezoidal_2 = absolute_error_lab6(exact_value, trapezoidal_2);

    double error_simpson_1 = absolute_error_lab6(exact_value, simpson_1);
    double error_simpson_2 = absolute_error_lab6(exact_value, simpson_2);

    cout << "left rectangle method: "
         << convergence_order_lab6(error_left_1, error_left_2) << endl;

    cout << "midpoint rectangle method: "
         << convergence_order_lab6(error_midpoint_1, error_midpoint_2) << endl;

    cout << "trapezoidal method: "
         << convergence_order_lab6(error_trapezoidal_1, error_trapezoidal_2) << endl;

    cout << "simpson method: "
         << convergence_order_lab6(error_simpson_1, error_simpson_2) << endl;

    cout << endl;
    cout << "data saved to results_lab6.csv" << endl;
}