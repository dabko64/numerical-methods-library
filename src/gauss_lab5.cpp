#include "gauss_lab5.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


void run_example_lab5(){
    int n;
    vector<vector<double>> A;
    vector<double> b;
    if (!wczytajDaneGauss("../data/dane.txt", n, A, b)) {
        return;
    }

    vector<double> x = metodaGaussa(A, b, n);

    cout<<"----- Sprawdzenie -----"<< endl;
    for (int i = 0; i < n; ++i) {
        double suma = 0;
        for (int j = 0; j < n; ++j) {
            suma += A[i][j] * x[j];
        }
        cout << "Rownanie " << i + 1 << ": wynik = " << setw(10) << suma
             << " | powinno byc: " << setw(10) << b[i] << endl;
    }

    return;
}

bool wczytajDaneGauss(const string& nazwaPliku, int& n, vector<vector<double>>& A, vector<double>& b) {
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Blad, nie mozna otworzyc pliku" << nazwaPliku << endl;
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

void wypiszMacierzRozszerzona(const vector<vector<double>>& A, const vector<double>& b) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) << A[i][j] << " ";
        }
        cout << "| " << setw(10) << b[i] << endl;
    }
    cout << endl;
}

vector<double> metodaGaussa(vector<vector<double>> A, vector<double> b, int n){
    if (!wczytajDaneGauss("../data/dane.txt", n, A, b)) {
        return {};
    }
    cout << "----- Poczatkowa macierz  -----"<<endl;
    wypiszMacierzRozszerzona(A,b);
    for(int i = 0; i < n-1; ++i){
        for(int j = i+1; j < n; ++j){
            if(A[i][i]==0){
                cout<<"blad, dzielenie przez zero";
                return {};
            }
            double mnoznik = A[j][i]/A[i][i];
            for(int k = i; k < n; ++k){
            A[j][k] -= mnoznik*A[i][k];
            }
            b[j] -= mnoznik * b[i];
        }
        cout << "----- Macierz po eliminacji " << i+1 << " -----" << endl;
        wypiszMacierzRozszerzona(A,b);
    }
    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i]; //macierz trojkatna
    }

    cout << "----- Rozwiazanie -----" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return x;
}
