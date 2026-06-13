#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include "../include/interpolation_lab2.hpp"

using namespace std;

void run_example_lab2(){
    vector<double> x;
    vector<double> y;
    string plikWejsciowy = "../data/interpolacja_gr_1_INO.txt";
    string plikWyjsciowy = "../data/interpolacja_wynik.csv";

    if (wczytajdane1(plikWejsciowy, x, y)) {

        vector<double> wezly_x;
        vector<double> wezly_y;

        for (size_t i = 0; i < x.size(); i += 5) {
            wezly_x.push_back(x[i]);
            wezly_y.push_back(y[i]);
        }

        vector<double> y_interp;
        double max_blad = 0.0;
        double suma_bladow = 0.0;

        for (size_t i = 0; i < x.size(); ++i) {
            double wartosc_interpolowana = interpolacja(x[i], wezly_x, wezly_y);
            y_interp.push_back(wartosc_interpolowana);
            double blad = abs(y[i] - wartosc_interpolowana);
            if(blad > max_blad){
                max_blad = blad;
            }
        }
        cout << "Liczba wszystkich analizowanych punktow: "<<x.size()<<endl;
        cout<< "Liczba wezlow interpolacji: " << wezly_x.size()<<endl;
        cout<< "Maksymalny blad interpolacji: " << max_blad<<endl;


        zapiszCSV(plikWyjsciowy, x, y, y_interp);
    }
}


bool wczytajdane1(const string& nazwaPliku, vector<double>& x, vector<double>& y) {
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Brak pliku\n";
        return false;
    }

    string slowo;
    bool czytajX = false;
    bool czytajY = false;
    bool wlasciwaGrupa = false;

    int grupa = 3;

    while (plik >> slowo) {
        if (slowo == "l.p.:") {
            int nrGrupy;
            if (plik >> nrGrupy) {
                if (nrGrupy == grupa) {
                    wlasciwaGrupa = true;
                } else if (wlasciwaGrupa) {
                    break;
                }
            }
            continue;
        }
        if (!wlasciwaGrupa) continue;

        if (slowo == "xi:") {
            czytajX = true;
            czytajY = false;
            continue;
        } else if (slowo == "f(xi):") {
            czytajX = false;
            czytajY = true;
            continue;
        }

        try {
            size_t pos;
            double wartosc = stod(slowo, &pos);
            if (czytajX) {
                x.push_back(wartosc);
            } else if (czytajY) {
                y.push_back(wartosc);
            }
        } catch (...) {
        }
    }

    if (x.empty() || y.empty() || x.size() != y.size()) {
        cout << "Blad wczytywania! Liczba elementow X: " << x.size() << ", Y: " << y.size() << "\n";
        return false;
    }

    cout << "dane poprawne (wczytano l.p.: " << grupa << ")" << endl;
    return true;
}

bool zapiszCSV(const string& nazwaPliku, const vector<double>& x, const vector<double>& y, const vector<double>& y_interp){
     ofstream plik(nazwaPliku);
     if(!plik.is_open()){
        cout<<"brak pliku dane_1";
        return false;
     }

     plik <<"xi,f(xi),L(xi)\n";

     for(size_t i=0; i<x.size(); ++i){
        plik << x[i] << "," << y[i] << "," << y_interp[i] << "\n";
     }
     cout<<"wyniki poprawnie zapisane do pliku CSV"<<endl;
     return true;
}

double interpolacja(double X, const vector<double>& wezlyX, const vector<double>& wezlyY){
    double wynik = 0.0;
    int n = wezlyX.size();

    for (int i = 0; i < n; ++i) {
        double l_i = 1.0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                l_i *= (X - wezlyX[j]) / (wezlyX[i] - wezlyX[j]);
            }
        }
        wynik += wezlyY[i] * l_i;
    }
    return wynik;
}