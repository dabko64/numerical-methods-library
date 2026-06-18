#ifndef INTEGRATION_LAB7_HPP
#define INTEGRATION_LAB7_HPP

// Oblicza wartość funkcji podcałkowej zdefiniowanej na potrzeby ćwiczenia.
// - Argumenty: x: zmienna wejściowa kwadratury
// - Zwraca: wartość funkcji f(x) = (1 - x) * exp(sin(x))
double function_lab7(double x);

// Oblicza całkę oznaczoną funkcji za pomocą złożonej metody trapezów.
// - Argumenty: f: wskaźnik do funkcji podcałkowej, a: początek przedziału, b: koniec przedziału, n: liczba podprzedziałów
// - Zwraca: przybliżoną wartość całki
// - Przypadek błędu: Rzuca wyjątek std::invalid_argument, jeśli n <= 0.
double trapezoidal_lab7(double (*f)(double), double a, double b, int n);

// Oblicza całkę oznaczoną funkcji za pomocą złożonej metody Simpsona.
// - Argumenty: f: wskaźnik do funkcji podcałkowej, a: początek przedziału, b: koniec przedziału, n: liczba podprzedziałów
// - Zwraca: przybliżoną wartość całki
// - Uwaga: Jeśli n jest nieparzyste, funkcja automatycznie zwiększa je o 1.
// - Przypadek błędu: Rzuca wyjątek std::invalid_argument, jeśli n <= 0.
double simpson_lab7(double (*f)(double), double a, double b, int n);

// Oblicza kwadraturę Gaussa-Legendre'a na pojedynczym przedziale dla 2, 3 lub 4 węzłów.
// - Argumenty: f: wskaźnik do funkcji podcałkowej, a: początek przedziału, b: koniec przedziału, nodes: liczba węzłów
// - Zwraca: obliczoną wartość kwadratury po transformacji przedziału na [-1, 1]
// - Przypadek błędu: Rzuca wyjątek std::invalid_argument, jeśli liczba węzłów jest inna niż 2, 3 lub 4.
double gauss_quadrature_lab7(double (*f)(double), double a, double b, int nodes);

// Oblicza całkę za pomocą złożonej kwadratury Gaussa, dzieląc przedział na mniejsze podprzedziały.
// - Argumenty: f: wskaźnik do funkcji podcałkowej, a: początek, b: koniec, intervals: liczba podprzedziałów, nodes: liczba węzłów w każdym podprzedziale
// - Zwraca: całkowitą przybliżoną wartość całki (sumę kwadratur z podprzedziałów)
// - Przypadek błędu: Rzuca wyjątek std::invalid_argument, jeśli intervals <= 0.
double composite_gauss_lab7(double (*f)(double), double a, double b, int intervals, int nodes);

// Oblicza błąd bezwzględny przybliżenia.
// - Argumenty: exact_value: wartość dokładna, approximate_value: wartość uzyskana z metody
// - Zwraca: wartość błędu |exact_value - approximate_value|
double absolute_error_lab7(double exact_value, double approximate_value);

// Oblicza błąd względny wyrażony w procentach.
// - Argumenty: exact_value: wartość dokładna, approximate_value: wartość uzyskana z metody
// - Zwraca: błąd procentowy (%)
// - Przypadek błędu: Rzuca wyjątek std::invalid_argument, jeśli exact_value wynosi 0.0 (brak możliwości dzielenia przez zero).
double percentage_error_lab7(double exact_value, double approximate_value);

// Koordynuje pełne wykonanie przykładu dla laboratorium 7: porównuje kwadraturę Gaussa (zwykłą i złożoną) 
// z metodami trapezów i Simpsona w przedziale [-1.0, 15.0], wyznacza błędy i wyświetla wyniki.
// - Zwraca: void
void run_example_lab7();

#endif
