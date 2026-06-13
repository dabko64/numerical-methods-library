#cmake_minimum_required(VERSION 4.2)
#project(mn_project)
#
#set(CMAKE_CXX_STANDARD 20)
#
#add_executable(mn_project main.cpp
#        include/integration_lab6.hpp
#        tests/test_integration_lab6.cpp
#        examples/example_integration_lab6.cpp
#        include/integration_lab7.hpp
#        src/integration_lab7.cpp
#        tests/test_integration_lab7.cpp
#        src/integration_lab6.cpp
#        src/interpolation_lab2.cpp
#        include/interpolation_lab2.hpp
#        include/approximation_lab8.hpp
#        src/approximation_lab8.cpp
#        examples/example_approximation_lab8.cpp
#        tests/test_approximation_lab8.cpp
#        examples/example_ode_lab9.cpp
#        include/ode_lab9.hpp
#        src/ode_lab9.cpp
#        tests/test_ode_lab9.cpp
#        tests/test_interpolation_lab2.cpp
#)

cmake_minimum_required(VERSION 4.2)
project(mn_project)

set(CMAKE_CXX_STANDARD 20)

add_library(numeryka_lib
        src/integration_lab6.cpp
        src/integration_lab7.cpp
        src/interpolation_lab2.cpp
        src/approximation_lab8.cpp
        src/ode_lab9.cpp
        src/interpolation_lab3.cpp
)

target_include_directories(numeryka_lib PUBLIC include)

add_executable(example_integration examples/example_integration_lab6.cpp)
target_link_libraries(example_integration numeryka_lib)

add_executable(example_approximation examples/example_approximation_lab8.cpp
        examples/example_interpolation_lab2.cpp
        include/interpolation_lab3.hpp
        examples/example_interpolation_lab3.cpp)
target_link_libraries(example_approximation numeryka_lib)

add_executable(example_ode examples/example_ode_lab9.cpp)
target_link_libraries(example_ode numeryka_lib)

add_executable(test_integration_6 tests/test_integration_lab6.cpp)
target_link_libraries(test_integration_6 numeryka_lib)

add_executable(test_integration_7 tests/test_integration_lab7.cpp)
target_link_libraries(test_integration_7 numeryka_lib)

add_executable(test_interpolation tests/test_interpolation_lab2.cpp)
target_link_libraries(test_interpolation numeryka_lib)

add_executable(test_approximation tests/test_approximation_lab8.cpp
        tests/test_interpolation_lab3.cpp)
target_link_libraries(test_approximation numeryka_lib)

add_executable(test_ode tests/test_ode_lab9.cpp)
target_link_libraries(test_ode numeryka_lib)

add_executable(mn_project main.cpp)
target_link_libraries(mn_project numeryka_lib)

add_executable(test_interpolation_lab3 tests/test_interpolation_lab3.cpp)
target_link_libraries(test_interpolation_lab3 numeryka_lib)
add_executable(example_interpolation_lab3 examples/example_interpolation_lab3.cpp)
target_link_libraries(example_interpolation_lab3 numeryka_lib)