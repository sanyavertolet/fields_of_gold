/**
 * @author sanyavertolet
 */

#include <cmath>

#include "ExponentialFunction.h"

ExponentialFunction::ExponentialFunction(const std::string &function_type, std::initializer_list<numeric_type> parameters)
: AbstractFunction(function_type, parameters) {
    if (parameters.size() != 1) {
        throw std::logic_error("ExponentialFunction must receive one parameter - base of exponent.");
    }
    auto base = *parameters.begin();
    if (base < 0) {
        throw std::logic_error("The base of exponent should not be negative.");
    }
    if (base > 0) {
        log = std::log(base);
    }
}

numeric_type ExponentialFunction::operator()(numeric_type x) {
    return std::pow(params[0], x);
}

numeric_type ExponentialFunction::get_derivative(numeric_type x) {
    if (params[0] == 0) {
        throw std::logic_error("Derivative is not defined as far as the base of exponential function is zero.");
    }
    return log * std::pow(params[0], x);
}

std::string ExponentialFunction::to_string() {
    return type + " " + std::to_string(params[0]) + "^x";
}
