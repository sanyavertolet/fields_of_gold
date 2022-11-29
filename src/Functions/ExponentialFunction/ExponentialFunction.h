/**
 * @author sanyavertolet
 */

#ifndef FIELDS_OF_GOLD_EXPONENTIALFUNCTION_H
#define FIELDS_OF_GOLD_EXPONENTIALFUNCTION_H

#include <initializer_list>
#include <string>
#include <vector>

#include "../AbstractFunction/AbstractFunction.h"

#include "../../utils.h"

class ExponentialFunction : public AbstractFunction {
public:
    ExponentialFunction(const std::string& function_type, std::initializer_list<numeric_type> parameters);

    numeric_type operator()(numeric_type x) override;
    numeric_type get_derivative(numeric_type x) override;

    std::string to_string() override;
private:
    numeric_type log = 0;
};


#endif //FIELDS_OF_GOLD_EXPONENTIALFUNCTION_H
