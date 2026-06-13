#ifndef LU_LAB4_HPP
#define LU_LAB4_HPP

#include <vector>
#include <string>

bool wczytajDaneLU(const std::string& nazwaPliku, int& n, std::vector<std::vector<double>>& A, std::vector<double>& b);
void wypiszMacierz(const std::vector<std::vector<double>>& M, const std::string& nazwa);
void metodaLU(std::vector<std::vector<double>> A, std::vector<double> b, int n);

void run_example_lab4();

#endif // LU_LAB4_HPP