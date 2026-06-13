#include <iostream>
#include <vector>
#include <string>
#include "../include/interpolation_lab2.hpp"

using namespace std;

// TESTY DLA FUNKCJI: interpolacja Lagrange'a

void test_interpolacja_proste_liczby() {
    vector<double> x = {0.0, 1.0, 2.0};
    vector<double> y = {0.0, 1.0, 2.0};

    double wynik = interpolacja(1.5, x, y);

    if (wynik == 1.5) {
        cout << "Test 1 (Interpolacja - poprawne dane): ZALICZONY\n";
    } else {
        cout << "Test 1: BLAD\n";
    }
}

void test_interpolacja_tylko_jeden_punkt() {
    vector<double> x = {5.0};
    vector<double> y = {10.0};

    double wynik = interpolacja(5.0, x, y);

    if (wynik == 10.0) {
        cout << "Test 2 (Interpolacja - jeden punkt): ZALICZONY\n";
    } else {
        cout << "Test 2: BLAD\n";
    }
}

// TESTY DLA FUNKCJI: wczytajdane1

void test_wczytywanie_zly_plik() {
    vector<double> x, y;
    // Błędny przypadek: podajemy plik, który nie istnieje
    bool czyWczytano = wczytajdane1("nie_ma_takiego_pliku.txt", x, y);

    if (czyWczytano == false) {
        cout << "Test 3 (Wczytywanie - brak pliku): ZALICZONY\n";
    } else {
        cout << "Test 3: BLAD\n";
    }
}

// TESTY DLA FUNKCJI: zapiszCSV

void test_zapis_poprawny() {
    vector<double> x = {1.0};
    vector<double> y = {2.0};
    vector<double> y_int = {2.0};

    bool czyZapisano = zapiszCSV("test_zapis.csv", x, y, y_int);

    if (czyZapisano == true) {
        cout << "Test 4 (Zapis - poprawny): ZALICZONY\n";
    } else {
        cout << "Test 4: BLAD\n";
    }
}


int main() {
    cout << "--- START TESTOW ---" << endl;

    test_interpolacja_proste_liczby();
    test_interpolacja_tylko_jeden_punkt();
    test_wczytywanie_zly_plik();
    //test_zapis_poprawny();

    cout << "--- KONIEC TESTOW ---" << endl;
    return 0;
}