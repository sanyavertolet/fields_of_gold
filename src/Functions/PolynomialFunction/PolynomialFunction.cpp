/**
 * @author sanyavertolet
 */

#include "PolynomialFunction.h"

std::string get_monom_string(numeric_type coefficient, numeric_type power) {
    if (power == 0) {
        return std::to_string(coefficient);
    } else {
        return std::to_string(coefficient) + "*x" + "^" + std::to_string(power);
    }
}

PolynomialFunction::PolynomialFunction(const std::string &function_type, std::initializer_list<numeric_type> parameters)
: AbstractFunction(function_type, parameters) {
    if (parameters.size() < 1) {
        throw std::logic_error("PolynomialFunction must receive at least one parameter - polynomial coefficient.");
    }
    derivative_coefficients = parameters;
    derivative_coefficients.erase(derivative_coefficients.begin());
    int counter = 1;
    for (auto &coefficient : derivative_coefficients) {
        coefficient *= counter;
        ++counter;
    }
    counter = 0;
    for (auto coefficient_iter = parameters.begin(); coefficient_iter != parameters.end(); ++coefficient_iter) {
        polynomial_string += get_monom_string(*coefficient_iter, counter++);
        if (counter != parameters.size()) {
            polynomial_string += " + ";
        }
    }
}

numeric_type PolynomialFunction::operator()(numeric_type x) {
    return heron_scheme(params, x);
}

numeric_type PolynomialFunction::get_derivative(numeric_type x) {
    return heron_scheme(derivative_coefficients, x);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-loop-convert"
numeric_type PolynomialFunction::heron_scheme(const std::vector<numeric_type> &coefficients, numeric_type x) {
    numeric_type result = 0;
    for (auto coefficient_it = coefficients.rbegin(); coefficient_it != coefficients.rend(); ++coefficient_it) {
        result = result * x + *coefficient_it;
    }
    return result;
}

std::string PolynomialFunction::to_string() {
    return type + " " + polynomial_string;
}

#pragma clang diagnostic pop
