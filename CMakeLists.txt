cmake_minimum_required(VERSION 3.10)

project(numerical_methods_library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(numerical_library
        src/integration_lab6.cpp
        src/integration_lab7.cpp
        src/approximation_lab8.cpp
        src/ode_lab9.cpp
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

target_link_libraries(example_integration_lab7 numerical_library)

add_executable(example_approximation_lab8
        examples/example_approximation_lab8.cpp
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