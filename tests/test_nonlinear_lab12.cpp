#include <iostream>
#include <cmath>
#include <cstdlib>

#include "../include/nonlinear_lab12.hpp"

using namespace std;


// this simple function is used only in tests
double test_function_lab12(double x) {return x * x - 4.0;}


// this derivative is used only in tests
double test_derivative_lab12(double x){ return 2.0 * x;}



// this function has zero derivative at start point
double zero_derivative_function_lab12(double x)  {return x * x * x; }


// this derivative is zero at x = 0
double zero_derivative_test_lab12(double x) { return 3.0 * x * x; }

// this constant function is used to check wrong secant data
double constant_function_lab12(double x){ return 5.0; }



// this test checks numeric derivative
void test_numeric_derivative_lab12()
{
    double result = numeric_derivative_lab12(test_function_lab12, 3.0);
    if (fabs(result - 6.0) > 0.0001)
    {
        cout << "test failed: numeric derivative" << endl;
        exit(1);
    }
}


// this test checks newton method for correct data
void test_newton_method_lab12()
{
    steps_history_lab12 history;


    result_lab12 result = newton_method_lab12(test_function_lab12, test_derivative_lab12, 3.0, false, history);

    if (result.status != converged_lab12)
    {
        cout << "test failed: newton method did not converge" << endl;
        exit(1);
    }

    if (fabs(result.root - 2.0) > 0.000001)
    {
        cout << "test failed: newton method wrong root" << endl;
        exit(1);
    }
}




// this test checks newton method with numeric derivative
void test_newton_numeric_derivative_lab12() {


    steps_history_lab12 history;
    result_lab12 result = newton_method_lab12(test_function_lab12, test_derivative_lab12, 3.0, true, history);


    if (result.status != converged_lab12)
    {
        cout << "test failed: newton numeric derivative did not converge" << endl;
        exit(1);
    }
    if (fabs(result.root - 2.0) > 0.000001)
    {
        cout << "test failed: newton numeric derivative wrong root" << endl;
        exit(1);
    }
}



// this test checks secant method for correct data
void test_secant_method_lab12()
{
    steps_history_lab12 history;
    result_lab12 result = secant_method_lab12(test_function_lab12, 1.0,3.0, history);


    if (result.status != converged_lab12)
    {
        cout << "test failed: secant method did not converge" << endl;
        exit(1);
    }

    if (fabs(result.root - 2.0) > 0.000001)
    {
        cout << "test failed: secant method wrong root" << endl;
        exit(1);
    }
}


// this test checks zero derivative situation
void test_zero_derivative_lab12()
{
    steps_history_lab12 history;
    result_lab12 result = newton_method_lab12(zero_derivative_function_lab12, zero_derivative_test_lab12, 0.0, false, history);

    if (result.status != zero_derivative_lab12)
    {
        cout << "test failed: zero derivative was not detected" << endl;
        exit(1);
    }
}



// this test checks wrong data for secant method
void test_wrong_secant_data_lab12()
{
    steps_history_lab12 history;

    result_lab12 result = secant_method_lab12(constant_function_lab12, 1.0, 2.0, history);


    if (result.status != zero_derivative_lab12)
    {
        cout << "test failed: wrong secant data was not detected" << endl;
        exit(1);
    }
}

int main()
{
    test_numeric_derivative_lab12();
    test_newton_method_lab12();
    test_newton_numeric_derivative_lab12();
    test_secant_method_lab12();
    test_zero_derivative_lab12();
    test_wrong_secant_data_lab12();


    cout << "all nonlinear lab12 tests passed" << endl;
    return 0;
}