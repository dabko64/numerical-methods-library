cmake_minimum_required(VERSION 3.10)

project(numerical_methods_library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(numeryka_lib
include_directories(include)

add_library(numerical_library
        src/integration_lab6.cpp
        src/integration_lab7.cpp
        src/interpolation_lab2.cpp
        src/approximation_lab8.cpp
        src/ode_lab9.cpp
        src/interpolation_lab3.cpp
        src/ode_lab10.cpp
)

add_executable(main_app
        main.cpp
)

target_link_libraries(main_app numerical_library)

add_executable(example_integration_lab6
        examples/example_integration_lab6.cpp
)

target_link_libraries(example_integration_lab6 numerical_library)

add_executable(example_integration_lab7
        examples/example_integration_lab7.cpp
)

target_include_directories(numeryka_lib PUBLIC include)
target_link_libraries(example_integration_lab7 numerical_library)

add_executable(example_integration examples/example_integration_lab6.cpp)
target_link_libraries(example_integration numeryka_lib)
add_executable(example_approximation_lab8
        examples/example_approximation_lab8.cpp
        examples/example_nonlinear_lab11.cpp
        include/nonlinear_lab11.hpp
        src/nonlinear_lab11.cpp
        tests/test_nonlinear_lab11.cpp
)

add_executable(example_approximation examples/example_approximation_lab8.cpp
        examples/example_interpolation_lab2.cpp
        include/interpolation_lab3.hpp
        examples/example_interpolation_lab3.cpp)
target_link_libraries(example_approximation numeryka_lib)
target_link_libraries(example_approximation_lab8 numerical_library)

add_executable(example_ode_lab9
        examples/example_ode_lab9.cpp
)

add_executable(test_integration_6 tests/test_integration_lab6.cpp)
target_link_libraries(test_integration_6 numeryka_lib)
target_link_libraries(example_ode_lab9 numerical_library)

add_executable(example_ode_lab10
        examples/example_ode_lab10.cpp
)

target_link_libraries(example_ode_lab10 numerical_library)

add_executable(test_approximation tests/test_approximation_lab8.cpp
        tests/test_interpolation_lab3.cpp)
target_link_libraries(test_approximation numeryka_lib)
add_executable(test_integration_lab6
        tests/test_integration_lab6.cpp
)

target_link_libraries(test_integration_lab6 numerical_library)

add_executable(mn_project main.cpp)
target_link_libraries(mn_project numeryka_lib)

add_executable(test_interpolation_lab3 tests/test_interpolation_lab3.cpp)
target_link_libraries(test_interpolation_lab3 numeryka_lib)
add_executable(example_interpolation_lab3 examples/example_interpolation_lab3.cpp)
target_link_libraries(example_interpolation_lab3 numeryka_lib)
add_executable(test_integration_lab7
        tests/test_integration_lab7.cpp
)

target_link_libraries(test_integration_lab7 numerical_library)

add_executable(test_approximation_lab8
        tests/test_approximation_lab8.cpp
)

target_link_libraries(test_approximation_lab8 numerical_library)

add_executable(test_ode_lab9
        tests/test_ode_lab9.cpp
)

target_link_libraries(test_ode_lab9 numerical_library)

add_executable(test_ode_lab10
        tests/test_ode_lab10.cpp
)

target_link_libraries(test_ode_lab10 numerical_library)