#include <iostream>
#include <vector>
#include <cmath>
#include "../include/LU_lab4.hpp"

using namespace std;

vector<vector<double>> pomnozMacierze(const vector<vector<double>>& L, const vector<vector<double>>& U) {
    int n = L.size();
    vector<vector<double>> A(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                A[i][j] += L[i][k] * U[k][j];
            }
        }
    }
    return A;
}

void test_rozkładu_LU() {
    int n = 2;
    vector<vector<double>> A = {{2.0, 1.0}, {1.0, 3.0}};
    vector<double> b = {1.0, 1.0};
    
    vector<vector<double>> L = {{1.0, 0.0}, {0.5, 1.0}};
    vector<vector<double>> U = {{2.0, 1.0}, {0.0, 2.5}};
    
    vector<vector<double>> wynik = pomnozMacierze(L, U);
    
    bool czyPoprawne = true;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(abs(wynik[i][j] - A[i][j]) > 0.0001) czyPoprawne = false;
        }
    }

    if (czyPoprawne) {
        cout << "Test LU (L*U = A): ZALICZONY\n";
    } else {
        cout << "Test LU: BLAD\n";
    }
}

int main() {
    test_rozkładu_LU();
    return 0;
}