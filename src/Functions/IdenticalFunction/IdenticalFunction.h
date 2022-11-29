/**
 * @author sanyavertolet
 */

#ifndef FIELDS_OF_GOLD_IDENTICALFUNCTION_H
#define FIELDS_OF_GOLD_IDENTICALFUNCTION_H

#include <initializer_list>
#include <string>
#include <vector>

#include "../AbstractFunction/AbstractFunction.h"

#include "../../utils.h"

class IdenticalFunction : public AbstractFunction {
public:
    explicit IdenticalFunction(const std::string& function_type, std::initializer_list<numeric_type> parameters = std::initializer_list<numeric_type>());

    numeric_type operator()(numeric_type x) override;
    numeric_type get_derivative(numeric_type x) override;

    std::string to_string() override;
};


#endif //FIELDS_OF_GOLD_IDENTICALFUNCTION_H
