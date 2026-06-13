cmake_minimum_required(VERSION 4.2)
project(mn_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(mn_project main.cpp
        include/integration_lab6.hpp
        tests/test_integration_lab6.cpp
        examples/example_integration_lab6.cpp
        include/integration_lab7.hpp
        src/integration_lab7.cpp
        tests/test_integration_lab7.cpp
        src/integration_lab6.cpp
        src/interpolation_lab2.cpp
        include/interpolation_lab2.hpp
)
        tests/test_integration_lab7.cpp
        include/approximation_lab8.hpp
        src/approximation_lab8.cpp
        examples/example_approximation_lab8.cpp
        tests/test_approximation_lab8.cpp
        examples/example_ode_lab9.cpp
        include/ode_lab9.hpp
        src/ode_lab9.cpp
        tests/test_ode_lab9.cpp)
