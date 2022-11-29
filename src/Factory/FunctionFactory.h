/**
 * @author sanyavertolet
 */

#ifndef FIELDS_OF_GOLD_FUNCTIONFACTORY_H
#define FIELDS_OF_GOLD_FUNCTIONFACTORY_H

#include <functional>
#include <initializer_list>
#include <string>

#include "../Functions/AbstractFunction/AbstractFunction.h"
#include "../Functions/ConstantFunction/ConstantFunction.h"
#include "../Functions/ExponentialFunction/ExponentialFunction.h"
#include "../Functions/IdenticalFunction/IdenticalFunction.h"
#include "../Functions/PolynomialFunction/PolynomialFunction.h"
#include "../Functions/PowerFunction/PowerFunction.h"

#include "../utils.h"

class FunctionFactory {
public:
    using constructor_function_type = std::function<AbstractFunctionPtr(const std::string&, std::initializer_list<numeric_type>)>;

    FunctionFactory() = default;

    AbstractFunctionPtr create(const std::string &function_type, std::initializer_list<numeric_type> parameters);
    void add(AbstractFunctionPtr function);
    [[nodiscard]] size_t size() const;

    ~FunctionFactory();
private:
    std::vector<AbstractFunctionPtr> functions;
    static std::map<std::string, constructor_function_type> function_constructors;
};


#endif //FIELDS_OF_GOLD_FUNCTIONFACTORY_H
