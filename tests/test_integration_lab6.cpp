#include <iostream>
#include <cmath>
#include <stdexcept>

#include "../include/integration_lab6.hpp"

using namespace std;

// this test checks simpson method for correct input data
void test_simpson_correct_data_lab6()
{
    double a = 0.0;
    double b = 3.0;
    int n = 1000;

    double exact_value = -0.07686081533310683;

    double result = simpson_lab6(a, b, n);
    double error = absolute_error_lab6(exact_value, result);

    if (error > 0.000001)
    {
        cout << "test failed: simpson method for correct data" << endl;
        exit(1);
    }
}

// this test checks trapezoidal method for correct input data
void test_trapezoidal_correct_data_lab6()
{
    double a = 0.0;
    double b = 3.0;
    int n = 1000;

    double exact_value = -0.07686081533310683;

    double result = trapezoidal_lab6(a, b, n);
    double error = absolute_error_lab6(exact_value, result);

    if (error > 0.001)
    {
        cout << "test failed: trapezoidal method for correct data" << endl;
        exit(1);
    }
}

// this test checks if method throws exception for wrong n value
void test_wrong_n_value_lab6()
{
    bool exception_thrown = false;

    try
    {
        trapezoidal_lab6(0.0, 3.0, 0);
    }
    catch (invalid_argument &e)
    {
        exception_thrown = true;
    }

    if (!exception_thrown)
    {
        cout << "test failed: no exception for n = 0" << endl;
        exit(1);
    }
}

// this test checks absolute error function

void test_absolute_error_lab6()
{
    double result = absolute_error_lab6(10.0, 7.5);

    if (fabs(result - 2.5) > 0.0000001)
    {
        cout << "test failed: absolute error" << endl;
        exit(1);
    }
}

// this test checks if convergence order throws exception for wrong error value
void test_convergence_order_wrong_data_lab6()
{
    bool exception_thrown = false;

    try
    {
        convergence_order_lab6(0.0, 0.1);
    }
    catch (invalid_argument &e)
    {
        exception_thrown = true;
    }

    if (!exception_thrown)
    {
        cout << "test failed: no exception for zero error" << endl;
        exit(1);
    }
}

int main()
{
    test_simpson_correct_data_lab6();
    test_trapezoidal_correct_data_lab6();
    test_wrong_n_value_lab6();
    test_absolute_error_lab6();
    test_convergence_order_wrong_data_lab6();

    cout << "all integration lab6 tests passed" << endl;

    return 0;
}