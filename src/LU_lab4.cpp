#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include "../include/LU_lab4.hpp"

using namespace std;


void run_example_lab4() {
    int n;
    vector<vector<double>> A;
    vector<double> b;

    if (!wczytajDaneLU("../data/dane.txt", n, A, b)) {
        return;
    }

    metodaLU(A, b, n);

}

bool wczytajDaneLU(const string& nazwaPliku, int& n, vector<vector<double>>& A, vector<double>& b) {
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Blad, nie mozna otworzyc pliku " << nazwaPliku << endl;
        return false;
    }

    string temp;
    plik >> temp >> temp >> n;

    plik >> temp;
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        plik >> b[i];
    }

    plik >> temp;
    A.assign(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            plik >> A[i][j];
        }
    }

    return true;
}

void wypiszMacierz(const vector<vector<double>>& M, const string& nazwa) {
    int n = M.size();
    cout << "--- Macierz " << nazwa << " ---" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(12) << setprecision(5) << M[i][j] << " ";
        }
        cout << endl;
    }
}

void metodaLU(vector<vector<double>> A, vector<double> b, int n) {
    vector<vector<double>> L(n, vector<double>(n, 0.0));
    vector<vector<double>> U(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) {
        L[i][i] = 1.0;
    }

    cout << "----- Rozpoczecie rozkladu LU -----" << endl;

    //Rozkład LU
    for (int k = 0; k < n; ++k) {

        for (int j = k; j < n; ++j) {
            double suma = 0.0;
            for (int s = 0; s < k; s++) {
                suma += L[k][s] * U[s][j];
            }
            U[k][j] = (A[k][j] - suma) / L[k][k];
        }

        for (int i = k + 1; i < n; ++i) {
            if (U[k][k] == 0) {
                cout << "Blad: 0 na przekatnej macierzy U. Klasyczny rozklad LU niemozliwy." << endl;
                return;
            }
            double suma = 0.0;
            for (int s = 0; s < k; s++) {
                suma += L[i][s] * U[s][k];
            }
            L[i][k] = (A[i][k] - suma) / U[k][k];
        }

        cout << "\n----- Krok k = " << k + 1 << " -----" << endl;
        wypiszMacierz(L, "L");
        wypiszMacierz(U, "U");
    }

    // Rozwiązywanie L * z = b (Podstawianie w przód)
    vector<double> z(n);
    for (int i = 0; i < n; ++i) {
        z[i] = b[i];
        for (int j = 0; j < i; ++j) {
            z[i] -= L[i][j] * z[j];
        }
        z[i] /= L[i][i];
    }

    // RozwiązywanieU * x = z (Podstawianie wstecz)
    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = z[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }

    cout << "\n----- Otrzymane rozwiazania -----" << endl;
    cout << "Wektor posredni z:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "z_" << i + 1 << " = " << z[i] << endl;
    }

    cout << "\nWektor docelowy x:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x_" << i + 1 << " = " << x[i] << endl;
    }
}