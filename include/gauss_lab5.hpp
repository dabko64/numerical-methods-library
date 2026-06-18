#ifndef GAUSS_LAB5_HPP
#define GAUSS_LAB5_HPP

#include <vector>
#include <string>

// Ta funkcja wczytuje dane układu równań liniowych (rozmiar macierzy, wektor b oraz macierz A) z pliku tekstowego.
// - Argumenty:
//   nazwaPliku: ścieżka do wejściowego pliku tekstowego
//   n: referencja do zapisania rozmiaru (wymiaru) macierzy
//   A: referencja do zapisania dwuwymiarowej macierzy współczynników układu
//   b: referencja do zapisania wektora wyrazów wolnych
// - Zwraca: true, jeśli dane zostały pomyślnie załadowane; false, jeśli nie można otworzyć pliku.
bool wczytajDaneGauss(const std::string& nazwaPliku, int& n, std::vector<std::vector<double>>& A, std::vector<double>& b);

// Ta funkcja wypisuje macierz rozszerzoną [A | b] do konsoli w przejrzystym formacie.
// - Argumenty:
//   A: dwuwymiarowa macierz współczynników
//   b: wektor wyrazów wolnych
// - Zwraca: void
void wypiszMacierzRozszerzona(const std::vector<std::vector<double>>& A, const std::vector<double>& b);

// Ta funkcja rozwiązuje układ równań liniowych Ax = b przy użyciu klasycznej eliminacji Gaussa i podstawiania wstecz.
// Wypisuje stan macierzy rozszerzonej po każdym kroku eliminacji.
// - Argumenty:
//   A: macierz układu (przekazywana przez wartość, aby chronić oryginalne dane)
//   b: wektor wyrazów wolnych (przekazywany przez wartość)
//   n: rozmiar układu
// - Zwraca: wektor zawierający rozwiązania x lub pusty wektor, jeśli wystąpi błąd.
// - Przypadek błędu: Wypisuje komunikat i zwraca pusty wektor, jeśli na przekątnej zostanie wykryte zero (dzielenie przez zero).
std::vector<double> metodaGaussa(std::vector<std::vector<double>> A, std::vector<double> b, int n);

// Ta funkcja koordynuje laboratoryjny przykład: ładuje dane, uruchamia metodę Gaussa i weryfikuje poprawność wyniku.
// - Zwraca: void
void run_example_lab5();

#endif
