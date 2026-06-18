#ifndef LU_LAB4_HPP
#define LU_LAB4_HPP

#include <vector>
#include <string>

// Ta funkcja wczytuje rozmiar macierzy (n), wektor b oraz macierz A z pliku tekstowego.
// - Argumenty: 
//   nazwaPliku: ścieżka do pliku wejściowego
//   n: referencja do zapisania rozmiaru macierzy
//   A: referencja do zapisania dwuwymiarowej macierzy współczynników
//   b: referencja do zapisania wektrowa wyrazów wolnych
// - Zwraca: true, jeśli dane zostały pomyślnie załadowane; false, jeśli nie można otworzyć pliku.
// - Przykład: wczytajDaneLU("../data/dane.txt", n, A, b);
bool wczytajDaneLU(const std::string& nazwaPliku, int& n, std::vector<std::vector<double>>& A, std::vector<double>& b);

// Ta funkcja wypisuje sformatowaną macierz dwuwymiarową do konsoli w celu wizualizacji.
// - Argumenty:
//   M: macierz dwuwymiarowa do wypisania
//   nazwa: etykieta/nazwa nagłówka macierzy (np. "L" lub "U")
// - Zwraca: void
void wypiszMacierz(const std::vector<std::vector<double>>& M, const std::string& nazwa);

// Ta funkcja wykonuje rozkład LU (algorytm Doolittle'a) i rozwiązuje układ Ax = b.
// Rozkłada macierz A na L i U, wypisuje je, a następnie stosuje podstawianie w przód i wstecz.
// - Argumenty:
//   A: macierz współczynników (przekazywana przez wartość)
//   b: wektor wyrazów wolnych (przekazywany przez wartość)
//   n: rozmiar macierzy
// - Zwraca: void
// - Przypadek błędu: Wypisuje błąd i przerywa działanie, jeśli U[k][k] == 0 (dzielenie przez zero).
// - Przykład: metodaLU(A, b, n);
void metodaLU(std::vector<std::vector<double>> A, std::vector<double> b, int n);

// Ta funkcja koordynuje cały proces: ładuje dane i uruchamia metodę LU.
// - Zwraca: void
void run_example_lab4();

#endif // LU_LAB4_HPP
