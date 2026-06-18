#ifndef INTEGRATION_LAB6_HPP
#define INTEGRATION_LAB6_HPP

// Oblicza wartość funkcji matematycznej zdefiniowanej na potrzeby całkowania numerycznego.
// - Argumenty: x: zmienna integracji
// - Zwraca: wartość funkcji f(x) = cos(12x + 1) / (1 + x^2)
double function_lab6(double x);

// Oblicza całkę oznaczoną w przedziale [a, b] metodą prostokątów (lewobrzeżną).
// - Argumenty: a: początek przedziału, b: koniec przedziału, n: liczba podprzedziałów
// - Zwraca: przybliżoną wartość całki
// - Przypadek błędu: Rzuca wyjątek std::invalid_argument, jeśli n <= 0.
double left_rectangle_lab6(double a, double b, int n);

// Oblicza całkę oznaczoną w przedziale [a, b] metodą prostokątów (punktów środkowych).
// - Argumenty: a: początek przedziału, b: koniec przedziału, n: liczba podprzedziałów
// - Zwraca: przybliżoną wartość całki
// - Przypadek błędu: Rzuca wyjątek std::invalid_argument, jeśli n <= 0.
double midpoint_rectangle_lab6(double a, double b, int n);

// Oblicza całkę oznaczoną w przedziale [a, b] metodą trapezów.
// - Argumenty: a: początek przedziału, b: koniec przedziału, n: liczba podprzedziałów
// - Zwraca: przybliżoną wartość całki
// - Przypadek błędu: Rzuca wyjątek std::invalid_argument, jeśli n <= 0.
double trapezoidal_lab6(double a, double b, int n);

// Oblicza całkę oznaczoną w przedziale [a, b] metodą Simpsona (parabol).
// - Argumenty: a: początek przedziału, b: koniec przedziału, n: liczba podprzedziałów
// - Zwraca: przybliżoną wartość całki
// - Uwaga: Automatycznie zwiększa n o 1, jeżeli przekazana liczba podprzedziałów jest nieparzysta.
// - Przypadek błędu: Rzuca wyjątek std::invalid_argument, jeśli n <= 0.
double simpson_lab6(double a, double b, int n);

// Oblicza błąd bezwzględny pomiędzy wartością dokładną a przybliżoną.
// - Argumenty: exact_value: wartość dokładna (referencyjna), approximate_value: wartość przybliżona
// - Zwraca: wartość błędu |exact_value - approximate_value|
double absolute_error_lab6(double exact_value, double approximate_value);

// Oblicza eksperymentalny rząd zbieżności na podstawie stosunku błędów dla kroków n oraz 2n.
// - Argumenty: error_n: błąd dla n podprzedziałów, error_2n: błąd dla 2n podprzedziałów
// - Zwraca: oszacowany rząd zbieżności (wartość typu double)
// - Przypadek błędu: Rzuca wyjątek std::invalid_argument, jeśli którykolwiek z błędów jest mniejszy bądź równy 0.0.
double convergence_order_lab6(double error_n, double error_2n);

// Mierzy czas wykonania wybranej metody całkowania numerycznego w mikrosekundach.
// - Argumenty: method: wskaźnik na funkcję realizującą całkowanie, a: początek, b: koniec, n: liczba podprzedziałów, result: referencja do zapisania wyniku całkowania
// - Zwraca: zmierzony czas wykonania w mikrosekundach
double measure_time_lab6(double (*method)(double, double, int), double a, double b, int n, double &result);

// Koordynuje pełne wykonanie przykładu dla laboratorium 6: oblicza całki w przedziale [0.0, 3.0], 
// analizuje błędy, wyświetla tabele porównawcze, wyznacza rzędy zbieżności oraz zapisuje dane do pliku "results_lab6.csv".
// - Zwraca: void
void run_example_lab6();

#endif
