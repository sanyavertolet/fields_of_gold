/**
 * @author sanyavertolet
 */

#include <iostream>

#include "gtest/gtest.h"
#include "../src/Functions/ConstantFunction/ConstantFunction.h"
#include "../src/Factory/FunctionFactory.h"
#include "../src/GradientDescent.h"
#include "../src/Functions/Operators/operators.h"

class GradientDescent_test : public testing::Test { };

TEST(GradientDescent_test, polynomial_equation_test) {
    auto &factory = FunctionFactory::get();
    factory.clear();
    ASSERT_EQ(factory.size(), 0);
    auto polynomial = factory.create("polynomial", { 1, -2, 1 } );
    auto result1 = solve(polynomial, 0, 1000000, 0.01);
    auto result2 = solve(polynomial, 0, 1000000, 0.5, 2);
    std::cerr << "Expected result: " << 1 << std::endl;
    std::cerr << "Actual result with constant descent: " << result1 << std::endl;
    std::cerr << "Actual result with decreasing descent: " << result2 << std::endl;

    auto min_delta = std::min(abs(result1 - 1), abs(result2 - 1));

    ASSERT_TRUE(abs(min_delta) <= delta);
}

TEST(GradientDescent_test, compositional_equation_test) {
    auto &factory = FunctionFactory::get();
    factory.clear();
    ASSERT_EQ(factory.size(), 0);
    auto exponential = factory.create("exp", { 2 } );
    auto constant = factory.create("const", { 4 });
    auto composition = *exponential - *constant;
    auto result1 = solve(composition, 0, 1000000, 0.1);
    auto result2 = solve(composition, 0, 1000000, 0.5, 2);
    std::cerr << "Expected result: " << 2 << std::endl;
    std::cerr << "Actual result with constant descent: " << result1 << std::endl;
    std::cerr << "Actual result with decreasing descent: " << result2 << std::endl;

    auto min_delta = std::min(abs(result1 - 2), abs(result2 - 2));

    ASSERT_TRUE(min_delta * min_delta <= delta * delta);
}