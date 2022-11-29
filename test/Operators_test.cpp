/**
 * @author sanyavertolet
 */

#include "gtest/gtest.h"

#include "../src/Factory/FunctionFactory.h"
#include "../src/Functions/CompositionFunction/CompositionFunction.h"
#include "../src/Functions/Operators/operators.h"

class Operators_test : public testing::Test { };

TEST(Operators_test, plus_test) {
    auto &factory = FunctionFactory::get();
    factory.clear();
    ASSERT_EQ(factory.size(), 0);

    auto polynomial = factory.create("polynomial", { 0, 1, 2, 3 });
    ASSERT_EQ(factory.size(), 1);
    auto power = factory.create("power", { 3 });
    ASSERT_EQ(factory.size(), 2);

    auto composition = *polynomial + *power;
    ASSERT_EQ(factory.size(), 3);

    ASSERT_EQ((*composition)(0), 0);
    ASSERT_EQ((*composition)(1), 7);
    ASSERT_EQ((*composition)(2), 0 * 2 + 2 + 2 * (2 * 2) + 3 * (2 * 2 * 2) + 8);

    ASSERT_EQ(composition->get_derivative(0), 1);
    ASSERT_EQ(composition->get_derivative(1), 1 * 1 + 2 * 2 + 3 * 3 + 3 * 1);
    ASSERT_EQ(composition->get_derivative(2), 1 + 4 * 2 + 9 * 4 + 3 * 2 * 2);

    ASSERT_EQ(composition->to_string(), "composition ((polynomial 0.000000 + 1.000000*x^1.000000 + 2.000000*x^2.000000 + 3.000000*x^3.000000) + (power x^3.000000))");
}

TEST(Operators_test, minus_test) {
    auto &factory = FunctionFactory::get();
    factory.clear();
    ASSERT_EQ(factory.size(), 0);

    auto polynomial = factory.create("polynomial", { 0, 1, 2, 3 });
    ASSERT_EQ(factory.size(), 1);
    auto power = factory.create("power", { 3 });
    ASSERT_EQ(factory.size(), 2);

    auto composition = *polynomial - *power;
    ASSERT_EQ(factory.size(), 3);

    ASSERT_EQ((*composition)(0), 0);
    ASSERT_EQ((*composition)(1), 5);
    ASSERT_EQ((*composition)(2), 0 * 2 + 2 + 2 * (2 * 2) + 3 * (2 * 2 * 2) - 8);

    ASSERT_EQ(composition->get_derivative(0), 1);
    ASSERT_EQ(composition->get_derivative(1), 1 * 1 + 2 * 2 + 3 * 3 - 3 * 1);
    ASSERT_EQ(composition->get_derivative(2), 1 + 4 * 2 + 9 * 4 - 3 * 2 * 2);

    ASSERT_EQ(composition->to_string(), "composition ((polynomial 0.000000 + 1.000000*x^1.000000 + 2.000000*x^2.000000 + 3.000000*x^3.000000) - (power x^3.000000))");
}

TEST(Operators_test, multipy_test) {
    auto &factory = FunctionFactory::get();
    factory.clear();
    ASSERT_EQ(factory.size(), 0);

    auto polynomial = factory.create("polynomial", { 0, 1, 2, 3 });
    ASSERT_EQ(factory.size(), 1);
    auto power = factory.create("power", { 3 });
    ASSERT_EQ(factory.size(), 2);

    auto composition = *polynomial * *power;
    ASSERT_EQ(factory.size(), 3);

    ASSERT_EQ((*composition)(0), 0);
    ASSERT_EQ((*composition)(1), 6);
    ASSERT_EQ((*composition)(2), 272);

    ASSERT_EQ(composition->get_derivative(0), 0);
    ASSERT_EQ(composition->get_derivative(1), 32);
    ASSERT_EQ(composition->get_derivative(2), 768);

    ASSERT_EQ(composition->to_string(), "composition ((polynomial 0.000000 + 1.000000*x^1.000000 + 2.000000*x^2.000000 + 3.000000*x^3.000000) * (power x^3.000000))");
}

TEST(Operators_test, divide_test) {
    auto &factory = FunctionFactory::get();
    factory.clear();
    ASSERT_EQ(factory.size(), 0);

    auto polynomial = factory.create("polynomial", { 0, 1, 2, 3 });
    ASSERT_EQ(factory.size(), 1);
    auto power = factory.create("power", { 3 });
    ASSERT_EQ(factory.size(), 2);

    auto composition = *polynomial / *power;
    ASSERT_EQ(factory.size(), 3);

    ASSERT_THROW((*composition)(0), std::logic_error);
    ASSERT_EQ((*composition)(1), 6);
    ASSERT_EQ((*composition)(2), 4.25);

    ASSERT_THROW(composition->get_derivative(0), std::logic_error);
    ASSERT_EQ(composition->get_derivative(1), -4);
    ASSERT_EQ(composition->get_derivative(2), -0.75);

    ASSERT_EQ(composition->to_string(), "composition ((polynomial 0.000000 + 1.000000*x^1.000000 + 2.000000*x^2.000000 + 3.000000*x^3.000000) / (power x^3.000000))");
}
