#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <chrono>
#include <iomanip>
#include "../include/interpolation_lab3.hpp"
using namespace std;


void run_example_lab3() {
    vector<double> a_wspolczynniki, x_punkty_H;
    if (!wczytajDaneH("../data/dane_H.txt", a_wspolczynniki, x_punkty_H)) {
        cout << "Blad: Nie udalo sie wczytac danych z pliku H." << endl;
        return;
    }

    vector<double> a_3;
    for (size_t i = 0; i < 3 && i < a_wspolczynniki.size(); ++i) {
        a_3.push_back(a_wspolczynniki[i]);
    }

    cout << "=== Porownanie czasow ===" << endl;
    cout << left << setw(12) << "Punkt x" 
         << setw(15) << "Wynik Nat." 
         << setw(15) << "Wynik Horn." 
         << setw(18) << "Czas Nat. (ns)" 
         << setw(18) << "Czas Horn. (ns)" << endl;
    cout << string(78, '-') << endl;

    for (double xi : x_punkty_H) {
        auto startN = chrono::high_resolution_clock::now();
        double resN = postacNaturalna(xi, a_3);
        auto endN = chrono::high_resolution_clock::now();
        auto czasN = chrono::duration_cast<chrono::nanoseconds>(endN - startN).count();

        auto startH = chrono::high_resolution_clock::now();
        double resH = schematHornera(xi, a_3);
        auto endH = chrono::high_resolution_clock::now();
        auto czasH = chrono::duration_cast<chrono::nanoseconds>(endH - startH).count();

        cout << left << setw(12) << xi 
             << setw(15) << resN 
             << setw(15) << resH 
             << setw(18) << czasN 
             << setw(18) << czasH << endl;
    }
    cout << "\n=== Interpolacja Newtona ===" << endl;
    vector<double> x_punkty_N, y_punkty_N;
    
    if (!wczytajDaneN("../data/dane_N.txt", x_punkty_N, y_punkty_N)) {
        cout << "Blad: Nie udalo sie wczytac danych z pliku N." << endl;
        return;
    } 
    vector<double> x_wezly, y_wezly;
    for (size_t i = 0; i < x_punkty_N.size(); i += 5) {
        x_wezly.push_back(x_punkty_N[i]);
        y_wezly.push_back(y_punkty_N[i]);
    }

    cout << "Pobrano " << x_wezly.size() << endl;
    vector<double> a_newton = wspolczynnikiNewtona(x_wezly, y_wezly);
    
    cout << "Wspolczynniki wielomianu Newtona (a_i):" << endl;
    for (size_t i = 0; i < a_newton.size(); ++i) {
        cout << "a_" << i << " = " << a_newton[i] << endl;
    }
    vector<double> x_wykres, y_wykres;
    double x_min = x_wezly.front();
    double x_max = x_wezly.back();
    int liczba_krokow = 200;
    double krok = (x_max - x_min) / liczba_krokow;

    for (int i = 0; i <= liczba_krokow; ++i) {
        double x_val = x_min + i * krok;
        double y_val = interpolacjaNewtona(x_val, x_wezly, a_newton);
        x_wykres.push_back(x_val);
        y_wykres.push_back(y_val);
    } 
    zapiszCSV_lab3("wykres_newton.csv", x_wykres, y_wykres);
    return;
}

bool wczytajDaneH(const string& nazwaPliku, vector<double>& a, vector<double>& x) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) return false;

    string slowo;
    bool czytajX = false;
    
    while (plik >> slowo) {
        size_t znakRownosci = slowo.find('=');
        if (znakRownosci != string::npos && slowo[0] == 'a') {
            try {
                double wartosc = stod(slowo.substr(znakRownosci + 1));
                a.push_back(wartosc);
            } catch (...) {}
        } 
        else if (slowo == "xi:") {
            czytajX = true;
        } 
        else if (czytajX) {
            try {
                x.push_back(stod(slowo));
            } catch (...) {}
        }
    }
    return !a.empty() && !x.empty();
}

bool wczytajDaneN(const string& nazwaPliku, vector<double>& x, vector<double>& y) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) return false;

    string slowo;
    int tryb = 0;

    while (plik >> slowo) {
        if (slowo == "xi:") {
            tryb = 1;
            continue;
        } else if (slowo == "f(xi):") {
            tryb = 2;
            continue;
        }

        try {
            double wartosc = stod(slowo);
            if (tryb == 1) x.push_back(wartosc);
            else if (tryb == 2) y.push_back(wartosc);
        } catch (...) {}
    }
    return !x.empty() && (x.size() == y.size());
}

bool zapiszCSV_lab3(const string& nazwaPliku, const vector<double>& x, const vector<double>& y) {
    ofstream plik(nazwaPliku);
    if (!plik.is_open()) return false;
    
    plik << "x,y\n";
    for (size_t i = 0; i < x.size(); ++i) {
        plik << x[i] << "," << y[i] << "\n";
    }
    cout << "Dane do wykresu zapisano w pliku: " << nazwaPliku << endl;
    return true;
}

double postacNaturalna(double x, const vector<double>& a) {
    double wynik = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        wynik += a[i] * pow(x, i);
    }
    return wynik;
}

double schematHornera(double x, const vector<double>& a) {
    int n = a.size() - 1;
    double b = a[n];
    for (int i = n - 1; i >= 0; --i) {
        b = a[i] + x * b;
    }
    return b;
}

vector<double> wspolczynnikiNewtona(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    vector<double> a = y;
    for (int j = 1; j < n; ++j) {
        for (int i = n - 1; i >= j; --i) {
            a[i] = (a[i] - a[i - 1]) / (x[i] - x[i - j]);
        }
    }
    return a;
}

double interpolacjaNewtona(double X, const vector<double>& x, const vector<double>& a) {
    int n = a.size();
    double wynik = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        wynik = a[i] + (X - x[i]) * wynik;
    }
    return wynik;
}