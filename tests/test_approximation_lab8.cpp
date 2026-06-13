#include <iostream>
#include <cmath>

#include "../include/approximation_lab8.hpp"

using namespace std;

// this test checks polynomial value
void test_polynomial_value_lab8()
{
    double coeff[max_degree_lab8 + 1];
    for (int i = 0; i <= max_degree_lab8; i++) {coeff[i] = 0.0;}
    coeff[0] = 1.0;
    coeff[1] = 2.0;
    coeff[2] = 3.0;

    double result = polynomial_value_lab8(coeff, 2, 2.0);



    if (fabs(result - 17.0) > 0.0000001)
    {
        cout << "test failed: polynomial value" << endl;
        exit(1);
    }
}

// this test checks integral of power
void test_power_integral_lab8()
{
    double result = power_integral_lab8(0);
    if (fabs(result - 6.0) > 0.0000001)
    {
        cout << "test failed: power integral" << endl;
        exit(1);
    }
}


// this test checks gauss method for simple system
void test_gaussian_elimination_lab8()
{
    double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1];
    double rhs[max_degree_lab8 + 1];
    double result[max_degree_lab8 + 1];

    for (int i = 0; i <= max_degree_lab8; i++)
    {
        rhs[i] = 0.0;
        result[i] = 0.0;

        for (int j = 0; j <= max_degree_lab8; j++) {matrix[i][j] = 0.0;}
    }

    matrix[0][0] = 2.0;
    matrix[0][1] = 1.0;
    matrix[1][0] = 1.0;
    matrix[1][1] = 3.0;
    rhs[0] = 5.0;
    rhs[1] = 6.0;


    bool solved = gaussian_elimination_silent_lab8(matrix, rhs, result, 1);

    if (!solved)
    {
        cout << "test failed: gauss method did not solve system" << endl;
        exit(1);
    }
    if (fabs(result[0] - 1.8) > 0.0000001 || fabs(result[1] - 1.4) > 0.0000001)
    {
        cout << "test failed: gauss method wrong result" << endl;
        exit(1);
    }
}

// this test checks wrong polynomial degree
void test_wrong_degree_lab8()
{
    double coeff[max_degree_lab8 + 1];
    for (int i = 0; i <= max_degree_lab8; i++){coeff[i] = 0.0;}

    double result = polynomial_value_lab8(coeff, -1, 2.0);


    if (result != 0.0)
    {
        cout << "test failed: wrong degree" << endl;
        exit(1);
    }
}

// this test checks singular system
void test_singular_system_lab8()
{
    double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1];
    double rhs[max_degree_lab8 + 1];
    double result[max_degree_lab8 + 1];

    for (int i = 0; i <= max_degree_lab8; i++)
    {
        rhs[i] = 0.0;
        result[i] = 0.0;

        for (int j = 0; j <= max_degree_lab8; j++){matrix[i][j] = 0.0;}
    }

    matrix[0][0] = 0.0;
    matrix[0][1] = 0.0;
    matrix[1][0] = 0.0;
    matrix[1][1] = 0.0;

    rhs[0] = 1.0;
    rhs[1] = 1.0;

    bool solved = gaussian_elimination_silent_lab8(matrix, rhs, result, 1);

    if (solved)
    {
        cout << "test failed: singular system should not be solved" << endl;
        exit(1);
    }
}

int main()
{
    test_polynomial_value_lab8();
    test_power_integral_lab8();
    test_gaussian_elimination_lab8();
    test_wrong_degree_lab8();
    test_singular_system_lab8();

    cout << "all approximation lab8 tests passed" << endl;

    return 0;
}