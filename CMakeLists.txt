cmake_minimum_required(VERSION 3.10)

project(numerical_methods_library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(numerical_library
        src/interpolation_lab2.cpp
        src/interpolation_lab3.cpp
        src/integration_lab6.cpp
        src/integration_lab7.cpp
        src/approximation_lab8.cpp
        src/ode_lab9.cpp
        src/ode_lab10.cpp
        src/nonlinear_lab11.cpp
        src/nonlinear_lab12.cpp
        src/LU_lab4.cpp
        src/gauss_lab5.cpp
)

add_executable(main_app
        main.cpp
)

add_executable(example_interpolation_lab2 examples/example_interpolation_lab2.cpp)
target_link_libraries(example_interpolation_lab2 numerical_library)

add_executable(example_interpolation_lab3 examples/example_interpolation_lab3.cpp)
target_link_libraries(example_interpolation_lab3 numerical_library)


add_executable(example_lu_lab4 examples/example_lu_lab4.cpp)
target_link_libraries(example_lu_lab4 numerical_library)

add_executable(test_lu_lab4 tests/test_lu_lab4.cpp)
target_link_libraries(test_lu_lab4 numerical_library)

add_executable(example_gauss_lab5 examples/example_gauss_lab5.cpp)
target_link_libraries(example_gauss_lab5 numerical_library)

add_executable(test_gauss_lab5 tests/test_gauss_lab5.cpp)
target_link_libraries(test_gauss_lab5 numerical_library)

target_link_libraries(main_app numerical_library)

add_executable(example_integration_lab6
        examples/example_integration_lab6.cpp
)

target_link_libraries(example_integration_lab6 numerical_library)

add_executable(example_integration_lab7
        examples/example_integration_lab7.cpp
)

target_link_libraries(example_integration_lab7 numerical_library)

add_executable(example_approximation_lab8
        examples/example_approximation_lab8.cpp
        include/LU_lab4.hpp
        examples/example_LU_lab4.cpp
        include/gauss_lab5.hpp
        examples/example_gauss_lab5.cpp

)

target_link_libraries(example_approximation_lab8 numerical_library)

add_executable(example_ode_lab9
        examples/example_ode_lab9.cpp
)

target_link_libraries(example_ode_lab9 numerical_library)

add_executable(example_ode_lab10
        examples/example_ode_lab10.cpp
)

target_link_libraries(example_ode_lab10 numerical_library)

add_executable(example_nonlinear_lab11
        examples/example_nonlinear_lab11.cpp
)

target_link_libraries(example_nonlinear_lab11 numerical_library)

add_executable(example_nonlinear_lab12
        examples/example_nonlinear_lab12.cpp
)

target_link_libraries(example_nonlinear_lab12 numerical_library)

add_executable(test_integration_lab6
        tests/test_integration_lab6.cpp
)

target_link_libraries(test_integration_lab6 numerical_library)

add_executable(test_integration_lab7
        tests/test_integration_lab7.cpp
)

target_link_libraries(test_integration_lab7 numerical_library)

add_executable(test_approximation_lab8
        tests/test_approximation_lab8.cpp
        tests/test_LU_lab4.cpp
        tests/test_gauss_lab5.cpp
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

add_executable(test_nonlinear_lab11
        tests/test_nonlinear_lab11.cpp
)

target_link_libraries(test_nonlinear_lab11 numerical_library)

add_executable(test_nonlinear_lab12
        tests/test_nonlinear_lab12.cpp
)

target_link_libraries(test_nonlinear_lab12 numerical_library)

