#ifndef ODE_LAB10_HPP
#define ODE_LAB10_HPP

// Oblicza wartość prawej strony równania różniczkowego (pochodną temperatury po czasie).
// Zgodnie z modelem chłodzenia: dT/dt = -alpha * (temperature^4 - beta).
// - Argumenty: temperature: aktualna temperatura obiektu, alpha: współczynnik chłodzenia, beta: parametr otoczenia
// - Zwraca: wartość pochodnej w danym punkcie
double derivative_lab10(double temperature, double alpha, double beta);

// Wyznacza dokładną (analityczną) wartość temperatury w zadanym czasie dla parametru beta = 0.
// - Argumenty: time: czas obliczeniowy, initial_temperature: temperatura początkowa, alpha: współczynnik chłodzenia
// - Zwraca: dokładną wartość temperatury lub 0.0 w przypadku błędnych danych
// - Przypadek błędu: Wypisuje błąd i zwraca 0.0, jeśli temperatura początkowa wynosi 0.0 (dzielenie przez zero).
double exact_solution_lab10(double time, double initial_temperature, double alpha);

// Wykonuje jeden krok integracji numerycznej przy użyciu jawnej metody Eulera (1. rząd).
// - Zwraca: przybliżoną wartość temperatury w kolejnym kroku czasowym
// - Przypadek błędu: Wypisuje komunikat i zwraca niezmienioną temperaturę, jeśli krok 'step' jest mniejszy bądź równy 0.0.
double euler_step_lab10(double temperature, double step, double alpha, double beta);

// Wykonuje jeden krok integracji numerycznej przy użyciu metody Heuna (jawna metoda trapezów, 2. rząd).
// - Zwraca: przybliżoną wartość temperatury w kolejnym kroku czasowym
// - Przypadek błędu: Wypisuje komunikat i zwraca niezmienioną temperaturę, jeśli krok 'step' jest mniejszy bądź równy 0.0.
double heun_step_lab10(double temperature, double step, double alpha, double beta);

// Wykonuje jeden krok integracji numerycznej przy użyciu metody punktu środkowego (2. rząd).
// - Zwraca: przybliżoną wartość temperatury w kolejnym kroku czasowym
// - Przypadek błędu: Wypisuje komunikat i zwraca niezmienioną temperaturę, jeśli krok 'step' jest mniejszy bądź równy 0.0.
double midpoint_step_lab10(double temperature, double step, double alpha, double beta);

// Wykonuje jeden krok integracji numerycznej przy użyciu klasycznej metody Rungego-Kutty 4. rzędu (RK4).
// - Zwraca: przybliżoną wartość temperatury w kolejnym kroku czasowym
// - Przypadek błędu: Wypisuje komunikat i zwraca niezmienioną temperaturę, jeśli krok 'step' jest mniejszy bądź równy 0.0.
double runge_kutta_4_step_lab10(double temperature, double step, double alpha, double beta);

// Oblicza błąd bezwzględny przybliżenia numerycznego.
// - Zwraca: wartość błędu |exact_value - approximate_value|
double absolute_error_lab10(double exact_value, double approximate_value);

// Zapisuje pojedynczy wiersz z wynikami symulacji i błędami wszystkich metod do pliku "results_lab10.csv".
// - Przypadek błędu: Wypisuje komunikat tekstowy, jeśli nie uda się otworzyć pliku do zapisu.
void save_row_lab10(double time, double euler_temperature, double heun_temperature, double midpoint_temperature, double rk4_temperature, double exact_temperature, double euler_error, double heun_error, double midpoint_error, double rk4_error);

// Wypisuje pojedynczy wiersz danych tabelarycznych (wyniki metod) na standardowe wyjście konsoli z zachowaniem stałych szerokości kolumn.
void print_row_lab10(double time, double euler_temperature, double heun_temperature, double midpoint_temperature, double rk4_temperature, double exact_temperature);

// Uruchamia główną symulację porównawczą procesu chłodzenia dla wszystkich czterech metod, wypisując wyniki w tabeli i zapisując je do pliku CSV.
// - Przypadek błędu: Przerywa działanie, jeśli temperatura początkowa bądź czas chłodzenia są niedodatnie, lub gdy nie można utworzyć pliku CSV.
void run_temperature_change_lab10(double initial_temperature, double alpha, double beta, double cooling_time);

// Przeprowadza analizę zbieżności metod dla różnych długości kroków czasowych i zapisuje uzyskane błędy końcowe do pliku "convergence_lab10.csv".
// - Przypadek błędu: Wypisuje komunikat tekstowy, jeśli nie uda się utworzyć pliku CSV.
void run_convergence_analysis_lab10(double initial_temperature, double alpha, double beta, double cooling_time);

// Koordynuje wykonanie pełnego przykładu z laboratorium 10: ustawia parametry początkowe symulacji na podstawie zdefiniowanego numeru albumu, po czym wywołuje symulację oraz analizę zbieżności.
// - Zwraca: void
void run_example_lab10();

#endif
