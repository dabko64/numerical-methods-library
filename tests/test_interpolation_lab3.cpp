#include <iostream>
#include <vector>
#include "../include/interpolation_lab3.hpp"

using namespace std;

// TEST: Schemat Hornera
void test_schemat_hornera() {
    vector<double> a = {1.0, 2.0, 3.0};
    double x = 2.0;
    
    double wynik = schematHornera(x, a);

    if (wynik == 17.0) {
        cout << "Test 1 (Schemat Hornera - poprawne dane): ZALICZONY\n";
    } else {
        cout << "Test 1: BLAD\n";
    }
}

// TEST: Współczynniki Newtona
void test_wspolczynniki_newtona() {
    vector<double> x = {0.0, 1.0, 2.0};
    vector<double> y = {1.0, 3.0, 7.0}; 
    
    vector<double> a = wspolczynnikiNewtona(x, y);

    if (a.size() == 3 && a[0] == 1.0 && a[1] == 2.0 && a[2] == 1.0) {
        cout << "Test 2 (Wspolczynniki Newtona - poprawne obliczenia): ZALICZONY\n";
    } else {
        cout << "Test 2: BLAD\n";
    }
}

// TEST: Interpolacja Newtona
void test_interpolacja_newtona() {
    vector<double> x = {0.0, 1.0, 2.0};
    vector<double> a = {1.0, 2.0, 1.0};
    
    double wynik = interpolacjaNewtona(1.5, x, a);

    if (wynik == 4.75) {
        cout << "Test 3 (Interpolacja Newtona - poprawna wartosc): ZALICZONY\n";
    } else {
        cout << "Test 3: BLAD\n";
    }
}

// TEST: Wczytywanie pliku
void test_wczytywanie_brak_pliku() {
    vector<double> x, y;
    
    // wczytujemy plik, który nie istnieje
    bool czyWczytano = wczytajDaneN("nieistniejacy_plik.txt", x, y);

    if (czyWczytano == false) {
        cout << "Test 4 (Wczytywanie - prawidlowa reakcja na brak pliku): ZALICZONY\n";
    } else {
        cout << "Test 4: BLAD\n";
    }
}

int main() {
    cout << "--- START TESTOW LAB 3 (Newton) ---\n";
    test_schemat_hornera();
    test_wspolczynniki_newtona();
    test_interpolacja_newtona();
    test_wczytywanie_brak_pliku();
    cout << "--- KONIEC TESTOW ---\n";
    return 0;
}