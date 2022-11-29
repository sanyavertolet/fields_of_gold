/**
 * @author sanyavertolet
 */

#ifndef FIELDS_OF_GOLD_ABSTRACTFUNCTION_H
#define FIELDS_OF_GOLD_ABSTRACTFUNCTION_H

#include <initializer_list>
#include <string>
#include <vector>
#include <stdexcept>

#include "../../utils.h"

class AbstractFunction {
public:
    AbstractFunction(std::string function_type, std::initializer_list<numeric_type> parameters);

    virtual numeric_type operator()(numeric_type x) = 0;
    virtual numeric_type get_derivative(numeric_type x) = 0;

    virtual std::string to_string();

    virtual ~AbstractFunction() = default;
protected:
    std::vector<numeric_type> params;
    std::string type;
};

using AbstractFunctionPtr = AbstractFunction*;

#endif //FIELDS_OF_GOLD_ABSTRACTFUNCTION_H
