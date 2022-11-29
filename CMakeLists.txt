cmake_minimum_required(VERSION 3.22)
project(fields_of_gold)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(AbstractFunction src/Functions/AbstractFunction/AbstractFunction.h src/Functions/AbstractFunction/AbstractFunction.cpp)
set(ConstantFunction src/Functions/ConstantFunction/ConstantFunction.h src/Functions/ConstantFunction/ConstantFunction.cpp)
set(IdenticalFunction src/Functions/IdenticalFunction/IdenticalFunction.h src/Functions/IdenticalFunction/IdenticalFunction.cpp)
set(PowerFunction src/Functions/PowerFunction/PowerFunction.h src/Functions/PowerFunction/PowerFunction.cpp)
set(ExponentialFunction src/Functions/ExponentialFunction/ExponentialFunction.h src/Functions/ExponentialFunction/ExponentialFunction.cpp)
set(PolynomialFunction src/Functions/PolynomialFunction/PolynomialFunction.h src/Functions/PolynomialFunction/PolynomialFunction.cpp)
set(CompositionFunction src/Functions/CompositionFunction/CompositionFunction.h src/Functions/CompositionFunction/CompositionFunction.cpp)

set(operators src/Functions/Operators/operators.h src/Functions/Operators/operators.cpp)

set(Functions ${AbstractFunction} ${ConstantFunction} ${IdenticalFunction} ${PowerFunction} ${ExponentialFunction} ${PolynomialFunction} ${CompositionFunction} ${operators})

set(Factory src/Factory/FunctionFactory.h src/Factory/FunctionFactory.cpp)

set(GradientDescent src/GradientDescent.h src/GradientDescent.cpp)

add_library(fields_of_gold_lib ${Functions} ${Factory} ${GradientDescent})

add_executable(fields_of_gold main.cpp)
target_link_libraries(fields_of_gold fields_of_gold_lib)

add_executable(tests test/Functions_test.cpp test/Operators_test.cpp test/GradientDescent_test.cpp)
target_link_libraries(tests fields_of_gold_lib)
target_link_libraries(tests gtest_main)
add_test(NAME tests COMMAND tests)

