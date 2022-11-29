/**
 * @author sanyavertolet
 */

#ifndef FIELDS_OF_GOLD_CONSTANTFUNCTION_H
#define FIELDS_OF_GOLD_CONSTANTFUNCTION_H

#include <initializer_list>
#include <string>
#include <vector>

#include "../AbstractFunction/AbstractFunction.h"

#include "../../utils.h"

class ConstantFunction : public AbstractFunction {
public:
    ConstantFunction(const std::string& function_type, std::initializer_list<numeric_type> parameters);

    numeric_type operator()(numeric_type x) override;
    numeric_type get_derivative(numeric_type x) override;

    std::string to_string() override;
};


#endif //FIELDS_OF_GOLD_CONSTANTFUNCTION_H
