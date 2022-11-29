/**
 * @author sanyavertolet
 */

#include <map>

#include "FunctionFactory.h"

AbstractFunctionPtr FunctionFactory::create(const std::string &function_type, std::initializer_list<numeric_type> parameters) {
    if (function_constructors.count(function_type) == 0) {
        throw std::logic_error("Could not find function type " + function_type);
    }
    auto new_function = function_constructors[function_type](function_type, parameters);
    functions.push_back(new_function);
    return new_function;
}

std::map<std::string, FunctionFactory::constructor_function_type> FunctionFactory::function_constructors = {
        { "ident", [](const std::string &function_type, std::initializer_list<numeric_type> parameters) {
            return (AbstractFunctionPtr)(new IdenticalFunction(function_type, parameters));
        }},
        { "const", [](const std::string &function_type, std::initializer_list<numeric_type> parameters) {
            return (AbstractFunctionPtr)(new ConstantFunction(function_type, parameters));
        }},
        { "power", [](const std::string &function_type, std::initializer_list<numeric_type> parameters) {
            return (AbstractFunctionPtr)(new PowerFunction(function_type, parameters));
        }},
        { "exp", [](const std::string &function_type, std::initializer_list<numeric_type> parameters) {
            return (AbstractFunctionPtr)(new ExponentialFunction(function_type, parameters));
        }},
        { "polynomial", [](const std::string &function_type, std::initializer_list<numeric_type> parameters) {
            return (AbstractFunctionPtr)(new PolynomialFunction(function_type, parameters));
        }}
};

void FunctionFactory::add(AbstractFunctionPtr function) {
    functions.push_back(function);
}

FunctionFactory::~FunctionFactory() {
    for (auto &function : functions) {
        delete function;
    }
}

size_t FunctionFactory::size() const {
    return functions.size();
}

FunctionFactory& FunctionFactory::get() {
    static FunctionFactory factory;
    return factory;
}

void FunctionFactory::clear() {
    for (auto &function : functions) {
        delete function;
    }
    functions = {};
}
