#include <iostream>
#include <cmath>


#include "../include/ode_lab10.hpp"

using namespace std;




// this test checks derivative value
void test_derivative_lab10()
{
    double result = derivative_lab10(2.0, 0.5, 0.0);

    if (fabs(result + 8.0) > 0.0000001)
    {
        cout << "test failed: derivative" << endl;
        exit(1);
    }
}



// this test checks one euler step
void test_euler_step_lab10()
{
    double result = euler_step_lab10(2.0, 0.1, 0.5, 0.0);

    if (fabs(result - 1.2) > 0.0000001)
    {
        cout << "test failed: euler step" << endl;
        exit(1);
    }
}



// this test checks one heun step
void test_heun_step_lab10()
{
    double result = heun_step_lab10(2.0, 0.1, 0.5, 0.0);

    if (fabs(result - 1.80192) > 0.0001)
    {
        cout << "test failed: heun step" << endl;
        exit(1);
    }
}



// this test checks one midpoint step
void test_midpoint_step_lab10()
{
    double result = midpoint_step_lab10(2.0, 0.1, 0.5, 0.0);

    if (fabs(result - 1.6288) > 0.0001)
    {
        cout << "test failed: midpoint step" << endl;
        exit(1);
    }
}




// this test checks one runge kutta 4 step
void test_runge_kutta_4_step_lab10()
{
    double result = runge_kutta_4_step_lab10(2.0, 0.1, 0.5, 0.0);

    if (result <= 0.0 || result >= 2.0)
    {
        cout << "test failed: runge kutta 4 step" << endl;
        exit(1);
    }
}



// this test checks exact solution at time zero
void test_exact_solution_time_zero_lab10()
{
    double result = exact_solution_lab10(0.0, 100.0, 0.5);

    if (fabs(result - 100.0) > 0.0000001)
    {
        cout << "test failed: exact solution at time zero" << endl;
        exit(1);
    }
}




// this test checks wrong step value
void test_wrong_step_lab10()
{
    double result = euler_step_lab10(50.0, 0.0, 0.5, 0.0);
    if (fabs(result - 50.0) > 0.0000001)
    {
        cout << "test failed: wrong step" << endl;
        exit(1);
    }
}

int main()
{
    test_derivative_lab10();
    test_euler_step_lab10();
    test_heun_step_lab10();
    test_midpoint_step_lab10();
    test_runge_kutta_4_step_lab10();
    test_exact_solution_time_zero_lab10();
    test_wrong_step_lab10();

    cout << "all ode lab10 tests passed" << endl;

    return 0;
}