/**
 * @author sanyavertolet
 */

#include "CompositionFunction.h"

CompositionFunction::CompositionFunction(AbstractFunctionPtr first, AbstractFunctionPtr second, char op)
: AbstractFunction("composition", { }), lhs(first), rhs(second), operation(op) { }

numeric_type CompositionFunction::operator()(numeric_type x) {
    return operations[operation](lhs, rhs, x);
}

numeric_type CompositionFunction::get_derivative(numeric_type x) {
    return derivative_operations[operation](lhs, rhs, x);
}

std::string CompositionFunction::to_string() {
    return type + " ((" + lhs->to_string() + ") " + operation + " (" + rhs->to_string() + "))";
}

std::map<char, CompositionFunction::operation_type> CompositionFunction::operations = {
        { '+', [](AbstractFunctionPtr left, AbstractFunctionPtr right, numeric_type x) {
            return (*left)(x) + (*right)(x);
        }},
        { '-', [](AbstractFunctionPtr left, AbstractFunctionPtr right, numeric_type x) {
            return (*left)(x) - (*right)(x);
        }},
        { '*', [](AbstractFunctionPtr left, AbstractFunctionPtr right, numeric_type x) {
            return (*left)(x) * (*right)(x);
        }},
        { '/', [](AbstractFunctionPtr left, AbstractFunctionPtr right, numeric_type x) {
            auto right_value = (*right)(x);
            if (right_value == 0) {
                throw std::logic_error("Division by zero.");
            }
            return (*left)(x) / right_value;
        }},
};

std::map<char, CompositionFunction::operation_type> CompositionFunction::derivative_operations = {
        { '+', [](AbstractFunctionPtr left, AbstractFunctionPtr right, numeric_type x) {
            return left->get_derivative(x) + right->get_derivative(x);
        }},
        { '-', [](AbstractFunctionPtr left, AbstractFunctionPtr right, numeric_type x) {
            return left->get_derivative(x) - right->get_derivative(x);
        }},
        { '*', [](AbstractFunctionPtr left, AbstractFunctionPtr right, numeric_type x) {
            return (*left)(x) * right->get_derivative(x) + left->get_derivative(x) * (*right)(x);
        }},
        { '/', [](AbstractFunctionPtr left, AbstractFunctionPtr right, numeric_type x) {
            auto right_value = (*right)(x);
            if (right_value == 0) {
                throw std::logic_error("Division by zero.");
            }
            return (left->get_derivative(x) * right_value - (*left)(x) * right->get_derivative(x)) / (right_value * right_value);
        }},
};
