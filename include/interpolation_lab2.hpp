#ifndef INTERPOLATION_LAB2_HPP
#define INTERPOLATION_LAB2_HPP

#include <vector>
#include <string>

// Ta funkcja wczytuje dane punktów pomiarowych (wektory x i y) dla określonej grupy z pliku tekstowego.
// - Argumenty:
//   nazwaPliku: ścieżka do pliku wejściowego z danymi grupy
//   x: referencja do wektora, w którym zostaną zapisane współrzędne X punktów
//   y: referencja do wektora, w którym zostaną zapisane wartości funkcji Y
// - Zwraca: true, jeśli dane zostały pomyślnie wczytane; false, jeśli plik nie istnieje lub struktura danych jest błędna.
// - Przypadek błędu: Wypisuje komunikat i zwraca false, gdy wektory są puste lub ich rozmiary się nie zgadzają (x.size() != y.size()).
bool wczytajdane1(const std::string& nazwaPliku, std::vector<double>& x, std::vector<double>& y);

// Ta funkcja zapisuje oryginalne punkty oraz wartości interpolowane do pliku formatu CSV.
// - Argumenty:
//   nazwaPliku: ścieżka docelowa do zapisu pliku CSV
//   x: wektor z oryginalnymi współrzędnymi X
//   y: wektor z oryginalnymi wartościami Y
//   y_interp: wektor z wyznaczonymi wartościami wielomianu interpolacyjnego
// - Zwraca: true, jeśli zapis przebiegł pomyślnie; false, gdy nie udało się otworzyć pliku do zapisu.
bool zapiszCSV(const std::string& nazwaPliku, const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& y_interp);

// Ta funkcja wyznacza wartość wielomianu interpolacyjnego Lagrange'a w zadanym punkcie X.
// - Argumenty:
//   X: punkt, dla którego obliczana jest wartość interpolowana
//   wezlyX: wektor współrzędnych X węzłów interpolacji
//   wezlyY: wektor współrzędnych Y węzłów interpolacji
// - Zwraca: obliczoną przybliżoną wartość wielomianu w punkcie X
double interpolacja(double X, const std::vector<double>& wezlyX, const std::vector<double>& wezlyY);

// Ta funkcja koordynuje pełne wykonanie przykładu: wczytuje dane wejściowe, wybiera co piąty punkt jako węzeł, 
// przeprowadza interpolację Lagrange'a dla wszystkich argumentów, wyznacza błąd maksymalny i zapisuje wyniki do pliku CSV.
// - Zwraca: void
void run_example_lab2();

#endif // INTERPOLATION_LAB2_HPP
