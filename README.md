# numerical-methods-library


This project was created for the **Numerical Methods** course.

The goal of the project is to create a simple numerical library in C++ based on functions implemented during laboratory classes.

The library contains methods from the following areas:

* interpolation,
* numerical integration,
* approximation,
* ordinary differential equations,
* nonlinear equations.

The project also contains examples, unit tests, a main menu program and documentation.

---

## Project structure

```txt
numerical-methods-library/
|
|-- include/        # header files
|-- src/            # source files
|-- tests/          # unit tests
|-- examples/       # example programs
|-- main.cpp        # main menu program
|-- CMakeLists.txt  # cmake build file
|-- README.md       # project documentation
```

---

## Library content

### Interpolation

Files:

```txt
include/interpolation_lab2.hpp
src/interpolation_lab2.cpp

include/interpolation_lab3.hpp
src/interpolation_lab3.cpp
```

Implemented functions include:

* lagrange interpolation,
* newton interpolation,
* polynomial value calculation,
* saving results to files.

---

### Numerical integration

Files:

```txt
include/integration_lab6.hpp
src/integration_lab6.cpp

include/integration_lab7.hpp
src/integration_lab7.cpp
```

Implemented methods include:

* left rectangle method,
* midpoint rectangle method,
* trapezoidal method,
* simpson method,
* gauss quadrature,
* composite gauss quadrature,
* absolute error calculation,
* percentage error calculation,
* convergence order analysis.

Example function from lab 6:

```txt
f(x) = cos(12x + 1) / (1 + x^2)
```

Example function from lab 7:

```txt
f(x) = (1 - x) * exp(sin(x))
```

---

### Approximation

Files:

```txt
include/approximation_lab8.hpp
src/approximation_lab8.cpp
```

Implemented functions include:

* creating a normal equation system,
* calculating integrals needed for approximation,
* solving a linear system with gaussian elimination,
* calculating polynomial approximation values,
* calculating mean square error,
* saving plot data to files.

Approximated function:

```txt
f(x) = x^2 * sin(x)^2 - x^2 + x
```

on the interval:

```txt
[5, 11]
```

---

### Ordinary differential equations

Files:

```txt
include/ode_lab9.hpp
src/ode_lab9.cpp

include/ode_lab10.hpp
src/ode_lab10.cpp
```

Implemented methods include:

* euler method,
* heun method,
* midpoint method,
* fourth order runge kutta method,
* comparison of numerical methods,
* saving results to csv files.

The analyzed equation describes temperature change:

```txt
T'(t) = -alpha * (T^4 - beta)
```

---

### Nonlinear equations

Files:

```txt
include/nonlinear_lab11.hpp
src/nonlinear_lab11.cpp

include/nonlinear_lab12.hpp
src/nonlinear_lab12.cpp
```

Implemented methods include:

* newton method with analytical derivative,
* newton method with numerical derivative,
* secant method,
* searching for roots on an interval,
* detecting problems such as zero derivative or divergence,
* saving iteration history to csv files.

Example functions:

```txt
f1(x) = x^6 - 9x^5 + 29x^4 - 39x^3 + 23x^2 - 6x - 3
```

```txt
f2(x) = x^3 + cos(x) - 1/x
```

```txt
f3(x) = 2sin(x) + cos(x)^2
```

---

## Main program

File:

```txt
main.cpp
```

The main program contains a menu where the user can choose a selected laboratory module.

Example menu:

```txt
1. lab 2  - lagrange interpolation
2. lab 3  - newton interpolation
3. lab 6  - numerical integration 1
4. lab 7  - numerical integration 2
5. lab 8  - polynomial approximation
6. lab 9  - euler method for ode
7. lab 10 - ode methods comparison
8. lab 11 - nonlinear equations 1
9. lab 12 - nonlinear equations 2
0. exit
```

After choosing an option, the proper example function from the library is executed.

---

## Examples

The `examples/` directory contains demonstration files which show practical usage of the library functions.

Example files:

```txt
examples/example_integration_lab6.cpp
examples/example_integration_lab7.cpp
examples/example_approximation_lab8.cpp
examples/example_ode_lab9.cpp
examples/example_ode_lab10.cpp
examples/example_nonlinear_lab11.cpp
examples/example_nonlinear_lab12.cpp
```

Example usage from lab 6:

```cpp
#include "../include/integration_lab6.hpp"

int main()
{
    run_example_lab6();

    return 0;
}
```

---

## Unit tests

The `tests/` directory contains unit tests for selected modules.

Example test files:

```txt
tests/test_integration_lab6.cpp
tests/test_integration_lab7.cpp
tests/test_approximation_lab8.cpp
tests/test_ode_lab9.cpp
tests/test_ode_lab10.cpp
tests/test_nonlinear_lab11.cpp
tests/test_nonlinear_lab12.cpp
```

The tests check both correct and incorrect cases, for example:

* correct value calculated by simpson method,
* correct one step of euler method,
* correct root found by newton method,
* detection of wrong input data,
* detection of zero derivative,
* detection of a singular linear system.

---

## Building the project

The project can be built with CMake.

Commands:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

In CLion, choose a target such as:

```txt
main_app
```

and run it.

---

## Running the main program

After building the project, run the main program:

```bash
./main_app
```

On Windows, the executable file may have the `.exe` extension.

---

## Running examples

Example targets:

```txt
example_integration_lab6
example_integration_lab7
example_approximation_lab8
example_ode_lab9
example_ode_lab10
example_nonlinear_lab11
example_nonlinear_lab12
```

Each target runs one example program for a selected module.

---

## Running tests

Example test targets:

```txt
test_integration_lab6
test_integration_lab7
test_approximation_lab8
test_ode_lab9
test_ode_lab10
test_nonlinear_lab11
test_nonlinear_lab12
```

After running a test, the program prints a message such as:

```txt
all integration lab6 tests passed
```

---

## Output files

Some examples generate output files, for example:

```txt
results_lab6.csv
results_lab8.csv
results_lab9.csv
results_lab10.csv
results_lab11.csv
results_lab12.csv
degree_analysis_lab8.csv
convergence_lab10.csv
matrix_a_b_lab8.txt
```

These files can be used to analyze results and create plots.

---

## Repository

```txt
https://github.com/dabko64/numerical-methods-library
```

---

