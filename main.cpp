#include <iostream>
#include "include/interpolation_lab2.hpp"
#include "include/interpolation_lab3.hpp"
#include "include/integration_lab6.hpp"
#include "include/integration_lab7.hpp"
#include "include/approximation_lab8.hpp"
#include "include/ode_lab9.hpp"
#include "include/ode_lab10.hpp"
#include "include/nonlinear_lab11.hpp"
#include "include/nonlinear_lab12.hpp"

using namespace std;



void print_menu()
{
    cout << endl;

    cout << "        numerical methods library        \n" << endl;
    cout << "1. lab 2  - numerical interpolation 1" << endl;
    cout << "2. lab 3  - numerical interpolation 2" << endl;
    cout << "3. lab 6  - numerical integration 1" << endl;
    cout << "4. lab 7  - numerical integration 2" << endl;
    cout << "5. lab 8  - polynomial approximation" << endl;
    cout << "6. lab 9  - euler method for ode" << endl;
    cout << "7. lab 10 - ode methods comparison" << endl;
    cout << "8. lab 11 - nonlinear equations 1" << endl;
    cout << "9. lab 12 - nonlinear equations 2" << endl;
    cout << "10. exit" << endl;
    cout << "choose option: ";
}



void run_choice(int choice)
{
    switch (choice)
    {
            case 1:
            run_example_lab2();
            break;

            case 2:
            run_example_lab3();
            break;

            case 3:
            run_example_lab6();
            break;

            case 4:
            run_example_lab7();
            break;

            case 5:
            run_example_lab8();
            break;

            case 6:
            run_example_lab9();
            break;

            case 7:
            run_example_lab10();
            break;

            case 8:
            run_example_lab11();
            break;

            case 9:
            run_example_lab12();
            break;

        case 0:
            cout << "end of program" << endl;
            break;

            default:
            cout << "error: wrong option" << endl;
            break;
    }
}

int main()
{
    int choice;
    do {
        print_menu();
        cin >> choice;

        if (cin.fail()) {
            cout << "error: wrong input" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            choice = -1;
        }
        else { run_choice(choice); }
    } while (choice != 0);
    return 0;
}