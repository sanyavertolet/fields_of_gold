/**
 * @author sanyavertolet
 */

#include <cmath>

#include "gtest/gtest.h"
#include "../src/Functions/ConstantFunction/ConstantFunction.h"
#include "../src/Factory/FunctionFactory.h"

class Functions_test : public testing::Test { };

TEST(Functions_test, constant_function_test) {
    auto factory = FunctionFactory();
    ASSERT_EQ(factory.size(), 0);
    auto const_function = factory.create("const", { 1 } );
    ASSERT_EQ(factory.size(), 1);
    ASSERT_EQ((*const_function)(1), 1);
    ASSERT_EQ((*const_function)(1), (*const_function)(2));

    ASSERT_EQ(const_function->get_derivative(1), 0);
    ASSERT_EQ(const_function->get_derivative(10), 0);

    auto another_const_function = factory.create("const", { 2 });
    ASSERT_EQ(factory.size(), 2);
    ASSERT_EQ((*another_const_function)(1), 2);
    ASSERT_EQ((*another_const_function)(1), (*another_const_function)(2));

    ASSERT_EQ(another_const_function->get_derivative(1), 0);
    ASSERT_EQ(another_const_function->get_derivative(10), 0);

    ASSERT_EQ(const_function->to_string(), "const 1.000000");
    ASSERT_EQ(another_const_function->to_string(), "const 2.000000");

    ASSERT_THROW(factory.create("const", { }), std::logic_error);
    ASSERT_THROW(factory.create("const", { 1, 2 }), std::logic_error);
}

TEST(Functions_test, identical_function_test) {
    auto factory = FunctionFactory();
    ASSERT_EQ(factory.size(), 0);
    auto identical_function = factory.create("ident", { });
    ASSERT_EQ(factory.size(), 1);
    ASSERT_EQ((*identical_function)(1), 1);
    ASSERT_EQ((*identical_function)(2), 2);
    ASSERT_EQ((*identical_function)(-5), -5);
    ASSERT_NE((*identical_function)(1), (*identical_function)(2));

    ASSERT_EQ(identical_function->get_derivative(1), 1);
    ASSERT_EQ(identical_function->get_derivative(10), 1);
    ASSERT_EQ(identical_function->get_derivative(10), identical_function->get_derivative(-321));

    auto another_identical_function = factory.create("ident", { });
    ASSERT_EQ(factory.size(), 2);
    ASSERT_EQ((*another_identical_function)(5), 5);
    ASSERT_EQ((*identical_function)(1), (*another_identical_function)(1));

    ASSERT_EQ(identical_function->to_string(), "ident x");
    ASSERT_EQ(another_identical_function->to_string(), "ident x");

    ASSERT_THROW(factory.create("ident", { 1 }), std::logic_error);
    ASSERT_THROW(factory.create("ident", { 1, 2 }), std::logic_error);
}

TEST(Functions_test, exponential_function_test) {
    auto factory = FunctionFactory();
    ASSERT_EQ(factory.size(), 0);
    auto exponential_function = factory.create("exp", { 2 });
    ASSERT_EQ(factory.size(), 1);
    ASSERT_EQ((*exponential_function)(0), 1);
    ASSERT_EQ((*exponential_function)(1), 2);
    ASSERT_EQ((*exponential_function)(2), 4);
    ASSERT_EQ((*exponential_function)(3), 8);
    ASSERT_NE((*exponential_function)(1), (*exponential_function)(2));

    ASSERT_EQ(exponential_function->get_derivative(0), std::log(2) * 1);
    ASSERT_EQ(exponential_function->get_derivative(1), std::log(2) * 2);
    ASSERT_EQ(exponential_function->get_derivative(2), std::log(2) * 4);
    ASSERT_NE(exponential_function->get_derivative(10), exponential_function->get_derivative(1));

    ASSERT_EQ(exponential_function->to_string(), "exp 2.000000^x");

    ASSERT_THROW(factory.create("exp", { -1 }), std::logic_error);
    ASSERT_THROW(factory.create("exp", { 1, 2 }), std::logic_error);
}

TEST(Functions_test, power_function_test) {
    auto factory = FunctionFactory();
    ASSERT_EQ(factory.size(), 0);
    auto power_function = factory.create("power", { 2 });
    ASSERT_EQ(factory.size(), 1);
    ASSERT_EQ((*power_function)(0), 0);
    ASSERT_EQ((*power_function)(1), 1);
    ASSERT_EQ((*power_function)(2), 4);
    ASSERT_EQ((*power_function)(3), 9);
    ASSERT_EQ((*power_function)(-5), (*power_function)(+5));
    ASSERT_NE((*power_function)(1), (*power_function)(2));

    ASSERT_EQ(power_function->get_derivative(-1), -2);
    ASSERT_EQ(power_function->get_derivative(+0), +0);
    ASSERT_EQ(power_function->get_derivative(+1), +2);
    ASSERT_EQ(power_function->get_derivative(+2), +4);
    ASSERT_EQ(power_function->get_derivative(+3), +6);

    ASSERT_EQ(power_function->to_string(), "power x^2.000000");

    ASSERT_THROW(factory.create("power", { }), std::logic_error);
    ASSERT_THROW(factory.create("power", { 1, 2 }), std::logic_error);
}

TEST(Functions_test, polynomial_function_test) {
    auto factory = FunctionFactory();
    ASSERT_EQ(factory.size(), 0);
    auto polynomial_function = factory.create("polynomial", { 1, 2, 3, 4, 5 });
    ASSERT_EQ(factory.size(), 1);
    ASSERT_EQ((*polynomial_function)(0), 1);
    ASSERT_EQ((*polynomial_function)(1), 15);
    ASSERT_EQ((*polynomial_function)(2), 129);

    ASSERT_EQ(polynomial_function->get_derivative(0), 2);
    ASSERT_EQ(polynomial_function->get_derivative(1), 40);

    ASSERT_EQ(
            polynomial_function->to_string(),
            "polynomial 1.000000 + 2.000000*x^1.000000 + 3.000000*x^2.000000 + 4.000000*x^3.000000 + 5.000000*x^4.000000"
            );

    ASSERT_THROW(factory.create("polynomial", { }), std::logic_error);
}

TEST(Functions_test, factory_test) {
    auto factory = FunctionFactory();
    ASSERT_EQ(factory.size(), 0);
    ASSERT_THROW(factory.create("not_a_function_at_all", {}), std::logic_error);
}
