#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

#include "../include/approximation_lab8.hpp"

using namespace std;

const double a_interval_lab8 = 5.0;
const double b_interval_lab8 = 11.0;

// this function comes from lab 8
double function_lab8(double x){return x * x * sin(x) * sin(x) - x * x + x;}

// this function calculates integral of x to given power
double power_integral_lab8(int power)
{
    if (power < 0)
    {
        cout << "error: power cannot be negative" << endl;
        return 0.0;
    }

    return (pow(b_interval_lab8, power + 1) - pow(a_interval_lab8, power + 1)) / (power + 1);
}

// this function calculates integral of f(x) times x to given power
double function_times_power_integral_lab8(int power)
{
    if (power < 0)
    {
        cout << "error: power cannot be negative" << endl;
        return 0.0;
    }

    int n = simpson_n_lab8;
    if (n % 2 == 1) {n++;}


    double h = (b_interval_lab8 - a_interval_lab8) / n;
    double sum = function_lab8(a_interval_lab8) * pow(a_interval_lab8, power) + function_lab8(b_interval_lab8) * pow(b_interval_lab8, power);

    for (int i = 1; i < n; i++)
    {
        double x = a_interval_lab8 + i * h;
        double value = function_lab8(x) * pow(x, power);

        if (i % 2 == 0) {sum += 2.0 * value;}
        else {sum += 4.0 * value;}
    }

    return sum * h / 3.0;
}

// this function calculates polynomial value using horner method
double polynomial_value_lab8(double coeff[], int degree, double x)
{
    if (degree < 0 || degree > max_degree_lab8)
    {
        cout << "error: wrong polynomial degree" << endl;
        return 0.0;
    }

    double result = 0.0;

    for (int i = degree; i >= 0; i--) {result = result * x + coeff[i];}

    return result;
}

// this function creates normal equation system
void create_system_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1], double rhs[max_degree_lab8 + 1], int degree)
{
    if (degree < 1 || degree > max_degree_lab8)
    {
        cout << "error: wrong polynomial degree" << endl;
        return;
    }

    for (int row = 0; row <= degree; row++)
    {
        for (int col = 0; col <= degree; col++)
        {
            matrix[row][col] = power_integral_lab8(row + col);
        }
        rhs[row] = function_times_power_integral_lab8(row);
    }
}

// this function prints matrix
void print_matrix_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1],
                       int degree)
{
    cout << endl;
    cout << "matrix a:" << endl;
    cout << "[" << endl;

    for (int i = 0; i <= degree; i++)
    {
        cout << "  [ ";

        for (int j = 0; j <= degree; j++)
        {
            cout << setw(14) << fixed << setprecision(3) << matrix[i][j];

            if (j < degree){ cout << ", "; }
        }
        cout << " ]" << endl;
    }
    cout << "]" << endl;
}


// this function prints vector
void print_vector_lab8(double rhs[max_degree_lab8 + 1],
                       int degree)
{
    cout << endl;
    cout << "vector b:" << endl;
    cout << "[" << endl;

    for (int i = 0; i <= degree; i++)
    {
        cout << "  [ " << setw(14) << fixed << setprecision(3) << rhs[i] << " ]" << endl;
    }

    cout << "]" << endl;
}

// this function prints augmented matrix
void print_augmented_matrix_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 2],
                                 int size)
{
    cout << "[" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "  [ ";
        for (int j = 0; j <= size; j++)
        {
            if (j == size)
            {
                cout << " | ";
            }

            cout << setw(14) << fixed << setprecision(3) << matrix[i][j];

            if (j < size - 1)
            {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
    }
    cout << "]" << endl;
}


// this function saves matrix and vector to txt file
void save_system_to_file_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1],
                              double rhs[max_degree_lab8 + 1],
                              int degree)
{
    ofstream file("matrix_a_b_lab8.txt");

    if (!file)
    {
        cout << "error: cannot create matrix_a_b_lab8.txt" << endl;
        return;
    }

    file << fixed << setprecision(10);

    file << "matrix a:" << endl;
    file << "[" << endl;

    for (int i = 0; i <= degree; i++)
    {
        file << "  [ ";
        for (int j = 0; j <= degree; j++)
        {
            file << setw(20) << matrix[i][j];
            if (j < degree) { file << ", "; }
        }
        file << " ]" << endl;
    }
    file << "]" << endl << endl;

    file << "vector b:" << endl;
    file << "[" << endl;

    for (int i = 0; i <= degree; i++)
    {
        file << "  [ " << setw(20) << rhs[i] << " ]" << endl;
    }
    file << "]" << endl;
    file.close();
}

// this function solves linear system using gauss method
bool gaussian_elimination_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1],
                               double rhs[max_degree_lab8 + 1],
                               double result[max_degree_lab8 + 1],
                               int degree)
{
    int size = degree + 1;

    double augmented[max_degree_lab8 + 1][max_degree_lab8 + 2];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            augmented[i][j] = matrix[i][j];
        }

        augmented[i][size] = rhs[i];
    }

    cout << endl;
    cout << "augmented matrix before elimination:" << endl;
    print_augmented_matrix_lab8(augmented, size);

    for (int k = 0; k < size - 1; k++)
    {
        int max_row = k;

        for (int i = k + 1; i < size; i++)
        {
            if (fabs(augmented[i][k]) > fabs(augmented[max_row][k]))
            {
                max_row = i;
            }
        }

        if (max_row != k)
        {
            for (int j = k; j <= size; j++)
            {
                double temp = augmented[k][j];
                augmented[k][j] = augmented[max_row][j];
                augmented[max_row][j] = temp;
            }
        }

        if (fabs(augmented[k][k]) < 1e-14)
        {
            cout << "error: pivot is close to zero" << endl;
            return false;
        }
        for (int i = k + 1; i < size; i++)
        {
            double factor = augmented[i][k] / augmented[k][k];

            for (int j = k; j <= size; j++)
            {
                augmented[i][j] = augmented[i][j] - factor * augmented[k][j];
            }
        }
    }

    cout << endl;
    cout << "augmented matrix after elimination:" << endl;
    print_augmented_matrix_lab8(augmented, size);

    for (int i = size - 1; i >= 0; i--)
    {
        double sum = augmented[i][size];
        for (int j = i + 1; j < size; j++)
        {
            sum = sum - augmented[i][j] * result[j];
        }
        if (fabs(augmented[i][i]) < 1e-14)
        {
            cout << "error: pivot is close to zero" << endl;
            return false;
        }

        result[i] = sum / augmented[i][i];
    }

    return true;
}

// this function solves linear system without printing
bool gaussian_elimination_silent_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1],
                                      double rhs[max_degree_lab8 + 1],
                                      double result[max_degree_lab8 + 1],
                                      int degree)
{
    int size = degree + 1;

    double augmented[max_degree_lab8 + 1][max_degree_lab8 + 2];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) { augmented[i][j] = matrix[i][j]; }
        augmented[i][size] = rhs[i];
    }

    for (int k = 0; k < size - 1; k++)
    {
        int max_row = k;
        for (int i = k + 1; i < size; i++)
        {
            if (fabs(augmented[i][k]) > fabs(augmented[max_row][k]))
            {max_row = i;}
        }

        if (max_row != k)
        {
            for (int j = k; j <= size; j++)
            {
                double temp = augmented[k][j];
                augmented[k][j] = augmented[max_row][j];
                augmented[max_row][j] = temp;
            }
        }

        if (fabs(augmented[k][k]) < 1e-14)
        {
            cout << "error: pivot is close to zero" << endl;
            return false;
        }

        for (int i = k + 1; i < size; i++)
        {
            double factor = augmented[i][k] / augmented[k][k];
            for (int j = k; j <= size; j++)
            {
                augmented[i][j] = augmented[i][j] - factor * augmented[k][j];
            }
        }
    }

    for (int i = size - 1; i >= 0; i--)
    {
        double sum = augmented[i][size];
        for (int j = i + 1; j < size; j++)
        {
            sum = sum - augmented[i][j] * result[j];
        }

        if (fabs(augmented[i][i]) < 1e-14)
        {
            cout << "error: pivot is close to zero" << endl;
            return false;
        }

        result[i] = sum / augmented[i][i];
    }

    return true;
}

// this function calculates mean square error
double mean_square_error_lab8(double coeff[max_degree_lab8 + 1],
                              int degree)
{
    int n = simpson_n_lab8;

    if (n % 2 == 1) {n++;}

    double h = (b_interval_lab8 - a_interval_lab8) / n;

    double diff_a = polynomial_value_lab8(coeff, degree, a_interval_lab8) - function_lab8(a_interval_lab8);

    double diff_b = polynomial_value_lab8(coeff, degree, b_interval_lab8) - function_lab8(b_interval_lab8);

    double sum = diff_a * diff_a + diff_b * diff_b;

    for (int i = 1; i < n; i++)
    {
        double x = a_interval_lab8 + i * h;
        double diff = polynomial_value_lab8(coeff, degree, x) - function_lab8(x);
        double value = diff * diff;

        if (i % 2 == 0){sum += 2.0 * value;}
        else{sum += 4.0 * value;}
    }

    return sum * h / 3.0;
}

// this function saves function values and approximation values to csv
void save_plot_data_lab8(double coeff[max_degree_lab8 + 1],
                         int degree)
{
    ofstream file("results_lab8.csv");

    if (!file)
    {
        cout << "error: cannot create results_lab8.csv" << endl;
        return;
    }

    file << "x;f_x;approximation;error\n";

    int points = 100;

    for (int i = 0; i <= points; i++)
    {
        double x = a_interval_lab8 + (b_interval_lab8 - a_interval_lab8) * i / points;
        double fx = function_lab8(x);
        double px = polynomial_value_lab8(coeff, degree, x);
        double error = px - fx;

        file << fixed << setprecision(10)
             << x << ";"
             << fx << ";"
             << px << ";"
             << error << "\n";
    }

    file.close();
}

// this function saves error analysis for many polynomial degrees
void save_degree_analysis_lab8(int max_degree)
{
    if (max_degree < 1 || max_degree > max_degree_lab8)
    {
        cout << "error: wrong max degree" << endl;
        return;
    }

    ofstream file("degree_analysis_lab8.csv");
    if (!file)
    {
        cout << "error: cannot create degree_analysis_lab8.csv" << endl;
        return;
    }

    file << "degree;h;sqrt_h\n";
    for (int degree = 1; degree <= max_degree; degree++)
    {
        double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1];
        double rhs[max_degree_lab8 + 1];
        double coeff[max_degree_lab8 + 1];

        for (int i = 0; i <= max_degree_lab8; i++)
        {
            rhs[i] = 0.0;
            coeff[i] = 0.0;

            for (int j = 0; j <= max_degree_lab8; j++)
            {
                matrix[i][j] = 0.0;
            }
        }

        create_system_lab8(matrix, rhs, degree);
        gaussian_elimination_silent_lab8(matrix, rhs, coeff, degree);

        double error = mean_square_error_lab8(coeff, degree);

        file << fixed << setprecision(10)
             << degree << ";"
             << error << ";"
             << sqrt(error) << "\n";
    }

    file.close();
}

// this function runs the full lab 8 example
void run_example_lab8()
{
    cout << fixed << setprecision(10);
    int degree;
    cout << "enter polynomial degree from 1 to " << max_degree_lab8 << ": ";
    cin >> degree;
    if (degree < 1 || degree > max_degree_lab8)
    {
        cout << "error: wrong polynomial degree" << endl;
        return;
    }

    double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1];
    double rhs[max_degree_lab8 + 1];
    double coeff[max_degree_lab8 + 1];

    for (int i = 0; i <= max_degree_lab8; i++)
    {
        rhs[i] = 0.0;
        coeff[i] = 0.0;
        for (int j = 0; j <= max_degree_lab8; j++){matrix[i][j] = 0.0;}
    }

    create_system_lab8(matrix, rhs, degree);

    cout << endl;
    cout << "lab 8 - polynomial approximation" << endl;
    cout << "function: f(x) = x^2 * sin(x)^2 - x^2 + x" << endl;
    cout << "interval: [5, 11]" << endl;
    cout << "polynomial degree: " << degree << endl;


    print_matrix_lab8(matrix, degree);
    print_vector_lab8(rhs, degree);
    save_system_to_file_lab8(matrix, rhs, degree);
    bool solved = gaussian_elimination_lab8(matrix, rhs, coeff, degree);


    if (!solved)
    {
        cout << "error: system was not solved" << endl;
        return;
    }

    cout << endl;
    cout << "polynomial coefficients:" << endl;

    for (int i = 0; i <= degree; i++)
    {
        cout << "a" << i << " = " << coeff[i] << endl;
    }
    double error = mean_square_error_lab8(coeff, degree);

    cout << endl;
    cout << "mean square error h = " << error << endl;
    cout << "sqrt h = " << sqrt(error) << endl;

    save_plot_data_lab8(coeff, degree);
    save_degree_analysis_lab8(max_degree_lab8);

    cout << endl;
    cout << "data saved to results_lab8.csv" << endl;
    cout << "degree analysis saved to degree_analysis_lab8.csv" << endl;
    cout << "matrix saved to matrix_a_b_lab8.txt" << endl;
}