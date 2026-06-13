#ifndef INTERPOLATION_LAB3_HPP
#define INTERPOLATION_LAB3_HPP

#include <vector>
#include <string>


bool wczytajDaneH(const std::string& nazwaPliku, std::vector<double>& a, std::vector<double>& x);
bool wczytajDaneN(const std::string& nazwaPliku, std::vector<double>& x, std::vector<double>& y);
double postacNaturalna(double x, const std::vector<double>& a);
double schematHornera(double x, const std::vector<double>& a);
std::vector<double> wspolczynnikiNewtona(const std::vector<double>& x, const std::vector<double>& y);
double interpolacjaNewtona(double X, const std::vector<double>& x, const std::vector<double>& a);
bool zapiszCSV_lab3(const std::string& nazwaPliku, const std::vector<double>& x, const std::vector<double>& y);

void run_example_lab3();

#endif // INTERPOLATION_LAB3_HPP