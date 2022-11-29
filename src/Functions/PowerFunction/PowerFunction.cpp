/**
 * @author sanyavertolet
 */

#include <cmath>

#include "PowerFunction.h"

PowerFunction::PowerFunction(const std::string &function_type, std::initializer_list<numeric_type> parameters)
: AbstractFunction(function_type, parameters) {
    if (parameters.size() != 1) {
        throw std::logic_error("PowerFunction must receive one parameter - requested power.");
    }
}

numeric_type PowerFunction::operator()(numeric_type x) {
    return std::pow(x, params[0]);
}

numeric_type PowerFunction::get_derivative(numeric_type x) {
    return params[0] * std::pow(x, params[0] - 1);
}

std::string PowerFunction::to_string() {
    return type + " x^" + std::to_string(params[0]);
}
