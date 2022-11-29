/**
 * @author sanyavertolet
 */

#ifndef FIELDS_OF_GOLD_COMPOSITIONFUNCTION_H
#define FIELDS_OF_GOLD_COMPOSITIONFUNCTION_H

#include <functional>
#include <initializer_list>
#include <map>
#include <string>

#include "../AbstractFunction/AbstractFunction.h"

#include "../../utils.h"

class CompositionFunction : public AbstractFunction {
public:
    using operation_type = std::function<numeric_type(AbstractFunctionPtr, AbstractFunctionPtr, numeric_type)>;
    CompositionFunction(AbstractFunctionPtr first, AbstractFunctionPtr second, char op);

    numeric_type operator()(numeric_type x) override;
    numeric_type get_derivative(numeric_type x) override;

    std::string to_string() override;
private:
    static std::map<char, operation_type> operations;
    static std::map<char, operation_type> derivative_operations;

    AbstractFunctionPtr lhs;
    AbstractFunctionPtr rhs;
    char operation;
};


#endif //FIELDS_OF_GOLD_COMPOSITIONFUNCTION_H
