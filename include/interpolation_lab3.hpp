#ifndef INTERPOLATION_LAB3_HPP
#define INTERPOLATION_LAB3_HPP

#include <vector>
#include <string>

// Ta funkcja wczytuje współczynniki wielomianu 'a' oraz punkty testowe 'x' z pliku tekstowego dla schematu Hornera.
// - Argumenty:
//   nazwaPliku: ścieżka do pliku wejściowego z danymi (np. "dane_H.txt")
//   a: referencja do wektora, w którym zostaną zapisane wczytane współczynniki
//   x: referencja do wektora, w którym zostaną zapisane punkty ewaluacji
// - Zwraca: true, jeśli pomyślnie wczytano zarówno współczynniki, jak i punkty; false w przeciwnym wypadku.
bool wczytajDaneH(const std::string& nazwaPliku, std::vector<double>& a, std::vector<double>& x);

// Ta funkcja wczytuje punkty pomiarowe (współrzędne x oraz wartości y) z pliku tekstowego na potrzeby interpolacji Newtona.
// - Argumenty:
//   nazwaPliku: ścieżka do pliku wejściowego (np. "dane_N.txt")
//   x: referencja do wektora współrzędnych X węzłów
//   y: referencja do wektora wartości Y w węzłach
// - Zwraca: true, jeśli dane załadowano poprawnie oraz wektory X i Y mają ten sam rozmiar; false w przypadku błędu.
bool wczytajDaneN(const std::string& nazwaPliku, std::vector<double>& x, std::vector<double>& y);

// Ta funkcja oblicza wartość wielomianu w punkcie x przy użyciu klasycznej postaci naturalnej (z użyciem std::pow).
// - Argumenty:
//   x: punkt, dla którego obliczana jest wartość wielomianu
//   a: wektor współczynników wielomianu (od najniższej potęgi)
// - Zwraca: obliczoną wartość wielomianu w punkcie x
double postacNaturalna(double x, const std::vector<double>& a);

// Ta funkcja oblicza wartość wielomianu w punkcie x przy użyciu wydajnego schematu Hornera.
// - Argumenty:
//   x: punkt, dla którego obliczana jest wartość wielomianu
//   a: wektor współczynników wielomianu
// - Zwraca: obliczoną wartość wielomianu w punkcie x
double schematHornera(double x, const std::vector<std::vector<double>>& a_wspolczynniki) { return 0.0; } // Uwaga na dopasowanie typu: double schematHornera(double x, const std::vector<double>& a);
double schematHornera(double x, const std::vector<double>& a);

// Ta funkcja wyznacza współczynniki wielomianu interpolacyjnego Newtona przy użyciu metody ilorazów różnicowych.
// - Argumenty:
//   x: wektor współrzędnych X węzłów interpolacji
//   y: wektor współrzędnych Y węzłów interpolacji
// - Zwraca: wektor obliczonych współczynników wielomianu Newtona (ilorazów różnicowych)
std::vector<double> wspolczynnikiNewtona(const std::vector<double>& x, const std::vector<double>& y);

// Ta funkcja oblicza wartość wielomianu interpolacyjnego Newtona w zadanym punkcie X, stosując uogólniony schemat Hornera.
// - Argumenty:
//   X: punkt, dla którego wyznaczana jest wartość interpolowana
//   x: wektor współrzędnych X węzłów interpolacji
//   a: wektor współczynników wielomianu Newtona
// - Zwraca: obliczoną wartość interpolowaną w punkcie X
double interpolacjaNewtona(double X, const std::vector<double>& x, const std::vector<double>& a);

// Ta funkcja zapisuje współrzędne x oraz obliczone wartości y do pliku formatu CSV, umożliwiając późniejsze wygenerowanie wykresu.
// - Argumenty:
//   nazwaPliku: ścieżka docelowa do zapisu pliku CSV
//   x: wektor współrzędnych X punktów wykresu
//   y: wektor obliczonych wartości Y wielomianu
// - Zwraca: true, jeśli plik został pomyślnie utworzony i zapisany; false, jeśli otwarcie pliku się nie powiodło.
bool zapiszCSV_lab3(const std::string& nazwaPliku, const std::vector<double>& x, const std::vector<double>& y);

// Ta funkcja koordynuje pełne wykonanie przykładu dla laboratorium 3: porównuje czasowo działanie postaci naturalnej 
// oraz schematu Hornera, wyznacza ilorazy różnicowe dla wielomianu Newtona i generuje dane do wykresu w pliku CSV.
// - Zwraca: void
void run_example_lab3();

#endif // INTERPOLATION_LAB3_HPP
