#ifndef INTERPOLATION_LAB2_HPP
#define INTERPOLATION_LAB2_HPP

#include <vector>
#include <string>

bool wczytajdane1(const std::string& nazwaPliku, std::vector<double>& x, std::vector<double>& y);
bool zapiszCSV(const std::string& nazwaPliku, const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& y_interp);
double interpolacja(double X, const std::vector<double>& wezlyX, const std::vector<double>& wezlyY);
void run_lab2();
#endif // INTERPOLACJA_HPP