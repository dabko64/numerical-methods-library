#include <iostream>
#include <cmath>
#include <stdexcept>

#include "../include/integration_lab7.hpp"

using namespace std;

// this test checks gauss quadrature for correct input data
void test_gauss_quadrature_correct_data_lab7()
{
    double a = -1.0;
    double b = 15.0;
    double exact_value = -136.1836661445;

    double result = composite_gauss_lab7(function_lab7, a, b, 128, 4);
    double error = percentage_error_lab7(exact_value, result);

    if (error > 0.001)
    {
        cout << "test failed: composite gauss quadrature for correct data" << endl;
        exit(1);
    }
}

// this test checks trapezoidal method for correct input data
void test_trapezoidal_correct_data_lab7()
{
    double a = -1.0;
    double b = 15.0;
    double exact_value = -136.1836661445;

    double result = trapezoidal_lab7(function_lab7, a, b, 256);
    double error = percentage_error_lab7(exact_value, result);

    if (error > 0.1)
    {
        cout << "test failed: trapezoidal method for correct data" << endl;
        exit(1);
    }
}

// this test checks simpson method for correct input data
void test_simpson_correct_data_lab7()
{
    double a = -1.0;
    double b = 15.0;
    double exact_value = -136.1836661445;

    double result = simpson_lab7(function_lab7, a, b, 256);
    double error = percentage_error_lab7(exact_value, result);

    if (error > 0.001)
    {
        cout << "test failed: simpson method for correct data" << endl;
        exit(1);
    }
}

// this test checks if wrong number of nodes gives exception
void test_wrong_nodes_lab7()
{
    bool exception_thrown = false;

    try
    {
        gauss_quadrature_lab7(function_lab7, -1.0, 15.0, 5);
    }
    catch (invalid_argument &e)
    {
        exception_thrown = true;
    }

    if (!exception_thrown)
    {
        cout << "test failed: no exception for wrong number of nodes" << endl;
        exit(1);
    }
}

// this test checks if wrong number of intervals gives exception
void test_wrong_intervals_lab7()
{
    bool exception_thrown = false;

    try
    {
        composite_gauss_lab7(function_lab7, -1.0, 15.0, 0, 3);
    }
    catch (invalid_argument &e)
    {
        exception_thrown = true;
    }

    if (!exception_thrown)
    {
        cout << "test failed: no exception for zero intervals" << endl;
        exit(1);
    }
}

// this test checks percentage error function
void test_percentage_error_lab7()
{
    double result = percentage_error_lab7(100.0, 90.0);

    if (fabs(result - 10.0) > 0.0000001)
    {
        cout << "test failed: percentage error" << endl;
        exit(1);
    }
}

int main()
{
    test_gauss_quadrature_correct_data_lab7();
    test_trapezoidal_correct_data_lab7();
    test_simpson_correct_data_lab7();
    test_wrong_nodes_lab7();
    test_wrong_intervals_lab7();
    test_percentage_error_lab7();

    cout << "all integration lab7 tests passed" << endl;

    return 0;
}