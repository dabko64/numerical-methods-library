#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

#include "../include/ode_lab10.hpp"

using namespace std;



// this function calculates the right side of the differential equation
double derivative_lab10(double temperature, double alpha, double beta){return -alpha * (pow(temperature, 4) - beta);}




// this function calculates exact solution for beta equal to zero
double exact_solution_lab10(double time, double initial_temperature, double alpha)
{
    if (initial_temperature == 0.0)
    {
        cout << "error: initial temperature cannot be zero" << endl;
        return 0.0;
    }
    return 1.0 / cbrt(3.0 * alpha * time + 1.0 / pow(initial_temperature, 3));
}




// this function makes one euler method step
double euler_step_lab10(double temperature, double step, double alpha, double beta)
{
    if (step <= 0.0)
    {
        cout << "error: step must be positive" << endl;
        return temperature;
    }
    return temperature + step * derivative_lab10(temperature, alpha, beta);
}




// this function makes one heun method step
double heun_step_lab10(double temperature, double step, double alpha, double beta)
{
    if (step <= 0.0)
    {
        cout << "error: step must be positive" << endl;
        return temperature;
    }
    double f1 = derivative_lab10(temperature, alpha, beta);
    double predicted_temperature = temperature + step * f1;
    double f2 = derivative_lab10(predicted_temperature, alpha, beta);
    return temperature + (step / 2.0) * (f1 + f2);
}




// this function makes one midpoint method step
double midpoint_step_lab10(double temperature, double step, double alpha, double beta)
{
    if (step <= 0.0)
    {
        cout << "error: step must be positive" << endl;
        return temperature;
    }
    double f1 = derivative_lab10(temperature, alpha, beta);
    double middle_temperature = temperature + (step / 2.0) * f1;
    double middle_value = derivative_lab10(middle_temperature, alpha, beta);
    return temperature + step * middle_value;
}





// this function makes one runge kutta 4 method step
double runge_kutta_4_step_lab10(double temperature, double step, double alpha, double beta)
{
    if (step <= 0.0)
    {
        cout << "error: step must be positive" << endl;
        return temperature;
    }
    double k1 = step * derivative_lab10(temperature, alpha, beta);
    double k2 = step * derivative_lab10(temperature + k1 / 2.0, alpha, beta);
    double k3 = step * derivative_lab10(temperature + k2 / 2.0, alpha, beta);
    double k4 = step * derivative_lab10(temperature + k3, alpha, beta);
    return temperature + (1.0 / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
}

// this function calculates absolute error
double absolute_error_lab10(double exact_value, double approximate_value){return fabs(exact_value - approximate_value);}



// this function saves one row to csv file
void save_row_lab10(double time, double euler_temperature, double heun_temperature, double midpoint_temperature, double rk4_temperature, double exact_temperature, double euler_error, double heun_error, double midpoint_error, double rk4_error){
    ofstream file("results_lab10.csv", ios::app);

    if (!file)
    {
        cout << "error: cannot open results_lab10.csv" << endl;
        return;
    }

    file << fixed << setprecision(6)
         << time << ";"
         << euler_temperature << ";"
         << heun_temperature << ";"
         << midpoint_temperature << ";"
         << rk4_temperature << ";"
         << exact_temperature << ";"
         << euler_error << ";"
         << heun_error << ";"
         << midpoint_error << ";"
         << rk4_error << "\n";

    file.close();
}

// this function prints one table row

void print_row_lab10(double time, double euler_temperature, double heun_temperature, double midpoint_temperature, double rk4_temperature, double exact_temperature)
{
    cout << setw(15) << time
         << setw(18) << euler_temperature
         << setw(18) << heun_temperature
         << setw(18) << midpoint_temperature
         << setw(18) << rk4_temperature
         << setw(18) << exact_temperature << endl;
}





// this function compares methods for the cooling problem
void run_temperature_change_lab10(double initial_temperature,
                                  double alpha,
                                  double beta,
                                  double cooling_time)
{
    if (initial_temperature <= 0.0)
    {
        cout << "error: initial temperature must be positive" << endl;
        return;
    }

    if (cooling_time <= 0.0)
    {
        cout << "error: cooling time must be positive" << endl;
        return;
    }

    ofstream file("results_lab10.csv");

    if (!file)
    {
        cout << "error: cannot create results_lab10.csv" << endl;
        return;
    }

    file << "time;euler;heun;midpoint;rk4;exact;"
         << "euler_error;heun_error;midpoint_error;rk4_error\n";

    file.close();

    int number_of_results = 10;
    double print_step = cooling_time / number_of_results;

    double step = 2.0;
    double time = 0.0;

    double euler_temperature = initial_temperature;
    double heun_temperature = initial_temperature;
    double midpoint_temperature = initial_temperature;
    double rk4_temperature = initial_temperature;

    cout << fixed << setprecision(6);

    cout << "lab 10 - comparison of ode methods" << endl;
    cout << "initial temperature = " << initial_temperature << endl;

    cout << scientific << setprecision(6);
    cout << "alpha = " << alpha << endl;

    cout << fixed << setprecision(6);
    cout << "beta = " << beta << endl;
    cout << "cooling time = " << cooling_time << endl;
    cout << "calculation step = " << step << endl;
    cout << "results step = " << print_step << endl;
    cout << endl;

    cout << setw(15) << "time"
         << setw(18) << "euler"
         << setw(18) << "heun"
         << setw(18) << "midpoint"
         << setw(18) << "rk4"
         << setw(18) << "exact" << endl;

    cout << "------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i <= number_of_results; i++)
    {
        double target_time = i * print_step;

        while (time < target_time)
        {
            double current_step = step;
            if (time + current_step > target_time)
            { current_step = target_time - time; }
            euler_temperature = euler_step_lab10(euler_temperature, current_step, alpha, beta);
            heun_temperature = heun_step_lab10(heun_temperature, current_step, alpha, beta);
            midpoint_temperature = midpoint_step_lab10(midpoint_temperature, current_step, alpha, beta);
            rk4_temperature = runge_kutta_4_step_lab10(rk4_temperature, current_step, alpha, beta);

            time = time + current_step;
        }

        double exact_temperature = exact_solution_lab10(time, initial_temperature, alpha);
        double euler_error = absolute_error_lab10(exact_temperature, euler_temperature);
        double heun_error = absolute_error_lab10(exact_temperature, heun_temperature);
        double midpoint_error = absolute_error_lab10(exact_temperature, midpoint_temperature);
        double rk4_error = absolute_error_lab10(exact_temperature, rk4_temperature);

        print_row_lab10(time, euler_temperature, heun_temperature, midpoint_temperature, rk4_temperature, exact_temperature);
        save_row_lab10(time, euler_temperature, heun_temperature, midpoint_temperature, rk4_temperature, exact_temperature, euler_error, heun_error, midpoint_error, rk4_error);
    }

    cout << endl;
    cout << "data saved to results_lab10.csv" << endl;
}




// this function saves convergence analysis to csv file
void run_convergence_analysis_lab10(double initial_temperature,
                                    double alpha,
                                    double beta,
                                    double cooling_time)
{
    ofstream file("convergence_lab10.csv");

    if (!file)
    {
        cout << "error: cannot create convergence_lab10.csv" << endl;
        return;
    }

    file << fixed << setprecision(10);

    file << "step;euler;heun;midpoint;rk4;"
         << "euler_error;heun_error;midpoint_error;rk4_error\n";

    double steps[] = {1.0, 0.5, 0.25, 0.1, 0.05};

    for (int i = 0; i < 5; i++)
    {
        double step = steps[i];

        double time = 0.0;

        double euler_temperature = initial_temperature;
        double heun_temperature = initial_temperature;
        double midpoint_temperature = initial_temperature;
        double rk4_temperature = initial_temperature;

        while (time < cooling_time)
        {
            double current_step = step;

            if (time + current_step > cooling_time)
            {
                current_step = cooling_time - time;
            }

            euler_temperature = euler_step_lab10(euler_temperature, current_step, alpha, beta);
            heun_temperature = heun_step_lab10(heun_temperature, current_step, alpha, beta);
            midpoint_temperature = midpoint_step_lab10(midpoint_temperature, current_step, alpha, beta);
            rk4_temperature = runge_kutta_4_step_lab10(rk4_temperature, current_step, alpha, beta);

            time = time + current_step;
        }

        double exact_temperature = exact_solution_lab10(cooling_time, initial_temperature, alpha);

        double euler_error = absolute_error_lab10(exact_temperature, euler_temperature);
        double heun_error = absolute_error_lab10(exact_temperature, heun_temperature);
        double midpoint_error = absolute_error_lab10(exact_temperature, midpoint_temperature);
        double rk4_error = absolute_error_lab10(exact_temperature, rk4_temperature);

        file << step << ";"
             << euler_temperature << ";"
             << heun_temperature << ";"
             << midpoint_temperature << ";"
             << rk4_temperature << ";"
             << euler_error << ";"
             << heun_error << ";"
             << midpoint_error << ";"
             << rk4_error << "\n";
    }

    file.close();

    cout << "convergence analysis saved to convergence_lab10.csv" << endl;
}

// this function runs example from lab 10

void run_example_lab10()
{
    int album_number = 5972;

    double initial_temperature = album_number;
    double cooling_time = album_number;

    int last_digit = album_number % 10;

    double alpha = last_digit * pow(10, -12);
    double beta = 0.0;

    run_temperature_change_lab10(initial_temperature, alpha, beta, cooling_time);
    run_convergence_analysis_lab10(initial_temperature, alpha, beta, cooling_time);
}