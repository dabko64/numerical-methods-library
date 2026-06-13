#include <iostream>
#include <vector>
#include <cmath>
#include "../include/gauss_lab5.hpp"

using namespace std;

void test_metody_Gaussa() {
    int n = 3;

    vector<vector<double>> A = {
        {2.0, 1.0, -1.0},
        {1.0, 3.0, 2.0},
        {0.0, 1.0, -1.0}
    };
    vector<double> b = {1.0, 13.0, -1.0};

    vector<double> x = metodaGaussa(A, b, n);

    vector<double> oczekiwane = {1.0, 2.0, 3.0};
    bool czyPoprawne = true;

    for (int i = 0; i < n; ++i) {
        if (abs(x[i] - oczekiwane[i]) > 0.0001) {
            czyPoprawne = false;
        }
    }

    if (czyPoprawne) {
        cout << "Test Eliminacji Gaussa: ZALICZONY\n";
    } else {
        cout << "Test Eliminacji Gaussa: BLAD\n";
    }
}

int main() {
    test_metody_Gaussa();
    return 0;
}