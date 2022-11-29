/**
 * @author sanyavertolet
 */

#include "ConstantFunction.h"

ConstantFunction::ConstantFunction(const std::string& function_type, std::initializer_list<numeric_type> parameters)
: AbstractFunction(function_type, parameters) {
    if (parameters.size() != 1) {
        throw std::logic_error("ConstantFunction must receive one parameter - constant of type numeric_type.");
    }
}

numeric_type ConstantFunction::operator()(numeric_type x) {
    return params[0];
}

numeric_type ConstantFunction::get_derivative(numeric_type x) {
    return 0;
}

std::string ConstantFunction::to_string() {
    return type + " " + std::to_string(params[0]);
}
