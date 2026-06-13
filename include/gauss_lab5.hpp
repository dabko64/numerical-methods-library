#ifndef GAUSS_LAB5_HPP
#define GAUSS_LAB5_HPP

#include <vector>
#include <string>

bool wczytajDaneGauss(const std::string& nazwaPliku, int& n, std::vector<std::vector<double>>& A, std::vector<double>& b);
void wypiszMacierzRozszerzona(const std::vector<std::vector<double>>& A, const std::vector<double>& b);
std::vector<double> metodaGaussa(std::vector<std::vector<double>> A, std::vector<double> b, int n);
void run_example_lab5();

#endif