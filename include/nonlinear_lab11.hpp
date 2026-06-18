#ifndef NONLINEAR_LAB11_HPP
#define NONLINEAR_LAB11_HPP

#include <fstream>

using namespace std;

const int max_roots_lab11 = 32;
const int max_iter_lab11 = 100;

// Typ wyliczeniowy reprezentujący stan zakończenia algorytmu nieliniowego.
enum result_status_lab11
{
    converged_lab11,         // Algorytm osiągnął zbieżność (znaleziono pierwiastek).
    max_iter_lab11_status,   // Osiągnięto maksymalną liczbę iteracji bez zbieżności.
    zero_derivative_lab11,   // Pochodna lub mianownik bliski zeru – błąd dzielenia przez zero.
    oscillation_lab11        // Wykryto rozbieżność metody lub zapętlenie/oscylacje.
};

// Struktura przechowująca końcowy wynik działania metody dla jednego pierwiastka.
struct result_lab11
{
    double root;                      // Wyznaczona wartość przybliżona pierwiastka.
    int iterations;                   // Liczba wykonanych iteracji.
    result_status_lab11 status;       // Stan zakończenia algorytmu.
    double empirical_order;           // Eksperymentalny (empiryczny) rząd zbieżności.
    double empirical_constant;        // Eksperymentalna stała zbieżności asymptotycznej.
};

// Struktura przechowująca historię kolejnych kroków (iteracji) algorytmu.
struct steps_history_lab11
{
    double x[max_iter_lab11];      // Tablica kolejnych przybliżeń pierwiastka x_n.
    double fx[max_iter_lab11];     // Tablica wartości funkcji f(x_n).
    double error[max_iter_lab11];  // Tablica błędów przybliżenia (odległość |x_{n+1} - x_n|).
    int n;                         // Liczba zapisanych kroków.
};

// Pierwsza funkcja testowa (wielomian 6. stopnia).
double function_1_lab11(double x);
// Analityczna pochodna pierwszej funkcji testowej.
double derivative_1_lab11(double x);

// Druga funkcja testowa (równanie zawierające cos(x) oraz 1/x).
// - Przypadek błędu: Zgłasza błąd w konsoli i zwraca dużą wartość, gdy x jest bliskie zeru.
double function_2_lab11(double x);
// Analityczna pochodna drugiej funkcji testowej.
double derivative_2_lab11(double x);

// Trzecia funkcja testowa (trygonometryczna).
double function_3_lab11(double x);
// Analityczna pochodna trzeciej funkcji testowej.
double derivative_3_lab11(double x);

// Oblicza przybliżoną wartość pochodnej funkcji w punkcie x metodą ilorazu różnicowego (centralnego).
// - Argumenty: f: wskaźnik do funkcji, x: punkt obliczeniowy
// - Zwraca: wartość numerycznej pochodnej
double numeric_derivative_lab11(double (*f)(double), double x);

// Analizuje historię trzech kolejnych błędów w celu wyznaczenia empirycznego rzędu i stałej zbieżności.
// - Argumenty: e0, e1, e2: kolejne błędy iteracji; p, c: referencje do zapisu rzędu i stałej.
void analyze_convergence_lab11(double e0, double e1, double e2, double &p, double &c);

// Rozwiązuje równanie nieliniowe metodą Newtona (stycznych).
// Może korzystać z pochodnej analitycznej (df) lub numerycznej.
// - Argumenty: f: funkcja, df: pochodna, x0: punkt startowy, use_numeric_derivative: flaga wyboru pochodnej, history: zapis przebiegu
// - Zwraca: strukturę z końcowym wynikiem i statusem
// - Przypadek błędu: Przerywa działanie przy zerowej pochodnej lub rozbieżności/oscylacjach.
result_lab11 newton_method_lab11(double (*f)(double), double (*df)(double), double x0, bool use_numeric_derivative, steps_history_lab11 &history);

// Rozwiązuje równanie nieliniowe metodą siecznych na podstawie dwóch punktów startowych.
// - Argumenty: f: funkcja, x0, x1: przybliżenia początkowe, history: zapis przebiegu
// - Zwraca: strukturę z końcowym wynikiem i statusem
// - Przypadek błędu: Przerywa działanie, gdy mianownik (f(x_n) - f(x_{n-1})) jest zbyt bliski zeru.
result_lab11 secant_method_lab11(double (*f)(double), double x0, double x1, steps_history_lab11 &history);

// Sprawdza, czy znaleziony pierwiastek został już wcześniej zarejestrowany w tablicy wyników z określoną tolerancją.
// - Zwraca: true, jeśli pierwiastek już istnieje; false, jeśli jest nowy.
bool root_already_exists_lab11(double x);

// Tłumaczy kod statusu algorytmu (typ enum) na czytelny łańcuch tekstowy (np. "converged").
// - Zwraca: wskaźnik do statycznej tablicy znaków C-string.
const char* decode_status_lab11(result_status_lab11 status);

// Zapisuje kompletną historię zbieżności danej metody dla konkretnego pierwiastka do pliku CSV.
void save_method_to_csv_lab11(ofstream &file, const char* function_name, const char* method_name, double root_id, const steps_history_lab11 &history);

// Przeszukuje zadany przedział [start, end] krok po kroku w celu znalezienia zmian znaków funkcji,
// uruchamia dla nich metody Newtona oraz siecznych i zapisuje porównanie wyników do pliku.
void search_and_compare_lab11(ofstream &file, double (*f)(double), double (*df)(double), const char* function_name, double start, double end);

// Koordynuje pełne wykonanie przykładu dla laboratorium 11: pobiera przedział od użytkownika,
// zabezpiecza punkt x = 0 dla funkcji drugiej, wywołuje analizę porównawczą dla trzech funkcji testowych i zamyka plik CSV.
void run_example_lab11();

#endif
