#ifndef ODE_LAB9_HPP
#define ODE_LAB9_HPP

// Oblicza wartość prawej strony równania różniczkowego (pochodną temperatury po czasie).
// Modeluje proces chłodzenia zgodnie z zależnością: dT/dt = -alpha * (temperature^4 - beta).
// - Argumenty: temperature: aktualna temperatura obiektu, alpha: współczynnik intensywności chłodzenia, beta: parametr otoczenia
// - Zwraca: wartość pochodnej w zadanym punkcie
double derivative_lab9(double temperature, double alpha, double beta);

// Wyznacza dokładne (analityczne) rozwiązanie równania chłodzenia dla parametru beta = 0.
// - Argumenty: time: czas, dla którego wyznaczane jest rozwiązanie, initial_temperature: temperatura początkowa, alpha: współczynnik chłodzenia
// - Zwraca: dokładną wartość temperatury lub 0.0 w przypadku wystąpienia błędu
// - Przypadek błędu: Wypisuje komunikat i zwraca 0.0, jeśli temperatura początkowa wynosi 0.0 lub alpha jest ujemna.
double exact_solution_lab9(double time, double initial_temperature, double alpha);

// Wykonuje jeden krok integracji numerycznej przy użyciu jawnej metody Eulera (T_next = T + step * dT/dt).
// - Argumenty: temperature: aktualna temperatura, step: krok czasowy integracji, alpha: współczynnik chłodzenia, beta: parametr otoczenia
// - Zwraca: przybliżoną wartość temperatury po wykonaniu kroku
// - Przypadek błędu: Wypisuje komunikat i zwraca niezmienioną temperaturę, jeśli krok 'step' jest mniejszy bądź równy 0.0.
double euler_step_lab9(double temperature, double step, double alpha, double beta);

// Oblicza błąd bezwzględny pomiędzy wartością dokładną a przybliżoną.
// - Zwraca: wartość błędu |exact_value - approximate_value|
double absolute_error_lab9(double exact_value, double approximate_value);

// Oblicza błąd względny wyrażony w procentach.
// - Zwraca: błąd procentowy (%) lub 0.0 w przypadku błędu danych
// - Przypadek błędu: Wypisuje komunikat i zwraca 0.0, jeśli wartość dokładna wynosi 0.0 (brak możliwości dzielenia przez zero).
double percentage_error_lab9(double exact_value, double approximate_value);

// Zapisuje pojedynczy wiersz z wynikami symulacji do pliku "results_lab9.csv".
// - Przypadek błędu: Wypisuje komunikat tekstowy, jeśli nie uda się otworzyć pliku w trybie dopisywania.
void save_row_lab9(double time, double temperature, double exact_temperature, double error, double percentage_error);

// Wypisuje pojedynczy wiersz danych tabelarycznych na standardowe wyjście konsoli przy użyciu std::setw.
void print_row_lab9(double time, double temperature, double exact_temperature, double error, double percentage_error);

// Uruchamia pełną symulację procesu chłodzenia metodą Eulera, prezentując wyniki w konsoli oraz zapisując je do pliku CSV.
// - Przypadek błędu: Przerywa działanie, jeśli temperatura początkowa bądź czas chłodzenia są niedodatnie, lub gdy parametr alpha jest ujemny.
void run_cooling_simulation_lab9(double initial_temperature, double alpha, double beta, double cooling_time);

// Koordynuje wykonanie przykładu dla laboratorium 9: konfiguruje parametry początkowe symulacji na podstawie numeru albumu, a następnie uruchamia symulację.
// - Zwraca: void
void run_example_lab9();

#endif // ODE_LAB9_HPP
