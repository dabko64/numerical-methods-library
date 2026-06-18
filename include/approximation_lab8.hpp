#pragma once

const int max_degree_lab8 = 10;
const int simpson_n_lab8 = 10000;

// Oblicza wartość zadanej funkcji matematycznej badanej w ramach ćwiczenia.
// - Argumenty: x: zmienna wejściowa
// - Zwraca: wartość funkcji f(x) = x^2 * sin^2(x) - x^2 + x
double function_lab8(double x);

// Oblicza analityczną całkę z x podniesionego do zadanej potęgi w przedziale [5, 11].
// - Argumenty: power: wartość wykładnika potęgi
// - Zwraca: wartość całki lub 0.0, jeśli potęga jest ujemna (przypadek błędu).
double power_integral_lab8(int power);

// Oblicza całkę z f(x) * x^power w przedziale [5, 11] przy użyciu metody Simpsona.
// - Argumenty: power: wartość wykładnika potęgi dla x
// - Zwraca: przybliżoną wartość całki lub 0.0, jeśli potęga jest ujemna (przypadek błędu).
double function_times_power_integral_lab8(int power);

// Wyznacza wartość wielomianu w zadanym punkcie x przy użyciu schematu Hornera.
// - Argumenty: coeff: tablica współczynników, degree: stopień wielomianu, x: punkt ewaluacji
// - Zwraca: wartość wielomianu w punkcie x lub 0.0, jeśli stopień jest niepoprawny.
double polynomial_value_lab8(double coeff[], int degree, double x);

// Tworzy układ równań normalnych (macierz i wektor wyrazów wolnych) dla aproksymacji średniokwadratowej.
// - Argumenty: matrix: docelowa macierz 2D, rhs: docelowa tablica wektora, degree: wybrany stopień wielomianu
// - Przypadek błędu: Wypisuje komunikat, jeśli stopień wykracza poza dopuszczalny przedział (mniej niż 1 lub więcej niż max).
void create_system_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1], double rhs[max_degree_lab8 + 1], int degree);

// Wypisuje macierz współczynników A do konsoli.
// - Argumenty: matrix: macierz 2D, degree: odniesienie do rozmiaru układu
void print_matrix_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1], int degree);

// Wypisuje wektor wyrazów wolnych b do konsoli.
// - Argumenty: rhs: tablica wektora, degree: odniesienie do rozmiaru układu
void print_vector_lab8(double rhs[max_degree_lab8 + 1], int degree);

// Wypisuje macierz rozszerzoną [A | b] używaną w eliminacji Gaussa do konsoli.
// - Argumenty: matrix: macierz 2D zawierająca dodatkową kolumnę, size: wymiary macierzy
void print_augmented_matrix_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 2], int size);

// Zapisuje utworzoną macierz układu A oraz wektor b do pliku tekstowego ("matrix_a_b_lab8.txt").
// - Przypadek błędu: Wypisuje komunikat, jeśli nie można utworzyć pliku.
void save_system_to_file_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1], double rhs[max_degree_lab8 + 1], int degree);

// Rozwiązuje układ równań liniowych metodą eliminacji Gaussa z częściowym wyborem elementu podstawowego i wypisuje kroki.
// - Argumenty: matrix: współczynniki, rhs: wektor b, result: tablica na współczynniki wielomianu, degree: rozmiar układu
// - Zwraca: true, jeśli układ został rozwiązany; false, jeśli element osiowy jest bliski zeru (przypadek błędu).
bool gaussian_elimination_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1], double rhs[max_degree_lab8 + 1], double result[max_degree_lab8 + 1], int degree);

// Rozwiązuje układ równań liniowych metodą eliminacji Gaussa bez wypisywania kroków pośrednich do konsoli.
// - Zwraca: true, jeśli układ został rozwiązany; false, jeśli element osiowy jest bliski zeru (przypadek błędu).
bool gaussian_elimination_silent_lab8(double matrix[max_degree_lab8 + 1][max_degree_lab8 + 1], double rhs[max_degree_lab8 + 1], double result[max_degree_lab8 + 1], int degree);

// Oblicza średniokwadratowy błąd aproksymacji przy użyciu kwadratury Simpsona.
// - Argumenty: coeff: współczynniki wielomianu, degree: stopień wielomianu
// - Zwraca: obliczoną wartość błędu średniokwadratowego.
double mean_square_error_lab8(double coeff[max_degree_lab8 + 1], int degree);

// Oblicza i zapisuje do pliku "results_lab8.csv" wartości funkcji, aproksymacji oraz błędy bezwzględne do wykresu.
// - Przypadek błędu: Wypisuje komunikat, jeśli nie można utworzyć pliku CSV.
void save_plot_data_lab8(double coeff[max_degree_lab8 + 1], int degree);

// Przeprowadza analizę błędu dla wielu stopni wielomianów (od 1 do max_degree) i zapisuje wyniki do "degree_analysis_lab8.csv".
// - Przypadek błędu: Przerywa działanie, jeśli parametr max_degree wykracza poza dopuszczalne granice.
void save_degree_analysis_lab8(int max_degree);

// Koordynuje pełne wykonanie przykładu (pyta użytkownika o stopień, rozwiązuje układ, wyświetla wyniki i zapisuje dane).
// - Przykład: run_example_lab8();
void run_example_lab8();
