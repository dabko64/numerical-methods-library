#include <iostream>
#include <cmath>
#include <cstdlib>

#include "../include/ode_lab9.hpp"

using namespace std;

// this test checks derivative value
void test_derivative_lab9()
{
    double result = derivative_lab9(2.0, 0.5, 0.0);
    if (fabs(result + 8.0) > 0.0000001)
    {
        cout << "test failed: derivative" << endl;
        exit(1);
    }
}



// this test checks one euler step
void test_euler_step_lab9()
{
    double result = euler_step_lab9(2.0, 0.1, 0.5, 0.0);
    if (fabs(result - 1.2) > 0.0000001)
    {
        cout << "test failed: euler step" << endl;
        exit(1);
    }
}



// this test checks exact solution at time zero
void test_exact_solution_time_zero_lab9()
{
    double result = exact_solution_lab9(0.0, 100.0, 0.5);
    if (fabs(result - 100.0) > 0.0000001)
    {
        cout << "test failed: exact solution at time zero" << endl;
        exit(1);
    }
}


// this test checks absolute error
void test_absolute_error_lab9()
{
    double result = absolute_error_lab9(10.0, 7.5);

    if (fabs(result - 2.5) > 0.0000001)
    {
        cout << "test failed: absolute error" << endl;
        exit(1);
    }
}



// this test checks percentage error
void test_percentage_error_lab9()
{
    double result = percentage_error_lab9(100.0, 90.0);
    if (fabs(result - 10.0) > 0.0000001)
    {
        cout << "test failed: percentage error" << endl;
        exit(1);
    }
}



// this test checks wrong step value
void test_wrong_step_lab9()
{
    double result = euler_step_lab9(50.0, 0.0, 0.5, 0.0);


    if (fabs(result - 50.0) > 0.0000001)
    {
        cout << "test failed: wrong step" << endl;
        exit(1);
    }
}

int main()
{
    test_derivative_lab9();
    test_euler_step_lab9();
    test_exact_solution_time_zero_lab9();
    test_absolute_error_lab9();
    test_percentage_error_lab9();
    test_wrong_step_lab9();

    cout << "all ode lab9 tests passed" << endl;

    return 0;
}