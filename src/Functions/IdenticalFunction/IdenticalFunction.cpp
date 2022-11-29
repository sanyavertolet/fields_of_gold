/**
 * @author sanyavertolet
 */

#include "IdenticalFunction.h"

#include <utility>

IdenticalFunction::IdenticalFunction(const std::string& function_type, std::initializer_list<numeric_type> parameters)
: AbstractFunction(function_type, parameters) {
    if (parameters.size() != 0) {
        throw std::logic_error("IdenticalFunction may receive one optional parameter - empty initializer_list.");
    }
}

numeric_type IdenticalFunction::operator()(numeric_type x) {
    return x;
}

numeric_type IdenticalFunction::get_derivative(numeric_type x) {
    return 1;
}

std::string IdenticalFunction::to_string() {
    return type + " x";
}

