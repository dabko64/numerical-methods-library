#ifndef NONLINEAR_LAB12_HPP
#define NONLINEAR_LAB12_HPP

#include <fstream>

using namespace std;

const int max_roots_lab12 = 32;
const int max_iter_lab12 = 100;

// Typ wyliczeniowy reprezentujący stan zakończenia algorytmów poszukiwania pierwiastków.
enum status_lab12
{
    converged_lab12,         // Metoda osiągnęła zbieżność (znaleziono pierwiastek).
    max_iter_lab12_status,   // Osiągnięto limit iteracji bez uzyskania zbieżności.
    zero_derivative_lab12,   // Pochodna lub mianownik bliski zeru (dzielenie przez zero).
    oscillation_lab12        // Wykryto rozbieżność, zbyt duże wartości lub prawdopodobne oscylacje.
};

// Struktura przechowująca końcowy wynik działania metody dla danego pierwiastka.
struct result_lab12
{
    double root;                      // Wyznaczona przybliżona wartość pierwiastka.
    int iterations;                   // Liczba wykonanych iteracji.
    status_lab12 status;              // Stan zakończenia algorytmu.
    double empirical_order;           // Eksperymentalny (empiryczny) rząd zbieżności.
    double empirical_constant;        // Eksperymentalna stała zbieżności asymptotycznej.
};

// Struktura przechowująca historię kolejnych kroków (iteracji) algorytmu.
struct steps_history_lab12
{
    double x[max_iter_lab12];      // Tablica kolejnych przybliżeń pierwiastka x_n.
    double fx[max_iter_lab12];     // Tablica wartości funkcji f(x_n).
    double error[max_iter_lab12];  // Tablica błędów przybliżenia (|x_{n+1} - x_n|).
    int n;                         // Liczba zapisanych kroków.
};

// Pierwsza funkcja testowa (wielomian 6. stopnia).
double function_1_lab12(double x);
// Analityczna pochodna pierwszej funkcji testowej.
double derivative_1_lab12(double x);

// Druga funkcja testowa (równanie z cos(x) oraz 1/x).
// - Przypadek błędu: Zgłasza błąd w konsoli i zwraca dużą wartość, gdy x jest bliskie zeru.
double function_2_lab12(double x);
// Analityczna pochodna drugiej funkcji testowej.
double derivative_2_lab12(double x);

// Trzecia funkcja testowa (trygonometryczna).
double function_3_lab12(double x);
// Analityczna pochodna trzeciej funkcji testowej.
double derivative_3_lab12(double x);

// Oblicza numeryczną wartość pochodnej funkcji w punkcie x przy użyciu ilorazu różnicowego centralnego.
// - Argumenty: f: wskaźnik do funkcji, x: punkt, w którym liczona jest pochodna
// - Zwraca: wartość numerycznej pochodnej
double numeric_derivative_lab12(double (*f)(double), double x);

// Wyznacza empiryczny rząd oraz stałą zbieżności na podstawie trzech kolejnych błędów przybliżenia.
// - Argumenty: e0, e1, e2: kolejne błędy iteracji; p, c: referencje do zapisu rzędu i stałej.
void analyze_convergence_lab12(double e0, double e1, double e2, double &p, double &c);

// Rozwiązuje równanie nieliniowe metodą Newtona (stycznych).
// Może korzystać z pochodnej analitycznej (df) lub numerycznej przybliżanej ilorazem różnicowym.
// - Argumenty: f: funkcja, df: pochodna, x0: przybliżenie początkowe, use_numeric_derivative: flaga wyboru pochodnej, history: zapis przebiegu
// - Zwraca: strukturę z końcowym wynikiem i statusem
// - Przypadek błędu: Przerywa działanie w przypadku zerowej pochodnej, rozbieżności lub wykrycia oscylacji.
result_lab12 newton_method_lab12(double (*f)(double), double (*df)(double), double x0, bool use_numeric_derivative, steps_history_lab12 &history);

// Rozwiązuje równanie nieliniowe metodą siecznych na podstawie dwóch przybliżeń początkowych.
// - Argumenty: f: funkcja, x0, x1: przybliżenia początkowe, history: zapis przebiegu
// - Zwraca: strukturę z końcowym wynikiem i statusem
// - Przypadek błędu: Przerywa działanie, gdy mianownik (f(x_n) - f(x_{n-1})) jest zbyt bliski zeru.
result_lab12 secant_method_lab12(double (*f)(double), double x0, double x1, steps_history_lab12 &history);

// Sprawdza, czy znaleziony pierwiastek został już wcześniej zarejestrowany w tablicy z określoną tolerancją.
// - Zwraca: true, jeśli pierwiastek już istnieje; false, jeśli jest nowy.
bool root_already_exists_lab12(double x);

// Tłumaczy kod statusu algorytmu (typ enum) na czytelny tekst w formacie C-string (np. "converged").
// - Zwraca: wskaźnik do statycznej tablicy znaków.
const char* decode_status_lab12(status_lab12 status);

// Zapisuje kompletną historię kolejnych iteracji danej metody dla wyznaczonego pierwiastka do pliku CSV.
void save_method_to_csv_lab12(ofstream &file, const char* function_name, const char* method_name, double root_id, const steps_history_lab12 &history);

// Przeszukuje zadany przedział [start, end] metodą skanowania, wykrywa zmiany znaku funkcji,
// uruchamia metody Newtona oraz siecznych dla znalezionych obszarów i zapisuje porównanie do pliku.
void search_and_compare_lab12(ofstream &file, double (*f)(double), double (*df)(double), const char* function_name, double start, double end);

// Koordynuje pełne wykonanie przykładu dla laboratorium 12: pobiera przedział od użytkownika,
// zabezpiecza punkt x = 0 dla funkcji drugiej, uruchamia analizę porównawczą dla trzech funkcji testowych i zamyka plik CSV.
// - Zwraca: void
void run_example_lab12();

#endif // NONLINEAR_LAB12_HPP
