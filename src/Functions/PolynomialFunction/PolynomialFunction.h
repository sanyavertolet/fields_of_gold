/**
 * @author sanyavertolet
 */

#ifndef FIELDS_OF_GOLD_POLYNOMFUNCTION_H
#define FIELDS_OF_GOLD_POLYNOMFUNCTION_H

#include <initializer_list>
#include <string>
#include <vector>

#include "../AbstractFunction/AbstractFunction.h"

#include "../../utils.h"

class PolynomialFunction : AbstractFunction {
public:
    PolynomialFunction(const std::string& function_type, std::initializer_list<numeric_type> parameters);

    numeric_type operator()(numeric_type x) override;
    numeric_type get_derivative(numeric_type x) override;

    std::string to_string() override;
private:
    std::string polynomial_string;
    std::vector<numeric_type> derivative_coefficients;
    static numeric_type heron_scheme(const std::vector<numeric_type> &coefficients, numeric_type x);
};


#endif //FIELDS_OF_GOLD_POLYNOMFUNCTION_H
