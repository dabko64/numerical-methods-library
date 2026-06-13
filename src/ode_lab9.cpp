#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

#include "../include/ode_lab9.hpp"

using namespace std;

// this function calculates the right side of the differential equation
double derivative_lab9(double temperature, double alpha, double beta){return -alpha * (pow(temperature, 4) - beta);}

// this function calculates exact solution for beta equal to zero
double exact_solution_lab9(double time, double initial_temperature, double alpha)
{
    if (initial_temperature == 0.0)
    {
        cout << "error: initial temperature cannot be zero" << endl;
        return 0.0;
    }


    if (alpha < 0.0)
    {
        cout << "error: alpha cannot be negative" << endl;
        return 0.0;
    }

    return 1.0 / cbrt(3.0 * alpha * time + 1.0 / pow(initial_temperature, 3));
}



// this function makes one euler step
double euler_step_lab9(double temperature, double step, double alpha, double beta)
{
    if (step <= 0.0)
    {
        cout << "error: step must be positive" << endl;
        return temperature;
    }

    double value = derivative_lab9(temperature, alpha, beta);
    return temperature + step * value;
}



// this function calculates absolute error
double absolute_error_lab9(double exact_value, double approximate_value){return fabs(exact_value - approximate_value);}

// this function calculates percentage error
double percentage_error_lab9(double exact_value, double approximate_value)
{
    if (exact_value == 0.0)
    {
        cout << "error: exact value cannot be zero" << endl;
        return 0.0;
    }

    return fabs(exact_value - approximate_value) / fabs(exact_value) * 100.0;
}

// this function saves one row to csv file
void save_row_lab9(double time, double temperature, double exact_temperature, double error, double percentage_error)
{
    ofstream file("results_lab9.csv", ios::app);
    if (!file)
    {
        cout << "error: cannot open results_lab9.csv" << endl;
        return;
    }

    file << fixed << setprecision(6)
         << time << ";"
         << temperature << ";"
         << exact_temperature << ";"
         << error << ";"
         << percentage_error << "\n";

    file.close();
}


// this function prints one table row
void print_row_lab9(double time, double temperature, double exact_temperature, double error, double percentage_error)
{
    cout << setw(15) << time
         << setw(20) << temperature
         << setw(20) << exact_temperature
         << setw(20) << error
         << setw(20) << percentage_error << endl;
}


// this function runs euler method for cooling problem
void run_cooling_simulation_lab9(double initial_temperature, double alpha, double beta, double cooling_time)
{
    if (initial_temperature <= 0.0){cout << "error: initial temperature must be positive" << endl;
        return;
    }

    if (cooling_time <= 0.0){cout << "error: cooling time must be positive" << endl;
        return;
    }

    if (alpha < 0.0){cout << "error: alpha cannot be negative" << endl;
        return;
    }

    ofstream file("results_lab9.csv");
    if (!file) {cout << "error: cannot create results_lab9.csv" << endl;
        return;
    }

    file << "time;temperature_euler;temperature_exact;error;percentage_error\n";
    file.close();


    int number_of_results = 10;
    double print_step = cooling_time / number_of_results;
    double step = 0.1;
    double time = 0.0;
    double temperature = initial_temperature;

    cout << fixed << setprecision(6);
    cout << "lab 9 - euler method for cooling problem" << endl;
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
         << setw(20) << "euler"
         << setw(20) << "exact"
         << setw(20) << "error"
         << setw(20) << "error percent" << endl;

    cout << "-----------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i <= number_of_results; i++)
    {
        double target_time = i * print_step;
        while (time < target_time)
        {
            double current_step = step;
            if (time + current_step > target_time) { current_step = target_time - time;}


            temperature = euler_step_lab9(temperature, current_step, alpha, beta);
            time = time + current_step;
        }
        double exact_temperature = exact_solution_lab9(time, initial_temperature, alpha);
        double error = absolute_error_lab9(exact_temperature, temperature);
        double percent_error = percentage_error_lab9(exact_temperature, temperature);
        print_row_lab9(time, temperature, exact_temperature, error, percent_error);
        save_row_lab9(time, temperature, exact_temperature, error, percent_error);
    }
    cout << endl;
    cout << "data saved to results_lab9.csv" << endl;
}



// this function runs example from lab 9
void run_example_lab9()
{
    int album_number = 5972;
    double initial_temperature = album_number;
    double cooling_time = album_number;
    int last_digit = album_number % 10;
    double alpha = last_digit * pow(10, -12);
    double beta = 0.0;

    
    run_cooling_simulation_lab9(initial_temperature, alpha, beta, cooling_time);
}