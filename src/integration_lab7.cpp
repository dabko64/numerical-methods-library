#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>

#include "../include/integration_lab7.hpp"

using namespace std;

// this function comes from lab 7 f(x) = (1 - x) * exp(sin(x))
double function_lab7(double x){return (1.0 - x) * exp(sin(x));}

// this function calculates the integral using the trapezoidal method
double trapezoidal_lab7(double (*f)(double), double a, double b, int n)
{
    if (n <= 0) {throw invalid_argument("number of intervals must be positive");}

    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        sum += f(x);
    }

    return sum * h;
}

// this function calculates the integral using simpson method
double simpson_lab7(double (*f)(double), double a, double b, int n)
{
    if (n <= 0) {throw invalid_argument("number of intervals must be positive");}

    if (n % 2 != 0){n++;}

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
         if (i % 2 == 0) {sum += 2.0 * f(x);}
         else {sum += 4.0 * f(x);}
    }
    return (h / 3.0) * sum;
}


// this function calculates gauss quadrature on one interval
double gauss_quadrature_lab7(double (*f)(double), double a, double b, int nodes)
{
    double x[4];
    double w[4];

    if (nodes == 2)
    {
        x[0] = -1.0 / sqrt(3.0);
        x[1] = 1.0 / sqrt(3.0);

        w[0] = 1.0;
        w[1] = 1.0;
    }
    else if (nodes == 3)
    {
        x[0] = -sqrt(3.0 / 5.0);
        x[1] = 0.0;
        x[2] = sqrt(3.0 / 5.0);

        w[0] = 5.0 / 9.0;
        w[1] = 8.0 / 9.0;
        w[2] = 5.0 / 9.0;
    }
    else if (nodes == 4)
    {
        x[0] = -sqrt(3.0 / 7.0 + (2.0 / 7.0) * sqrt(6.0 / 5.0));
        x[1] = -sqrt(3.0 / 7.0 - (2.0 / 7.0) * sqrt(6.0 / 5.0));
        x[2] = sqrt(3.0 / 7.0 - (2.0 / 7.0) * sqrt(6.0 / 5.0));
        x[3] = sqrt(3.0 / 7.0 + (2.0 / 7.0) * sqrt(6.0 / 5.0));

        w[0] = (18.0 - sqrt(30.0)) / 36.0;
        w[1] = (18.0 + sqrt(30.0)) / 36.0;
        w[2] = (18.0 + sqrt(30.0)) / 36.0;
        w[3] = (18.0 - sqrt(30.0)) / 36.0;
    }
    else
    {
        throw invalid_argument("number of nodes must be 2, 3 or 4");
    }

    double sum = 0.0;

    for (int i = 0; i < nodes; i++)
    {
        double transformed_x = ((b - a) / 2.0) * x[i] + ((a + b) / 2.0);
        sum += w[i] * f(transformed_x);
    }

    return ((b - a) / 2.0) * sum;
}

// this function calculates composite gauss quadrature
double composite_gauss_lab7(double (*f)(double), double a, double b, int intervals, int nodes)
{
    if (intervals <= 0)
    {
        throw invalid_argument("number of intervals must be positive");
    }

    double h = (b - a) / intervals;
    double sum = 0.0;

    for (int i = 0; i < intervals; i++)
    {
        double start = a + i * h;
        double end = start + h;

        sum += gauss_quadrature_lab7(f, start, end, nodes);
    }

    return sum;
}

// this function calculates absolute error
double absolute_error_lab7(double exact_value, double approximate_value) {return fabs(exact_value - approximate_value);}

// this function calculates percentage error
double percentage_error_lab7(double exact_value, double approximate_value)
{
    if (exact_value == 0.0)
    {
        throw invalid_argument("exact value cannot be zero");
    }

    return fabs(exact_value - approximate_value) / fabs(exact_value) * 100.0;
}

// this function runs the full lab 7 example
void run_example_lab7()
{
    double a = -1.0;
    double b = 15.0;

    double exact_value = -136.1836661445;

    int intervals[] = {2, 4, 8, 16, 32, 64, 128, 256};

    cout << fixed << setprecision(10);

    cout << "lab 7 - numerical integration 2" << endl;
    cout << "function: f(x) = (1 - x) * exp(sin(x))" << endl;
    cout << "interval: [" << a << ", " << b << "]" << endl;
    cout << "exact value: " << exact_value << endl;

    cout << endl;
    cout << "gauss quadrature on the full interval" << endl;
    cout << "nodes\tresult\t\tabsolute error\tpercentage error" << endl;

    for (int nodes = 2; nodes <= 4; nodes++)
    {
        double result = gauss_quadrature_lab7(function_lab7, a, b, nodes);

        double error = absolute_error_lab7(exact_value, result);
        double percent_error = percentage_error_lab7(exact_value, result);

        cout << nodes << "\t"
             << result << "\t"
             << error << "\t"
             << percent_error << "%" << endl;
    }

    cout << endl;
    cout << "composite gauss quadrature" << endl;
    cout << "n\tg2 result\tg2 error %\tg3 result\tg3 error %\tg4 result\tg4 error %" << endl;

    for (int i = 0; i < 8; i++)
    {
        int n = intervals[i];

        double result_g2 = composite_gauss_lab7(function_lab7, a, b, n, 2);
        double result_g3 = composite_gauss_lab7(function_lab7, a, b, n, 3);
        double result_g4 = composite_gauss_lab7(function_lab7, a, b, n, 4);

        double error_g2 = percentage_error_lab7(exact_value, result_g2);
        double error_g3 = percentage_error_lab7(exact_value, result_g3);
        double error_g4 = percentage_error_lab7(exact_value, result_g4);

        cout << n << "\t"
             << result_g2 << "\t" << error_g2 << "%\t"
             << result_g3 << "\t" << error_g3 << "%\t"
             << result_g4 << "\t" << error_g4 << "%" << endl;
    }

    cout << endl;
    cout << "trapezoidal method and simpson method" << endl;
    cout << "n\ttrapezoidal\ttrapezoidal error %\tsimpson\t\tsimpson error %" << endl;

    for (int i = 0; i < 8; i++)
    {
        int n = intervals[i];

        double result_trapezoidal = trapezoidal_lab7(function_lab7, a, b, n);
        double result_simpson = simpson_lab7(function_lab7, a, b, n);

        double error_trapezoidal = percentage_error_lab7(exact_value, result_trapezoidal);
        double error_simpson = percentage_error_lab7(exact_value, result_simpson);

        cout << n << "\t"
             << result_trapezoidal << "\t"
             << error_trapezoidal << "%\t"
             << result_simpson << "\t"
             << error_simpson << "%" << endl;
    }
}